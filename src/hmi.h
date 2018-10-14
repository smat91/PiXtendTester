#ifndef HMI_H
#define HMI_H

// includes
//-------------------------------------------------------------------
#include <QMainWindow>

#include "customdatatypes.h"

namespace Ui{
class Hmi;
}

class Hmi : public QMainWindow
{
    Q_OBJECT

public:
    explicit Hmi(QWidget* parent = nullptr);
    ~Hmi();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Hmi* ui;
};

#endif // HMI_H
