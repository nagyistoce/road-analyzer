#ifndef ANALYZER_H
#define ANALYZER_H

#include <QObject>

namespace HANDLE{

class Analyzer : public QObject
{
    Q_OBJECT
public:
    explicit Analyzer(QObject *parent = 0);
    
signals:
    
public slots:
    
};
}
#endif // ANALYZER_H
