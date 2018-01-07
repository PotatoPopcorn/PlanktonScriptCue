#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <QByteArray>
#include <QDebug>
#include <QFile>
#include <QFileDialog>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QString>
#include <QStringList>
#include <QVector>
#include <QWidget>

#include "basecue.h"

class FileHandler
{
public:
    FileHandler();
    bool open(QVector<BaseCue*> &cueList, QString path);
    bool save(QVector<BaseCue*> &cueList, QWidget *parent);
    bool saveAs(QVector<BaseCue*> &cueList, QString path);

    bool isFileOpen();
    QString getOpenFile();
    void setFileOpen(bool tf);

private:
    bool m_fileOpen = false;
    QString m_openFile = "";
};

#endif // FILEHANDLER_H
