#include "preprocessedframe.h"

using namespace DATA;

PreProcessedFrame::PreProcessedFrame(TYPE type, cv::Mat* frame)
    : AbstrPreProcessedData(type), m_frame(frame)
{}
