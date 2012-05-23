#ifndef SETCONFWIDGET_H
#define SETCONFWIDGET_H

#include <QWidget>

namespace GUI{

class SetConfWidget : public QWidget
{
    Q_OBJECT
public:
    friend class AppWindow;

    explicit SetConfWidget(QWidget *parent = 0);
    
signals:
    
public slots:
    
};

}
#endif // SETCONFWIDGET_H
