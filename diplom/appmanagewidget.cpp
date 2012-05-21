#include "appmanagewidget.h"

#include <QHBoxLayout>

using namespace GUI;

AppManageWidget::AppManageWidget(QWidget *parent) :
    QWidget(parent)
{
    QWidget* internalWidget = new QWidget(this);
    QBoxLayout* layout = new QHBoxLayout(this);

    m_fileNavWidget = new FileNavWidget(internalWidget);
    m_configButton = new QPushButton("Config", internalWidget);
    m_startButton = new QPushButton("Start", internalWidget);
    m_saveButton = new QPushButton("Save", internalWidget);

    layout->addWidget(m_fileNavWidget);
    layout->addWidget(m_configButton);
    layout->addWidget(m_startButton);
    layout->addWidget(m_saveButton);
}
