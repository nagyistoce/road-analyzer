#ifndef ABSTRPROCESSEDDATA_H
#define ABSTRPROCESSEDDATA_H

#include "dataTypes.h"

#include <QObject>

namespace DATA{

class AbstrProcessedData : public QObject
{
    Q_OBJECT

protected:
    TYPE m_type;

public:
    AbstrProcessedData(TYPE type) : m_type(type) {}
    virtual ~AbstrProcessedData() {}

    TYPE getType() const { return m_type; }

signals:
    
public slots:
    
};

}
#endif // ABSTRPROCESSEDDATA_H
