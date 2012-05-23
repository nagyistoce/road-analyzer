#include "frameshowwidget.h"

using namespace GUI;

FrameShowWidget::FrameShowWidget(QWidget *parent, Qt::WindowFlags f) :
    QWidget(parent, f),
    m_image(640,480,QImage::Format_RGB888)
{
    resize(m_image.size());

    QPainter painter(&m_image);
    painter.fillRect(rect(), Qt::black);
    painter.fillRect(m_image.rect(),Qt::black);
}


void FrameShowWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)
    QPainter painter(this);
    painter.drawImage(0,0,m_image);
}

void FrameShowWidget::resizeEvent ( QResizeEvent * event )
{
    int width = event->size().width();
    int height = event->size().height();

    double scale = 2;

    if((m_image.width() > width) && (m_image.height() > height) ) {
        m_image = m_image.scaled( (int)m_image.width()/scale,
                                  (int)m_image.height()/scale );

    }
    if((m_image.width()*scale < width) || (m_image.height()*scale < height) ) {
        m_image = m_image.scaled( (int)m_image.width()*scale,
                                  (int)m_image.height()*scale );
    }
}


void FrameShowWidget::showData(const cv::Mat& image)
{
    m_cvImage = &image;
    if(image.data) {
        if(m_image.width()!= image.cols || m_image.height()!=image.rows)
            m_image=QImage(image.cols,image.rows,QImage::Format_RGB888);
        const uchar *ptr;
        for(int j,i=0;i<image.rows;++i) {
            ptr=image.data+i*image.step;
            for(j=0;j<image.cols;++j) {
                m_image.setPixel(j,i,qRgb(ptr[RED],ptr[GREEN],ptr[BLUE]));
                ptr+=3;
            }
        }
    }
    else {
        QPainter painter(&m_image);
        painter.fillRect(m_image.rect(),Qt::black);
    }
    if(m_image.width() > width() || m_image.height() > height()) {
        resizeEvent(new QResizeEvent(size(), size()));
    }
    update();
}

void FrameShowWidget::clear() {

    QPainter painter(&m_image);
    painter.fillRect(m_image.rect(),Qt::black);
    update();
}
