#ifndef VIDEOCONTROLWIDGET_H
#define VIDEOCONTROLWIDGET_H

#include <QWidget>
#include <QPushButton>

namespace GUI{

class VideoControlWidget : public QWidget
{
    Q_OBJECT

    QPushButton* m_playButton;
    QPushButton* m_pauseButton;
    QPushButton* m_stopButton;
    QPushButton* m_nextButton;
    QPushButton* m_prevButton;

public:
    explicit VideoControlWidget(QWidget *parent = 0);
    
protected:
    virtual void resizeEvent ( QResizeEvent * event );

signals:
    
public slots:
    
};
}
#endif // VIDEOCONTROLWIDGET_H
