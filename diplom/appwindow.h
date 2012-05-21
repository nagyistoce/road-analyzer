#ifndef APPWINDOW_H
#define APPWINDOW_H

#include "dataunit.h"
#include "appmanagewidget.h"
#include "videocontrolwidget.h"
#include "showwidget.h"

#include <QWidget>
#include <QMainWindow>
#include <QPushButton>
#include <QWidget>

namespace GUI{

class AppWindow : public QMainWindow
{
    Q_OBJECT

    DATA::DataUnit * const m_dataToShow;

    QLabel* m_nameLabel;

    QPushButton* m_prevHandledData;
    QPushButton* m_nextHandledData;

    AppManageWidget* m_appManageWidget;
    VideoControlWidget* m_videoControlWidget;

    DoubleFrameShowWidget* m_doubleFrameShowWidget;



public:
    AppWindow(QWidget *parent = 0);


signals:

    void openPath(QString);
    void nextFile();
    void prevFile();

    void nextHandledData();
    void prevHandledData();

    void process();
    void savePath(QString);

public slots:

    void showDataUnit(DATA::DataUnit const * const ) {}

private:

    QAction* m_fileAction;
    QAction* m_configAction;
    QAction* m_startAction;
    QAction* m_aboutAction;

    void createActions();
    void createConnections();
    QMenuBar* createMenuBar(QWidget* parent);
};

}
#endif // APPWINDOW_H
