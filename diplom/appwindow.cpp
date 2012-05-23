#include "appwindow.h"

#include <QDockWidget>
#include <QBoxLayout>
#include <QAction>
#include <QMenuBar>

using namespace GUI;

AppWindow::AppWindow(QWidget *parent) :
    QMainWindow(parent)
{
    resize(1300,750);
    createActions();
    setMenuWidget(createMenuBar(this));
    createWidgets();

}

void AppWindow::createWidgets() {

    m_appManageWidget = new AppManageWidget(this);
    m_videoControlWidget = new VideoControlWidget(this);

    m_prevHandledData = new QPushButton("<" , this);
    m_nextHandledData = new QPushButton(">" , this);

    m_doubleFrameShowWidget = new DoubleFrameShowWidget(this);

    QDockWidget* appManageDockWidget = new QDockWidget(this);
    appManageDockWidget->setWidget(m_appManageWidget);

    QDockWidget* bottomDockWidget = new QDockWidget(this);
    QWidget* bottomWidget = new QWidget(this);
    bottomDockWidget->setWidget(bottomWidget);
    QBoxLayout* bottomWidgetLayout = new QVBoxLayout(bottomWidget);
    QWidget* handledDataWidget = new QWidget(this);
    QBoxLayout* handledDataLayout = new QHBoxLayout(handledDataWidget);
    handledDataLayout->addWidget(m_prevHandledData);
    handledDataLayout->addWidget(m_nextHandledData);
    bottomWidgetLayout->addWidget(m_videoControlWidget);
    bottomWidgetLayout->addWidget(handledDataWidget);

    addDockWidget(Qt::TopDockWidgetArea, appManageDockWidget);
    addDockWidget(Qt::BottomDockWidgetArea, bottomDockWidget);

    setCentralWidget(m_doubleFrameShowWidget);
}

QMenuBar* AppWindow::createMenuBar(QWidget* parent) {

    QMenuBar*  menuBar = new QMenuBar(parent);
    menuBar->addAction(m_fileAction);
    menuBar->addAction(m_configAction);
    menuBar->addAction(m_startAction);
    menuBar->addAction(m_aboutAction);

    return menuBar;
}

void AppWindow::createActions() {

    m_fileAction = new QAction(tr("&File"), this);
    m_configAction = new QAction(tr("&Config"), this);
    m_startAction = new QAction(tr("&Start"), this);
    m_aboutAction = new QAction(tr("&About"), this);
}

void AppWindow::createConnections() {
}
