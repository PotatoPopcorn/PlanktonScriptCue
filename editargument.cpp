#include "editargument.h"
#include "ui_editargument.h"

/*
 * This class creates a window to edit arguments
 */

EditArgument::EditArgument(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditArgument)
{
    ui->setupUi(this);
}

EditArgument::~EditArgument()
{
    delete ui;
}

QString EditArgument::getText()
{
    return ui->argEdit->text();
}

void EditArgument::setText(QString arg)
{
    ui->argEdit->setText(arg);
}
