#ifndef APPWINDOW_H
#define APPWINDOW_H

#include "appmanagewidget.h"
#include "videocontrolwidget.h"
#include "doubleframeshowwidget.h"
#include "setconfwidget.h"

#include <QWidget>
#include <QMainWindow>
#include <QPushButton>
#include <QWidget>
#include <QLabel>

namespace GUI{

class AppWindow : public QMainWindow
{
    Q_OBJECT


public:
    AppWindow(QWidget *parent = 0);

    friend class GUIFacadClass;

private:

    QPushButton* m_prevHandledData;
    QPushButton* m_nextHandledData;

    AppManageWidget* m_appManageWidget;
    SetConfWidget* m_setConfWidget;

    VideoControlWidget* m_videoControlWidget;

    DoubleFrameShowWidget* m_doubleFrameShowWidget;


    QAction* m_fileAction;
    QAction* m_configAction;
    QAction* m_startAction;
    QAction* m_aboutAction;

    void createActions();
    void createConnections();
    void createWidgets();
    QMenuBar* createMenuBar(QWidget* parent);

signals:

    void openPath(QString);
    void nextFile();
    void prevFile();

    void nextHandledData();
    void prevHandledData();

    void process();
    void savePath(QString);
};

}
#endif // APPWINDOW_H
