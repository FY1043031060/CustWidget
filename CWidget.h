#ifndef CWIDGET_H
#define CWIDGET_H

#include "ui_CWidget.h"
#include <QMouseEvent>

class CWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CWidget(QWidget *parent = 0);

protected:
    //鼠标按下事件
    void mousePressEvent(QMouseEvent *event);
    //鼠标释放事件
    void mouseReleaseEvent(QMouseEvent *event);
    //鼠标移动事件
    void mouseMoveEvent(QMouseEvent *event);

private:
    Ui::CWidget ui;
    QPoint move_point; //移动的距离
    bool mouse_press; //鼠标按下
    void initTools();
};

#endif // CWIDGET_H
