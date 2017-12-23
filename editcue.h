#ifndef EDITCUE_H
#define EDITCUE_H

#include <QDialog>
#include <QFileDialog>
#include <QString>
#include <QVector>

#include "basecue.h"
#include "editarguments.h"

namespace Ui {
class EditCue;
}

class EditCue : public QDialog
{
    Q_OBJECT

public:
    explicit EditCue(QWidget *parent = 0);
    ~EditCue();

    void setCue(BaseCue cue);
    BaseCue getCue();

private slots:
    void on_browseProgramButton_clicked();

    void on_editArgument_clicked();

    void on_jumpSelectBox_currentIndexChanged(const QString &mode);

private:
    Ui::EditCue *ui;
    BaseCue m_Cue;

    EditArguments *m_editArgs;

};

#endif // EDITCUE_H
