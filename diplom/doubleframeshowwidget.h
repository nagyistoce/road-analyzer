#ifndef DOUBLEFRAMESHOWWIDGET_H
#define DOUBLEFRAMESHOWWIDGET_H

#include "frameshowwidget.h"

#include <QWidget>

namespace GUI{

class DoubleFrameShowWidget : public QWidget
{
    Q_OBJECT

    FrameShowWidget* m_originalFrame;
    FrameShowWidget* m_resultFrame;
public:
    explicit DoubleFrameShowWidget(QWidget *parent = 0);

signals:
    
public slots:
    
};

}
#endif // DOUBLEFRAMESHOWWIDGET_H
