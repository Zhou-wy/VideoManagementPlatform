//
// Created by zhouwy on 2023/2/21.
//

#ifndef VIDEOMANPLAT_ADDVIDEO_H
#define VIDEOMANPLAT_ADDVIDEO_H

#include <QDialog>
#include <QString>

QT_BEGIN_NAMESPACE
namespace Ui { class addVideo; }
QT_END_NAMESPACE

enum VideoType {
    //网络摄像头
    RTSP = 0,
    RTMP = 1,
    HTTP_FLV = 2,
    //本地摄像头
    LOCAL_CAM = 3
};

class VideoDevInfo {
public:
    VideoDevInfo() = delete;

    VideoDevInfo(QString &ip, int &port, QString &userName, QString &passWD, QString &type);

    void setVideoIP(QString ip);

    void setVideoPort(int port);

    void setVideoUserName(QString userName);

    void setVideoPassWord(QString passWD);

    void setVideoType(QString type);

    QString getVideoIP();

    int getVideoPort();

    QString getVideoUserName();

    QString getVideoPassWord();

    QString getVideoType();

private:
    QString m_ip;                //IP地址
    int m_port;              //端口
    QString m_userName;          //用户名
    QString m_passWord;          //密码
    QString m_type;              //摄像头类型
};


class addVideo : public QDialog {
Q_OBJECT

public:
    explicit addVideo(QWidget *parent = nullptr);

    ~addVideo() override;

public slots:

    void addWebVideoPage();

    void addLocalVideoPage();

    void saveVideoListConf();


private:
    Ui::addVideo *ui;
    VideoDevInfo *videoConf;
};


#endif //VIDEOMANPLAT_ADDVIDEO_H
