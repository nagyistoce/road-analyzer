#include "preprocessedvideo.h"
#include <iostream>

using namespace DATA;
PreProcessedVideo::PreProcessedVideo(CvCapture *videoStream)
    : AbstrPreProcessedData(VIDEO), m_videoStream(videoStream)

{

}

const cv::Mat& PreProcessedVideo::getFrame(int pos) {

    cv::Mat* toReturn = new cv::Mat();

    if(m_videoStream) {
        switch(pos) {
            case -1:
                ;
            break;

            case 0:
                ;
            break;

            case 1:
                    if(cvGrabFrame(m_videoStream)) {
                        IplImage* iplImg = cvRetrieveFrame(m_videoStream);
                        if(iplImg) {
                            toReturn = new cv::Mat(iplImg);
                        } else {
                            std::cout << "can't grab frame\n";
                        }
                    } else {
                        std::cout << "can't grab frame\n";
                    }

                //(*m_videoStream) >> (*toReturn);
            break;
        };
    }
    return (*toReturn);

}
