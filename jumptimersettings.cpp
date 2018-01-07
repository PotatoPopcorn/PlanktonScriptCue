#include "jumptimersettings.h"
#include "ui_jumptimersettings.h"

JumpTimerSettings::JumpTimerSettings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::JumpTimerSettings)
{
    ui->setupUi(this);
}

JumpTimerSettings::~JumpTimerSettings()
{
    delete ui;
}

void JumpTimerSettings::setTime(float time)
{
    ui->timeInput->setValue((double) time);
}

float JumpTimerSettings::getTime(){
    return (float) ui->timeInput->value();
}
