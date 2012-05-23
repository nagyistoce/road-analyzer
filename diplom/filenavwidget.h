#ifndef FILENAVWIDGET_H
#define FILENAVWIDGET_H

#include "openfilewidget.h"

#include <QWidget>
#include <QPushButton>

namespace GUI{

class FileNavWidget : public QWidget
{
    Q_OBJECT

    QPushButton* m_openButton;
    QPushButton* m_nextButton;
    QPushButton* m_prevButton;

    OpenFileWidget* m_openFileWidget;

public:
    FileNavWidget(QWidget *parent = 0);
    ~FileNavWidget();
    
signals:
    void pathChanged(QString);
    void nextFile();
    void prevFile();

public slots:
    void incorectPath();
    void corectPath();

private slots:
    void ps_pathChanged(QString);
    void ps_nextFile();
    void ps_prevFile();
};
}
#endif // FILENAVWIDGET_H
