#ifndef JUMPTIMER_H
#define JUMPTIMER_H

#include <QDebug>
#include <QTimer>

#include "basejump.h"
#include "jumptimersettings.h"
#include "jumptimerwindow.h"

class JumpTimer : public BaseJump
{
    Q_OBJECT
public:
    JumpTimer();

    QString getDetails();

    QJsonObject getSaveData();
    void loadData(QJsonObject data);


signals:
    void nextCue();

public slots:
    void startCue();
    void openSettings(); //TODO
    void stopCue();

private:
    bool m_showUIBool = false;
    float m_Time = 1;

    QTimer *m_Timer;

    JumpTimerSettings *m_JTS;
    JumpTimerWindow *m_JTW;

private slots:
    void timerDone();
};

#endif // JUMPTIMER_H
