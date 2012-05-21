#ifndef ENGINE_H
#define ENGINE_H

#include "appdata.h"
#include "appwindow.h"
#include "analyzer.h"

#include <QObject>

class Engine : public QObject
{
    Q_OBJECT

    HANDLE::Analyzer m_analyzer;
    DATA::AppData m_appData;
    GUI::AppWindow m_gui;

public:
    Engine(QObject *parent = 0);
    
signals:
    
public slots:
    
private:

    void createConnections();
};

#endif // ENGINE_H