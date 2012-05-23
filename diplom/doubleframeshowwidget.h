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

    void showData(const cv::Mat& left, const cv::Mat& right);
signals:
    
public slots:
    void showData(const QPair<cv::Mat, cv::Mat>&);
};

}
#endif // DOUBLEFRAMESHOWWIDGET_H
