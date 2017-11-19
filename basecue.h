#ifndef BASECUE_H
#define BASECUE_H

#include <QDebug>
#include <QString>
#include <QVector>

class BaseCue
{
public:
    BaseCue();

    QString getName();
    QString getProgram();
    QVector<QString> getArguments();

    QString getDisplayName();

    void setCue(QString name, QString program, QVector<QString> arguments);
    void setName(QString name);
    void setProgram(QString program);
    void setArguments(QVector<QString> arguments);
private:
    QString m_Name = "Untitled Cue";
    QString m_Program = "";
    QVector<QString> m_Arguments;
};

#endif // BASECUE_H
