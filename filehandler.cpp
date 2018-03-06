#include "filehandler.h"

FileHandler::FileHandler()
{

}

bool FileHandler::open(QVector<BaseCue*> &cueList, QVector<QuickButtonPage*> &qbPages, QString path)
{
    m_openFile=path;
    m_fileOpen=true;
    qDebug() << "Opening ...";
    cueList.clear();
    qbPages.clear();
    QFile loadFile(path);
    if(!loadFile.open(QIODevice::ReadOnly)){
        qWarning("Couldn't read file");
        return false;
    }

    QByteArray saveData = loadFile.readAll();

    QJsonDocument loadDoc(QJsonDocument::fromJson(saveData));
    QJsonArray cueArray = loadDoc.object()["cues"].toArray();
    for(int i = 0; i<cueArray.size(); i++){
        BaseCue *newCue = new BaseCue;
        newCue->load(cueArray[i].toObject());
        cueList.append(newCue);
    }

    QJsonArray qbArray = loadDoc.object()["qbPages"].toArray();
    if(qbArray.size() == 0)
    {
        QuickButtonPage *nextPage = new QuickButtonPage();
        qbPages.append(nextPage);
    }
    else
    {
        for(int i = 0; i < qbArray.size(); i++)
        {
            QJsonObject pageObject = qbArray[i].toObject();
            QuickButtonPage *nextPage = new QuickButtonPage();
            nextPage->load(pageObject);
            qbPages.append(nextPage);
        }
    }

    qDebug() << "Opened";
    return true;
}

bool FileHandler::saveAs(QVector<BaseCue*> &cueList, QVector<QuickButtonPage*> &qbPages, QString path)
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

    saveObject["version"] = "A1.4.0";

    QJsonArray cueArray;
    for(int i = 0; i < cueList.length(); i++)
    {
        BaseCue* cue = cueList.at(i);
        cueArray.append(cue->save());
    }
    saveObject["cues"] = cueArray;

    QJsonArray qbArray;
    for(int i = 0; i < qbPages.length(); i++)
    {
        qbArray.append(qbPages.at(i)->save());
    }
    saveObject["qbPages"] = qbArray;

    QJsonDocument saveDoc(saveObject);
    saveFile.write(saveDoc.toJson());

    qDebug() <<"Saved";

    return true;
}

bool FileHandler::save(QVector<BaseCue*> &cueList, QVector<QuickButtonPage*> &qbPages, QWidget *parent){
    if(m_fileOpen){
        return saveAs(cueList, qbPages, m_openFile);
    }
    else
    {
        QString path = QFileDialog::getSaveFileName(parent, QObject::tr("Save File"),
                                                    "",
                                                    QObject::tr("ScriptCue (*.planksc)"));
        return saveAs(cueList, qbPages, path);
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
