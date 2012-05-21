#include "engine.h"

#include <iostream>

Engine::Engine(QObject *parent)
    :
    QObject(parent),
    m_analyzer(),
    m_appData(m_analyzer),
    m_gui()
{
    std::cout << "CAR BLACK BOX DATA ANALYZER\n"
              << "created by Alexey Andriyash\n"
              << "ETU(LETI) 2012\n";

    m_gui.show();

    createConnections();
}

void Engine::createConnections() {

}
