// #ifndef WIDGET_H
// #define WIDGET_H

// #include <QWidget>

// QT_BEGIN_NAMESPACE
// namespace Ui {
// class Widget;
// }
// QT_END_NAMESPACE

// class Widget : public QWidget
// {
//     Q_OBJECT

// public:
//     explicit Widget(QWidget *parent = nullptr);
//     ~Widget() override;

// private:
//     Ui::Widget *ui;
// };
// #endif // WIDGET_H

#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "fileserver.h"
#include "fileclient.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_startServerBtn_clicked();
    void on_selectFileBtn_clicked();
    void updateProgress(qint64 bytes, qint64 total);
    void showError(QString error);
    void showSuccess(QString message);

private:
    Ui::Widget *ui;
    FileServer *m_server;
    FileClient *m_client;
};

#endif // WIDGET_H