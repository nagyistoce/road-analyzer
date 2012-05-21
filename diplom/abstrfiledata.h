#ifndef FILEDATA_H
#define FILEDATA_H

#include "dataTypes.h"

#include <QObject>
#include <QString>

#include <opencv2/core/core.hpp>

namespace DATA{

class DataUnit;
class AbstrPreProcessedData;

class   AbstrFileData : public QObject
{
    Q_OBJECT

protected:
    TYPE m_type;

    bool m_isReaded;
    bool m_isSaved;

    QString m_name;
    QString m_sourcePath;
    QString m_saveDir;

public:

    static AbstrFileData* Factory(const QString& sourcePath);

    static TYPE defineType(QString path);
    static bool defineIsFrame(QString fileSuffix);
    static bool defineIsVideo(QString fileSuffix); //stub!
    static bool defineIsXML(QString fileSuffix);   //stub!
    static bool defineIsUnknown(QString fileSuffix);

    AbstrFileData(const QString& name = "unknown");
    virtual ~AbstrFileData() {}

    virtual void setFileSourcePath(const QString& sourcePath);

    virtual void read(AbstrPreProcessedData* link) { m_isReaded = 0; link = 0; }
    virtual void read(DataUnit* link) { m_isReaded = 0; link = 0; }

    virtual void save() { m_isSaved = 0; }

    virtual void rename(const QString& newName) { m_name = newName; }
    virtual void retype(TYPE type) { m_type = type; }

    TYPE getType() const { return m_type; }

    const QString& getName() const {return m_name; }
    const QString& getSourcePath() const {return m_sourcePath; }
    const QString& getSaveDir() const {return m_saveDir; }

    bool isSaved() const {return m_isSaved; }
    bool isReaded() const {return m_isReaded; }

    bool isFrame() const { return (m_type == FRAME); }
    bool isVideo() const { return (m_type == VIDEO); }
    bool isXML() const { return (m_type == XML); }

signals:
    void readed(QString);
    void saved(QString);

public slots:

private:

};

}
#endif // FILEDATA_H
