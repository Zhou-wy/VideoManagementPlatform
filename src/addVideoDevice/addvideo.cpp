//
// Created by zhouwy on 2023/2/21.
//

// You may need to build the project (run Qt uic code generator) to get "ui_addVideo.h" resolved

#include <QString>
#include <QMessageBox>
#include <QFile>            // 文件读写
#include <QDebug>
#include <QString>

#include "addvideo.h"
#include "ui_addVideo.h"

#include "../utils/iLog.hpp"


addVideo::addVideo(QWidget *parent) :
        QDialog(parent), ui(new Ui::addVideo) {
    ui->setupUi(this);
    ui->videoTypeBox->setCurrentIndex(0);
    ui->stackedWidget->setCurrentIndex(0);

    connect(ui->CancelPbt, SIGNAL(clicked(bool)), this, SLOT(close()));
    connect(ui->savePbt, SIGNAL(clicked(bool)), this, SLOT(saveVideoConf()));
    connect(ui->videoTypeBox, SIGNAL(currentIndexChanged(int)), ui->stackedWidget, SLOT(setCurrentIndex(int)));
}

addVideo::~addVideo() {
    delete ui;
}

/*
 * 保存摄像头配置
 * */
bool addVideo::saveVideoListConf(QList<std::shared_ptr<VideoConf>> &videoList) {
    std::shared_ptr<VideoConf> newVideoConf;
    QString m_ip = QString(ui->ipEdit->text());
    QString m_port = QString(ui->portEdit->text());
    QString m_userName = QString(ui->usrNameEdit->text());
    QString m_passWord = QString(ui->passWordEdit->text());
    QString m_type = QString(ui->videoTypeBox->currentText());

    QString video_name = "video" + QString::number(videoList.length() + 1);
    if (m_type.toLower() == "rtsp") {
        //主码流
        QString main_code_stream = "rtsp://" + m_userName + ":" + m_passWord + "@" + m_ip + ":" + m_port +
                                   "/cam/realmonitor?channel=1&subtype=0";
        //辅码流
        QString Auxiliary_code_stream = "rtsp://" + m_userName + ":" + m_passWord + "@" + m_ip + ":" + m_port +
                                        "/cam/realmonitor?channel=1&subtype=1";
        newVideoConf = std::make_shared<VideoConf>(
                VideoConf{video_name, {main_code_stream, Auxiliary_code_stream}});
    } else if (m_type.toLower() == "rtmp") {
        QString url = "rtmp://" + ui->rtmp_url->text();
        if (url == "") {
            iERROR(ROOT_LOG) << QString("rtmp video" + QString::number(videoList.length() + 1) +
                                        " fails to be enabled.").toStdString();
            return false;
        } else {
            newVideoConf = std::make_shared<VideoConf>(VideoConf{video_name, {url}});
        }

    } else if (m_type.toLower() == "http-flv") {
        QString url = "http://" + ui->http_flv_url->text();
        if (url == "") {
            iERROR(ROOT_LOG) << QString("http flv video" + QString::number(videoList.length() + 1) +
                                        " fails to be enabled.").toStdString();
            return false;
        } else {
            newVideoConf = std::make_shared<VideoConf>(VideoConf{video_name, {url}});
        }
    } else if (m_type.toLower() == "local-camera") {
        iWARN(ROOT_LOG) << "local camera is fail";
    } else { iERROR(ROOT_LOG) << "save video config error"; }
    videoList.append(newVideoConf);
}

void addVideo::saveVideoConf() {
    if (QMessageBox::question(this, tr("Quit"), tr("请确认新增摄像头信息无误"), QMessageBox::Yes, QMessageBox::No) ==
        QMessageBox::Yes) {
        QDialog::accept();//不会将事件传递给组件的父组件
        emit confirmSignal();
        iINFO(ROOT_LOG) << "save";
    } else {
        QDialog::reject();
        iINFO(ROOT_LOG) << "cancel";
    }
}

void addVideo::closeEvent(QCloseEvent *e) {
    QDialog::accept();//不会将事件传递给组件的父组件
    QDialog::closeEvent(e);
}
