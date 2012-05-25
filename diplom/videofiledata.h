#ifndef VIDEOFILEDATA_H
#define VIDEOFILEDATA_H

#include "abstrfiledata.h"

#include "opencv2/opencv.hpp"

namespace DATA{

class VideoFileData : public AbstrFileData
{

public:
      VideoFileData(const QString& name);
      virtual ~VideoFileData();

    virtual AbstrPreProcessedData* read();
    virtual void save(){} //stub!
};

}
#endif // VIDEOFILEDATA_H
