#ifndef FILECLIENT_H
#define FILECLIENT_H

#include <QTcpSocket>
#include <QFile>
#include <QDataStream>  // 新增：缺少这个头文件导致QDataStream错误

class FileClient : public QObject
{
    Q_OBJECT
public:
    explicit FileClient(QObject *parent = nullptr);
    void connectToServer(QString ip, quint16 port);
    void sendFile(QString filePath);

signals:
    void progressUpdate(qint64 bytesSent, qint64 totalBytes);
    void transferFinished();
    void errorOccurred(QString error);
    void connected();

private slots:
    void sendData();
    void disconnected();

private:
    QTcpSocket *m_socket;
    QFile m_file;
    qint64 m_totalBytes;
    qint64 m_bytesSent;
    QString m_filePath;
};

#endif // FILECLIENT_H