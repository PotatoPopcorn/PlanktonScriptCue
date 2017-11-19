#ifndef EDITARGUMENTS_H
#define EDITARGUMENTS_H

#include <QDebug>
#include <QDialog>
#include <QFileDialog>
#include <QString>
#include <QVector>

#include "editargument.h"

namespace Ui {
class EditArguments;
}

class EditArguments : public QDialog
{
    Q_OBJECT

public:
    explicit EditArguments(QWidget *parent = 0);
    ~EditArguments();

    QVector<QString> getArgs();
    void setArgs(QVector<QString> args);

private slots:
    void on_addArgButton_clicked();

    void on_addPathButton_clicked();

    void on_editArgButton_clicked();

    void on_removeArgButton_clicked();

    void on_argList_currentRowChanged(int currentRow);

    void on_moveUpArgButton_clicked();

    void on_moveDownArgButton_clicked();

private:
    Ui::EditArguments *ui;
    QVector<QString> m_args;

    EditArgument *argEdit;

    void updateArgs();
};

#endif // EDITARGUMENTS_H
