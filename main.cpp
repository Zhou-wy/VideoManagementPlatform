//
// Created by zhouwy on 2023/2/19.
//

#include <QApplication>
#include "src/sevimanplat.h"
//#include "src/utils/iLogger.h"
int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
//    INFO("================start========================");
    SeViManPlat SVMP("/Users/zwy/CppProject/VidManPlat/conf/videoListConf.json","/Users/zwy/CppProject/VidManPlat/conf");
    SVMP.setWindowTitle("安防视频监控管理平台");
    SVMP.show();
    return QApplication::exec();
}