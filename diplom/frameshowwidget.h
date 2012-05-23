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
    FrameShowWidget(QWidget *parent = 0, Qt::WindowFlags f=0);
    
    void showData(const cv::Mat& image);
    void clear();

protected:
    virtual void paintEvent(QPaintEvent *event);
    virtual void resizeEvent ( QResizeEvent * event );

private:
    enum BGR { BLUE, GREEN, RED };
    cv::Mat const* m_cvImage;
    QImage m_image;
};

}
#endif // FRAMESHOWWIDGET_H
