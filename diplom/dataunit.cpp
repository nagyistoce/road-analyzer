#include "dataunit.h"

using namespace DATA;

DataUnit::DataUnit(const QString& name,
                   const QString &sourseFilePath,
                   const HANDLE::Analyzer &anylyzer)

                 : AbstrFileData(name),
                   m_analyzer(anylyzer)
{
    m_sourcePath = sourseFilePath;

    m_handleFile = 0;
    m_preProcessedData = 0;
    m_processedData = 0;
}

void DataUnit::read(DataUnit* link) { m_isReaded = 0; link = 0; }

void DataUnit::save() { m_isSaved = 0; }

void DataUnit::prepairFile() {
    m_handleFile = AbstrFileData::Factory(m_sourcePath);
    if(m_handleFile)
        m_isFilePrepared = true;
}

void DataUnit::prepairData() {
    m_handleFile->read(m_preProcessedData);
    if(m_preProcessedData)
            m_isDataPrepared = true;
}
void DataUnit::processData() {
    m_processedData = m_preProcessedData->process();
    if(m_processedData)
         m_isDataProcessed = true;
}

bool DataUnit::isFilePrepared() const {
    return m_isFilePrepared;
}

bool DataUnit::isDataPrepared() const {
    return m_isDataPrepared;
}

bool DataUnit::isDataProcessed() const {
    return m_isDataProcessed;
}

const AbstrFileData& DataUnit::getHandleFile() const {
    return *m_handleFile;
}

const AbstrPreProcessedData& DataUnit::getPreProcessedData() const {
    return *m_preProcessedData;
}

const AbstrProcessedData& DataUnit::getProcessedData() const {
    return *m_processedData;
}

const HANDLE::Analyzer& DataUnit::getAnalyzer() const {
    return m_analyzer;
}

