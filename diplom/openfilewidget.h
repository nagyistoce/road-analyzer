#ifndef OPENFILEWIDGET_H
#define OPENFILEWIDGET_H

#include <QWidget>
#include <QString>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>

namespace GUI{

class OpenFileWidget : public QWidget
{
    Q_OBJECT

    QLineEdit* m_pathLineEdit;
    QPushButton* m_okButton;
    QPushButton* m_cancelButton;
    QLabel* m_statusLabel;

public:
    OpenFileWidget(QWidget *parent = 0);


signals:

    void pathChanged(QString);
    
public slots:

    void incorectPath();
    void corectPath();

private slots:

    void ps_okButtonPressed();
};

}
#endif // OPENFILEWIDGET_H
