// includes
//-------------------------------------------------------------------
#include "plc.h"

// constructor
Plc::Plc(plcInOut& plcIOs, QObject* parent) :
    QObject(parent),
    plcIOs_(plcIOs)
{
    // init timer
    QTimer* timer {new QTimer(this)};
    connect(timer, SIGNAL(timeout()), this, SLOT(timerLoop()));
    timer->start(20);

    // init PiXtend

    Spi_SetupV2(0);                 // communication with uP
    Spi_SetupV2(1);                 // communication with DAC

    outputData.byModelOut = 83;     // set model as handschake, PiXtend V2-S = 83
    outputDataDAC.wAOut0 = 1023;    // pre-load analog ouputs
    outputDataDAC.wAOut1 = 1023;    // pre-load analog ouputs
}

// destructor
Plc::~Plc()
{
}

// update inputs and outputs
//-------------------------------------------------------------------

void Plc::updateInOut()
{
    // do data transfer
    Spi_AutoModeV2S(&outputData,&inputData);
}

// update DACoutputs
//-------------------------------------------------------------------

void Plc::updateOutDAC()
{
    // do data transfer
    Spi_AutoModeDAC(&outputDataDAC);
}

// main task
//-------------------------------------------------------------------

void Plc::mainTask()
{
    ;
}


// main loop [20ms cycle time]
//-------------------------------------------------------------------
void Plc::timerLoop()
{
    updateInOut();
    updateOutDAC();
    mainTask();
}
