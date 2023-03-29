//
// Created by zhouwy on 2023/2/15.
//
// You may need to build the project (run Qt uic code generator) to get "ui_SeViManPlat.h" resolved

#include <QList>
#include <QToolButton>
#include <algorithm>

#include "sevimanplat.h"
#include "ui_sevimanplat.h"
#include "utils/iLOG.hpp"

SeViManPlat::SeViManPlat(const QString &video_conf_json, const QString &log_save_dir, QWidget *parent) :
        QWidget(parent), ui(new Ui::SeViManPlat), m_video_conf_json(video_conf_json), m_log_save_dir(log_save_dir) {
    ui->setupUi(this);

    this->Json2VideoConf();
    this->initMenuPbt();
    this->initTimer();
    this->initCameraLayout();
    this->initVideoPlay();
    this->initLogger();

    // page2初始化
    this->initPage2();
    // page4初始化
    this->initPage4();

    connect(ui->p1_addVideoDevice, SIGNAL(clicked(bool)), this, SLOT(addVideoDialog()));
    connect(ui->p1_delVideoDevice, SIGNAL(clicked(bool)), this, SLOT(delVideoPlay()));

    connect(ui->p1_camDeviceList, SIGNAL(clicked(const QModelIndex&)), this,
            SLOT(onTreeViewClickedStream( const QModelIndex&)));
}

SeViManPlat::~SeViManPlat() {
    destroyAll();
    delete ui;
}

void SeViManPlat::initLogger() {
    // 设置logger级别为info
    ROOT_LOG.setLevel(spdlog::level::info);
    ROOT_LOG.setSaveDir("C:/Users/zwy/Desktop/VidManPlat/log");
    iINFO(ROOT_LOG) << "LOG INIT";
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
            foreach(QAbstractButton *btn, btns) {
            QToolButton *b = (QToolButton *) btn;
            //关联按钮单击事件
            connect(b, SIGNAL(clicked(bool)), this, SLOT(btnClicked()));
            b->setCheckable(true);
            b->setToolButtonStyle(textBesideIcon ? Qt::ToolButtonTextBesideIcon : Qt::ToolButtonTextUnderIcon);
        }
}

void SeViManPlat::btnClicked() {
    QToolButton *b = (QToolButton *)sender();
    QString name = b->text();

    QList<QToolButton *> tbtns = ui->widget->findChildren<QToolButton *>();
            foreach (QToolButton *btn, tbtns) {
            btn->setChecked(btn == b);
        }

    if (name == "视频监控") {
        ui->stackedWidget->setCurrentIndex(0);
    } else if (name == "视频回放") {
        ui->stackedWidget->setCurrentIndex(1);
    } else if (name == "设备管理") {
        ui->stackedWidget->setCurrentIndex(2);
    } else if (name == "数据分析") {
        ui->stackedWidget->setCurrentIndex(3);
    } else if (name == "系统设置") {
        ui->stackedWidget->setCurrentIndex(4);
    }
}

void SeViManPlat::onTimerOut() {
    //获取系统当前时间
    QTime time = QTime::currentTime();
    //设置晶体管控件QLCDNumber上显示的内容
    ui->timeLcd->display(time.toString("hh:mm:ss"));
    ui->cpuLabel->setText(QString("   CPU ") + JQCPUMonitor::cpuUsagePercentageDisplayString());
}

/*!
 * @brief: 初始化摄像头布局
 * */
void SeViManPlat::initCameraLayout() {
    videoWidget = new VideoPanel(ui->videoPanwidget);
    videoWidgetLayout = new QVBoxLayout(ui->videoPanwidget);
    videoWidgetLayout->addWidget(videoWidget);
}

/*!
 * @brief: 导入样式表
 * */
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
    else {
        iERROR(ROOT_LOG) << "Failed to open camera configuration file";
    }
}

/*!
 * @brief: 读取摄像头配置JSON，程序开始初始化
 * */
