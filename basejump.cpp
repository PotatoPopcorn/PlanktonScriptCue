#include "basejump.h"

BaseJump::BaseJump()
{

}

QString BaseJump::getIDName(){
    return m_idName;
}

QString BaseJump::getPublicName(){
    return m_publicName;
}

QString BaseJump::getDetails(){
    return "ERROR";
}

bool BaseJump::getHasEditPanel(){
    return m_hasEditPanel;
}

QJsonObject BaseJump::getSaveData(){
    QJsonObject data;
    data["data"]="NONE";
    return data;
}

void BaseJump::loadData(QJsonObject data){

}

void BaseJump::startCue(){

}

void BaseJump::openSettings(){

}
