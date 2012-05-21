#ifndef PREPROCESSEDVIDEO_H
#define PREPROCESSEDVIDEO_H

#include "abstrpreprocesseddata.h"

#include <opencv2/core/core.hpp>

namespace DATA{
class PreProcessedVideo : public AbstrPreProcessedData
{
public:
    PreProcessedVideo(TYPE type);
};
}
#endif // PREPROCESSEDVIDEO_H
