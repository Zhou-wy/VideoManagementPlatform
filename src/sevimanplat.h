//
// Created by zhouwy on 2023/2/15.
//

#ifndef VIDEOMANPLAT_SEVIMANPLAT_H
#define VIDEOMANPLAT_SEVIMANPLAT_H

#include <QWidget>
#include <QButtonGroup>
#include "iconHelper/iconhelper.h"
#include "cpuMonitor/cpumonitor.h"
#include "videoPanel/videopanel.h"
//#include "../ffmpeg4.4.3/ffmpeg.h"

QT_BEGIN_NAMESPACE
namespace Ui { class SeViManPlat; }
QT_END_NAMESPACE

class SeViManPlat : public QWidget {
Q_OBJECT

public:
    explicit SeViManPlat(QWidget *parent = nullptr);

    ~SeViManPlat() override;

public:
    void initMainBtnGroup();

    void initBtn(QButtonGroup *btnGroup, bool textBesideIcon);

    void initMenuPbt();

    void initTimer();

    void initCameraList();

    void initCameraLayout();

    void initPlayWidget();

    void loadStyle(const QString &qssFile);

public slots:

    void onTimerOut();

private:
    Ui::SeViManPlat *ui;
    QList<int> icons;
    int iconSize;
    QString CPUMon;
    QTimer *timer;
    VideoPanel *videoWidget;
    QVBoxLayout *vectorLayout;
//    FFmpegWidget *playWidget;
};


#endif //VIDEOMANPLAT_SEVIMANPLAT_H