void SeViManPlat::Json2VideoConf() {
    VideoConfJson = new Json(m_video_conf_json, true);
    videoNameList = VideoConfJson->getStringList("videoList");
    if (VideoConfJson->getString("VideoCount") == "") {
        iERROR(ROOT_LOG) << "The videoListConf file is empty";
    } else {
        int videoCount = VideoConfJson->getString("VideoCount").toInt();
        iDEBUG(ROOT_LOG) << "video init, VideoConfJson VideoCount :" << videoCount;
        QString url = "";
//        // 设置右侧设备树
//        QTreeWidgetItem *webCamRoot = ui->camDeviceList->topLevelItem(0);
        for (int i = 0; i < videoCount; ++i) { // 遍历所有的摄像头配置
            QString video_name = videoNameList[i];
            QString video_type = VideoConfJson->getString(video_name + ".type");
            std::shared_ptr<VideoConf> videoConf_i = nullptr;

            if (video_type.toLower() == "rtsp") {
                QString main_code_stream = "rtsp://" + VideoConfJson->getString(video_name + ".username") + ":" +
                                           VideoConfJson->getString(video_name + ".password") + "@" +
                                           VideoConfJson->getString(video_name + ".ip") + ":" +
                                           VideoConfJson->getString(video_name + ".port") +
                                           "/cam/realmonitor?channel=1&subtype=0";
                //辅码流
                QString Auxiliary_code_stream =
                        "rtsp://" + VideoConfJson->getString(video_name + ".username") + ":" +
                        VideoConfJson->getString(video_name + ".password") + "@" +
                        VideoConfJson->getString(video_name + ".ip") + ":" +
                        VideoConfJson->getString(video_name + ".port") +
                        "/cam/realmonitor?channel=1&subtype=1";

                videoConf_i = std::make_shared<VideoConf>(
                        VideoConf{video_name, {main_code_stream, Auxiliary_code_stream}});
            } else if (video_type.toLower() == "rtmp") {
                url = VideoConfJson->getString(video_name + ".url");
                if (url == "") {
                    QMessageBox::critical(this, tr("ERROR"), tr(QString(
                                                  "打开视频" + video_name + "有误，请检查摄像头信息").toStdString().c_str()),
                                          QMessageBox::Close);
                    continue;
                } else {
                    iDEBUG(ROOT_LOG)
                    << video_name.toStdString() << " : " << video_type.toStdString() << " : " << url.toStdString();
                    videoConf_i = std::make_shared<VideoConf>(VideoConf{video_name, {url}});
                }

            } else if (video_type.toLower() == "http") {
                url = VideoConfJson->getString(video_name + ".url");
                if (url == "") {
                    QMessageBox::critical(this, tr("ERROR"), tr(QString(
                                                  "打开视频" + video_name + "有误，请检查摄像头信息").toStdString().c_str()),
                                          QMessageBox::Close);
                    continue;
                } else {
                    iDEBUG(ROOT_LOG)
                    << video_name.toStdString() << " : " << video_type.toStdString() << " : " << url.toStdString();
                    videoConf_i = std::make_shared<VideoConf>(VideoConf{video_name, {url}});
                }
            } else if (video_type.toLower() == "local-camera") {
                iDEBUG(ROOT_LOG) << video_name.toStdString() << video_type.toStdString();
            } else
                iERROR(ROOT_LOG) << "This video" << i << " type is " << video_type.toStdString()
                                 << ", which does not belong to the preset video type!"
                                 << video_type.toStdString();
            if (!this->m_videoConf.contains(videoConf_i)) // 判断videoConf 是否在，如果存在就不要新增了
                this->m_videoConf.append(videoConf_i);
        }
    }
    delete VideoConfJson;
}

/*!
 * @brief: m_videoConf格式化Json写入配置文件，程序退出时写入
 */
