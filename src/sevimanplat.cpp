//
// Created by zhouwy on 2023/2/15.
//
// You may need to build the project (run Qt uic code generator) to get "ui_SeViManPlat.h" resolved
#pragma execution_character_set("utf-8")

#include "sevimanplat.h"
#include "ui_sevimanplat.h"
#include <QList>
#include <QToolButton>

SeViManPlat::SeViManPlat(QWidget *parent) :
        QWidget(parent), ui(new Ui::SeViManPlat) {
    ui->setupUi(this);
    this->initMenuPbt();
    this->initTimer();
    this->initCameraList();
    this->initCameraLayout();
//    this->initPlayWidget();

}

SeViManPlat::~SeViManPlat() {
    delete ui;
}

void SeViManPlat::initTimer() {
    QTime time = QTime::currentTime();
    //设置晶体管控件QLCDNumber上显示的内容
    ui->timeLcd->display(time.toString("hh:mm:ss"));
    ui->cpuLabel->setText(QString("   CPU ") + JQCPUMonitor::cpuUsagePercentageDisplayString());

    //新建一个QTimer对象
    timer = new QTimer();
    //设置定时器每个多少毫秒发送一个timeout()信号
    timer->setInterval(1000);
    //启动定时器
    timer->start();
    connect(timer, SIGNAL(timeout()), this, SLOT(onTimerOut()));

    this->loadStyle(":/qss/blacksoft.css");
}

void SeViManPlat::initMenuPbt() {
    iconSize = 40;
    //图标对应图形字体值
    icons << 0xea07 << 0xea14 << 0xea38 << 0xe608 << 0xe61b;
    //设置获取CPU占用率
    JQCPUMonitor::initialize();
    //设置样式表
    QStringList qss;
    qss << QString("QWidget#widget_title QAbstractButton{min-height:%1px;max-height:%1px;}").arg(80);
    this->setStyleSheet(qss.join(""));
    this->initMainBtnGroup();
}

void SeViManPlat::initMainBtnGroup() {
    QButtonGroup *btnGroup = new QButtonGroup(this);
    btnGroup->addButton(ui->monitorBtn);
    btnGroup->addButton(ui->videoBtn);
    btnGroup->addButton(ui->logBtn);
    btnGroup->addButton(ui->dataBtn);
    btnGroup->addButton(ui->setupBtn);

    //设置按钮可选中以及图标样式
    initBtn(btnGroup, false);
    //设置弱属性以便应用样式
    ui->widget_title->setProperty("flag", "bottom");

    //设置整体按钮组样式
    IconHelper::StyleColor styleColor;
    styleColor.defaultBorder = true;
    styleColor.position = "bottom";
    styleColor.iconSize = 25;
    styleColor.iconWidth = 25;
    styleColor.iconHeight = 25;
    styleColor.borderWidth = 3;
    styleColor.borderColor = "#A279C5";
    styleColor.setColor("#292929", "#B6D7E3", "#10689A", "#F0F0F0");
    IconHelper::setStyle(ui->widget_title, btnGroup->buttons(), icons, styleColor);

    //默认选中某个按钮
    ui->monitorBtn->click();
}

void SeViManPlat::initBtn(QButtonGroup *btnGroup, bool textBesideIcon) {
    QList<QAbstractButton *> btns = btnGroup->buttons();
            foreach (QAbstractButton *btn, btns) {
            QToolButton *b = (QToolButton *) btn;
            //关联按钮单击事件
//            connect(b, SIGNAL(clicked(bool)), this, SLOT(btnClicked()));
            b->setCheckable(true);
            b->setToolButtonStyle(textBesideIcon ? Qt::ToolButtonTextBesideIcon : Qt::ToolButtonTextUnderIcon);
        }
}

void SeViManPlat::onTimerOut() {
    //获取系统当前时间
    QTime time = QTime::currentTime();
    //设置晶体管控件QLCDNumber上显示的内容
    ui->timeLcd->display(time.toString("hh:mm:ss"));
    ui->cpuLabel->setText(QString("   CPU ") + JQCPUMonitor::cpuUsagePercentageDisplayString());
}

void SeViManPlat::initCameraList() {
//    ui->camDeviceList->set
//    ui->camDeviceList->header()->setMinimumHeight(30);
//    ui->camContorlList->setHeaderLabel("设备控制");
//    ui->camContorlList->header()->setMinimumHeight(30);

    //定义第一个树形组 网络摄像头项
//    QTreeWidget *WebcamGroup = new QTreeWidget(ui->camDeviceList);
//    WebcamGroup->setText(0, QStringLiteral("网络摄像头"));

//    QTreeWidget* Webcam_1 = new QTreeWidget(WebcamGroup);
//    Webcam_1->setText(0, "摄像头#1");  //设置子项显示的文本
//
//    QTreeWidget* Webcam_1_Main_stream = new QTreeWidget(Webcam_1);
//    Webcam_1_Main_stream->setText(0, "主码流");  //设置子项显示的文本
//
//    QTreeWidget* Webcam_1_Auxiliary_stream = new QTreeWidget(Webcam_1);
//    Webcam_1_Auxiliary_stream->setText(0, "主码流");  //设置子项显示的文本
//
//
//    //定义第二个树形组 本地摄像头项
//    QTreeWidget *camGroup = new QTreeWidget(ui->camDeviceList);
//    camGroup->setText(0, QStringLiteral("本地摄像头"));
//
//    //定义第二个树形组 本地视频项
//    QTreeWidget *localVideo = new QTreeWidget(ui->camDeviceList);
//    localVideo->setText(0, QStringLiteral("本地视频"));
}

void SeViManPlat::initCameraLayout() {
    videoWidget = new VideoPanel(ui->videoPanwidget);
    vectorLayout = new QVBoxLayout(ui->videoPanwidget);
    vectorLayout->addWidget(videoWidget);
}


void SeViManPlat::loadStyle(const QString &qssFile)
{
    //加载样式表
    QString qss;
    QFile file(qssFile);
    if (file.open(QFile::ReadOnly)) {
        //用QTextStream读取样式文件不用区分文件编码 带bom也行
        QStringList list;
        QTextStream in(&file);
        //in.setCodec("utf-8");
        while (!in.atEnd()) {
            QString line;
            in >> line;
            list << line;
        }

        file.close();
        qss = list.join("\n");
        QString paletteColor = qss.mid(20, 7);
        qApp->setPalette(QPalette(paletteColor));
        //用时主要在下面这句
        qApp->setStyleSheet(qss);
    }
}

//void SeViManPlat::initPlayWidget() {
//    playWidget = new FFmpegWidget();
//    playWidget->setObjectName(QString::fromUtf8("通道1"));
//    QSizePolicy sizePolicy(QSizePolicy(QSizePolicy::Preferred,QSizePolicy::Expanding));
//    sizePolicy.setHorizontalStretch(0);
//    sizePolicy.setVerticalStretch(0);
//    sizePolicy.setHeightForWidth(playWidget->sizePolicy().hasHeightForWidth());
//    playWidget->setSizePolicy(sizePolicy);
//}
