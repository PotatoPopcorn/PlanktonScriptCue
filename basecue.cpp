#include "basecue.h"

//Empty Constructor
BaseCue::BaseCue()
{

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
    ret.append("]");
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

//Changes all information about cue
void BaseCue::setCue(QString name, QString program, QVector<QString> arguments)
{
    setName(name);
    setProgram(program);
    setArguments(arguments);
}

BaseJump* BaseCue::getJumpSettingPtr(){
    return m_JumpSetting;
}
