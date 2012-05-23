#ifndef GUIFACADCLASS_H
#define GUIFACADCLASS_H

#include "appwindow.h"
#include "dataTypes.h"
#include <opencv2/core/core.hpp>

#include <QPair>
#include <QPushButton>
#include <QTimer>

namespace GUI{

class GUIFacadClass: public QObject
{
    Q_OBJECT

public:
    GUIFacadClass();

signals:
     void pathChanged(QString);
     void goToNextFile();
     void goToPrevFile();

     void goToNextHandledData();
     void goToPrevHandledData();

     void goToNextVideoFrame();
     void goToPrevVideoFrame();
     void goToFirstVideoFrame();

     void start();
     void save();

public slots:

    void incorrectPath();
    void dataPrepared(DATA::Info);

    void showDoubleFrame(const QPair<cv::Mat, cv::Mat> &);
    void showLeftFrame(const cv::Mat&);
    void showRightFrame(const cv::Mat&);

private slots:
    void ps_pathChanged(QString);
    void ps_nextFile();
    void ps_prevFile();

    void ps_nextHandledData();
    void ps_prevHandledData();

    void ps_stopVideo(); //stub!
    void ps_pauseVideo();//stub!
    void ps_playVideo(); //stub!
    void ps_nextFrame();
    void ps_prevFrame();

    void ps_start();
    void ps_save();

private:
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

    DATA::Info curDataInfo;

    QTimer* m_videoTimer;
};

}
#endif // GUIFACADCLASS_H
