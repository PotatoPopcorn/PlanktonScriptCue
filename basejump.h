#ifndef BASEJUMP_H
#define BASEJUMP_H

#include <QObject>
#include <QString>

#include <QJsonObject>

class BaseJump
{
public:
    BaseJump();

    QString getIDName();
    QString getPublicName();

    QString getDetails();

    bool getHasEditPanel();

    QJsonObject getSaveData();
    void loadData(QJsonObject data);


signals:
    void nextCue();

public slots:
    void startCue();
    void openSettings();

protected:
    QString m_idName = "NULL";
    QString m_publicName = "NULL";

    bool m_hasEditPanel = false;
};

#endif // BASEJUMP_H
