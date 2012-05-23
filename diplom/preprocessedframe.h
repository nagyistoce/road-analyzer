#ifndef PREPROCESSEDFRAME_H
#define PREPROCESSEDFRAME_H

#include "abstrpreprocesseddata.h"

#include <opencv2/core/core.hpp>

namespace DATA{

class PreProcessedFrame : public AbstrPreProcessedData
{
    Q_OBJECT

    cv::Mat* m_frame;
public:

    PreProcessedFrame(TYPE type, cv::Mat* frame);
    virtual ~PreProcessedFrame() {}    //stub!

    virtual AbstrProcessedData* process() const { return 0; }   //stub!

    virtual const cv::Mat& getFrame(int pos = 0) const { return *m_frame; }
};
}
#endif // PREPROCESSEDFRAME_H
