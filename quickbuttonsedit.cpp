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

QString QuickButtonsEdit::getTitle(int num)
{
    QString retString = "QC " + QString::number(num) + ": ";
    if(m_qbPages.at(m_currentPage)->getCueExists(num))
    {
        retString.append(m_qbPages.at(m_currentPage)->getCue(num)->getDisplayName());
    }
    else
    {
        retString.append("None");
    }
    return retString;
}

void QuickButtonsEdit::updatePage()
{
    QuickButtonPage *page = m_qbPages.at(m_currentPage);
    ui->quickCue0Label->setText(getTitle(0));
    ui->quickCue1Label->setText(getTitle(1));
    ui->quickCue2Label->setText(getTitle(2));
    ui->quickCue3Label->setText(getTitle(3));
    ui->quickCue4Label->setText(getTitle(4));
    ui->quickCue5Label->setText(getTitle(5));
    ui->quickCue6Label->setText(getTitle(6));
    ui->quickCue7Label->setText(getTitle(7));
    ui->quickCue8Label->setText(getTitle(8));
    ui->quickCue9Label->setText(getTitle(9));
    ui->quickCue0Delete->setEnabled(page->getCueExists(0));
    ui->quickCue1Delete->setEnabled(page->getCueExists(1));
    ui->quickCue2Delete->setEnabled(page->getCueExists(2));
    ui->quickCue3Delete->setEnabled(page->getCueExists(3));
    ui->quickCue4Delete->setEnabled(page->getCueExists(4));
    ui->quickCue5Delete->setEnabled(page->getCueExists(5));
    ui->quickCue6Delete->setEnabled(page->getCueExists(6));
    ui->quickCue7Delete->setEnabled(page->getCueExists(7));
    ui->quickCue8Delete->setEnabled(page->getCueExists(8));
    ui->quickCue9Delete->setEnabled(page->getCueExists(9));
}

void QuickButtonsEdit::editCue(int num)
{
    BaseCue *cue = new BaseCue();
    if(m_qbPages.at(m_currentPage)->getCueExists(num))
    {
        cue = m_qbPages.at(m_currentPage)->getCue(num);
    }
    m_editCue = new EditCue(this);
    cue->setIsQuickButton(true);
    m_editCue->setCue(cue);
    if(m_editCue->exec())
    {
        cue = m_editCue->getCue();
        cue->setIsQuickButton(true);
        m_qbPages.at(m_currentPage)->setCue(cue, num);
    }
    updatePage();
}

void QuickButtonsEdit::on_pageSelectionBox_currentIndexChanged(int index)
{
    m_currentPage = index;
    updatePage();
}

void QuickButtonsEdit::on_quickCue1Delete_clicked()
{
    m_qbPages.at(m_currentPage)->removeCue(1);
    updatePage();
}

void QuickButtonsEdit::on_quickCue2Delete_clicked()
{
    m_qbPages.at(m_currentPage)->removeCue(2);
    updatePage();
}

void QuickButtonsEdit::on_quickCue3Delete_clicked()
{
    m_qbPages.at(m_currentPage)->removeCue(3);
    updatePage();
}

void QuickButtonsEdit::on_quickCue4Delete_clicked()
{
    m_qbPages.at(m_currentPage)->removeCue(4);
    updatePage();
}

void QuickButtonsEdit::on_quickCue5Delete_clicked()
{
    m_qbPages.at(m_currentPage)->removeCue(5);
    updatePage();
}

void QuickButtonsEdit::on_quickCue6Delete_clicked()
{
    m_qbPages.at(m_currentPage)->removeCue(6);
    updatePage();
}

void QuickButtonsEdit::on_quickCue7Delete_clicked()
{
    m_qbPages.at(m_currentPage)->removeCue(7);
    updatePage();
}

void QuickButtonsEdit::on_quickCue8Delete_clicked()
{
    m_qbPages.at(m_currentPage)->removeCue(8);
    updatePage();
}

void QuickButtonsEdit::on_quickCue9Delete_clicked()
{
    m_qbPages.at(m_currentPage)->removeCue(9);
    updatePage();
}

void QuickButtonsEdit::on_quickCue0Delete_clicked()
{
    m_qbPages.at(m_currentPage)->removeCue(0);
    updatePage();
}

void QuickButtonsEdit::on_quickCue1Edit_clicked()
{
    editCue(1);
}

void QuickButtonsEdit::on_quickCue2Edit_clicked()
{
    editCue(2);
}

void QuickButtonsEdit::on_quickCue3Edit_clicked()
{
    editCue(3);
}

void QuickButtonsEdit::on_quickCue4Edit_clicked()
{
    editCue(4);
}

void QuickButtonsEdit::on_quickCue5Edit_clicked()
{
    editCue(5);
}

void QuickButtonsEdit::on_quickCue6Edit_clicked()
{
    editCue(6);
}

void QuickButtonsEdit::on_quickCue7Edit_clicked()
{
    editCue(7);
}

void QuickButtonsEdit::on_quickCue8Edit_clicked()
{
    editCue(8);
}

void QuickButtonsEdit::on_quickCue9Edit_clicked()
{
    editCue(9);
}

void QuickButtonsEdit::on_quickCue0Edit_clicked()
{
    editCue(0);
}
