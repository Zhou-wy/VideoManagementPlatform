﻿#ifndef YTREEWIDGET_H
#define YTREEWIDGET_H

#include <QTreeWidget>

class QScrollBar;
class YScrollBarV;

#ifdef quc
class Q_DECL_EXPORT YTreeWidget : public QTreeWidget
#else
class YTreeWidget : public QTreeWidget
#endif

{
    Q_OBJECT
public:
    explicit YTreeWidget(QWidget *parent = 0);

protected:
    bool eventFilter(QObject *watched, QEvent *event);

private:
    bool isShow;
    QScrollBar *vscrollBar;
    YScrollBarV *scrollBarV;

public:
    QSize sizeHint()        const;
    QSize minimumSizeHint() const;

private slots:
    void setPosition();
    void setRange(int min, int max);
};

#endif // YTREEWIDGET_H
