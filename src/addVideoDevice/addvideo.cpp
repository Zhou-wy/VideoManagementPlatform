//
// Created by zhouwy on 2023/2/21.
//

// You may need to build the project (run Qt uic code generator) to get "ui_addVideo.h" resolved

#include <QString>
#include <QMessageBox>
#include <QFile>            // 文件读写
#include <QDebug>

#include "addvideo.h"
#include "ui_addVideo.h"

//#include "../utils/iLogger.h"


addVideo::addVideo(QString &video_conf_json, QWidget *parent) :
        QDialog(parent), ui(new Ui::addVideo), m_video_conf_json(video_conf_json) {
    ui->setupUi(this);
    ui->videoTypeBox->setCurrentIndex(0);
    ui->stackedWidget->setCurrentIndex(0);

    connect(ui->CancelPbt, SIGNAL(clicked(bool)), this, SLOT(close()));
    connect(ui->savePbt, SIGNAL(clicked(bool)), this, SLOT(saveVideoConf()));
    connect(ui->videoTypeBox, SIGNAL(currentIndexChanged(int)), ui->stackedWidget, SLOT(setCurrentIndex(int)));
}

addVideo::~addVideo() {
    delete videoConf;
    delete ui;
}

/*
 * 保存摄像头配置
 * */
void addVideo::saveVideoListConf() {
    videoConf = new VideoInfo;
    videoConf->m_ip = QString(ui->ipEdit->text());
    videoConf->m_port = QString(ui->portEdit->text());
    videoConf->m_userName = QString(ui->usrNameEdit->text());
    videoConf->m_passWord = QString(ui->passWordEdit->text());
    videoConf->m_type = QString(ui->videoTypeBox->currentText());


    Json VideoConfJson(m_video_conf_json, true);
    if (VideoConfJson.getString("VideoCount") == "") {
        VideoCount = 0;
    } else {
        VideoCount = VideoConfJson.getString("VideoCount").toInt();
        VideoCount += 1;
    }
    if (videoConf->m_type == "RTSP") {
        if (videoConf->m_ip == "" || videoConf->m_type == "" || videoConf->m_passWord == "" ||
            videoConf->m_userName == "" || videoConf->m_port == "") {
//            INFOW(QString("rtsp video" + QString::number(VideoCount) +
//                          " fails to be enabled. Check the device").toStdString().c_str());
        } else {
            VideoConfJson.set("video" + QString::number(VideoCount) + ".ip", videoConf->m_ip);
            VideoConfJson.set("video" + QString::number(VideoCount) + ".port", videoConf->m_port);
            VideoConfJson.set("video" + QString::number(VideoCount) + ".username", videoConf->m_userName);
            VideoConfJson.set("video" + QString::number(VideoCount) + ".password", videoConf->m_passWord);
            VideoConfJson.set("video" + QString::number(VideoCount) + ".type", videoConf->m_type);
        }
    } else if (videoConf->m_type == "RTMP") {
        QString url = ui->rtmp_url->text();
        if (url == "")
            qDebug() << QString("rtmp video" + QString::number(VideoCount) +
                                " fails to be enabled. Check the device");
        else {
            VideoConfJson.set("video" + QString::number(VideoCount) + ".type", videoConf->m_type);
            VideoConfJson.set("video" + QString::number(VideoCount) + ".url", url);
        }
    } else if (videoConf->m_type == "HTTP-FLV") {
        QString url = ui->http_flv_url->text();
        if (url == "")
            qDebug() << QString("fttp flv video" + QString::number(VideoCount) +
                                " fails to be enabled. Check the device");
        else {
            VideoConfJson.set("video" + QString::number(VideoCount) + ".type", videoConf->m_type);
            VideoConfJson.set("video" + QString::number(VideoCount) + ".url", url);
        }

    } else if (videoConf->m_type == "Local-Camera") {
        QString dev = QString(ui->localCamDevice->currentText());
        if (dev == "")
            qDebug() << QString("local camera video" + QString::number(VideoCount) +
                                " fails to be enabled. Check the device");
        else {
            VideoConfJson.set("video" + QString::number(VideoCount) + ".type", videoConf->m_type);
            VideoConfJson.set("video" + QString::number(VideoCount) + ".url", dev);
        }

    } else {
        qDebug("save video config error");
    }
    VideoConfJson.set("VideoCount", QString::number(VideoCount));
    VideoConfJson.save(m_video_conf_json);
    qDebug("save video%d config info successfully", VideoCount);
    this->close();
}

void addVideo::saveVideoConf() {
    if (QMessageBox::question(this, tr("Quit"), tr("请确认新增摄像头信息无误"), QMessageBox::Yes, QMessageBox::No) ==
        QMessageBox::Yes) {
        QDialog::accept();//不会将事件传递给组件的父组件
//        INFO("save");
        saveVideoListConf();

    } else {
        QDialog::reject();
//        INFO("cancel");
    }
}

void addVideo::closeEvent(QCloseEvent *e) {
    //    if (QMessageBox::question(this, tr("Quit"), tr("请确认取消吗？"), QMessageBox::Yes,QMessageBox::No ) == QMessageBox::Yes) {
    //        QDialog::accept();//不会将事件传递给组件的父组件
    //    } else {
    //        QDialog::reject();
    //    }
    QDialog::accept();//不会将事件传递给组件的父组件
    QDialog::closeEvent(e);
}
