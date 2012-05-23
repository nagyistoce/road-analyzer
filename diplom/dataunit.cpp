#include "dataunit.h"

#include <iostream>

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

    m_isFilePrepared = false;
    m_isDataPrepared = false;
    m_isDataProcessed = false;
}

void DataUnit::read(DataUnit* link) { m_isReaded = 0; link = 0; }

void DataUnit::save() { m_isSaved = 0; }

void DataUnit::prepairFile() {
    m_handleFile = AbstrFileData::Factory(m_sourcePath);
    if(m_handleFile) {
        m_isFilePrepared = true;
        m_type = m_handleFile->getType();
    }
}

void DataUnit::prepairData() {
    m_preProcessedData = m_handleFile->read();
    std::cout << "DataUnit::prepairData adr - " <<  m_preProcessedData <<"\n";
    if(m_preProcessedData) {
        std::cout << "DataUnit::prepairData,data Prepared\n";
        m_isDataPrepared = true;
    }
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

