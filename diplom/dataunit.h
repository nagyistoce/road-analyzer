#ifndef DATAUNIT_H
#define DATAUNIT_H

#include "dataTypes.h"
#include "abstrfiledata.h"
#include "abstrpreprocesseddata.h"
#include "abstrprocesseddata.h"
#include "analyzer.h"

#include <QObject>
#include <QString>
#include <QPair>

namespace DATA{

class DataUnit : public AbstrFileData
{
    Q_OBJECT

    AbstrFileData* m_handleFile;
    AbstrPreProcessedData* m_preProcessedData;
    AbstrProcessedData* m_processedData;

    const HANDLE::Analyzer& m_analyzer;

public:
    DataUnit();

    DataUnit(const QString& name,
             const QString& sourseFilePath,
             const HANDLE::Analyzer& anylyzer);

    void read(DataUnit* link);
    void save();

    void prepairFile();
    void prepairData();
    void processData();

    bool isFilePrepared() const;
    bool isDataPrepared() const;
    bool isDataProcessed() const;

    const AbstrFileData& getHandleFile() const;
    /*const*/ AbstrPreProcessedData& getPreProcessedData() const;
    const AbstrProcessedData& getProcessedData() const;
    const HANDLE::Analyzer& getAnalyzer() const;
signals:

public slots:

private:
    bool m_isFilePrepared;
    bool m_isDataPrepared;
    bool m_isDataProcessed;

};
}
#endif // DATAUNIT_H
