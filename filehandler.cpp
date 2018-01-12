#include "filehandler.h"

FileHandler::FileHandler()
{

}

bool FileHandler::open(QVector<BaseCue*> &cueList, QString path)
{
    m_openFile=path;
    m_fileOpen=true;
    qDebug() << "Opening ...";
    cueList.clear();
    QFile loadFile(path);
    if(!loadFile.open(QIODevice::ReadOnly)){
        qWarning("Couldn't read file");
        return false;
    }

    QByteArray saveData = loadFile.readAll();

    QJsonDocument loadDoc(QJsonDocument::fromJson(saveData));
    QJsonArray cueArray = loadDoc.object()["cues"].toArray();
    for(int i = 0; i<cueArray.size(); i++){
        QJsonObject cueObject = cueArray[i].toObject();
        BaseCue *newCue = new BaseCue;
        QVector<QString> cueArgs;
        QJsonArray argArray = cueObject["arguemnts"].toArray();
        for(int j = 0; j < argArray.size(); j++)
        {
            QJsonObject argObject = argArray[j].toObject();
            cueArgs.append(argObject["argument"].toString());
        }
        newCue->setCue(
                cueObject["name"].toString(),
                cueObject["program"].toString(),
                cueArgs,
                cueObject["jump"].toString(),
                cueObject["endOnNext"].toBool(true),
                cueObject["jumpOnEnd"].toBool());
        newCue->setJumpSettingData(cueObject["jumpProp"].toObject());
        cueList.append(newCue);
    }
    qDebug() << "Opened";
    return true;
}

bool FileHandler::saveAs(QVector<BaseCue*> &cueList, QString path)
{
    m_openFile=path;
    m_fileOpen=true;
    qDebug() <<"Saving... " << path;
    QFile saveFile(path);

    if(!saveFile.open(QIODevice::WriteOnly))
    {
        qWarning("Couldn't open file to save");
        return false;
    }

    QJsonObject saveObject;

    saveObject["version"] = "A1.3.0";

    QJsonArray cueArray;
    for(int i = 0; i < cueList.length(); i++)
    {
        QJsonObject cueObject;
        BaseCue* cue = cueList.at(i);
        cueObject["name"] = cue->getName();
        cueObject["program"] = cue->getProgram();
        //TODO: Update Arguments
        QJsonArray argArray;
        for(int j = 0; j < cue->getArguments().length(); j++)
        {
            QJsonObject argObject;
            argObject["argument"] = cue->getArguments().at(j);
            argArray.append(argObject);
        }
        cueObject["arguemnts"] = argArray;
        cueObject["jump"] = cue->getJumpSettingPtr()->getIDName();
        cueObject["jumpProp"] = cue->getJumpSettingPtr()->getSaveData();
        cueObject["endOnNext"] = cue->getEndOnNext();
        cueObject["jumpOnEnd"] = cue->getJumpOnEnd();
        cueArray.append(cueObject);
    }
    saveObject["cues"] = cueArray;
    QJsonDocument saveDoc(saveObject);
    saveFile.write(saveDoc.toJson());

    qDebug() <<"Saved";

    return true;
}

bool FileHandler::save(QVector<BaseCue*> &cueList, QWidget *parent){
    if(m_fileOpen){
        return saveAs(cueList, m_openFile);
    }
    else
    {
        QString path = QFileDialog::getSaveFileName(parent, QObject::tr("Save File"),
                                                    "",
                                                    QObject::tr("ScriptCue (*.planksc)"));
        return saveAs(cueList, path);
    }
}

bool FileHandler::isFileOpen()
{
    return m_fileOpen;
}

QString FileHandler::getOpenFile()
{
    return m_openFile;
}

void FileHandler::setFileOpen(bool tf)
{
    m_fileOpen = tf;
}