void SeViManPlat::VideoConf2Json() {

    if (QFile::remove(this->m_video_conf_json)) {
        iWARN(ROOT_LOG) << "delete video conf file successful";
    }
    VideoConfJson = new Json(m_video_conf_json, true);
    QList<QString> _videoNameList;
    //将m_videoConf按video_name由小到大排序
    std::sort(this->m_videoConf.begin(), this->m_videoConf.end(),
              [](const std::shared_ptr<VideoConf> &video1, const std::shared_ptr<VideoConf> &video2) {
                  return video1->video_name < video2->video_name;
              });
    // 摄像头个数
    VideoConfJson->set("VideoCount", QString::number(this->m_videoConf.length()));
    //遍历m_videoConf，将配置写入JSON
    for (const auto &conf: this->m_videoConf) {
        _videoNameList.append(conf->video_name);
        if (conf->urls.length() == 2) { // RTSP
            /*"rtsp://admin:admin123@192.168.0.213:554/cam/realmonitor?channel=1&subtype=0";*/
            // 提取_type
            QStringList parts = conf->urls[0].split(
                    "://"); // [rtsp ,admin:admin123@192.168.0.213:554/cam/realmonitor?channel=1&subtype=0]
            QString _type = parts[0];

            // 提取_username和_password
            QStringList parts_ = parts[1].split(
                    "@"); // [admin:admin123, 192.168.0.213:554/cam/realmonitor?channel=1&subtype=0]
            QStringList user_pwd = parts_[0].split(":"); //[admin, admin123]
            QString _username = user_pwd[0];
            QString _password = user_pwd[1];

            // 提取_ip和_port
            QStringList ip_port = parts_[1].split("/cam")[0].split(
                    ":"); // [192.168.0.213:554/cam/realmonitor?channel=1&subtype=0]
            QString _ip = ip_port[0];
            QString _port = ip_port[1];

            //写入JSON文件
            VideoConfJson->set(conf->video_name + ".ip", _ip);
            VideoConfJson->set(conf->video_name + ".port", _port);
            VideoConfJson->set(conf->video_name + ".username", _username);
            VideoConfJson->set(conf->video_name + ".password", _password);
            VideoConfJson->set(conf->video_name + ".type", _type);
        } else if (conf->urls.length() == 1) {// rtmp hhtp-flv local
            /* rtmp://ns8.indexforce.com/home/mystream
             * http://1011.hlsplay.aodianyun.com/demo/game.flv
             * */
            QStringList parts = conf->urls[0].split("://");
            QString _type = parts[0];
            if (_type.toLower() == "rtmp") {
                VideoConfJson->set(conf->video_name + ".type", _type);
                VideoConfJson->set(conf->video_name + ".url", conf->urls[0]);
            } else if (_type.toLower() == "http") {
                VideoConfJson->set(conf->video_name + ".type", _type);
                VideoConfJson->set(conf->video_name + ".url", conf->urls[0]);
            } else {
                VideoConfJson->set(conf->video_name + ".type", _type);
                VideoConfJson->set(conf->video_name + ".url", conf->urls[0]);
            }
        } else {
            iERROR(ROOT_LOG) << "";
        }
    }
    VideoConfJson->set("videoList", _videoNameList);
    VideoConfJson->save(this->m_video_conf_json);
    delete VideoConfJson;
}

/*!
 * @brief: 初始化视频播放
 */
void SeViManPlat::initVideoPlay() {
//    if (VideoConfJson->getString("VideoCount") == "") {
//        iERROR(ROOT_LOG) << "The videoListConf file is empty";
//    } else {
    QString url = "";
    for (int i = 0; i < 64; i++) {
        this->videoPlay.append(new FFmpegWidget(nullptr));
        this->videoPlayLayout.append(new QVBoxLayout(nullptr));
    }
    for (const auto &conf: this->m_videoConf) { // 遍历所有的摄像头配置
        QString video_type = conf->urls[0].split("://").at(0);
        // 设置右侧设备树
        QTreeWidgetItem *webCamRoot = ui->p1_camDeviceList->topLevelItem(0);
        // 创建子节点
        auto *webCamItem = new QTreeWidgetItem();
        webCamItem->setText(0, "摄像头-" + conf->video_name);
        int video_pos = conf->video_name.split("video").last().toInt() - 1;
        webCamRoot->addChild(webCamItem);
        if (video_type.toLower() == "rtsp") {
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
            // 创建主码流和辅码流
            auto *webCamMain_code_stream = new QTreeWidgetItem();
            webCamMain_code_stream->setText(0, "RSTP-主码流");
            webCamItem->addChild(webCamMain_code_stream);
            auto *webCamAuxiliary_code_stream = new QTreeWidgetItem();
            webCamAuxiliary_code_stream->setText(0, "RSTP-辅码流");
            webCamItem->addChild(webCamAuxiliary_code_stream);

            // TODO: 后期补充切换主码流和辅码流逻辑，现用主码流代替
            url = conf->urls[0];
            iDEBUG(ROOT_LOG) << conf->video_name.toStdString() << " : " << url.toStdString();
        } else if (video_type.toLower() == "rtmp") {
            url = conf->urls[0];
            if (url == "") {
                QMessageBox::critical(this, tr("ERROR"), tr(QString(
                                              "打开视频" + conf->video_name + "有误，请检查摄像头信息").toStdString().c_str()),
                                      QMessageBox::Close);
                continue;
            } else {
                iDEBUG(ROOT_LOG)
                << conf->video_name.toStdString() << " : " << video_type.toStdString() << " : "
                << url.toStdString();

                // 创建码流
                auto *web_stream = new QTreeWidgetItem();
                web_stream->setText(0, "RTMP-视频流");
                webCamItem->addChild(web_stream);
            }

        } else if (video_type.toLower() == "http-flv") {
            url = conf->urls[0];
            if (url == "") {
                QMessageBox::critical(this, tr("ERROR"), tr(QString(
                                              "打开视频" + conf->video_name + "有误，请检查摄像头信息").toStdString().c_str()),
                                      QMessageBox::Close);
                continue;
            } else {
                iDEBUG(ROOT_LOG)
                << conf->video_name.toStdString() << " : " << video_type.toStdString() << " : "
                << url.toStdString();
                // 创建码流
                auto *web_stream = new QTreeWidgetItem();
                web_stream->setText(0, "HTTP-FLV-视频流");
                webCamItem->addChild(web_stream);
            }

        } else if (video_type.toLower() == "local-camera") {
            iDEBUG(ROOT_LOG) << conf->video_name.toStdString() << video_type.toStdString();
        } else
            iERROR(ROOT_LOG) << "This " << conf->video_name.toStdString() << " type is " << video_type.toStdString()
                             << ", which does not belong to the preset video type!"
                             << video_type.toStdString();

        this->videoPlay.replace(video_pos, new FFmpegWidget(videoWidget->getVideoWidgetList().at(video_pos)));
        this->videoPlayLayout.replace(video_pos, new QVBoxLayout(videoWidget->getVideoWidgetList().at(video_pos)));
        this->videoPlayLayout.at(video_pos)->addWidget(this->videoPlay.at(video_pos));
        this->videoPlay.at(video_pos)->setUrl(url);
        this->videoPlay.at(video_pos)->open();
    }
}

