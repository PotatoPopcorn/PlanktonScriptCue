#ifndef BASECUE_H
#define BASECUE_H

#include <QDebug>
#include <QJsonArray>
#include <QJsonObject>
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

    bool getEndOnNext();
    bool getJumpOnEnd();
    bool isQuickButton();
    QString getName();
    QString getProgram();
    QVector<QString> getArguments();
    BaseJump* getJumpSettingPtr();

    QString getDisplayName();

    void setCue(QString name, QString program, QVector<QString> arguments, QString jumpModeID, bool endOnNext, bool jumpOnEnd);
    void setName(QString name);
    void setProgram(QString program);
    void setArguments(QVector<QString> arguments);
    void setJumpModeID(QString jumpModeID);
    void setJumpSettingData(QJsonObject);
    void setEndOnNext(bool value);
    void setJumpOnEnd(bool value);
    void setIsQuickButton(bool value);

    QJsonObject save();
    void load(QJsonObject data);

signals:
    void nextCue();

public slots:
    void startCue();
    void callNextCue();
    void endCue();
    void finishedCue();

private:
    bool m_EndOnNext = true;
    bool m_JumpOnEnd = false;
    bool m_isQuickButton = false;

    QString m_Name = "Untitled Cue";
    QString m_Program = "";
    QVector<QString> m_Arguments;
    BaseJump *m_JumpSetting = new JumpNone;

    QJsonObject m_JumpData;

    QObject *procParent;
    QProcess *process;

};

#endif // BASECUE_H
