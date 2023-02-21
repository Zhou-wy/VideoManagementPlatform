/********************************************************************************
** Form generated from reading UI file 'addVideo.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDVIDEO_H
#define UI_ADDVIDEO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_addVideo
{
public:
    QVBoxLayout *verticalLayout_2;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *addWebVideo;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *addLocalVideo;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QComboBox *videoTypeBox;
    QLabel *label;
    QLineEdit *ipEdit;
    QLabel *label_4;
    QLineEdit *portEdit;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_8;
    QLineEdit *usrNameEdit;
    QSpacerItem *horizontalSpacer_5;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_6;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_9;
    QLineEdit *passWordEdit;
    QSpacerItem *horizontalSpacer_7;
    QWidget *page_2;
    QWidget *widget_2;
    QGridLayout *gridLayout_2;
    QPushButton *savePbt;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *CancelPbt;

    void setupUi(QDialog *addVideo)
    {
        if (addVideo->objectName().isEmpty())
            addVideo->setObjectName(QString::fromUtf8("addVideo"));
        addVideo->resize(400, 280);
        addVideo->setMinimumSize(QSize(400, 280));
        addVideo->setMaximumSize(QSize(500, 320));
        QFont font;
        font.setFamily(QString::fromUtf8("Times New Roman"));
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        addVideo->setFont(font);
        verticalLayout_2 = new QVBoxLayout(addVideo);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        widget_5 = new QWidget(addVideo);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        widget_5->setMinimumSize(QSize(0, 40));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Songti SC"));
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setWeight(75);
        widget_5->setFont(font1);
        horizontalLayout_4 = new QHBoxLayout(widget_5);
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        addWebVideo = new QPushButton(widget_5);
        addWebVideo->setObjectName(QString::fromUtf8("addWebVideo"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Songti SC"));
        font2.setPointSize(12);
        font2.setBold(true);
        font2.setWeight(75);
        addWebVideo->setFont(font2);

        horizontalLayout_4->addWidget(addWebVideo);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        addLocalVideo = new QPushButton(widget_5);
        addLocalVideo->setObjectName(QString::fromUtf8("addLocalVideo"));
        addLocalVideo->setFont(font2);

        horizontalLayout_4->addWidget(addLocalVideo);

        horizontalLayout_4->setStretch(0, 1);
        horizontalLayout_4->setStretch(2, 1);

        verticalLayout_2->addWidget(widget_5);

        stackedWidget = new QStackedWidget(addVideo);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        verticalLayout = new QVBoxLayout(page);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget = new QWidget(page);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMinimumSize(QSize(170, 45));
        widget->setFont(font);
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        videoTypeBox = new QComboBox(widget);
        videoTypeBox->addItem(QString());
        videoTypeBox->addItem(QString());
        videoTypeBox->addItem(QString());
        videoTypeBox->setObjectName(QString::fromUtf8("videoTypeBox"));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Times New Roman"));
        font3.setPointSize(12);
        font3.setBold(true);
        font3.setWeight(75);
        videoTypeBox->setFont(font3);

        horizontalLayout->addWidget(videoTypeBox);

        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);

        horizontalLayout->addWidget(label);

        ipEdit = new QLineEdit(widget);
        ipEdit->setObjectName(QString::fromUtf8("ipEdit"));
        ipEdit->setMinimumSize(QSize(100, 25));
        ipEdit->setFont(font);

        horizontalLayout->addWidget(ipEdit);

        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout->addWidget(label_4);

        portEdit = new QLineEdit(widget);
        portEdit->setObjectName(QString::fromUtf8("portEdit"));
        portEdit->setMinimumSize(QSize(0, 25));

        horizontalLayout->addWidget(portEdit);

        horizontalLayout->setStretch(0, 3);
        horizontalLayout->setStretch(1, 1);
        horizontalLayout->setStretch(2, 5);
        horizontalLayout->setStretch(3, 2);
        horizontalLayout->setStretch(4, 3);

        verticalLayout->addWidget(widget);

        widget_3 = new QWidget(page);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setMinimumSize(QSize(0, 40));
        widget_3->setFont(font);
        horizontalLayout_2 = new QHBoxLayout(widget_3);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        label_2 = new QLabel(widget_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        horizontalLayout_2->addWidget(label_2);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_8);

        usrNameEdit = new QLineEdit(widget_3);
        usrNameEdit->setObjectName(QString::fromUtf8("usrNameEdit"));
        usrNameEdit->setMinimumSize(QSize(135, 25));
        usrNameEdit->setFont(font);

        horizontalLayout_2->addWidget(usrNameEdit);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);

        horizontalLayout_2->setStretch(1, 1);
        horizontalLayout_2->setStretch(3, 3);

        verticalLayout->addWidget(widget_3);

        widget_4 = new QWidget(page);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        widget_4->setMinimumSize(QSize(0, 40));
        widget_4->setFont(font);
        horizontalLayout_3 = new QHBoxLayout(widget_4);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_6);

        label_3 = new QLabel(widget_4);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);

        horizontalLayout_3->addWidget(label_3);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_9);

        passWordEdit = new QLineEdit(widget_4);
        passWordEdit->setObjectName(QString::fromUtf8("passWordEdit"));
        passWordEdit->setMinimumSize(QSize(135, 25));
        passWordEdit->setFont(font);

        horizontalLayout_3->addWidget(passWordEdit);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_7);

        horizontalLayout_3->setStretch(1, 1);
        horizontalLayout_3->setStretch(3, 3);

        verticalLayout->addWidget(widget_4);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        stackedWidget->addWidget(page_2);

        verticalLayout_2->addWidget(stackedWidget);

        widget_2 = new QWidget(addVideo);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        gridLayout_2 = new QGridLayout(widget_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        savePbt = new QPushButton(widget_2);
        savePbt->setObjectName(QString::fromUtf8("savePbt"));

        gridLayout_2->addWidget(savePbt, 0, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 0, 3, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 0, 0, 1, 1);

        CancelPbt = new QPushButton(widget_2);
        CancelPbt->setObjectName(QString::fromUtf8("CancelPbt"));

        gridLayout_2->addWidget(CancelPbt, 0, 1, 1, 1);


        verticalLayout_2->addWidget(widget_2);


        retranslateUi(addVideo);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(addVideo);
    } // setupUi

    void retranslateUi(QDialog *addVideo)
    {
        addVideo->setWindowTitle(QCoreApplication::translate("addVideo", "addVideo", nullptr));
        addWebVideo->setText(QCoreApplication::translate("addVideo", "\347\275\221\347\273\234\346\221\204\345\203\217\345\244\264", nullptr));
        addLocalVideo->setText(QCoreApplication::translate("addVideo", "\346\234\254\345\234\260\346\221\204\345\203\217\345\244\264", nullptr));
        videoTypeBox->setItemText(0, QCoreApplication::translate("addVideo", "RTSP", nullptr));
        videoTypeBox->setItemText(1, QCoreApplication::translate("addVideo", "RTMP", nullptr));
        videoTypeBox->setItemText(2, QCoreApplication::translate("addVideo", "HTTP-FLV", nullptr));

        label->setText(QCoreApplication::translate("addVideo", "IP:", nullptr));
        label_4->setText(QCoreApplication::translate("addVideo", "Port:", nullptr));
        label_2->setText(QCoreApplication::translate("addVideo", "usrName:", nullptr));
        label_3->setText(QCoreApplication::translate("addVideo", "passWord:", nullptr));
        savePbt->setText(QCoreApplication::translate("addVideo", "\344\277\235\345\255\230", nullptr));
        CancelPbt->setText(QCoreApplication::translate("addVideo", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class addVideo: public Ui_addVideo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDVIDEO_H
