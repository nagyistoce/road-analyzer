#include "guifasadclass.h"

using namespace GUI;

GUIFasadClass::GUIFasadClass()
{
    m_mainWindow = new AppWindow();

    m_prevHandledData = m_mainWindow->m_prevHandledData;
    m_nextHandledData = m_mainWindow->m_nextHandledData;

    m_appManageWidget = m_mainWindow->m_appManageWidget;
    m_fileNavWidget = m_appManageWidget->m_fileNavWidget;
    m_configButton = m_appManageWidget->m_configButton;
    m_startButton = m_appManageWidget->m_startButton;
    m_saveButton = m_appManageWidget->m_saveButton;

    m_videoControlWidget = m_mainWindow->m_videoControlWidget;
    m_playButton = m_videoControlWidget->m_playButton;
    m_pauseButton = m_videoControlWidget->m_pauseButton;
    m_stopButton = m_videoControlWidget->m_stopButton;
    m_nextButton = m_videoControlWidget->m_nextButton;
    m_prevButton = m_videoControlWidget->m_prevButton;

    m_doubleFrameShowWidget = m_mainWindow->m_doubleFrameShowWidget;

    createConnections();

    m_mainWindow->show();
}


void GUIFasadClass::createConnections() {

    connect(m_fileNavWidget, SIGNAL(pathChanged(QString)),
                        this, SLOT(ps_pathChanged(QString)));
    connect(m_fileNavWidget, SIGNAL(nextFile()),
                        this, SLOT(ps_nextFile()));
    connect(m_fileNavWidget, SIGNAL(prevFile()),
                            this, SLOT(ps_prevFile()));
    connect(m_nextHandledData, SIGNAL(pressed()),
                            this, SLOT(ps_nextHandledData()));
    connect(m_prevHandledData, SIGNAL(pressed()),
                            this, SLOT(ps_prevHandledData()));
    connect(m_stopButton, SIGNAL(pressed()),
                            this, SLOT(ps_stopVideo()));
    connect(m_playButton, SIGNAL(pressed()),
                            this, SLOT(ps_playVideo()));
    connect(m_pauseButton, SIGNAL(pressed()),
                            this, SLOT(ps_pauseVideo()));
    connect(m_nextButton, SIGNAL(pressed()),
                            this, SLOT(ps_nextFrame()));
    connect(m_prevButton, SIGNAL(pressed()),
                            this, SLOT(ps_prevFarme()));
    connect(m_startButton, SIGNAL(pressed()),
                            this, SLOT(ps_start()));
    connect(m_saveButton, SIGNAL(pressed()),
                            this, SLOT(ps_save()));
}

void GUIFasadClass::showData(const QPair<cv::Mat, cv::Mat> &data) {
    m_doubleFrameShowWidget->showData(data);
}

void GUIFasadClass::incorrectPath() {
    m_fileNavWidget->incorectPath();
}

void GUIFasadClass::correctPath() {
    m_fileNavWidget->incorectPath();
}

void GUIFasadClass::ps_pathChanged(QString path) {
    pathChanged(path);
}

void GUIFasadClass::ps_nextFile() {
    nextFile();
}

void GUIFasadClass::ps_prevFile() {
    prevFile();
}

void GUIFasadClass::ps_nextHandledData() {
    nextHandledData();
}

void GUIFasadClass::ps_prevHandledData() {
    prevHandledData();
}

void GUIFasadClass::ps_stopVideo() {
    stopVideo();
}

void GUIFasadClass::ps_pauseVideo() {
    pauseVideo();
}

void GUIFasadClass::ps_playVideo() {
    playVideo();
}

void GUIFasadClass::ps_nextFrame() {
    nextFrame();
}

void GUIFasadClass::ps_prevFarme() {
    prevFarme();
}

void GUIFasadClass::ps_start() {
    start();
}

void GUIFasadClass::ps_save() {
    save();
}
