#ifndef PLC_H
#define PLC_H

// includes
//-------------------------------------------------------------------
#include <QTimer>
#include <QObject>

extern "C"
{
    #include <pixtend.h>
}


#include "customdatatypes.h"

class Plc : public QObject
{
    Q_OBJECT
public:
    explicit Plc(plcInOut& plcIOs, QObject* parent = nullptr);
    ~Plc();

    plcInOut& plcIOs_;

public slots:
    void timerLoop();

private:

    struct pixtInV2S inputData;         // PiXtend V2-S input data
    struct pixtOutV2S outputData;       // PiXtend V2-S output data
    struct pixtOutDAC outputDataDAC;     // PiXtend V2-S output data DAC

    void updateInOut();
    void updateOutDAC();
    void mainTask();
};

#endif // PLC_H
