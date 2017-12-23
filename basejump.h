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

    virtual QString getDetails();

    bool getHasEditPanel();

    virtual QJsonObject getSaveData();
    virtual void loadData(QJsonObject data);


signals:
    void nextCue();

public slots:
    virtual void startCue();
    virtual void openSettings();

protected:
    QString m_idName = "NULL";
    QString m_publicName = "NULL";

    bool m_hasEditPanel = false;
};

#endif // BASEJUMP_H
