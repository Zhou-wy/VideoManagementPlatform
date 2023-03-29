//
// Created by zwy on 2023/3/26.
//

#include "sevimanplat.h"
#include "ui_sevimanplat.h"
#include "utils/iLOG.hpp"

#include <QString>

void SeViManPlat::initPage2() {
    getPlayDeviceInfo();
}

void SeViManPlat::getPlayDeviceInfo() {
    ui->p2_UserName->setText("zwy");
    ui->p2_Password->setText("123456");

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




