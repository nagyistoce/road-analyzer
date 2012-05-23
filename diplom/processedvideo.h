#ifndef PROCESSEDVIDEO_H
#define PROCESSEDVIDEO_H

#include "abstrprocesseddata.h"

#include <opencv2/core/core.hpp>

namespace DATA{

class ProcessedVideo : public AbstrProcessedData
{
public:
    ProcessedVideo(): AbstrProcessedData(VIDEO) {}

};
}
#endif // PROCESSEDVIDEO_H
