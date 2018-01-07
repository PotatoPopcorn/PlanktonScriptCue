#ifndef BASECUE_H
#define BASECUE_H

#include <QDebug>
#include <QObject>
#include <QProcess>
#include <QString>
#include <QStringList>
#include <QVector>

#include "jumpnone.h"
#include "jumptimer.h"

class BaseCue : public QObject
{
    Q_OBJECT
public:
    BaseCue();

    QString getName();
    QString getProgram();
    QVector<QString> getArguments();
    BaseJump* getJumpSettingPtr();

    QString getDisplayName();

    void setCue(QString name, QString program, QVector<QString> arguments, QString jumpModeID);
    void setName(QString name);
    void setProgram(QString program);
    void setArguments(QVector<QString> arguments);
    void setJumpModeID(QString jumpModeID);
    void setJumpSettingData(QJsonObject);

signals:
    void nextCue();

public slots:
    void startCue();
    void callNextCue();
    void endCue();

private:
    QString m_Name = "Untitled Cue";
    QString m_Program = "";
    QVector<QString> m_Arguments;
    BaseJump *m_JumpSetting = new JumpNone;

    QJsonObject m_JumpData;

    QObject *procParent;
    QProcess *process;

};

#endif // BASECUE_H