void SeViManPlat::destroyAll() {
    this->VideoConf2Json();
    delete cpuMonTimer;
    delete videoWidget;
    delete videoWidgetLayout;
}

/*!
 * @brief: 新增摄像头弹窗
 */
void SeViManPlat::addVideoDialog() {
    this->addVideoTool = new addVideo(this);
    this->addVideoTool->show();
    connect(this->addVideoTool, SIGNAL(confirmSignal()), this, SLOT(addVideoPlay()));
}

/*!
 * @brief: 新增摄像头播放
 */
void SeViManPlat::addVideoPlay() {
    int insert_pos = this->addVideoTool->saveVideoListConf(this->m_videoConf);
    iINFO(ROOT_LOG) << "this->m_videoConf add len : " << this->m_videoConf.length();
//    int videoCount = this->m_videoConf.length();
    iINFO(ROOT_LOG) << "insert_pos : " << insert_pos << "  this->m_videoConf len : " << this->m_videoConf.length();
    std::shared_ptr<VideoConf> video_i = this->m_videoConf.at(insert_pos);
    iINFO(ROOT_LOG) << "add video name  : " << video_i->video_name.toStdString();
    QString url = "";
    // 设置右侧设备树
    QTreeWidgetItem *webCamRoot = ui->p1_camDeviceList->topLevelItem(0);
    // 创建子节点
    auto *webCamItem = new QTreeWidgetItem();
    webCamItem->setText(0, "摄像头-" + video_i->video_name);
    webCamRoot->addChild(webCamItem);

    if (video_i->urls.length() == 2) { // rtsp
        url = video_i->urls.at(0);

        auto *webCamMain_code_stream = new QTreeWidgetItem();
        webCamMain_code_stream->setText(0, "RTSP-主码流");
        webCamItem->addChild(webCamMain_code_stream);
        auto *webCamAuxiliary_code_stream = new QTreeWidgetItem();
        webCamAuxiliary_code_stream->setText(0, "RTSP-辅码流");
        webCamItem->addChild(webCamAuxiliary_code_stream);

    } else if (video_i->urls.length() == 1) {
        QString _type = video_i->urls[0].split("://")[0];
        if (_type.toLower() == "rtmp") {
            url = video_i->urls.at(0);
            auto *webCam_stream = new QTreeWidgetItem();
            webCam_stream->setText(0, "RTMP-视频流");
            webCamItem->addChild(webCam_stream);
        } else if (_type.toLower() == "http-flv") {
            url = video_i->urls.at(0);
            auto *webCam_stream = new QTreeWidgetItem();
            webCam_stream->setText(0, "HTTP-FLV-视频流");
            webCamItem->addChild(webCam_stream);
        } else {
            iWARN(ROOT_LOG) << "New local camera";
        }
    } else {
        iERROR(ROOT_LOG) << "Creating a video" << insert_pos << "failed to play";
    }
    iINFO(ROOT_LOG)
    << "add video info -> " << "name: " << video_i->video_name.toStdString() << " url:" << url.toStdString();
    this->videoPlay.replace(insert_pos, new FFmpegWidget(videoWidget->getVideoWidgetList().at(insert_pos)));
    this->videoPlayLayout.replace(insert_pos, new QVBoxLayout(videoWidget->getVideoWidgetList().at(insert_pos)));
    this->videoPlayLayout.at(insert_pos)->addWidget(this->videoPlay.at(insert_pos));
    this->videoPlay.at(insert_pos)->setUrl(url);
    this->videoPlay.at(insert_pos)->open();
}

