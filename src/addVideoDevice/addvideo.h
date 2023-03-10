//
// Created by zhouwy on 2023/2/21.
//

#ifndef VIDEOMANPLAT_ADDVIDEO_H
#define VIDEOMANPLAT_ADDVIDEO_H

#include <QDialog>
#include <QString>
#include <QMessageBox>
#include <memory>
#include "../utils/Json.h"
#include "../dataType.h"

QT_BEGIN_NAMESPACE
namespace Ui { class addVideo; }
QT_END_NAMESPACE

class addVideo : public QDialog {
Q_OBJECT

public:
    explicit addVideo(QWidget *parent = nullptr);

    ~addVideo() override;

protected:
    void closeEvent(QCloseEvent *e) override;

public:

    int saveVideoListConf(QList<std::shared_ptr<VideoConf>>& videoList);
    // 定义一个名为 confirmSignal 的信号
    Q_SIGNAL void confirmSignal();
public slots:

    void saveVideoConf();

private:
    Ui::addVideo* ui;
};


#endif //VIDEOMANPLAT_ADDVIDEO_H
