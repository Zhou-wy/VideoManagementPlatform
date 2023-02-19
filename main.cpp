//
// Created by zhouwy on 2023/2/19.
//
#pragma execution_character_set("utf-8")

#include <QApplication>
#include <iostream>
#include "src/sevimanplat.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    SeViManPlat SVMP;
//    std::cout << avformat_configuration() << std::endl; // 打印libavformat构建时配置信息。
    SVMP.setWindowTitle("安防视频监控管理平台");
    SVMP.show();
    return QApplication::exec();
}