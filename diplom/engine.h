#ifndef ENGINE_H
#define ENGINE_H

#include "datafacadclass.h"
#include "guifacadclass.h"
#include "analyzer.h"

#include <QObject>

class Engine : public QObject
{
    Q_OBJECT

    HANDLE::Analyzer m_analyzer;
    DATA::DataFacadClass m_appData;
    GUI::GUIFacadClass m_gui;

public:
    Engine(QObject *parent = 0);
    
signals:
    
public slots:
    
private:

    void createConnections();
};

#endif // ENGINE_H
