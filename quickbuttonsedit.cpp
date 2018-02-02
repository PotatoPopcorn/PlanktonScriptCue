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

void QuickButtonsEdit::setQBVector(QVector<QuickButtonPage *> qbVector)
{
    m_qbPages = qbVector;
    for(int i = 0; i < m_qbPages.length(); ++i){
        ui->pageSelectionBox->addItem("Page " + QString::number(i+1));
    }
}

QVector<QuickButtonPage*> QuickButtonsEdit::getQBVector()
{
    return m_qbPages;
}
