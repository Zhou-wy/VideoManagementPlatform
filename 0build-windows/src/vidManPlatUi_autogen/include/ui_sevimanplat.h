/********************************************************************************
** Form generated from reading UI file 'sevimanplat.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEVIMANPLAT_H
#define UI_SEVIMANPLAT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SeViManPlat
{
public:
    QVBoxLayout *verticalLayout_4;
    QWidget *widget_title;
    QHBoxLayout *horizontalLayout;
    QWidget *widget;
    QVBoxLayout *verticalLayout_3;
    QLabel *logoLab;
    QWidget *widget_label;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer;
    QToolButton *monitorBtn;
    QToolButton *videoBtn;
    QToolButton *logBtn;
    QToolButton *dataBtn;
    QToolButton *setupBtn;
    QWidget *widget_lcd;
    QVBoxLayout *verticalLayout_2;
    QLabel *suepLab;
    QLCDNumber *timeLcd;
    QLabel *cpuLabel;
    QStackedWidget *stackedWidget;
    QWidget *page_1;
    QHBoxLayout *horizontalLayout_2;
    QWidget *videoPanwidget;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_5;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *addVideoDevice;
    QPushButton *delVideoDevice;
    QTreeWidget *camDeviceList;
    QTreeWidget *camContorlList;
    QWidget *page_2;
    QWidget *page_3;
    QWidget *page_4;
    QWidget *page_5;

    void setupUi(QWidget *SeViManPlat)
    {
        if (SeViManPlat->objectName().isEmpty())
            SeViManPlat->setObjectName(QString::fromUtf8("SeViManPlat"));
        SeViManPlat->resize(1449, 866);
        SeViManPlat->setMinimumSize(QSize(1248, 702));
        SeViManPlat->setMaximumSize(QSize(3480, 2160));
        QFont font;
        font.setFamily(QString::fromUtf8("Songti SC"));
        font.setPointSize(18);
        SeViManPlat->setFont(font);
        SeViManPlat->setTabletTracking(false);
        verticalLayout_4 = new QVBoxLayout(SeViManPlat);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        widget_title = new QWidget(SeViManPlat);
        widget_title->setObjectName(QString::fromUtf8("widget_title"));
        widget_title->setMinimumSize(QSize(0, 105));
        widget_title->setMaximumSize(QSize(16777215, 100));
        widget_title->setFont(font);
        horizontalLayout = new QHBoxLayout(widget_title);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(widget_title);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setFont(font);
        verticalLayout_3 = new QVBoxLayout(widget);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        logoLab = new QLabel(widget);
        logoLab->setObjectName(QString::fromUtf8("logoLab"));
        logoLab->setMinimumSize(QSize(75, 75));
        logoLab->setMaximumSize(QSize(75, 75));
        logoLab->setFont(font);
        logoLab->setFocusPolicy(Qt::NoFocus);
        logoLab->setStyleSheet(QString::fromUtf8(""));
        logoLab->setPixmap(QPixmap(QString::fromUtf8(":/qss/icon/logo.png")));
        logoLab->setScaledContents(true);

        verticalLayout_3->addWidget(logoLab);

        verticalLayout_3->setStretch(0, 1);

        horizontalLayout->addWidget(widget);

        widget_label = new QWidget(widget_title);
        widget_label->setObjectName(QString::fromUtf8("widget_label"));
        widget_label->setFont(font);
        verticalLayout = new QVBoxLayout(widget_label);
        verticalLayout->setSpacing(2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(2, 2, 2, -1);
        label = new QLabel(widget_label);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Songti SC"));
        font1.setPointSize(48);
        label->setFont(font1);
        label->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));"));

        verticalLayout->addWidget(label);

        label_2 = new QLabel(widget_label);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Times New Roman"));
        font2.setPointSize(24);
        font2.setBold(true);
        font2.setWeight(75);
        label_2->setFont(font2);
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        verticalLayout->addWidget(label_2);


        horizontalLayout->addWidget(widget_label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        monitorBtn = new QToolButton(widget_title);
        monitorBtn->setObjectName(QString::fromUtf8("monitorBtn"));
        monitorBtn->setMinimumSize(QSize(80, 40));
        monitorBtn->setFont(font);
        monitorBtn->setAutoFillBackground(false);
        monitorBtn->setAutoRaise(false);

        horizontalLayout->addWidget(monitorBtn);

        videoBtn = new QToolButton(widget_title);
        videoBtn->setObjectName(QString::fromUtf8("videoBtn"));
        videoBtn->setMinimumSize(QSize(80, 40));
        videoBtn->setFont(font);

        horizontalLayout->addWidget(videoBtn);

        logBtn = new QToolButton(widget_title);
        logBtn->setObjectName(QString::fromUtf8("logBtn"));
        logBtn->setMinimumSize(QSize(80, 40));
        logBtn->setFont(font);

        horizontalLayout->addWidget(logBtn);

        dataBtn = new QToolButton(widget_title);
        dataBtn->setObjectName(QString::fromUtf8("dataBtn"));
        dataBtn->setMinimumSize(QSize(80, 40));
        dataBtn->setFont(font);

        horizontalLayout->addWidget(dataBtn);

        setupBtn = new QToolButton(widget_title);
        setupBtn->setObjectName(QString::fromUtf8("setupBtn"));
        setupBtn->setMinimumSize(QSize(80, 40));
        setupBtn->setFont(font);

        horizontalLayout->addWidget(setupBtn);

        widget_lcd = new QWidget(widget_title);
        widget_lcd->setObjectName(QString::fromUtf8("widget_lcd"));
        widget_lcd->setFont(font);
        verticalLayout_2 = new QVBoxLayout(widget_lcd);
        verticalLayout_2->setSpacing(1);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(2, 2, 2, 2);
        suepLab = new QLabel(widget_lcd);
        suepLab->setObjectName(QString::fromUtf8("suepLab"));
        suepLab->setMinimumSize(QSize(100, 50));
        suepLab->setMaximumSize(QSize(100, 50));
        suepLab->setFont(font);
        suepLab->setFocusPolicy(Qt::NoFocus);
        suepLab->setContextMenuPolicy(Qt::NoContextMenu);
        suepLab->setToolTipDuration(0);
        suepLab->setStyleSheet(QString::fromUtf8("image: url(:/icon/suep.png);"));
        suepLab->setPixmap(QPixmap(QString::fromUtf8(":/qss/icon/suep.png")));
        suepLab->setScaledContents(true);
        suepLab->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout_2->addWidget(suepLab);

        timeLcd = new QLCDNumber(widget_lcd);
        timeLcd->setObjectName(QString::fromUtf8("timeLcd"));
        timeLcd->setMinimumSize(QSize(120, 50));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Times New Roman"));
        font3.setPointSize(48);
        font3.setBold(false);
        font3.setItalic(false);
        font3.setWeight(9);
        timeLcd->setFont(font3);
        timeLcd->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 75 48pt \"Times New Roman\";"));
        timeLcd->setFrameShape(QFrame::NoFrame);
        timeLcd->setDigitCount(8);
        timeLcd->setSegmentStyle(QLCDNumber::Filled);

        verticalLayout_2->addWidget(timeLcd);

        cpuLabel = new QLabel(widget_lcd);
        cpuLabel->setObjectName(QString::fromUtf8("cpuLabel"));
        cpuLabel->setMinimumSize(QSize(30, 30));
        cpuLabel->setMaximumSize(QSize(16777215, 50));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Yuanti SC"));
        font4.setPointSize(14);
        font4.setBold(false);
        font4.setItalic(false);
        font4.setWeight(9);
        cpuLabel->setFont(font4);
        cpuLabel->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 75 14pt \"Yuanti SC\";"));

        verticalLayout_2->addWidget(cpuLabel);


        horizontalLayout->addWidget(widget_lcd);


        verticalLayout_4->addWidget(widget_title);

        stackedWidget = new QStackedWidget(SeViManPlat);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setFont(font);
        page_1 = new QWidget();
        page_1->setObjectName(QString::fromUtf8("page_1"));
        page_1->setStyleSheet(QString::fromUtf8(""));
        horizontalLayout_2 = new QHBoxLayout(page_1);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        videoPanwidget = new QWidget(page_1);
        videoPanwidget->setObjectName(QString::fromUtf8("videoPanwidget"));
        videoPanwidget->setMinimumSize(QSize(800, 600));
        videoPanwidget->setFont(font);

        horizontalLayout_2->addWidget(videoPanwidget);

        widget_2 = new QWidget(page_1);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setMinimumSize(QSize(270, 600));
        widget_2->setMaximumSize(QSize(270, 16777215));
        widget_2->setFont(font);
        verticalLayout_5 = new QVBoxLayout(widget_2);
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        widget_3 = new QWidget(widget_2);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        horizontalLayout_3 = new QHBoxLayout(widget_3);
        horizontalLayout_3->setSpacing(3);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(-1, 3, 3, 3);
        addVideoDevice = new QPushButton(widget_3);
        addVideoDevice->setObjectName(QString::fromUtf8("addVideoDevice"));
        addVideoDevice->setMinimumSize(QSize(0, 0));
        addVideoDevice->setMaximumSize(QSize(250, 16777215));
        QFont font5;
        font5.setFamily(QString::fromUtf8("Songti SC"));
        font5.setPointSize(14);
        addVideoDevice->setFont(font5);

        horizontalLayout_3->addWidget(addVideoDevice);

        delVideoDevice = new QPushButton(widget_3);
        delVideoDevice->setObjectName(QString::fromUtf8("delVideoDevice"));
        QFont font6;
        font6.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font6.setPointSize(14);
        delVideoDevice->setFont(font6);

        horizontalLayout_3->addWidget(delVideoDevice);

        horizontalLayout_3->setStretch(0, 1);
        horizontalLayout_3->setStretch(1, 1);

        verticalLayout_5->addWidget(widget_3);

        camDeviceList = new QTreeWidget(widget_2);
        QFont font7;
        font7.setFamily(QString::fromUtf8("Arial"));
        font7.setPointSize(18);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setTextAlignment(0, Qt::AlignCenter);
        __qtreewidgetitem->setFont(0, font7);
        camDeviceList->setHeaderItem(__qtreewidgetitem);
        QFont font8;
        font8.setFamily(QString::fromUtf8("Arial"));
        font8.setPointSize(16);
        QTreeWidgetItem *__qtreewidgetitem1 = new QTreeWidgetItem(camDeviceList);
        __qtreewidgetitem1->setFont(0, font8);
        QTreeWidgetItem *__qtreewidgetitem2 = new QTreeWidgetItem(camDeviceList);
        __qtreewidgetitem2->setFont(0, font8);
        camDeviceList->setObjectName(QString::fromUtf8("camDeviceList"));
        camDeviceList->setMinimumSize(QSize(0, 0));
        camDeviceList->setSizeIncrement(QSize(0, 0));
        camDeviceList->setBaseSize(QSize(0, 0));
        camDeviceList->setFont(font);
        camDeviceList->setLayoutDirection(Qt::LeftToRight);
        camDeviceList->setAutoExpandDelay(1);
        camDeviceList->header()->setVisible(true);
        camDeviceList->header()->setCascadingSectionResizes(false);
        camDeviceList->header()->setMinimumSectionSize(37);
        camDeviceList->header()->setDefaultSectionSize(100);
        camDeviceList->header()->setHighlightSections(false);

        verticalLayout_5->addWidget(camDeviceList, 0, Qt::AlignHCenter);

        camContorlList = new QTreeWidget(widget_2);
        QTreeWidgetItem *__qtreewidgetitem3 = new QTreeWidgetItem();
        __qtreewidgetitem3->setText(0, QString::fromUtf8("\350\256\276\345\244\207\347\256\241\347\220\206"));
        __qtreewidgetitem3->setTextAlignment(0, Qt::AlignCenter);
        __qtreewidgetitem3->setFont(0, font);
        camContorlList->setHeaderItem(__qtreewidgetitem3);
        camContorlList->setObjectName(QString::fromUtf8("camContorlList"));
        camContorlList->setFont(font);
        camContorlList->setAutoExpandDelay(1);
        camContorlList->header()->setVisible(true);
        camContorlList->header()->setCascadingSectionResizes(false);
        camContorlList->header()->setMinimumSectionSize(1);
        camContorlList->header()->setDefaultSectionSize(100);
        camContorlList->header()->setHighlightSections(false);

        verticalLayout_5->addWidget(camContorlList, 0, Qt::AlignHCenter);

        verticalLayout_5->setStretch(0, 1);
        verticalLayout_5->setStretch(1, 10);
        verticalLayout_5->setStretch(2, 10);

        horizontalLayout_2->addWidget(widget_2);

        horizontalLayout_2->setStretch(1, 1);
        stackedWidget->addWidget(page_1);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        stackedWidget->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName(QString::fromUtf8("page_4"));
        stackedWidget->addWidget(page_4);
        page_5 = new QWidget();
        page_5->setObjectName(QString::fromUtf8("page_5"));
        stackedWidget->addWidget(page_5);

        verticalLayout_4->addWidget(stackedWidget);


        retranslateUi(SeViManPlat);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(SeViManPlat);
    } // setupUi

    void retranslateUi(QWidget *SeViManPlat)
    {
        SeViManPlat->setWindowTitle(QApplication::translate("SeViManPlat", "SeViManPlat", nullptr));
        logoLab->setText(QString());
        label->setText(QApplication::translate("SeViManPlat", "\347\256\241\351\201\223\347\274\272\351\231\267\346\243\200\346\265\213\346\243\200\346\265\213\345\271\263\345\217\260", nullptr));
        label_2->setText(QApplication::translate("SeViManPlat", "Pipeline Defect Detection Platform", nullptr));
        monitorBtn->setText(QApplication::translate("SeViManPlat", "\350\247\206\351\242\221\347\233\221\346\216\247", nullptr));
        videoBtn->setText(QApplication::translate("SeViManPlat", "\350\247\206\351\242\221\345\233\236\346\224\276", nullptr));
        logBtn->setText(QApplication::translate("SeViManPlat", "\346\227\245\345\277\227\346\237\245\350\257\242", nullptr));
        dataBtn->setText(QApplication::translate("SeViManPlat", "\346\225\260\346\215\256\345\210\206\346\236\220", nullptr));
        setupBtn->setText(QApplication::translate("SeViManPlat", "\347\263\273\347\273\237\350\256\276\347\275\256", nullptr));
        suepLab->setText(QString());
        cpuLabel->setText(QApplication::translate("SeViManPlat", "cpu", nullptr));
        addVideoDevice->setText(QApplication::translate("SeViManPlat", "\346\226\260\345\242\236\346\221\204\345\203\217\345\244\264", nullptr));
        delVideoDevice->setText(QApplication::translate("SeViManPlat", "\345\210\240\351\231\244\346\221\204\345\203\217\345\244\264", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = camDeviceList->headerItem();
        ___qtreewidgetitem->setText(0, QApplication::translate("SeViManPlat", "\350\256\276\345\244\207\344\277\241\346\201\257", nullptr));

        const bool __sortingEnabled = camDeviceList->isSortingEnabled();
        camDeviceList->setSortingEnabled(false);
        QTreeWidgetItem *___qtreewidgetitem1 = camDeviceList->topLevelItem(0);
        ___qtreewidgetitem1->setText(0, QApplication::translate("SeViManPlat", "\347\275\221\347\273\234\346\221\204\345\203\217\345\244\264", nullptr));
        QTreeWidgetItem *___qtreewidgetitem2 = camDeviceList->topLevelItem(1);
        ___qtreewidgetitem2->setText(0, QApplication::translate("SeViManPlat", "\346\234\254\345\234\260\346\221\204\345\203\217\345\244\264", nullptr));
        camDeviceList->setSortingEnabled(__sortingEnabled);

    } // retranslateUi

};

namespace Ui {
    class SeViManPlat: public Ui_SeViManPlat {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEVIMANPLAT_H
