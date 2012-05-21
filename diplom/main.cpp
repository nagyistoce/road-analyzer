#include "engine.h"

#include <QtCore/QCoreApplication>
#include <QtGUI>


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Engine engine;

    return app.exec();
}
