#ifndef APPDATA_H
#define APPDATA_H

#include "dataunit.h"

#include "analyzer.h"

#include <QObject>
#include <QDir>

namespace DATA{

class AppData : public QObject
{
    Q_OBJECT

    DataUnit* m_curDataUnit;

    bool m_isCurReaded;
    bool m_isCurPrepeared;
    bool m_isCurProcessed;

    QList<DataUnit*> m_HandledDataList;
    QListIterator<DataUnit*> m_HandledDataIterator;


    const HANDLE::Analyzer& m_analyzer;

public:
    AppData(const HANDLE::Analyzer& analyzer);
    
    const DataUnit& getCurDataUnit() const { return *m_curDataUnit; }

    bool isCurReaded() { return m_isCurReaded; }
    bool isCurPrepeared() { return m_isCurPrepeared; }
    bool isCurProcessed() { return m_isCurProcessed; }

signals:
    
    void cantPrepar(DataUnit&);
    void cantProcess(DataUnit&);
    void fileNotExist();

    void prepared(DataUnit&);
    void processed(DataUnit&);

public slots:

    void newFile(const QString& path);
    void process();
    void save(){}

    void nextHandledData()  {}
    void prevHandledData() {}

    void nextFile()  {}
    void prevFile()  {}
};
}
#endif // APPDATA_H
