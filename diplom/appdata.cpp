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

void AppData::newFile(const QString& path)  {

    if(!QFile::exists(path)) {
        fileNotExist();
    } else {

        m_isCurReaded = false;
        m_isCurPrepeared = false;
        m_isCurProcessed = false;

        QString name = QFileInfo(path).baseName();

        m_curDataUnit = new DataUnit(name, path, m_analyzer);

        m_curDataUnit->prepairFile();
        m_curDataUnit->prepairData();

        m_isCurReaded = m_curDataUnit->isFilePrepared();
        m_isCurPrepeared = m_curDataUnit->isDataPrepared();

        if(!(m_isCurReaded || m_isCurPrepeared)) {
            cantPrepar(*m_curDataUnit);
        }
   }
}

void AppData::process() {
    if(m_isCurReaded && m_isCurPrepeared) {
        m_curDataUnit->processData();
        m_isCurProcessed = m_curDataUnit->isDataProcessed();
    }
}

