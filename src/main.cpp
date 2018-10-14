// QT includes
#include <QApplication>

// user includes
#include "hmi.h"
#include "plc.h"

int main(int argc, char *argv[])
{
    static bool init {false};
    plcInOut plcIOs;
    QApplication app(argc, argv);

    // init
    if (!init)
    {
        init = true;
    }

    // PiXtend PLC
    new Plc(plcIOs, &app);

    // PiXtend HMI
    Hmi window;
    window.show();

    return app.exec();
}
