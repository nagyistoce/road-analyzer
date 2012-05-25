#include "videofiledata.h"
#include "preprocessedvideo.h"

using namespace DATA;

VideoFileData::VideoFileData(const QString& name):
    AbstrFileData(name)
{
    AbstrFileData::m_type = VIDEO;
}

VideoFileData::~VideoFileData() {
/*    if(m_videoStream) {
        delete m_videoStream;
    }
*/
}

AbstrPreProcessedData* VideoFileData::read()
{
    assert((m_sourcePath != "unknown") &&
           (AbstrFileData::defineType(m_sourcePath) == VIDEO));

    CvCapture* videoStream = cvCaptureFromFile(m_sourcePath.toAscii().data());
    //cv::VideoCapture* videoStream  = new cv::VideoCapture(m_sourcePath.toAscii().data());

    //AbstrPreProcessedData* toReturn = 0;
    //if(videoStream->isOpened()) {
    AbstrPreProcessedData* toReturn = new PreProcessedVideo(videoStream);
    //}

    return toReturn;
}
