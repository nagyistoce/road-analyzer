#ifndef FRAMESHOWWIDGET_H
#define FRAMESHOWWIDGET_H

#include <QWidget>
#include <QPainter>
#include <QResizeEvent>

#include <opencv2/core/core.hpp>

namespace GUI{

class FrameShowWidget : public QWidget
{
    Q_OBJECT
public:
    explicit FrameShowWidget(QWidget *parent = 0, Qt::WindowFlags f=0);
    
    void showImage(const cv::Mat& image);

protected:
    virtual void paintEvent(QPaintEvent *event);
    virtual void resizeEvent ( QResizeEvent * event );

private:
    enum BGR { BLUE, GREEN, RED };

    QImage m_image;
};

}
#endif // FRAMESHOWWIDGET_H
