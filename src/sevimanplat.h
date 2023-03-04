//
// Created by zhouwy on 2023/2/15.
//

#ifndef VIDEOMANPLAT_SEVIMANPLAT_H
#define VIDEOMANPLAT_SEVIMANPLAT_H

#include <QWidget>
#include <QButtonGroup>
#include <memory>
#include <utility>
#include <QString>

#include "iconHelper/iconhelper.h"
#include "utils/cpumonitor.h"
#include "videoPanel/videopanel.h"
#include "playFFmpeg/ffmpeg.h"
#include "addVideoDevice/addvideo.h"
#include "utils/Json.h"
#include "dataType.h"

QT_BEGIN_NAMESPACE
namespace Ui { class SeViManPlat; }
QT_END_NAMESPACE

class SeViManPlat : public QWidget {
Q_OBJECT

public:
    explicit SeViManPlat(const QString &video_conf_json, const QString &log_save_dir, QWidget *parent = nullptr);

    ~SeViManPlat() override;

public:

    void initBtn(QButtonGroup *btnGroup, bool textBesideIcon);

    void initMenuPbt();

    void initTimer();

    void initCameraLayout();

    void initVideoPlay(); // 设置视频播放

    void loadStyle(const QString &qssFile);

    void initLogger();

    void Json2VideoConf();

    void VideoConf2Json();

public slots:

    void onTimerOut();

    void addVideoDialog(); // 添加摄像头槽函数

    void addVideoPlay();

    void onTreeViewClickedStream(const QModelIndex &index);

    void delVideoPlay(); // 删除摄像头槽函数

    void onTreeViewClickedDelVideo(const QModelIndex &index);

private:
    void destroyAll();

private:
    Ui::SeViManPlat *ui;
    QList<int> icons;
    QTimer *cpuMonTimer;
    VideoPanel *videoWidget; // 视频面板
    QVBoxLayout *videoWidgetLayout; // 视频面板布局

    QList<FFmpegWidget *> videoPlay; // 视频播放
    QList<QVBoxLayout *> videoPlayLayout; // 视频播放布局

    addVideo *addVideoTool; // 添加摄像头
    QString m_video_conf_json;
    QString m_log_save_dir;
    QList<std::shared_ptr<VideoConf>> m_videoConf;

    Json *VideoConfJson; // 摄像头配置文件
};


#endif //VIDEOMANPLAT_SEVIMANPLAT_H
