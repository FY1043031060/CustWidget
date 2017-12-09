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
    //��갴���¼�
    void mousePressEvent(QMouseEvent *event);
    //����ͷ��¼�
    void mouseReleaseEvent(QMouseEvent *event);
    //����ƶ��¼�
    void mouseMoveEvent(QMouseEvent *event);

private:
    Ui::CWidget ui;
    QPoint move_point; //�ƶ��ľ���
    bool mouse_press; //��갴��
    void initTools();
};

#endif // CWIDGET_H
