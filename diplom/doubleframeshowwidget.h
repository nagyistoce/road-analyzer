#ifndef DOUBLEFRAMESHOWWIDGET_H
#define DOUBLEFRAMESHOWWIDGET_H

#include "frameshowwidget.h"

#include <opencv2/core/core.hpp>

#include <QWidget>
#include <QPair>

namespace GUI{

class DoubleFrameShowWidget : public QWidget
{
    Q_OBJECT

    FrameShowWidget* m_leftFrame;
    FrameShowWidget* m_rightFrame;

public:
    DoubleFrameShowWidget(QWidget *parent = 0);

signals:
    
public slots:
    void showDoubleFrame(const QPair<cv::Mat, cv::Mat>&);

    void showLeftFrame(const cv::Mat& left);
    void showRightFrame(const cv::Mat& right);

    void clearFrames();
};

}
#endif // DOUBLEFRAMESHOWWIDGET_H
