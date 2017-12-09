#include "CWidget.h"

CWidget::CWidget(QWidget *parent) :
    QWidget(parent)
{
    ui.setupUi(this);
    //设置窗体标题栏隐藏并设置位于顶层
    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
    //可获取鼠标跟踪效果
    setMouseTracking(true);
    initTools();

}

void CWidget::mousePressEvent(QMouseEvent *event) {
    if(event->button() == Qt::LeftButton)
    {      mouse_press = true;
        //鼠标相对于窗体的位置（或者使用event->globalPos() - this->pos()）
        move_point = event->pos();;
    }
}
void CWidget::mouseMoveEvent(QMouseEvent *event) {
    //若鼠标左键被按下
    if(mouse_press)    {
        //鼠标相对于屏幕的位置
        QPoint move_pos = event->globalPos();
        //移动主窗体位置
        this->move(move_pos - move_point);
    }
}
void CWidget::mouseReleaseEvent(QMouseEvent *event) {
    //设置鼠标为未被按下
    mouse_press = false;
}
#include <QToolButton>
void CWidget::initTools()
{
    int width = this->width();//获取界面的宽度
    //构建最小化、最大化、关闭按钮
    QToolButton *minButton = new QToolButton(this);
    QToolButton *closeButton= new QToolButton(this);
    //获取最小化、关闭按钮图标
    QPixmap minPix  = style()->standardPixmap(QStyle::SP_TitleBarMinButton);
    QPixmap closePix = style()->standardPixmap(QStyle::SP_TitleBarCloseButton);
    //设置最小化、关闭按钮图标
    minButton->setIcon(minPix);
    closeButton->setIcon(closePix);
    //设置最小化、关闭按钮在界面的位置
    minButton->setGeometry(width-46,5,20,20);
    closeButton->setGeometry(width-25,5,20,20);

    //设置鼠标移至按钮上的提示信息
    minButton->setToolTip(tr("最小化"));
    closeButton->setToolTip(tr("关闭"));
    //设置最小化、关闭按钮的样式
    minButton->setStyleSheet("background-color:transparent;");
    closeButton->setStyleSheet("background-color:transparent;");

    connect(closeButton,&QToolButton::clicked, this, &CWidget::close);
    connect(minButton,&QToolButton::clicked,this, &CWidget::showMinimized);
}
