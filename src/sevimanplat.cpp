//
// Created by zhouwy on 2023/2/15.
//
// You may need to build the project (run Qt uic code generator) to get "ui_SeViManPlat.h" resolved

#include <QList>
#include <QToolButton>

#include "sevimanplat.h"
#include "ui_sevimanplat.h"
#include "utils/iLOG.hpp"


SeViManPlat::SeViManPlat(const QString &video_conf_json, const QString &log_save_dir, QWidget *parent) :
        QWidget(parent), ui(new Ui::SeViManPlat), m_video_conf_json(video_conf_json), m_log_save_dir(log_save_dir) {
    ui->setupUi(this);
    this->initMenuPbt();
    this->initTimer();
    this->initCameraLayout();
    this->initVideoPlay();
    this->initLogger();
    connect(ui->addVideoDevice, SIGNAL(clicked(bool)), this, SLOT(addVideoDialog()));
    connect(ui->camDeviceList, SIGNAL(clicked(const QModelIndex&)), this, SLOT(onTreeViewClicked(const QModelIndex&)));

}

SeViManPlat::~SeViManPlat() {
    destroyAll();
    delete ui;
}

void SeViManPlat::initLogger() {
    // 获取名为"myLogger"的logger
    Logger &logger = LoggerManager::getLogger("root");
    // 设置logger级别为info
    logger.setLevel(spdlog::level::debug);
    logger.setSaveDir("C:/Users/zwy/Desktop/VideoManagementPlatform-windows/log");
    DEBUG_FMT(logger, "test %d", 12);
    INFO_FMT(logger, "hello {}", "world");
    WARN_FMT(logger, "test %s", "str");
    ERROR_FMT(logger, "test %f", 3.14);
    FATAL_FMT(logger, "end");

}

void SeViManPlat::initTimer() {
    QTime time = QTime::currentTime();
    //设置晶体管控件QLCDNumber上显示的内容
    ui->timeLcd->display(time.toString("hh:mm:ss"));
    ui->cpuLabel->setText(QString("   CPU ") + JQCPUMonitor::cpuUsagePercentageDisplayString());

    //新建一个QTimer对象
    cpuMonTimer = new QTimer();
    //设置定时器每个多少毫秒发送一个timeout()信号
    cpuMonTimer->setInterval(1000);
    //启动定时器
    cpuMonTimer->start();
    connect(cpuMonTimer, SIGNAL(timeout()), this, SLOT(onTimerOut()));

    this->loadStyle(":/qss/lightblue.css");
}

