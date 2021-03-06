#include "basecue.h"

//Empty Constructor
BaseCue::BaseCue()
{
    procParent = new QObject();
    process=new QProcess(procParent);
}

//Returns cue name
QString BaseCue::getName()
{
    return m_Name;
}

//Returns program path
QString BaseCue::getProgram()
{
    return m_Program;
}

//Returns program arguments
QVector<QString> BaseCue::getArguments()
{
    return m_Arguments;
}

//Creates a standard string to show all information about the cue
QString BaseCue::getDisplayName()
{
    QString ret;
    ret.append(m_Name);
    ret.append(" (");
    ret.append(m_Program);
    for(int i = 0; i < m_Arguments.length(); i++)
    {
        ret.append(" ");
        ret.append(m_Arguments.at(i));
    }
    ret.append(") [");
    ret.append(m_JumpSetting->getDetails());
    ret.append("] { ");
    if(m_EndOnNext) ret.append(("E "));
    if(m_JumpOnEnd) ret.append(("J "));
    ret.append("}");
    return ret;
}

//Sets cue name
void BaseCue::setName(QString name)
{
    m_Name = name;
}

//Sets cue program path
void BaseCue::setProgram(QString program)
{
    m_Program = program;
}

//Sets cue arguments
void BaseCue::setArguments(QVector<QString> arguments)
{
    m_Arguments = arguments;
}

void BaseCue::setJumpModeID(QString jumpModeID){
    if(jumpModeID == m_JumpSetting->getIDName()){
        return;
    }
    if(jumpModeID == "NONE")
    {
        m_JumpSetting = new JumpNone;
    }
    else if(jumpModeID == "TIMER")
    {
        m_JumpSetting = new JumpTimer;
    }
    else
    {
        qDebug() << "Error with jump mode" << jumpModeID;
    }
    connect(m_JumpSetting, SIGNAL(nextCue()), this, SLOT(callNextCue()));
}

//Changes all information about cue
void BaseCue::setCue(
        QString name,
        QString program,
        QVector<QString> arguments,
        QString jumpModeID,
        bool endOnNext,
        bool jumpOnEnd)
{
    setName(name);
    setProgram(program);
    setArguments(arguments);
    setJumpModeID(jumpModeID);
    setEndOnNext(endOnNext);
    setJumpOnEnd(jumpOnEnd);
}

BaseJump* BaseCue::getJumpSettingPtr(){
    return m_JumpSetting;
}

void BaseCue::setJumpSettingData(QJsonObject data){
    //m_JumpData = data;
    m_JumpSetting->loadData(data);
}

void BaseCue::startCue()
{
    QString procName = getProgram();
    QStringList procArgs;
    for(int i = 0; i < getArguments().length(); i++)
    {
        procArgs.append(getArguments().at(i));
    }
    process->start(procName, procArgs);
    m_JumpSetting->startCue();
    connect(process, SIGNAL(finished(int)), this, SLOT(finishedCue()));
}

void BaseCue::endCue()
{
    m_JumpSetting->stopCue();
    if(m_EndOnNext)
    {
        process->terminate();
        process->kill();
    }
    disconnect(process, SIGNAL(finished(int)), this, SLOT(finishedCue()));
}

void BaseCue::callNextCue()
{
    emit nextCue();
}

void BaseCue::finishedCue()
{
    if(m_JumpOnEnd){
        emit nextCue();
    }
}

bool BaseCue::getEndOnNext()
{
    return m_EndOnNext;
}

bool BaseCue::getJumpOnEnd()
{
    return m_JumpOnEnd;
}

void BaseCue::setEndOnNext(bool value)
{
    m_EndOnNext = value;
}

void BaseCue::setJumpOnEnd(bool value)
{
    m_JumpOnEnd = value;
}

bool BaseCue::isQuickButton()
{
    return m_isQuickButton;
}

void BaseCue::setIsQuickButton(bool value)
{
    m_isQuickButton = value;
}

QJsonObject BaseCue::save()
{
    QJsonObject cueObject;
    cueObject["name"] = getName();
    cueObject["program"] = getProgram();
    //TODO: Update Arguments
    QJsonArray argArray;
    for(int j = 0; j < getArguments().length(); j++)
    {
        QJsonObject argObject;
        argObject["argument"] = getArguments().at(j);
        argArray.append(argObject);
    }
    cueObject["arguemnts"] = argArray;
    cueObject["jump"] = getJumpSettingPtr()->getIDName();
    cueObject["jumpProp"] = getJumpSettingPtr()->getSaveData();
    cueObject["endOnNext"] = getEndOnNext();
    cueObject["jumpOnEnd"] = getJumpOnEnd();
    return cueObject;
}

void BaseCue::load(QJsonObject data)
{
    QVector<QString> cueArgs;
    QJsonArray argArray = data["arguemnts"].toArray();
    for(int j = 0; j < argArray.size(); j++)
    {
        QJsonObject argObject = argArray[j].toObject();
        cueArgs.append(argObject["argument"].toString());
    }
    setCue(
            data["name"].toString(),
            data["program"].toString(),
            cueArgs,
            data["jump"].toString(),
            data["endOnNext"].toBool(true),
            data["jumpOnEnd"].toBool());
    setJumpSettingData(data["jumpProp"].toObject());
}
