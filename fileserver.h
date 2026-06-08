#ifndef FILESERVER_H
#define FILESERVER_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QFile>
#include <QDataStream>  // 新增：缺少这个头文件导致QDataStream错误

class FileServer : public QTcpServer
{
    Q_OBJECT
public:
    explicit FileServer(QObject *parent = nullptr);
    void startServer(quint16 port);

signals:
    void progressUpdate(qint64 bytesReceived, qint64 totalBytes);
    void transferFinished(QString fileName);
    void errorOccurred(QString error);

protected:
    void incomingConnection(qintptr socketDescriptor) override;

private slots:
    void readData();
    void disconnected();

private:
    QTcpSocket *m_socket;
    QFile m_file;
    qint64 m_totalBytes;
    qint64 m_bytesReceived;
    QString m_fileName;
};

#endif // FILESERVER_H