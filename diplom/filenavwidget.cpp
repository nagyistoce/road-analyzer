#include "filenavwidget.h"

#include <QBoxLayout>

using namespace GUI;

FileNavWidget::FileNavWidget(QWidget *parent) :
    QWidget(parent)
{
    QBoxLayout* layout = new QHBoxLayout(this);

    m_openButton = new QPushButton("Open", this);
    m_nextButton = new QPushButton(" > ", this);
    m_prevButton = new QPushButton(" < ", this);

    layout->addWidget(m_prevButton);
    layout->addWidget(m_openButton);
    layout->addWidget(m_nextButton);
}
