#include "doubleframeshowwidget.h"

#include <QLabel>
#include <QBoxLayout>

using namespace GUI;

DoubleFrameShowWidget::DoubleFrameShowWidget(QWidget *parent) :
    QWidget(parent)
{

    QBoxLayout* mainLayout = new QHBoxLayout(this);

    m_originalFrame = new FrameShowWidget(this);
    m_resultFrame = new FrameShowWidget(this);

    mainLayout->addWidget(m_originalFrame);
    mainLayout->addWidget(m_resultFrame);
    setLayout(mainLayout);
}
