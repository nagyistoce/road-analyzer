#include "appdata.h"

using namespace DATA;

AppData::AppData(const HANDLE::Analyzer& analyzer)
    :
      QObject(0),
      m_analyzer(analyzer),
      m_curDataUnit(0),
      m_HandledDataIterator(m_HandledDataList)
{

}

void AppData::newPath(const QString& path)  {

    if(!QFile::exists(path)) {
        fileNotExist();
    } else {

        m_isCurReaded = false;
        m_isCurPrepeared = false;
        m_isCurProcessed = false;

        QString name = QFileInfo(path).baseName();

        DataUnit* curDataUnit = new DataUnit(name, path, m_analyzer);

        curDataUnit->prepairFile();
        curDataUnit->prepairData();

        if(!(curDataUnit->isFilePrepared() || curDataUnit->isDataPrepared())) {
            cantPrepar();
        } else {
            m_curDataUnit = curDataUnit;
            m_isCurReaded = m_curDataUnit->isFilePrepared();
            m_isCurPrepeared = m_curDataUnit->isDataPrepared();
            prepared();
        }
   }
}

void AppData::process() {
    if(m_isCurReaded && m_isCurPrepeared) {
        m_curDataUnit->processData();
        m_isCurProcessed = m_curDataUnit->isDataProcessed();
    }
    if(m_isCurProcessed) {
        m_HandledDataList.push_back(m_curDataUnit);
    } else {
        cantProcess();
    }
}

