#include "engine.h"

#include <QtCore/QCoreApplication>
#include <QtGUI>


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Engine engine;
    //Engine* engine = new Engine();

    return app.exec();
}
