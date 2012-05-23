#include "guifacadclass.h"

#include <iostream>

using namespace GUI;

GUIFacadClass::GUIFacadClass()
{
    m_videoTimer = new QTimer(this);
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


void GUIFacadClass::createConnections() {

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
    connect(m_playButton, SIGNAL(released()),
                            this, SLOT(ps_playVideo()));
    connect(m_pauseButton, SIGNAL(pressed()),
                            this, SLOT(ps_pauseVideo()));
    connect(m_nextButton, SIGNAL(pressed()),
                            this, SLOT(ps_nextFrame()));
    connect(m_prevButton, SIGNAL(pressed()),
                            this, SLOT(ps_prevFrame()));
    connect(m_startButton, SIGNAL(pressed()),
                            this, SLOT(ps_start()));
    connect(m_saveButton, SIGNAL(pressed()),
                            this, SLOT(ps_save()));
    connect(m_videoTimer, SIGNAL(timeout()), this, SLOT(ps_nextFrame()));
}

void GUIFacadClass::showDoubleFrame(const QPair<cv::Mat, cv::Mat> &data) {
    std::cout << "GUIFacadClass::showDoubleFrame slot\n";
    m_doubleFrameShowWidget->showDoubleFrame(data);
}

void GUIFacadClass::showLeftFrame(const cv::Mat& left) {
    std::cout << "GUIFacadClass::showLeftFrame slot\n";
    m_doubleFrameShowWidget->showLeftFrame(left);
}

void GUIFacadClass::showRightFrame(const cv::Mat& right) {
    std::cout << "GUIFacadClass::showRightFrame slot\n";
    m_doubleFrameShowWidget->showRightFrame(right);
}


void GUIFacadClass::incorrectPath() {
    std::cout << "GUIFacadClass::incorrectPath() slot\n";
    m_fileNavWidget->incorectPath();
}

void GUIFacadClass::dataPrepared(DATA::Info dataInfo) {
    std::cout << "GUIFacadClass::dataPrepared slot\n"
              << "Info: " << "isProsessed - " << dataInfo.isProcessed
              << "; type - " << dataInfo.type << ";\n";
    m_fileNavWidget->corectPath();
    m_doubleFrameShowWidget->clearFrames();
    curDataInfo = dataInfo;
    if(curDataInfo.type == DATA::VIDEO) {
        m_videoControlWidget->setVisible(true);
    } else {
        m_videoControlWidget->setVisible(false);
    }
    goToNextVideoFrame();
}

void GUIFacadClass::ps_pathChanged(QString path) {
    m_videoTimer->stop();
    pathChanged(path);
}

void GUIFacadClass::ps_nextFile() {
    m_videoTimer->stop();
    goToNextFile();
}

void GUIFacadClass::ps_prevFile() {
    m_videoTimer->stop();
    goToPrevFile();
}

void GUIFacadClass::ps_nextHandledData() {
    m_videoTimer->stop();
    goToNextHandledData();
}

void GUIFacadClass::ps_prevHandledData() {
    m_videoTimer->stop();
    goToPrevHandledData();
}

void GUIFacadClass::ps_stopVideo() {
    m_videoTimer->stop();
    goToFirstVideoFrame();
}

void GUIFacadClass::ps_pauseVideo() {
    m_videoTimer->stop();
}

void GUIFacadClass::ps_playVideo() {
   m_videoTimer->start(500);
}

void GUIFacadClass::ps_nextFrame() {
    goToNextVideoFrame();
}

void GUIFacadClass::ps_prevFrame() {
    goToPrevVideoFrame();
}

void GUIFacadClass::ps_start() {
    m_videoTimer->stop();
    start();
}

void GUIFacadClass::ps_save() {
    save();
}