void SeViManPlat::onTreeViewClickedStream(const QModelIndex &index) {
    // 获取点击的节点的行号、数据和父节点索引
    int row = index.row();
    QVariant data = index.data(Qt::DisplayRole);
    QModelIndex parentIndex = index.parent(); //父节点
    QModelIndex GrandpaIndex = parentIndex.parent(); //父节点的父节点->祖父节点

    // 如果父节点为无效索引，则表示点击的是根节点
    if (parentIndex.isValid() && !GrandpaIndex.isValid()) { // index 有父节点且没有祖父节点
        iWARN(ROOT_LOG)
        << "Clicked on root node: " << data.toString().split("-").at(1).toStdString() << " at row: " << row;
    } else {
        QVariant parentData = parentIndex.data(Qt::DisplayRole);
        int video_i = parentData.toString().split("摄像头-video").at(1).toInt();
        QString url = "";
        QString findVideoName = "video" + QString::number(video_i);
        iDEBUG(ROOT_LOG) << "clicked the video: " << video_i << " len m_videoConf: " << this->m_videoConf.length();

        for (auto item: this->m_videoConf) {
            if (item->video_name == findVideoName)
                if (!item->urls.isEmpty() && row >= 0 && row < item->urls.size()) {
                    url = item->urls[row];
                }
        }
        iDEBUG(ROOT_LOG) << "url: " << url.toStdString();
        if (url != "") {
            this->videoPlay.at(video_i - 1)->close();
            this->videoPlay.at(video_i - 1)->setUrl(url);
            this->videoPlay.at(video_i - 1)->open();
        } else {
            iERROR(ROOT_LOG) << "Failed to switch the video stream.";
        }
    }
}

/*
 * @brief 删除摄像头
 *         1、删除json文件中的关于选中摄像头的信息
 *         2、删除m_videoConf在关于摄像头中的信息
 *         3、删除QTreeWidget *camDeviceList;中关于摄像头的信息
 * */
void SeViManPlat::delVideoPlay() {
    QMessageBox::StandardButton reply = QMessageBox::question(this, "安防视频监控管理平台", "确认删除摄像头吗？",
                                                              QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        iINFO(ROOT_LOG) << "delete video";
        QAbstractItemModel *model = ui->p1_camDeviceList->model();
        QItemSelectionModel *selection_model = ui->p1_camDeviceList->selectionModel();

        // 获取所选索引的列表
        QModelIndexList selected_indexes = selection_model->selectedIndexes();

        for (const QModelIndex &index: selected_indexes) {
            QVariant data = model->data(index);
            // 获取父索引和数据
            QModelIndex parent_index = index.parent();
            QVariant parent_data = model->data(parent_index);

            //删除this->m_videoConf的内容
            QString findVideoName = data.toString().split("-").at(1);
            this->m_videoConf.erase(
                    std::remove_if(m_videoConf.begin(), m_videoConf.end(), [&](const std::shared_ptr<VideoConf> &conf) {
                        return conf->video_name == findVideoName;
                    }), m_videoConf.end());

            iINFO(ROOT_LOG) << "delete video info -> " << "name: " << findVideoName.toStdString();

            int i = findVideoName.split("video").last().toInt();

            if (i > 0 && i <= this->videoPlay.size()) {
                this->videoPlay.at(i - 1)->close();
                delete this->videoPlay.at(i - 1); // 释放指针所指向的内存
                this->videoPlay.removeAt(i - 1);   // 删除指针元素
                delete this->videoPlayLayout.at(i - 1); // 释放指针所指向的内存
                this->videoPlayLayout.removeAt(i - 1);// 删除指针元素
            }
        }
        // 删除所选索引对应的项
        for (const QModelIndex &index: selected_indexes) {
            model->removeRow(index.row(), index.parent());
        }


    } else {
        iINFO(ROOT_LOG) << "cancel delete video";
    }
}


