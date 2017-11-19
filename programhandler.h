#ifndef PROGRAMHANDLER_H
#define PROGRAMHANDLER_H

#include <QDebug>
#include <QObject>
#include <QProcess>
#include <QStringList>
#include "basecue.h"

class ProgramHandler
{
public:
    ProgramHandler();
    void run(BaseCue cue);
    void stop();
private:
    bool m_running = false;
    QObject *parent;
    QProcess *process;
};

#endif // PROGRAMHANDLER_H
