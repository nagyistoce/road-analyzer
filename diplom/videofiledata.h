#ifndef VIDEOFILEDATA_H
#define VIDEOFILEDATA_H

#include "abstrfiledata.h"

namespace DATA{

class VideoFileData : public AbstrFileData
{
public:
      VideoFileData(const QString& name);
   //   virtual ~VideoFileData();

    virtual void read(AbstrPreProcessedData* link) {} //stub!
    virtual void save(){} //stub!
};

}
#endif // VIDEOFILEDATA_H
