#include "jumptimerwindow.h"
#include "ui_jumptimerwindow.h"

JumpTimerWindow::JumpTimerWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::JumpTimerWindow)
{
    ui->setupUi(this);
    m_UpdateTimer = new QTimer();
}

JumpTimerWindow::~JumpTimerWindow()
{
    delete ui;
}

void JumpTimerWindow::setQTimer(QTimer *timer)
{
    m_Timer = timer;
}

void JumpTimerWindow::startBackground()
{
    m_UpdateTimer->setInterval(50);
    connect(m_UpdateTimer, SIGNAL(timeout()), this, SLOT(updateUI()));
    m_UpdateTimer->start();
    this->show();
}

void JumpTimerWindow::updateUI()
{
    int tr = m_Timer->remainingTime();
    int min = tr / 60000;
    int sec = (tr / 1000) % 60;
    int csec = (tr % 1000)/10;
    QString time;
    if(min < 10) time.append("0");
    time.append(QString::number(min));
    time.append(":");
    if(sec < 10) time.append("0");
    time.append(QString::number(sec));
    time.append(".");
    if(csec < 10) time.append("0");
    time.append(QString::number(csec));
    ui->timeDisplay->setText(time);
}

void JumpTimerWindow::stopBackground()
{
    m_UpdateTimer->stop();
    this->close();
}
