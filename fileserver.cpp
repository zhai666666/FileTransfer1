// #include "fileserver.h"

// fileserver::fileserver() {}

#include "fileserver.h"
#include <QDebug>

FileServer::FileServer(QObject *parent) : QTcpServer(parent),
    m_socket(nullptr), m_totalBytes(0), m_bytesReceived(0)
{
}

void FileServer::startServer(quint16 port)
{
    if (!this->listen(QHostAddress::Any, port)) {
        emit errorOccurred("服务器启动失败: " + this->errorString());
        return;
    }
    qDebug() << "服务器已启动，监听端口:" << port;
}

void FileServer::incomingConnection(qintptr socketDescriptor)
{
    if (m_socket && m_socket->state() == QTcpSocket::ConnectedState) {
        // 只允许一个连接
        QTcpSocket *tempSocket = new QTcpSocket(this);
        tempSocket->setSocketDescriptor(socketDescriptor);
        tempSocket->disconnectFromHost();
        tempSocket->deleteLater();
        return;
    }

    m_socket = new QTcpSocket(this);
    m_socket->setSocketDescriptor(socketDescriptor);

    connect(m_socket, &QTcpSocket::readyRead, this, &FileServer::readData);
    connect(m_socket, &QTcpSocket::disconnected, this, &FileServer::disconnected);
    connect(m_socket, &QTcpSocket::errorOccurred, this, [this](QAbstractSocket::SocketError) {
        emit errorOccurred("连接错误: " + m_socket->errorString());
    });

    m_totalBytes = 0;
    m_bytesReceived = 0;
    qDebug() << "客户端已连接:" << m_socket->peerAddress().toString();
}

void FileServer::readData()
{
    if (m_bytesReceived == 0) {
        // 第一次接收：先接收文件信息（文件名+文件大小）
        QDataStream in(m_socket);
        in.setVersion(QDataStream::Qt_5_15);

        if (m_socket->bytesAvailable() < sizeof(qint64) + sizeof(quint32))
            return;

        in >> m_totalBytes;  // 读取文件总大小
        quint32 fileNameSize;
        in >> fileNameSize;  // 读取文件名长度

        if (m_socket->bytesAvailable() < fileNameSize)
            return;

        in >> m_fileName;  // 读取文件名
        m_bytesReceived += sizeof(qint64) + sizeof(quint32) + fileNameSize;

        // 打开文件准备写入
        m_file.setFileName(m_fileName);
        if (!m_file.open(QIODevice::WriteOnly)) {
            emit errorOccurred("无法创建文件: " + m_file.errorString());
            m_socket->disconnectFromHost();
            return;
        }
    }

    // 接收文件数据
    qint64 bytesToRead = qMin<qint64>(m_socket->bytesAvailable(), m_totalBytes - m_bytesReceived);
    QByteArray data = m_socket->read(bytesToRead);
    m_file.write(data);
    m_bytesReceived += bytesToRead;

    emit progressUpdate(m_bytesReceived, m_totalBytes);

    // 传输完成
    if (m_bytesReceived == m_totalBytes) {
        m_file.close();
        emit transferFinished(m_fileName);
        m_socket->disconnectFromHost();
    }
}

void FileServer::disconnected()
{
    if (m_file.isOpen())
        m_file.close();

    m_socket->deleteLater();
    m_socket = nullptr;
    m_totalBytes = 0;
    m_bytesReceived = 0;
    qDebug() << "客户端已断开连接";
}