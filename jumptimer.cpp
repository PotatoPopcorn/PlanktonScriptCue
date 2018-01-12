#include "jumptimer.h"

JumpTimer::JumpTimer()
{
    m_publicName = "Timer [NYI]";
    m_idName = "TIMER";
    m_JTW = new JumpTimerWindow();
}

void JumpTimer::timerDone()
{
    emit nextCue();
}

QString JumpTimer::getDetails(){
    QString rs = "Timer: ";
    rs.append(QString::number(m_Time));
    rs.append("s");
    if(m_showUIBool) rs.append(" U");
    return rs;
}

QJsonObject JumpTimer::getSaveData(){
    QJsonObject r;
    r["time"] = (double) m_Time;
    r["showUI"] = m_showUIBool;
    return r;
}

void JumpTimer::loadData(QJsonObject data){
    double timed = data["time"].toDouble();
    qDebug() << timed;
    m_Time = (float) timed;
    m_showUIBool = data["showUI"].toBool();
}

void JumpTimer::startCue(){
    m_Timer = new QTimer(this);
    QObject::connect(m_Timer, SIGNAL(timeout()), this, SLOT(timerDone()));
    float timemsf = m_Time * 1000;
    int timemsi= (int) timemsf;
    m_Timer->setSingleShot(true);
    m_Timer->setInterval(timemsi);
    if(m_showUIBool){
        m_JTW->setQTimer(m_Timer);
        m_JTW->startBackground();
    }
    m_Timer->start();
}

void JumpTimer::openSettings(){
    m_JTS = new JumpTimerSettings();
    m_JTS->setTime(m_Time);
    m_JTS->setShowUI(m_showUIBool);
    if(m_JTS->exec()){
        m_Time = m_JTS->getTime();
        m_showUIBool = m_JTS->getShowUI();
    }
}

void JumpTimer::stopCue(){
    m_JTW->stopBackground();
    m_Timer->stop();
}
