#include "abstrfiledata.h"

#include "framefiledata.h"
#include "videofiledata.h"
#include "xmlfiledata.h"

#include <QFileInfo>
#include <QFile>

#include "assert.h"

using namespace DATA;

AbstrFileData* AbstrFileData::Factory(const QString& sourcePath) {

    AbstrFileData* returned;
    QString name = QFileInfo(sourcePath).baseName();
    switch(defineType(sourcePath)) {

        case FRAME:
            returned = new FrameFileData(name);
            returned->setFileSourcePath(sourcePath);
        break;

        case VIDEO:
            returned = new VideoFileData(name);
            returned->setFileSourcePath(sourcePath);
        break;

        case XML:
            returned = new VideoFileData(name);
            returned->setFileSourcePath(sourcePath);
        break;

        case UNKNOWN:
            returned = 0;
        break;
    };

    return returned;
}

AbstrFileData::AbstrFileData(const QString& name)
        :
        m_name(name), m_type(UNKNOWN),
        m_sourcePath("unknown"), m_saveDir("unknown"),
        m_isReaded(false), m_isSaved(false)
{


}

void AbstrFileData::setFileSourcePath(const QString& sourcePath) {

    assert(QFile::exists(sourcePath));
    m_sourcePath = sourcePath;
    m_type = defineType(sourcePath);
}

TYPE AbstrFileData::defineType(QString path) {

    assert(QFile::exists(path));

    QString fileSuffix(QFileInfo(path).completeSuffix());
    if(defineIsFrame(fileSuffix)) {
      return FRAME;
    } else if(defineIsVideo(fileSuffix)) {
        return VIDEO;
    } else if(defineIsXML(fileSuffix)) {
         return XML;
    } else {
        return UNKNOWN;
    }
}

bool AbstrFileData::defineIsFrame(QString fileSuffix) {

    QString frameSuffixes[] = {".bmp", ".dib",
                             ".jpeg", ".jpg", ".jpe", ".jp2",
                             ".png", ".pbm", ".pgm",
                             ".sr",  ".ras",  ".tiff", ".tif"};

    for(int i = 0; i < 13; i++) {
        if(fileSuffix == frameSuffixes[i]) {
            return true;
        }
    }
    return false;
}

bool AbstrFileData::defineIsVideo(QString) {
    return false;
}
bool AbstrFileData::defineIsXML(QString) {
    return false;
}
