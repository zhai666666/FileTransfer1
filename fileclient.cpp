// #include "fileclient.h"

// fileclient::fileclient() {}

#include "fileclient.h"
#include <QDataStream>
#include <QFileInfo>
#include <QDebug>

FileClient::FileClient(QObject *parent) : QObject(parent),
    m_socket(new QTcpSocket(this)), m_totalBytes(0), m_bytesSent(0)
{
    connect(m_socket, &QTcpSocket::connected, this, &FileClient::connected);
    connect(m_socket, &QTcpSocket::bytesWritten, this, &FileClient::sendData);
    connect(m_socket, &QTcpSocket::disconnected, this, &FileClient::disconnected);
    connect(m_socket, &QTcpSocket::errorOccurred, this, [this](QAbstractSocket::SocketError) {
        emit errorOccurred("连接错误: " + m_socket->errorString());
    });
}

void FileClient::connectToServer(QString ip, quint16 port)
{
    if (m_socket->state() == QTcpSocket::ConnectedState)
        m_socket->disconnectFromHost();

    m_socket->connectToHost(ip, port);
}

void FileClient::sendFile(QString filePath)
{
    if (m_socket->state() != QTcpSocket::ConnectedState) {
        emit errorOccurred("未连接到服务器");
        return;
    }

    m_filePath = filePath;
    m_file.setFileName(m_filePath);
    if (!m_file.open(QIODevice::ReadOnly)) {
        emit errorOccurred("无法打开文件: " + m_file.errorString());
        return;
    }

    m_totalBytes = m_file.size();
    m_bytesSent = 0;

    // 先发送文件信息（文件总大小+文件名长度+文件名）
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_15);

    QFileInfo fileInfo(m_filePath);
    QString fileName = fileInfo.fileName();

    out << m_totalBytes;  // 文件总大小
    out << (quint32)fileName.toUtf8().size();  // 文件名长度
    out << fileName;  // 文件名

    m_socket->write(block);
    m_bytesSent += block.size();

    qDebug() << "开始发送文件:" << fileName << "大小:" << m_totalBytes << "字节";
}

void FileClient::sendData()
{
    if (m_bytesSent < m_totalBytes) {
        qint64 bytesToWrite = qMin(m_file.bytesAvailable(), (qint64)65536);  // 每次发送64KB
        QByteArray data = m_file.read(bytesToWrite);
        qint64 bytesWritten = m_socket->write(data);
        m_bytesSent += bytesWritten;

        emit progressUpdate(m_bytesSent, m_totalBytes);
    }

    // 传输完成
    if (m_bytesSent == m_totalBytes) {
        m_file.close();
        emit transferFinished();
        qDebug() << "文件发送完成";
    }
}

void FileClient::disconnected()
{
    if (m_file.isOpen())
        m_file.close();

    // 只有当文件没有发送完成时，才发出错误信号
    if (m_bytesSent < m_totalBytes) {
        emit errorOccurred("连接被意外断开");
    }

    m_totalBytes = 0;
    m_bytesSent = 0;
    qDebug() << "已断开与服务器的连接";
}