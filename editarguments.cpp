#include "editarguments.h"
#include "ui_editarguments.h"

EditArguments::EditArguments(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditArguments)
{
    ui->setupUi(this);
}

EditArguments::~EditArguments()
{
    delete ui;
}

void EditArguments::on_addArgButton_clicked()
{
    argEdit = new EditArgument;
    argEdit->exec();
    m_args.append(argEdit->getText());
    updateArgs();
}

void EditArguments::on_addPathButton_clicked()
{
    m_args.append(QFileDialog::getOpenFileName(this, tr("Open File"),
                                               "",
                                               tr("All Files (*)")));
    updateArgs();
}

void EditArguments::on_editArgButton_clicked()
{
    ui->editArgButton->setEnabled(false);
    ui->removeArgButton->setEnabled(false);
    argEdit = new EditArgument;
    argEdit->setText(ui->argList->currentItem()->text());
    argEdit->exec();
    m_args.replace(ui->argList->currentIndex().row(), argEdit->getText());
    updateArgs();
}

void EditArguments::on_removeArgButton_clicked()
{
    ui->editArgButton->setEnabled(false);
    ui->removeArgButton->setEnabled(false);
    m_args.removeAt(ui->argList->currentIndex().row());
    updateArgs();
}

void EditArguments::updateArgs()
{
    ui->argList->clear();
    for(int i = 0; i < m_args.length(); i++)
    {
        ui->argList->addItem(m_args.at(i));
    }
    if(m_args.length() > 0){

    }
    else
    {
        ui->moveUpArgButton->setEnabled(false);
        ui->moveDownArgButton->setEnabled(false);
        ui->editArgButton->setEnabled(false);
        ui->removeArgButton->setEnabled(false);
    }
}

QVector<QString> EditArguments::getArgs(){
    return m_args;
}

void EditArguments::setArgs(QVector<QString> args)
{

    m_args.clear();
    for (int i = 0; i < args.length(); i++){
        m_args.append(args.at(i));
    }
    updateArgs();
}

void EditArguments::on_argList_currentRowChanged(int currentRow)
{
    if(currentRow== -1){
        ui->editArgButton->setEnabled(false);
        ui->removeArgButton->setEnabled(false);
        ui->moveUpArgButton->setEnabled(false);
        ui->moveDownArgButton->setEnabled(false);
        return;
    }
    ui->editArgButton->setEnabled(true);
    ui->removeArgButton->setEnabled(true);
    if(currentRow == 0)
    {
        ui->moveUpArgButton->setEnabled(false);
    }
    else
    {
        ui->moveUpArgButton->setEnabled(true);
    }

    if(currentRow == m_args.length() -1)
    {
           ui->moveDownArgButton->setEnabled(false);
    }
    else
    {
           ui->moveDownArgButton->setEnabled(true);
    }

}

void EditArguments::on_moveUpArgButton_clicked()
{
    int i = ui->argList->currentRow();
    m_args.move(i, i-1);
    updateArgs();
    ui->argList->setCurrentRow(i-1);
}

void EditArguments::on_moveDownArgButton_clicked()
{
    int i = ui->argList->currentRow();
    m_args.move(i, i+1);
    updateArgs();
    ui->argList->setCurrentRow(i+1);
}
