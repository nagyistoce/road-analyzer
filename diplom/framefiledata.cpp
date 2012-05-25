#include "framefiledata.h"

#include "preprocessedframe.h"
#include <iostream>

using namespace DATA;

FrameFileData::FrameFileData(const QString& name):
    AbstrFileData(name)
{
    AbstrFileData::m_type = FRAME;
}

AbstrPreProcessedData *FrameFileData::read() {

    assert((m_sourcePath != "unknown") &&
           (AbstrFileData::defineType(m_sourcePath) == FRAME));

    AbstrPreProcessedData *link = 0;
    IplImage* img = 0;
    img = cvLoadImage(m_sourcePath.toAscii().data());

    if(!img) {
        std::cout << "FrameFileData::read, can't load img\n";
    } else {
        m_frame = new cv::Mat(img);
        link = new PreProcessedFrame(m_type, m_frame);

        if(!link) {
            std::cout << "FrameFileData::read, can't create cv::Mat\n";
        } else {
            m_isReaded = true;
            std::cout << "FrameFileData::read, image readed, adr - " << link <<"\n";
        }
    }
    return link;
}

void FrameFileData::save() {

    QString path(m_saveDir + "/" + m_name +".jpg");
    m_isSaved = cvSaveImage(path.toAscii().data(), m_frame);
}
