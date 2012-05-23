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

void DoubleFrameShowWidget::showDoubleFrame(const QPair<cv::Mat, cv::Mat>& data) {
    m_leftFrame->showData(data.first);
    m_rightFrame->showData(data.second);
}

void DoubleFrameShowWidget::showLeftFrame(const cv::Mat& left) {
    m_leftFrame->showData(left);
}

void DoubleFrameShowWidget::showRightFrame(const cv::Mat& right) {
    m_rightFrame->showData(right);
}

void DoubleFrameShowWidget::clearFrames() {
    m_leftFrame->clear();
    m_rightFrame->clear();
}
