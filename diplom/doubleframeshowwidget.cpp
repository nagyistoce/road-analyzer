#include "doubleframeshowwidget.h"

#include <QLabel>
#include <QBoxLayout>

using namespace GUI;

DoubleFrameShowWidget::DoubleFrameShowWidget(QWidget *parent) :
    QWidget(parent)
{

    QBoxLayout* mainLayout = new QHBoxLayout(this);

    m_leftFrame = new FrameShowWidget(this);
    m_rightFrame = new FrameShowWidget(this);

    mainLayout->addWidget(m_leftFrame);
    mainLayout->addWidget(m_rightFrame);
    setLayout(mainLayout);
}

void DoubleFrameShowWidget::showData(const cv::Mat &left, const cv::Mat &right) {
    m_leftFrame->showData(left);
    m_rightFrame->showData(right);
}

void DoubleFrameShowWidget::showData(const QPair<cv::Mat, cv::Mat>& data) {
    showData(data.first, data.second);
}
