#ifndef DATAFACADCLASS_H
#define DATAFACADCLASS_H

#include "dataTypes.h"
#include "analyzer.h"
#include "dataunit.h"
#include "analyzer.h"

#include <opencv2/core/core.hpp>

#include <QObject>
#include <QPair>

namespace DATA{

class DataFacadClass : public QObject
{
    Q_OBJECT

public:
    DataFacadClass(const HANDLE::Analyzer& analyzer, QObject *parent = 0);

signals:
    void incorrecPath();
    void dataPrepared(DATA::Info);

    void sendDoubleFrame(const QPair<cv::Mat,cv::Mat>&);
    void sendOriginalFrame(const cv::Mat&);
    void sendResultFrame(const cv::Mat&);

public slots:
    void newPath(QString); //stub!
    void nextFile(); //stub!
    void prevFile(); //stub!

    void nextHandledData(); //stub!
    void prevHandledData(); //stub!

    void sendNextFrame(); //stub!
    void sendPrevFrame(); //stub!
    void sendAndReturnToFirstFrame(); //stub!

    void start(); //stub!
    void save(); //stub!

private:
    DataUnit* m_curDataUnit;

   const HANDLE::Analyzer& m_analyzer;
};
}
#endif // DATAFACADCLASS_H
