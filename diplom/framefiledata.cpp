#include "framefiledata.h"

#include "preprocessedframe.h"

using namespace DATA;

FrameFileData::FrameFileData(const QString& name):
    AbstrFileData(name)
{
    AbstrFileData::m_type = FRAME;
}

FrameFileData::~FrameFileData() {
    delete m_frame;
}

void FrameFileData::read(AbstrPreProcessedData *link) {

    assert((m_sourcePath != "unknown") &&
           (AbstrFileData::defineType(m_sourcePath) == FRAME));

    IplImage* img = 0;
    img = cvLoadImage(m_sourcePath.toAscii().data());

    if(!img) link = 0;

    link = new PreProcessedFrame
                (
                    m_type,
                    new cv::Mat(img)
                );

    m_isReaded = true;
}

void FrameFileData::save() {

    QString path(m_saveDir + "/" + m_name +".jpg");
    m_isSaved = cvSaveImage(path.toAscii().data(), m_frame);
}
