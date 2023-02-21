//
// Created by zhouwy on 2023/2/21.
//

// You may need to build the project (run Qt uic code generator) to get "ui_addVideo.h" resolved

#include "addvideo.h"
#include "ui_addVideo.h"
#include <QString>
#include <QMessageBox>
#include <QJsonDocument>    // Json文档
#include <QJsonObject>      // Json对象
#include <QJsonParseError>  // Json异常捕捉
#include <QFile>            // 文件读写
#include <utility>


VideoDevInfo::VideoDevInfo(QString &ip, int &port, QString &userName, QString &passWD, QString &type) : m_ip(ip), m_port(port),
                                                                                                m_userName(userName),
                                                                                                m_passWord(passWD),
                                                                                                m_type(type) {

}


void VideoDevInfo::setVideoIP(QString ip) {
    m_ip = std::move(ip);
}

void VideoDevInfo::setVideoPort(int port) {
    m_port = port;
}

void VideoDevInfo::setVideoUserName(QString userName) {
    m_userName = std::move(userName);
}

void VideoDevInfo::setVideoPassWord(QString passWD) {
    m_passWord = std::move(passWD);
}

void VideoDevInfo::setVideoType(QString type) {
    m_type = std::move(type);
}

QString VideoDevInfo::getVideoIP() {
    return m_ip;
}

int VideoDevInfo::getVideoPort() {
    return m_port;
}

QString VideoDevInfo::getVideoUserName() {
    return m_userName;
}

QString VideoDevInfo::getVideoPassWord() {
    return m_passWord;
}

QString VideoDevInfo::getVideoType(){
    return m_type;
}

addVideo::addVideo(QWidget *parent) :
        QDialog(parent), ui(new Ui::addVideo) {
    ui->setupUi(this);
    connect(ui->CancelPbt, SIGNAL(clicked(bool)), this, SLOT(close()));
    connect(ui->addWebVideo, SIGNAL(clicked(bool)), this, SLOT(addWebVideoPage()));
    connect(ui->addLocalVideo, SIGNAL(clicked(bool)), this, SLOT(addLocalVideoPage()));

    connect(ui->savePbt, SIGNAL(clicked(bool)), this, SLOT(saveVideoListConf()));
}

addVideo::~addVideo() {
    delete ui;
}

void addVideo::addWebVideoPage() {
    ui->stackedWidget->setCurrentIndex(0);
}

void addVideo::addLocalVideoPage() {
    ui->stackedWidget->setCurrentIndex(1);
}

void addVideo::saveVideoListConf() {
//    qDebug() << "saveVideoListConf";
//    videoConf->setVideoIP(ui->ipEdit->text());
//    videoConf->setVideoPort(ui->portEdit->text().toInt());
//    videoConf->setVideoUserName(ui->usrNameEdit->text());
//    videoConf->setVideoPassWord(ui->passWordEdit->text());
//    videoConf->setVideoType(ui->videoTypeBox->currentText());
//
//    qDebug()<< videoConf->getVideoType();
//
//    if (nullptr == videoConf) {
//        QMessageBox::critical(this, tr("ERROR"), tr("保存信息有误，或者某项为空"), QMessageBox::Close);
//    } else {
//        QFile file("/Users/zwy/CppProject/VidManPlat/bin/workspace/videoListConf.json");
//        if (!file.open(QIODevice::ReadWrite)) {
//            qDebug() << "File open error";
//        } else {
//            qDebug() << "File open!";
//        }
//        // 使用QJsonObject对象插入键值对。
//        QJsonObject jsonObject;
//        jsonObject.insert("type", videoConf->getVideoType());
//        jsonObject.insert("ip", videoConf->getVideoIP());
//        jsonObject.insert("port", videoConf->getVideoPort());
//        jsonObject.insert("userName", videoConf->getVideoUserName());
//        jsonObject.insert("passWord", videoConf->getVideoPassWord());
//
//        // 使用QJsonDocument设置该json对象
//        QJsonDocument jsonDoc;
//        jsonDoc.setObject(jsonObject);
//
//        // 将json以文本形式写入文件并关闭文件。
//        file.write(jsonDoc.toJson());
//        file.close();
//        this->close();
//        qDebug() << "Write to file";
//    }
}
