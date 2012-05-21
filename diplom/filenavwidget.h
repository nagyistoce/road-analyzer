#ifndef FILENAVWIDGET_H
#define FILENAVWIDGET_H

#include <QWidget>
#include <QPushButton>

namespace GUI{
class FileNavWidget : public QWidget
{
    Q_OBJECT

    QPushButton* m_openButton;
    QPushButton* m_nextButton;
    QPushButton* m_prevButton;

public:
    explicit FileNavWidget(QWidget *parent = 0);
    
signals:
    
public slots:
    
};
}
#endif // FILENAVWIDGET_H
