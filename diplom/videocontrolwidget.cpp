#include "videocontrolwidget.h"

#include <QBoxLayout>

using namespace GUI;

VideoControlWidget::VideoControlWidget(QWidget *parent) :
    QWidget(parent)
{
    QWidget* mainWidget = new QWidget(this);
    QBoxLayout* layout = new QHBoxLayout(this);
    m_playButton = new QPushButton("|>", mainWidget);
    m_pauseButton = new QPushButton("||", mainWidget);
    m_stopButton = new QPushButton("[]", mainWidget);
    m_nextButton = new QPushButton(">", mainWidget);
    m_prevButton = new QPushButton("<", mainWidget);

    layout->addWidget(m_prevButton);
    layout->addWidget(m_stopButton);
    layout->addWidget(m_playButton);
    layout->addWidget(m_pauseButton);
    layout->addWidget(m_nextButton);
    resize(minimumWidth(), minimumHeight());
}

void VideoControlWidget::resizeEvent ( QResizeEvent * event ) {

}
