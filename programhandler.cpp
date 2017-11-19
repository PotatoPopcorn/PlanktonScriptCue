#include "programhandler.h"

ProgramHandler::ProgramHandler()
{
    process=new QProcess(parent);
}

void ProgramHandler::run(BaseCue cue)
{
    qDebug() << "Starting process...";
    QString name = cue.getProgram();
    QStringList args;
    for(int i = 0; i < cue.getArguments().length(); i++)
    {
        args.append(cue.getArguments().at(i));
    }
    process->start(name, args);
    //qDebug() << "Error: " << process->errorString();
    qDebug() << "Started process: " << process->program();
    //qDebug() << "Args: " << process->arguments();
    //qDebug() << "Args: " << process->arguments();
}

void ProgramHandler::stop()
{
    process->kill();
}
