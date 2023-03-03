/********************************************************************************
** Form generated from reading UI file 'addVideo.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
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
    QComboBox *videoTypeBox;
    QStackedWidget *stackedWidget;
    QWidget *rtspPage;
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *ipEdit;
    QLabel *label_4;
    QLineEdit *portEdit;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_2;
    QLineEdit *usrNameEdit;
    QSpacerItem *horizontalSpacer_5;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_6;
    QLabel *label_3;
    QLineEdit *passWordEdit;
    QSpacerItem *horizontalSpacer_7;
    QWidget *rtmpPage;
    QHBoxLayout *horizontalLayout_4;
    QWidget *widget_6;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QLineEdit *rtmp_url;
    QWidget *httpFlvPage;
    QVBoxLayout *verticalLayout_3;
    QWidget *widget_7;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_6;
    QLineEdit *http_flv_url;
    QWidget *page;
    QVBoxLayout *verticalLayout_4;
    QWidget *widget_5;
    QComboBox *localCamDevice;
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
        videoTypeBox = new QComboBox(addVideo);
        videoTypeBox->addItem(QString());
        videoTypeBox->addItem(QString());
        videoTypeBox->addItem(QString());
        videoTypeBox->addItem(QString());
        videoTypeBox->setObjectName(QString::fromUtf8("videoTypeBox"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Times New Roman"));
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        videoTypeBox->setFont(font1);

        verticalLayout_2->addWidget(videoTypeBox);

        stackedWidget = new QStackedWidget(addVideo);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        rtspPage = new QWidget();
        rtspPage->setObjectName(QString::fromUtf8("rtspPage"));
        verticalLayout = new QVBoxLayout(rtspPage);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget = new QWidget(rtspPage);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMinimumSize(QSize(170, 45));
        widget->setFont(font);
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);

        horizontalLayout->addWidget(label);

        ipEdit = new QLineEdit(widget);
        ipEdit->setObjectName(QString::fromUtf8("ipEdit"));
        ipEdit->setMinimumSize(QSize(125, 25));
        ipEdit->setMaximumSize(QSize(150, 25));

        horizontalLayout->addWidget(ipEdit);

        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout->addWidget(label_4);

        portEdit = new QLineEdit(widget);
        portEdit->setObjectName(QString::fromUtf8("portEdit"));
        portEdit->setMinimumSize(QSize(0, 25));

        horizontalLayout->addWidget(portEdit);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(2, 2);
        horizontalLayout->setStretch(3, 3);

        verticalLayout->addWidget(widget);

        widget_3 = new QWidget(rtspPage);
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
        label_2->setMinimumSize(QSize(120, 40));
        label_2->setMaximumSize(QSize(120, 40));
        label_2->setFont(font);

        horizontalLayout_2->addWidget(label_2);

        usrNameEdit = new QLineEdit(widget_3);
        usrNameEdit->setObjectName(QString::fromUtf8("usrNameEdit"));
        usrNameEdit->setMinimumSize(QSize(135, 25));
        usrNameEdit->setFont(font);

        horizontalLayout_2->addWidget(usrNameEdit);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);

        horizontalLayout_2->setStretch(0, 1);
        horizontalLayout_2->setStretch(1, 1);
        horizontalLayout_2->setStretch(2, 3);
        horizontalLayout_2->setStretch(3, 1);

        verticalLayout->addWidget(widget_3);

        widget_4 = new QWidget(rtspPage);
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
        label_3->setMinimumSize(QSize(120, 40));
        label_3->setMaximumSize(QSize(120, 40));
        label_3->setFont(font);

        horizontalLayout_3->addWidget(label_3);

        passWordEdit = new QLineEdit(widget_4);
        passWordEdit->setObjectName(QString::fromUtf8("passWordEdit"));
        passWordEdit->setMinimumSize(QSize(135, 25));
        passWordEdit->setFont(font);
        passWordEdit->setContextMenuPolicy(Qt::DefaultContextMenu);
        passWordEdit->setEchoMode(QLineEdit::Password);

        horizontalLayout_3->addWidget(passWordEdit);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_7);

        horizontalLayout_3->setStretch(0, 1);
        horizontalLayout_3->setStretch(1, 1);
        horizontalLayout_3->setStretch(2, 3);
        horizontalLayout_3->setStretch(3, 1);

        verticalLayout->addWidget(widget_4);

        stackedWidget->addWidget(rtspPage);
        rtmpPage = new QWidget();
        rtmpPage->setObjectName(QString::fromUtf8("rtmpPage"));
        horizontalLayout_4 = new QHBoxLayout(rtmpPage);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        widget_6 = new QWidget(rtmpPage);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        widget_6->setMinimumSize(QSize(170, 45));
        widget_6->setFont(font);
        horizontalLayout_5 = new QHBoxLayout(widget_6);
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(widget_6);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font);

        horizontalLayout_5->addWidget(label_5);

        rtmp_url = new QLineEdit(widget_6);
        rtmp_url->setObjectName(QString::fromUtf8("rtmp_url"));
        rtmp_url->setMinimumSize(QSize(125, 25));

        horizontalLayout_5->addWidget(rtmp_url);

        horizontalLayout_5->setStretch(0, 1);
        horizontalLayout_5->setStretch(1, 10);

        horizontalLayout_4->addWidget(widget_6);

        stackedWidget->addWidget(rtmpPage);
        httpFlvPage = new QWidget();
        httpFlvPage->setObjectName(QString::fromUtf8("httpFlvPage"));
        verticalLayout_3 = new QVBoxLayout(httpFlvPage);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        widget_7 = new QWidget(httpFlvPage);
        widget_7->setObjectName(QString::fromUtf8("widget_7"));
        widget_7->setMinimumSize(QSize(170, 45));
        widget_7->setFont(font);
        horizontalLayout_6 = new QHBoxLayout(widget_7);
        horizontalLayout_6->setSpacing(0);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(widget_7);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font);

        horizontalLayout_6->addWidget(label_6);

        http_flv_url = new QLineEdit(widget_7);
        http_flv_url->setObjectName(QString::fromUtf8("http_flv_url"));
        http_flv_url->setMinimumSize(QSize(125, 25));

        horizontalLayout_6->addWidget(http_flv_url);

        horizontalLayout_6->setStretch(0, 1);
        horizontalLayout_6->setStretch(1, 10);

        verticalLayout_3->addWidget(widget_7);

        stackedWidget->addWidget(httpFlvPage);
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        verticalLayout_4 = new QVBoxLayout(page);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        widget_5 = new QWidget(page);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        localCamDevice = new QComboBox(widget_5);
        localCamDevice->setObjectName(QString::fromUtf8("localCamDevice"));
        localCamDevice->setGeometry(QRect(0, 10, 341, 71));

        verticalLayout_4->addWidget(widget_5);

        stackedWidget->addWidget(page);

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
        addVideo->setWindowTitle(QApplication::translate("addVideo", "addVideo", nullptr));
        videoTypeBox->setItemText(0, QApplication::translate("addVideo", "RTSP", nullptr));
        videoTypeBox->setItemText(1, QApplication::translate("addVideo", "RTMP", nullptr));
        videoTypeBox->setItemText(2, QApplication::translate("addVideo", "HTTP-FLV", nullptr));
        videoTypeBox->setItemText(3, QApplication::translate("addVideo", "Local-Camera", nullptr));

        label->setText(QApplication::translate("addVideo", "IP:", nullptr));
        label_4->setText(QApplication::translate("addVideo", "Port:", nullptr));
        label_2->setText(QApplication::translate("addVideo", "userName:", nullptr));
        label_3->setText(QApplication::translate("addVideo", "passWord:", nullptr));
        label_5->setText(QApplication::translate("addVideo", "url:", nullptr));
        label_6->setText(QApplication::translate("addVideo", "url:", nullptr));
        savePbt->setText(QApplication::translate("addVideo", "\344\277\235\345\255\230", nullptr));
        CancelPbt->setText(QApplication::translate("addVideo", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class addVideo: public Ui_addVideo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDVIDEO_H
