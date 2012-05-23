#include "openfilewidget.h"

#include <QGridLayout>
#include <QFile>
#include <QDir>

using namespace GUI;

OpenFileWidget::OpenFileWidget(QWidget *parent) :
    QWidget(parent)
{
    QLabel* widgetLaybel = new QLabel(tr("Path: "), this);
    m_pathLineEdit = new QLineEdit(tr("input_data\\p1.jpg"), this);
    m_okButton = new QPushButton(tr("OK"), this);
    m_cancelButton = new QPushButton(tr("Cancel"), this);
    m_statusLabel = new QLabel(tr("Status: "), this);

    QGridLayout* widgetLayout = new QGridLayout(this);
    widgetLayout->addWidget(widgetLaybel, 1, 1);
    widgetLayout->addWidget(m_pathLineEdit, 1, 2);
    widgetLayout->addWidget(m_okButton, 1, 3);
    widgetLayout->addWidget(m_cancelButton, 1, 4);
    widgetLayout->addWidget(m_statusLabel, 2, 2);

    connect(m_okButton, SIGNAL(pressed()), this, SLOT(ps_okButtonPressed()));
    connect(m_cancelButton, SIGNAL(pressed()), this, SLOT(close()));
}


void OpenFileWidget::ps_okButtonPressed() {

    QString newPath = m_pathLineEdit->text();

    if(!(QFile::exists(newPath) || QDir().exists(newPath))) {
        incorectPath();
    } else {
        corectPath();
        pathChanged(newPath);
    }
}


void OpenFileWidget::incorectPath() {
    m_statusLabel->setText("Status: incorrect path");
}

void OpenFileWidget::corectPath() {
    m_statusLabel->setText("Status: correct path");
}
