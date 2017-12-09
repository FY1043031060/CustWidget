#include "CWidget.h"
#include <QToolButton>
////
/// \brief CWidget::CWidget
/// \param parent
///
CWidget::CWidget(QWidget *parent) :
    QWidget(parent)
{
    ui.setupUi(this);
    //���ô�����������ز�����λ�ڶ���
    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);////NOTE::���治�϶�������������
    //�ɻ�ȡ������Ч��
    setMouseTracking(true);
    initTools();

}
////
/// \brief CWidget::mousePressEvent
/// \param event
///
void CWidget::mousePressEvent(QMouseEvent *event) {
    if(event->button() == Qt::LeftButton)
    {
        mouse_press = true;
        //�������ڴ����λ�ã�����ʹ��event->globalPos() - this->pos()��
        move_point = event->pos();;
    }
}
////
/// \brief CWidget::mouseMoveEvent
/// \param event
///
void CWidget::mouseMoveEvent(QMouseEvent *event) {
    //��������������
    if(mouse_press)    {
        //����������Ļ��λ��
        QPoint move_pos = event->globalPos();
        //�ƶ�������λ��
        this->move(move_pos - move_point);
    }
}
////
/// \brief CWidget::mouseReleaseEvent
/// \param event
///
void CWidget::mouseReleaseEvent(QMouseEvent *event) {
    //�������Ϊδ������
    mouse_press = false;
}
////
/// \brief CWidget::initTools
///
void CWidget::initTools()
{
    int width = this->width();//��ȡ����Ŀ��
    //������С������󻯡��رհ�ť
    QToolButton *minButton = new QToolButton(this);
    QToolButton *closeButton= new QToolButton(this);
    //��ȡ��С�����رհ�ťͼ��
    QPixmap minPix  = style()->standardPixmap(QStyle::SP_TitleBarMinButton);
    QPixmap closePix = style()->standardPixmap(QStyle::SP_TitleBarCloseButton);
    //������С�����رհ�ťͼ��
    minButton->setIcon(minPix);
    closeButton->setIcon(closePix);
    //������С�����رհ�ť�ڽ����λ��
    minButton->setGeometry(width-46,5,20,20);
    closeButton->setGeometry(width-25,5,20,20);

    //�������������ť�ϵ���ʾ��Ϣ
    minButton->setToolTip(tr("��С��"));
    closeButton->setToolTip(tr("�ر�"));
    //������С�����رհ�ť����ʽ
    minButton->setStyleSheet("background-color:transparent;");
    closeButton->setStyleSheet("background-color:transparent;");

    connect(closeButton,&QToolButton::clicked, this, &CWidget::close);
    connect(minButton,&QToolButton::clicked,this, &CWidget::showMinimized);
}
