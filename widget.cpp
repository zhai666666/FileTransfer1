// #include "widget.h"
// #include "ui_widget.h"

// Widget::Widget(QWidget *parent)
//     : QWidget(parent)
//     , ui(new Ui::Widget)
// {
//     ui->setupUi(this);
// }

// Widget::~Widget()
// {
//     delete ui;
// }

#include "widget.h"
#include "ui_widget.h"
#include <QFileDialog>
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowTitle("跨平台文件传输工具");
    this->resize(400, 200);

    // 初始化服务器和客户端
    m_server = new FileServer(this);
    m_client = new FileClient(this);

    // 连接信号槽
    connect(m_server, &FileServer::progressUpdate, this, &Widget::updateProgress);
    connect(m_server, &FileServer::transferFinished, this, &Widget::showSuccess);
    connect(m_server, &FileServer::errorOccurred, this, &Widget::showError);

    connect(m_client, &FileClient::progressUpdate, this, &Widget::updateProgress);
    connect(m_client, &FileClient::transferFinished, this, [this]() {
        showSuccess("文件发送成功！");
    });
    connect(m_client, &FileClient::errorOccurred, this, &Widget::showError);
    connect(m_client, &FileClient::connected, this, [this]() {
        ui->statusLabel->setText("已连接到服务器");
    });

    // 设置默认值
    ui->portEdit->setText("8888");
    ui->ipEdit->setText("192.168.1.100");  // 替换为你的树莓派IP
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_startServerBtn_clicked()
{
    quint16 port = ui->portEdit->text().toUShort();
    m_server->startServer(port);
    ui->statusLabel->setText("服务器已启动，端口: " + QString::number(port));
    ui->startServerBtn->setEnabled(false);
}

void Widget::on_selectFileBtn_clicked()
{
    QString filePath = QFileDialog::getOpenFileName(this, "选择要发送的文件");
    if (filePath.isEmpty())
        return;

    // 连接服务器并发送文件
    QString ip = ui->ipEdit->text();
    quint16 port = ui->portEdit->text().toUShort();

    ui->statusLabel->setText("正在连接服务器...");
    m_client->connectToServer(ip, port);

    // 等待连接成功后发送文件
    connect(m_client, &FileClient::connected, this, [this, filePath]() {
        m_client->sendFile(filePath);
        ui->statusLabel->setText("正在发送文件...");
    }, Qt::UniqueConnection);
}

void Widget::updateProgress(qint64 bytes, qint64 total)
{
    ui->progressBar->setMaximum(total);
    ui->progressBar->setValue(bytes);
    ui->statusLabel->setText(QString("传输进度: %1/%2 MB")
                                 .arg(bytes / 1024.0 / 1024.0, 0, 'f', 2)
                                 .arg(total / 1024.0 / 1024.0, 0, 'f', 2));
}

void Widget::showError(QString error)
{
    QMessageBox::critical(this, "错误", error);
    ui->statusLabel->setText("错误: " + error);
}

void Widget::showSuccess(QString message)
{
    QMessageBox::information(this, "成功", message);
    ui->statusLabel->setText(message);
    ui->progressBar->setValue(0);
}