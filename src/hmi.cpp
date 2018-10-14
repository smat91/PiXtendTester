// includes
//-------------------------------------------------------------------
#include "hmi.h"
#include "ui_hmi.h"
#include "customdatatypes.h"

// constructor
Hmi::Hmi(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Hmi)
{
    ui->setupUi(this);
}

// destructor
Hmi::~Hmi()
{
    delete ui;
}

void Hmi::on_pushButton_clicked()
{
    ;
}
