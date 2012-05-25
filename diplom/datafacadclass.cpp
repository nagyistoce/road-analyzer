#include "datafacadclass.h"

#include <iostream>
#include <QFile>
#include <QString>
#include <QFileInfo>

using namespace DATA;

DataFacadClass::DataFacadClass(const HANDLE::Analyzer& analyzer, QObject *parent) :
    QObject(parent), m_analyzer(analyzer)
{
}

void DataFacadClass::newPath(QString path) {
    std::cout << "DataFacadClass::newPath slot -  " << (path.toLocal8Bit().constData()) << "\n";

    if(!QFile::exists(path)) {
        incorrecPath();
    } else {
        QString name = QFileInfo(path).baseName();
        DataUnit* curDataUnit = new DataUnit(name, path, m_analyzer);
        curDataUnit->prepairFile();

        if(!curDataUnit->isFilePrepared()) {
            incorrecPath();
        }   else {
            std::cout << "DataFacadClass::FilePrepared\n";
            curDataUnit->prepairData();
            if(!curDataUnit->isDataPrepared()) {
                incorrecPath();
            } else {
                std::cout << "DataFacadClass::DataPrepared\n";
                Info curDataInfo;
                curDataInfo.isProcessed = curDataUnit->isDataProcessed();
                curDataInfo.type = curDataUnit->getType();
                m_curDataUnit = curDataUnit;
                dataPrepared(curDataInfo);
            }
        }
   }

}

void DataFacadClass::nextFile() {
    std::cout << "DataFacadClass::nextFile() slot\n";
}

void DataFacadClass::prevFile() {
    std::cout << "DataFacadClass::prevFile() slot\n";
}

void DataFacadClass::nextHandledData() {
    std::cout << "DataFacadClass::nextHandledData() slot\n";
}

void DataFacadClass::prevHandledData() {
    std::cout << "DataFacadClass::prevHandledData() slot\n";
}


void DataFacadClass::sendNextFrame() {
    switch(m_curDataUnit->getType()) {
            case FRAME:
                    sendOriginalFrame(m_curDataUnit->getPreProcessedData().getFrame());
                    if(m_curDataUnit->isDataProcessed()) {

                    }
            break;

            case VIDEO:
                    sendOriginalFrame(m_curDataUnit->getPreProcessedData().getFrame(1));
                    if(m_curDataUnit->isDataProcessed()) {

                    }
            break;
        };

    std::cout << "DataFacadClass::sendNextFrame() slot\n";
}

void DataFacadClass::sendPrevFrame() {
    std::cout << "DataFacadClass::sendPrevFrame() slot\n";
}

void DataFacadClass::sendAndReturnToFirstFrame() {
    std::cout << "DataFacadClass::sendAndReturnToFirstFrame() slot\n";
}

void DataFacadClass::start() {
    std::cout << "DataFacadClass::start() slot\n";
}

void DataFacadClass::save() {
    std::cout << "DataFacadClass::save() slot\n";
}

