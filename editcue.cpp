#include "editcue.h"
#include "ui_editcue.h"

EditCue::EditCue(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditCue)
{
    ui->setupUi(this);
    m_editArgs = new EditArguments();
    ui->jumpSelectBox->addItem("None");
    ui->jumpSelectBox->addItem("Timer");
}

EditCue::~EditCue()
{
    delete ui;
}

void EditCue::setCue(BaseCue *cue)
{
    m_Cue = cue;
    ui->nameEdit->setText(m_Cue->getName());
    ui->programEdit->setText(m_Cue->getProgram());
    m_editArgs->setArgs(m_Cue->getArguments());
    if(m_Cue->getJumpSettingPtr()->getIDName() == "TIMER"){
        ui->jumpSelectBox->setCurrentText("Timer");
    }else{
        ui->jumpSelectBox->setCurrentText("None");
    }
    ui->jumpOnEndCheckBox->setChecked(m_Cue->getJumpOnEnd());
    ui->endOnNextCheckBox->setChecked(m_Cue->getEndOnNext());
    if(m_Cue->isQuickButton()){
        ui->jumpSelectBox->setEnabled(false);
        ui->editJumpButton->setEnabled(false);
        ui->jumpOnEndCheckBox->setEnabled(false);
        ui->endOnNextCheckBox->setEnabled(false);

        ui->jumpOnEndCheckBox->setChecked(false);
        ui->endOnNextCheckBox->setChecked(false);

    }

}

BaseCue* EditCue::getCue()
{
    //TODO: Use pointers to optimise code
    m_Cue->setName(ui->nameEdit->text());
    m_Cue->setProgram(ui->programEdit->text());
    m_Cue->setArguments(m_editArgs->getArgs()); //TODO Fix This
    if(ui->jumpSelectBox->currentText() == "Timer"){
        m_Cue->setJumpModeID("TIMER");
    }else{
        m_Cue->setJumpModeID("NONE");
    }
    m_Cue->setJumpOnEnd(ui->jumpOnEndCheckBox->checkState() == Qt::Checked);
    m_Cue->setEndOnNext(ui->endOnNextCheckBox->checkState() == Qt::Checked);

    return m_Cue;
}

void EditCue::on_browseProgramButton_clicked()
{
    QString newPath = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                   "",
                                                   tr("All Files (*)"));
    ui->programEdit->setText(ui->programEdit->text().append(newPath));
}

void EditCue::on_editArgument_clicked()
{
    m_editArgs->exec();
}

void EditCue::on_jumpSelectBox_currentIndexChanged(const QString &mode)
{
    if(mode == "None"){
        ui->editJumpButton->setEnabled(false);
    }else if(mode == "Timer"){
        ui->editJumpButton->setEnabled(true);

    }else{
        qDebug() << "Edit Cue is incorrect";
    }
}

void EditCue::on_editJumpButton_clicked()
{
    if(ui->jumpSelectBox->currentText() == "Timer"){
        m_Cue->setJumpModeID("TIMER");
    }else{
        m_Cue->setJumpModeID("NONE");
    }
    m_Cue->getJumpSettingPtr()->openSettings();
}
