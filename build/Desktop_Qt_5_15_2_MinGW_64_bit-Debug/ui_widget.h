/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *portEdit;
    QPushButton *startServerBtn;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *ipEdit;
    QPushButton *selectFileBtn;
    QProgressBar *progressBar;
    QLabel *statusLabel;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(400, 220);
        verticalLayout = new QVBoxLayout(Widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(Widget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        portEdit = new QLineEdit(Widget);
        portEdit->setObjectName(QString::fromUtf8("portEdit"));

        horizontalLayout->addWidget(portEdit);

        startServerBtn = new QPushButton(Widget);
        startServerBtn->setObjectName(QString::fromUtf8("startServerBtn"));

        horizontalLayout->addWidget(startServerBtn);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(Widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        ipEdit = new QLineEdit(Widget);
        ipEdit->setObjectName(QString::fromUtf8("ipEdit"));

        horizontalLayout_2->addWidget(ipEdit);

        selectFileBtn = new QPushButton(Widget);
        selectFileBtn->setObjectName(QString::fromUtf8("selectFileBtn"));

        horizontalLayout_2->addWidget(selectFileBtn);


        verticalLayout->addLayout(horizontalLayout_2);

        progressBar = new QProgressBar(Widget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setValue(0);

        verticalLayout->addWidget(progressBar);

        statusLabel = new QLabel(Widget);
        statusLabel->setObjectName(QString::fromUtf8("statusLabel"));
        statusLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(statusLabel);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "\350\267\250\345\271\263\345\217\260\346\226\207\344\273\266\344\274\240\350\276\223\345\267\245\345\205\267", nullptr));
        label->setText(QCoreApplication::translate("Widget", "\347\253\257\345\217\243\345\217\267:", nullptr));
        portEdit->setText(QCoreApplication::translate("Widget", "8888", nullptr));
        startServerBtn->setText(QCoreApplication::translate("Widget", "\345\220\257\345\212\250\346\234\215\345\212\241\345\231\250", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "\346\234\215\345\212\241\345\231\250IP:", nullptr));
        ipEdit->setText(QCoreApplication::translate("Widget", "192.168.1.100", nullptr));
        selectFileBtn->setText(QCoreApplication::translate("Widget", "\351\200\211\346\213\251\346\226\207\344\273\266\345\271\266\345\217\221\351\200\201", nullptr));
        statusLabel->setText(QCoreApplication::translate("Widget", "\345\260\261\347\273\252", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