void SeViManPlat::initMenuPbt() {
    //图标对应图形字体值
    icons << 0xea07 << 0xea14 << 0xea38 << 0xe608 << 0xe61b;
    //设置获取CPU占用率
    JQCPUMonitor::initialize();
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
    styleColor.iconSize = 35;
    styleColor.iconWidth = 35;
    styleColor.iconHeight = 35;
    styleColor.borderWidth = 3;
    styleColor.borderColor = "#A279C5";
    styleColor.setColor("#396488", "#B6D7E3", "#10689A", "#F0F0F0");
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

void SeViManPlat::initCameraLayout() {
    videoWidget = new VideoPanel(ui->videoPanwidget);
    videoWidgetLayout = new QVBoxLayout(ui->videoPanwidget);
    videoWidgetLayout->addWidget(videoWidget);
}

void SeViManPlat::loadStyle(const QString &qssFile) {
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

void SeViManPlat::initVideoPlay() {
    Json ReadVideoConfJson(m_video_conf_json, true);
    if (ReadVideoConfJson.getString("VideoCount") == "") {
//        INFOE("videoListConf 文件为空");
    } else {
        int videoCount = ReadVideoConfJson.getString("VideoCount").toInt();
        QString url = "";
        for (int i = 0; i < videoCount; ++i) { // 遍历所有的摄像头配置
            QString video_type = ReadVideoConfJson.getString("video" + QString::number(i + 1) + ".type");
            QString video_name = "video" + QString::number(i + 1);
            VideoConf *videoConf_i = new VideoConf;
            videoConf_i->video_name = video_name;
            if (video_type == "RTSP") {
                /*
                格式说明：
                1、username: 设备登录用户名。例如admin。
                2、password: 设备登录密码。例如admin123。
                3、ip: 设备IP地址。例如192.168.0.213
                4、port: 端口号默认为554，若为默认可不填写。
                5、channel: 通道号，起始为1。例如通道2，则为channel=2。
                6、subtype: 码流类型，主码流为0（即subtype=0），辅码流为1（即subtype=1）。
                 例如：
                     const string videoStreamAddress = "rtsp://admin:admin123@192.168.0.213:554/cam/realmonitor?channel=1&subtype=0";
                */
                //主码流
                QString main_code_stream = "rtsp://" + ReadVideoConfJson.getString(video_name + ".username") + ":" +
                                           ReadVideoConfJson.getString(video_name + ".password") + "@" +
                                           ReadVideoConfJson.getString(video_name + ".ip") + ":" +
                                           ReadVideoConfJson.getString(video_name + ".port") +
                                           "/cam/realmonitor?channel=1&subtype=0";
                //辅码流
                QString Auxiliary_code_stream =
                        "rtsp://" + ReadVideoConfJson.getString(video_name + ".username") + ":" +
                        ReadVideoConfJson.getString(video_name + ".password") + "@" +
                        ReadVideoConfJson.getString(video_name + ".ip") + ":" +
                        ReadVideoConfJson.getString(video_name + ".port") +
                        "/cam/realmonitor?channel=1&subtype=1";
                videoConf_i->urls.append(main_code_stream);
                videoConf_i->urls.append(Auxiliary_code_stream);

                // 设置右侧设备树
                QTreeWidgetItem *webCamRoot = ui->camDeviceList->topLevelItem(0);
                // 创建子节点
                auto *webCamItem = new QTreeWidgetItem();
                webCamItem->setText(0, "摄像头" + QString::number(i + 1));
                webCamRoot->addChild(webCamItem);

                // 创建主码流和辅码流
                auto *webCamMain_code_stream = new QTreeWidgetItem();
                webCamMain_code_stream->setText(0, "主码流");
                webCamItem->addChild(webCamMain_code_stream);
                auto *webCamAuxiliary_code_stream = new QTreeWidgetItem();
                webCamAuxiliary_code_stream->setText(0, "辅码流");
                webCamItem->addChild(webCamAuxiliary_code_stream);

                // TODO: 后期补充切换主码流和辅码流逻辑，现用主码流代替
                url = true ? main_code_stream : Auxiliary_code_stream;
//                INFO(main_code_stream.toStdString().c_str());
            } else if (video_type == "RTMP") {
                url = ReadVideoConfJson.getString(video_name + ".url");
                if (url == "") {
                    QMessageBox::critical(this, tr("ERROR"), tr(QString(
                                                  "打开视频" + video_name + "有误，请检查摄像头信息").toStdString().c_str()),
                                          QMessageBox::Close);
                    continue;
                } else {
//                    INFO("%s : %s", video_name.toStdString().c_str(), url.toStdString().c_str());
                    videoConf_i->urls.append(url);
                }

            } else if (video_type == "HTTP-FLV") {
                url = ReadVideoConfJson.getString(video_name + ".url");
                if (url == "") {
                    QMessageBox::critical(this, tr("ERROR"), tr(QString(
                                                  "打开视频" + video_name + "有误，请检查摄像头信息").toStdString().c_str()),
                                          QMessageBox::Close);
                    continue;
                } else {
//                    INFO("%s : %s", video_name.toStdString().c_str(), url.toStdString().c_str());
                    videoConf_i->urls.append(url);
                }

            } else if (video_type == "Local-Camera") {
                qDebug("%s : %s", video_name.toStdString().c_str(), video_type.toStdString().c_str());
            } else
                qDebug("This video%d type is %s, which does not belong to the preset video type!", i,
                       video_type.toStdString().c_str());
            if (!m_videoConf.contains(videoConf_i)) // 判断videoConf 是否在，如果存在就不要新增了
                m_videoConf.append(videoConf_i);

            this->videoPlay.append(new FFmpegWidget(videoWidget->getVideoWidgetList().at(i)));
            this->videoPlayLayout.append(new QVBoxLayout(videoWidget->getVideoWidgetList().at(i)));
            this->videoPlayLayout.at(i)->addWidget(this->videoPlay.at(i));
            this->videoPlay.at(i)->setUrl(url);
            this->videoPlay.at(i)->open();

//            delete videoConf_i;
        }
    }
    ReadVideoConfJson.save(m_video_conf_json);
}

void SeViManPlat::destroyAll() {
    delete cpuMonTimer;
    delete videoWidget;
    delete videoWidgetLayout;
    qDeleteAll(videoPlay);
    qDeleteAll(videoPlayLayout);
    qDeleteAll(m_videoConf);
}

void SeViManPlat::addVideoDialog() {
    this->addVideoTool = new addVideo(m_video_conf_json, this);
    this->addVideoTool->show();
    connect(this->addVideoTool, SIGNAL(finished(int)), this, SLOT(addVideoPlay()));
}

void SeViManPlat::addVideoPlay() {
    Json ReadVideoConfJson(m_video_conf_json, true);
    if (ReadVideoConfJson.getString("VideoCount") == "") {
//        INFOE("videoListConf 文件为空");
    } else {
        int videoCount = ReadVideoConfJson.getString("VideoCount").toInt();
        QString url = "";
        if (videoCount - this->m_videoConf.length() == 1) {
//            INFO("len(this->m_videoConf.length()) : %d, videoCount : %d ", this->m_videoConf.length(), videoCount);
            QString video_type = ReadVideoConfJson.getString("video" + QString::number(videoCount) + ".type");
            QString video_name = "video" + QString::number(videoCount);
            VideoConf *videoConf_i = new VideoConf;
            videoConf_i->video_name = video_name;
            if (video_type == "RTSP") {
                /*
                格式说明：
                1、username: 设备登录用户名。例如admin。
                2、password: 设备登录密码。例如admin123。
                3、ip: 设备IP地址。例如192.168.0.213
                4、port: 端口号默认为554，若为默认可不填写。
                5、channel: 通道号，起始为1。例如通道2，则为channel=2。
                6、subtype: 码流类型，主码流为0（即subtype=0），辅码流为1（即subtype=1）。
                 例如：
                     const string videoStreamAddress = "rtsp://admin:admin123@192.168.0.213:554/cam/realmonitor?channel=1&subtype=0";
                */
                //主码流
                QString main_code_stream = "rtsp://" + ReadVideoConfJson.getString(video_name + ".username") + ":" +
                                           ReadVideoConfJson.getString(video_name + ".password") + "@" +
                                           ReadVideoConfJson.getString(video_name + ".ip") + ":" +
                                           ReadVideoConfJson.getString(video_name + ".port") +
                                           "/cam/realmonitor?channel=1&subtype=0";
                //辅码流
                QString Auxiliary_code_stream =
                        "rtsp://" + ReadVideoConfJson.getString(video_name + ".username") + ":" +
                        ReadVideoConfJson.getString(video_name + ".password") + "@" +
                        ReadVideoConfJson.getString(video_name + ".ip") + ":" +
                        ReadVideoConfJson.getString(video_name + ".port") +
                        "/cam/realmonitor?channel=1&subtype=1";
                videoConf_i->urls.append(main_code_stream);
                videoConf_i->urls.append(Auxiliary_code_stream);

                // 设置右侧设备树
                QTreeWidgetItem *webCamRoot = ui->camDeviceList->topLevelItem(0);
                // 创建子节点
                auto *webCamItem = new QTreeWidgetItem();
                webCamItem->setText(0, "摄像头" + QString::number(videoCount));
                webCamRoot->addChild(webCamItem);

                // 创建主码流和辅码流
                auto *webCamMain_code_stream = new QTreeWidgetItem();
                webCamMain_code_stream->setText(0, "主码流");
                webCamItem->addChild(webCamMain_code_stream);
                auto *webCamAuxiliary_code_stream = new QTreeWidgetItem();
                webCamAuxiliary_code_stream->setText(0, "辅码流");
                webCamItem->addChild(webCamAuxiliary_code_stream);

                url = main_code_stream;
//                INFO("%s : %s", video_name.toStdString().c_str(), url.toStdString().c_str());
            } else if (video_type == "RTMP") {
                url = ReadVideoConfJson.getString(video_name + ".url");
                if (url == "") {
                    QMessageBox::critical(this, tr("ERROR"), tr(QString(
                                                  "打开视频" + video_name + "有误，请检查摄像头信息").toStdString().c_str()),
                                          QMessageBox::Close);
                } else {
//                    INFO("%s : %s", video_name.toStdString().c_str(), url.toStdString().c_str());
                    videoConf_i->urls.append(url);
                }

            } else if (video_type == "HTTP-FLV") {
                url = ReadVideoConfJson.getString(video_name + ".url");
                if (url == "") {
                    QMessageBox::critical(this, tr("ERROR"), tr(QString(
                                                  "打开视频" + video_name + "有误，请检查摄像头信息").toStdString().c_str()),
                                          QMessageBox::Close);
                } else {
//                    INFO("%s : %s", video_name.toStdString().c_str(), url.toStdString().c_str());
                    videoConf_i->urls.append(url);
                }
            } else if (video_type == "Local-Camera") {
                qDebug("%s : %s", video_name.toStdString().c_str(), video_type.toStdString().c_str());
            } else
                qDebug("This video%d type is %s, which does not belong to the preset video type!", videoCount,
                       video_type.toStdString().c_str());

            this->m_videoConf.append(videoConf_i);

            this->videoPlay.append(new FFmpegWidget(videoWidget->getVideoWidgetList().at(videoCount - 1)));
            this->videoPlayLayout.append(new QVBoxLayout(videoWidget->getVideoWidgetList().at(videoCount - 1)));
            this->videoPlayLayout.at(videoCount - 1)->addWidget(this->videoPlay.at(videoCount - 1));
            this->videoPlay.at(videoCount - 1)->setUrl(url);
            this->videoPlay.at(videoCount - 1)->open();
//            delete videoConf_i;
        }
    }
    ReadVideoConfJson.save(m_video_conf_json);
}

void SeViManPlat::onTreeViewClicked(const QModelIndex &index) {
    // 获取点击的节点的行号、数据和父节点索引
    int row = index.row();
    QVariant data = index.data(Qt::DisplayRole);
    QModelIndex parentIndex = index.parent();

    // 如果父节点为无效索引，则表示点击的是根节点
    if (!parentIndex.isValid()) {
        qDebug() << "Clicked on root node: " << data.toString() << " at row: " << row;
    } else {
        QVariant parentData = parentIndex.data(Qt::DisplayRole);
        int parentRow = parentIndex.row();
        qDebug() << "Clicked on node: " << data.toString() << " at row: " << row
                 << " under parent node: " << parentData.toString() << " at row: " << parentRow;
        int video_i = parentData.toString().split("摄像头").at(1).toInt();
        QString url = "";
        QString findVideoName = "video" + QString::number(video_i);
        qDebug("clicked the video %d, len m_videoConf: %d", video_i, m_videoConf.length());

        for (auto item: this->m_videoConf) {
            if (item->video_name == findVideoName)
                if (!item->urls.isEmpty() && row >= 0 && row < item->urls.size()) {
                    url = item->urls[row];
                }
        }
        qDebug() << "url: " << url;
        if (url != "") {
            this->videoPlay.at(video_i - 1)->close();
            this->videoPlay.at(video_i - 1)->setUrl(url);
            this->videoPlay.at(video_i - 1)->open();
        } else {
            qDebug() << "切换失败";
        }
    }
}


