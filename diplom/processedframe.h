#ifndef PROCESSEDFRAME_H
#define PROCESSEDFRAME_H

#include "abstrprocesseddata.h"

#include <opencv2/core/core.hpp>

namespace DATA{

class ProcessedFrame : public AbstrProcessedData
{
   cv::Mat* m_frame;

public:
    ProcessedFrame(TYPE type, cv::Mat* frame)
            : AbstrProcessedData(type), m_frame(frame)
    {}

    const cv::Mat& getFrame() const { return *m_frame; }

};

}
#endif // PROCESSEDFRAME_H
