#ifndef ABSTRPREPROCESSEDDATA_H
#define ABSTRPREPROCESSEDDATA_H

#include "dataTypes.h"
#include "abstrprocesseddata.h"

#include <QObject>

#include <opencv2/core/core.hpp>

namespace DATA{

class AbstrPreProcessedData : public QObject
{
    Q_OBJECT

protected:
    TYPE m_type;

public:
    AbstrPreProcessedData(TYPE type) : m_type(type) {}
    virtual ~AbstrPreProcessedData() {}

    virtual const cv::Mat& getFrame(int pos = 0) const { return *(new cv::Mat()); }

    virtual AbstrProcessedData* process() const { return 0; }

    TYPE getType() const { return m_type; }

signals:
    void processed() const;
    void unprocessed() const;
public slots:
    
};
}
#endif // ABSTRPREPROCESSEDDATA_H
