//
// Created by zwy on 2023/3/4.
//

#ifndef VIDMANPLAT_DATATYPE_H
#define VIDMANPLAT_DATATYPE_H

#include <QString>
#include <QList>

typedef struct videoConf {
    QString video_name;
    QList<QString> urls;

    bool operator==(const videoConf &other) const {
        return (video_name == other.video_name) && (urls == other.urls);
    }
} VideoConf;
#endif //VIDMANPLAT_DATATYPE_H