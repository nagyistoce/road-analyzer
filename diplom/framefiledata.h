#ifndef FRAMEFILEDATA_H
#define FRAMEFILEDATA_H

#include "abstrfiledata.h"

#include "opencv2\highgui\highgui_c.h"

namespace DATA{

class FrameFileData : public AbstrFileData
{
    cv::Mat* m_frame;
public:
    FrameFileData(const QString& name);
    virtual ~FrameFileData();

    virtual void read(AbstrPreProcessedData* link);
    virtual void save(); //stub!
};

}
#endif // FRAMEFILEDATA_H
