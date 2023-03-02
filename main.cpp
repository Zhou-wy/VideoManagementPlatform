//
// Created by zhouwy on 2023/2/19.
//

#include <QApplication>

#include "src/sevimanplat.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    SeViManPlat SVMP("C:/Users/zwy/Desktop/VidManPlat/conf/videoListConf.json","C:/Users/zwy/Desktop/VidManPlat/conf");
    SVMP.setWindowTitle("安防视频监控管理平台");
    SVMP.show();
    return QApplication::exec();
}

/*
 *
 * 将log4c库封装成C++类，并将头文件和源文件分开，
 * 1、在构造函数判断appender是文件还是控制台等重要设置
 * 2、可变参数和string流方式实现debug、info、warn、Error、Fatal 方法。
 *
 * */