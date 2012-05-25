#ifndef PREPROCESSEDVIDEO_H
#define PREPROCESSEDVIDEO_H

#include "abstrpreprocesseddata.h"

#include <opencv2/core/core.hpp>
#include "opencv2/opencv.hpp"

namespace DATA{

class PreProcessedVideo : public AbstrPreProcessedData
{
    CvCapture* m_videoStream;

public:
    PreProcessedVideo(CvCapture* videoStream);
    virtual const cv::Mat& getFrame(int pos = 0);

};

}
#endif // PREPROCESSEDVIDEO_H
