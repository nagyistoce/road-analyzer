#ifndef GUIFASADCLASS_H
#define GUIFASADCLASS_H

#include "appwindow.h"

#include <opencv2/core/core.hpp>

#include <QPair>
#include <QPushButton>

namespace GUI{

class GUIFasadClass: public QObject
{
    Q_OBJECT

    AppWindow* m_mainWindow;

    QPushButton* m_prevHandledData;
    QPushButton* m_nextHandledData;

    AppManageWidget* m_appManageWidget;
    FileNavWidget* m_fileNavWidget;
    QPushButton* m_configButton;
    QPushButton* m_startButton;
    QPushButton* m_saveButton;

    VideoControlWidget* m_videoControlWidget;
    QPushButton* m_playButton;
    QPushButton* m_pauseButton;
    QPushButton* m_stopButton;
    QPushButton* m_nextButton;
    QPushButton* m_prevButton;

    DoubleFrameShowWidget* m_doubleFrameShowWidget;

    void createConnections();

public:
    GUIFasadClass();

signals:

     void pathChanged(QString);
     void nextFile();
     void prevFile();

     void nextHandledData();
     void prevHandledData();

     void stopVideo();
     void pauseVideo();
     void playVideo();
     void nextFrame();
     void prevFarme();

     void start();
     void save();

public slots:

    void showData(const QPair<cv::Mat, cv::Mat> &);
    void incorrectPath();
    void correctPath();

private slots:

    void ps_pathChanged(QString);
    void ps_nextFile();
    void ps_prevFile();

    void ps_nextHandledData();
    void ps_prevHandledData();

    void ps_stopVideo();
    void ps_pauseVideo();
    void ps_playVideo();
    void ps_nextFrame();
    void ps_prevFarme();

    void ps_start();
    void ps_save();


};

}
#endif // GUIFASADCLASS_H
