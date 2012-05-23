#include "filenavwidget.h"

#include <QBoxLayout>

using namespace GUI;

FileNavWidget::FileNavWidget(QWidget *parent) :
    QWidget(parent)
{
    QBoxLayout* widgetLayout = new QHBoxLayout(this);

    m_openButton = new QPushButton("Open", this);
    m_nextButton = new QPushButton(" > ", this);
    m_prevButton = new QPushButton(" < ", this);
    m_openFileWidget = new OpenFileWidget();

    widgetLayout->addWidget(m_prevButton);
    widgetLayout->addWidget(m_openButton);
    widgetLayout->addWidget(m_nextButton);

    connect( m_openButton, SIGNAL(pressed()), m_openFileWidget, SLOT(show()));
    connect( m_prevButton, SIGNAL(pressed()), this, SLOT(ps_prevFile()));
    connect( m_nextButton, SIGNAL(pressed()), this, SLOT(ps_nextFile()));
    connect( m_openFileWidget, SIGNAL(pathChanged(QString)),
                        this, SLOT(ps_pathChanged(QString)));
}

FileNavWidget::~FileNavWidget() {

    delete m_openFileWidget;
}

void FileNavWidget::incorectPath() {
    m_openFileWidget->incorectPath();
}

void FileNavWidget::corectPath() {
    m_openFileWidget->corectPath();
    m_openFileWidget->close();
}


void FileNavWidget::ps_pathChanged(QString path) {
    this->pathChanged(path);
}

void FileNavWidget::ps_nextFile() {
    this->nextFile();
}

void FileNavWidget::ps_prevFile() {
    this->prevFile();
}
