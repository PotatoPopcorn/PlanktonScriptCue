#include "quickbuttonsedit.h"
#include "ui_quickbuttonsedit.h"

QuickButtonsEdit::QuickButtonsEdit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QuickButtonsEdit)
{
    ui->setupUi(this);
}

QuickButtonsEdit::~QuickButtonsEdit()
{
    delete ui;
}
