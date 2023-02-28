//
// Created by zhouwy on 2023/2/21.
//

#ifndef VIDEOMANPLAT_ADDVIDEO_H
#define VIDEOMANPLAT_ADDVIDEO_H

#include <QDialog>
#include <QString>
#include <QMessageBox>

#include "../utils/Json.h"

QT_BEGIN_NAMESPACE
namespace Ui { class addVideo; }
QT_END_NAMESPACE

typedef struct _VideoInfo {
    QString m_ip;                //IP地址
    QString m_port;              //端口
    QString m_userName;          //用户名
    QString m_passWord;          //密码
    QString m_type;              //摄像头类型
} VideoInfo;


class addVideo : public QDialog {
Q_OBJECT

public:
    explicit addVideo(QString &video_conf_json, QWidget *parent = nullptr);

    ~addVideo() override;

protected:
    void closeEvent(QCloseEvent *e) override;

public:

    void saveVideoListConf();

public slots:

    void saveVideoConf();

private:
    Ui::addVideo* ui;
    VideoInfo *videoConf; // 每个摄像头的配置
    unsigned int VideoCount = 0; // 记录多少个摄像头
    QString m_video_conf_json;
};


#endif //VIDEOMANPLAT_ADDVIDEO_H
