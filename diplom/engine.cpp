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

    createConnections();
}

void Engine::createConnections() {
    //gui->data
    connect(&m_gui ,SIGNAL(pathChanged(QString)),
                            &m_appData, SLOT(newPath(QString)));
    connect(&m_gui ,SIGNAL(goToNextFile()),
                            &m_appData, SLOT(nextFile()));
    connect(&m_gui ,SIGNAL(goToPrevFile()),
                            &m_appData, SLOT(prevFile()));
    connect(&m_gui ,SIGNAL(goToNextHandledData()),
                            &m_appData, SLOT(nextHandledData()));
    connect(&m_gui ,SIGNAL(goToPrevHandledData()),
                            &m_appData, SLOT(prevHandledData()));
    connect(&m_gui ,SIGNAL(goToNextVideoFrame()),
                            &m_appData, SLOT(sendNextFrame()));
    connect(&m_gui ,SIGNAL(goToPrevVideoFrame()),
                            &m_appData, SLOT(sendPrevFrame()));
    connect(&m_gui ,SIGNAL(goToFirstVideoFrame()),
                            &m_appData, SLOT(sendAndReturnToFirstFrame()));
    connect(&m_gui ,SIGNAL(start()),
                            &m_appData, SLOT(start()));
    connect(&m_gui ,SIGNAL(save()),
                            &m_appData, SLOT(save()));

//    connect(&m_gui ,SIGNAL(), &m_appData, SLOT());

    //data->gui
    connect(&m_appData, SIGNAL(incorrecPath()),
                            &m_gui, SLOT(incorrectPath()));
    connect(&m_appData, SIGNAL(dataPrepared(DATA::Info)),
                            &m_gui, SLOT(dataPrepared(DATA::Info)));
    connect(&m_appData, SIGNAL(sendDoubleFrame(const QPair<cv::Mat,cv::Mat>&)),
                            &m_gui, SLOT(showDoubleFrame(const QPair<cv::Mat, cv::Mat>&)));
    connect(&m_appData, SIGNAL(sendOriginalFrame(const cv::Mat&)),
                            &m_gui, SLOT(showLeftFrame(const cv::Mat&)));
    connect(&m_appData, SIGNAL(sendResultFrame(const cv::Mat&)),
                            &m_gui, SLOT(showRightFrame(const cv::Mat&)));

//    connect(&m_appData, SIGNAL(), &m_gui, SLOT());

}
