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

public:
    AppData(const HANDLE::Analyzer& analyzer);
    
    const DataUnit& getCurDataUnit() const { return *m_curDataUnit; }

    bool isCurReaded() { return m_isCurReaded; }
    bool isCurPrepeared() { return m_isCurPrepeared; }
    bool isCurProcessed() { return m_isCurProcessed; }

public slots:

    void newPath(const QString& path);
    void process();
    void save(){}

    void nextHandledData()  {}
    void prevHandledData() {}

    void nextFile()  {}
    void prevFile()  {}

signals:

    void cantPrepar();
    void fileNotExist();

    void cantProcess();

    void prepared();
    void processed();

private:
    DataUnit * m_curDataUnit;

    bool m_isCurReaded;
    bool m_isCurPrepeared;
    bool m_isCurProcessed;

    QList<DataUnit*> m_HandledDataList;
    QListIterator<DataUnit*> m_HandledDataIterator;


    const HANDLE::Analyzer& m_analyzer;

};
}
#endif // APPDATA_H
