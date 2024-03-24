//
// Created by zwy on 2023/3/26.
//

#include "sevimanplat.h"
#include "ui_sevimanplat.h"
#include "utils/iLOG.hpp"

#include <QString>

// 指定目录路径
static QString dirPath = "D:/testvideo";

void SeViManPlat::initPage2() {
    getPlayDeviceInfo();

    connect(ui->p2_pbtFind, SIGNAL(clicked(bool)), this, SLOT(getHistoryVideoList()));
}

void SeViManPlat::getPlayDeviceInfo() {
    ui->p2_UserName->setText("zwy");
    ui->p2_Password->setText("123456");

    ui->p2_videoCallBckPlay->setUrl(dirPath + "/1.mp4");
    ui->p2_videoCallBckPlay->open();


    QTime time = QTime::currentTime();
    QDate Date = QDate::currentDate();

    ui->p2_EndTime->setText(Date.toString("yyyy:MM:dd") +time.toString("-hh:mm"));

    if (this->m_videoConf.length() > 0){
        for (auto item: this->m_videoConf) {
            ui->p2_VideoListCombox->addItem(item->video_name);
        }
        if (this->m_videoConf.at(0)->urls.size() == 2) {
            ui->p2_StreamCode->addItem("主码流");
            ui->p2_StreamCode->addItem("辅码流");
        } else if (this->m_videoConf.at(0)->urls.size() == 1) {
            ui->p2_StreamCode->addItem("码流");
        }
    }
    else{
        iERROR(ROOT_LOG) << "Description Failed to obtain the video stream on the video playback page";
        return;
    }


}


void SeViManPlat::getHistoryVideoList() {

    // 创建 QDir 对象
    QDir dir(dirPath);

    // 列出所有的 .mp4 文件
    QStringList filters;
    filters << "*.mp4";
    QStringList fileList = dir.entryList(filters, QDir::Files);

    if (fileList.isEmpty()) {
        qDebug() << "No .mp4 files found in the directory.";
        return;
    }

    // 将 QStringList 转换为 QStringListModel
    auto *model = new QStringListModel(fileList);
    // 将 QStringListModel 设置为 QListView 的模型
    ui->p2_VideoListView->setModel(model);

    // 在构造函数或其他适当的地方连接双击信号和槽
    connect(ui->p2_VideoListView, &QListView::doubleClicked, this, &SeViManPlat::onVideoItemDoubleClicked);
}

void SeViManPlat::onVideoItemDoubleClicked(const QModelIndex &index) {
    // 获取双击选中的项的文件名
    QString selectedFileName = ui->p2_VideoListView->model()->data(index).toString();

    // 打印双击选中的文件名
    qDebug() << "Double-clicked item: " <<  dirPath + "/"+ selectedFileName;

    // 可以在这里执行任何其他与双击文件相关的操作
    ui->p2_videoCallBckPlay->setUrl(dirPath + "/"+ selectedFileName);
    ui->p2_videoCallBckPlay->open();
}
