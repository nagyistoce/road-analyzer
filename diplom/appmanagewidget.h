#ifndef APPMANAGEWIDGET_H
#define APPMANAGEWIDGET_H

#include "filenavwidget.h"
#include <QDockWidget>
#include <QPushButton>

namespace GUI{

class AppManageWidget : public QWidget
{
    Q_OBJECT

    FileNavWidget* m_fileNavWidget;

    QPushButton* m_configButton;
    QPushButton* m_startButton;
    QPushButton* m_saveButton;

public:
    AppManageWidget(QWidget *parent = 0);
    friend class GUIFasadClass;

};

}
#endif // APPMANAGEWIDGET_H
