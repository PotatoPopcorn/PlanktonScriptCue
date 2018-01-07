#include "jumptimer.h"

JumpTimer::JumpTimer()
{
    m_publicName = "Timer [NYI]";
    m_idName = "TIMER";
}

void JumpTimer::timerDone()
{
    emit nextCue();
}

QString JumpTimer::getDetails(){
    QString rs = "Timer: ";
    rs.append(QString::number(m_Time));
    rs.append("s");
    return rs;
}

QJsonObject JumpTimer::getSaveData(){
    QJsonObject r;
    r["time"] = (double) m_Time;
    return r;
}

void JumpTimer::loadData(QJsonObject data){
    double timed = data["time"].toDouble();
    qDebug() << timed;
    m_Time = (float) timed;
}

void JumpTimer::startCue(){
    m_Timer = new QTimer(this);
    QObject::connect(m_Timer, SIGNAL(timeout()), this, SLOT(timerDone()));
    float timemsf = m_Time * 1000;
    int timemsi= (int) timemsf;
    m_Timer->setSingleShot(true);
    m_Timer->setInterval(timemsi);
    m_Timer->start();
}

void JumpTimer::openSettings(){
    m_JTS = new JumpTimerSettings();
    m_JTS->setTime(m_Time);
    if(m_JTS->exec()){
        m_Time = m_JTS->getTime();
    }
}

void JumpTimer::stopCue(){
    m_Timer->stop();
}
