#ifndef QUICKBUTTONSEDIT_H
#define QUICKBUTTONSEDIT_H

#include <QDialog>
#include <QString>
#include <QVector>

#include "basecue.h"
#include "editcue.h"
#include "quickbuttonpage.h"

namespace Ui {
class QuickButtonsEdit;
}

class QuickButtonsEdit : public QDialog
{
    Q_OBJECT

public:
    explicit QuickButtonsEdit(QWidget *parent = 0);
    ~QuickButtonsEdit();

    void setQBVector(QVector<QuickButtonPage*> qbVector);
    QVector<QuickButtonPage*> getQBVector();

private slots:
    void on_pageSelectionBox_currentIndexChanged(int index);

    void on_quickCue1Delete_clicked();

    void on_quickCue2Delete_clicked();

    void on_quickCue3Delete_clicked();

    void on_quickCue4Delete_clicked();

    void on_quickCue5Delete_clicked();

    void on_quickCue6Delete_clicked();

    void on_quickCue7Delete_clicked();

    void on_quickCue8Delete_clicked();

    void on_quickCue9Delete_clicked();

    void on_quickCue0Delete_clicked();

    void on_quickCue1Edit_clicked();

    void on_quickCue2Edit_clicked();

    void on_quickCue3Edit_clicked();

    void on_quickCue4Edit_clicked();

    void on_quickCue5Edit_clicked();

    void on_quickCue6Edit_clicked();

    void on_quickCue7Edit_clicked();

    void on_quickCue8Edit_clicked();

    void on_quickCue9Edit_clicked();

    void on_quickCue0Edit_clicked();

private:
    Ui::QuickButtonsEdit *ui;

    QVector<QuickButtonPage*> m_qbPages;

    int m_currentPage = 0;

    void updatePage();
    void editCue(int num);
    QString getTitle(int num);

    EditCue *m_editCue;
};

#endif // QUICKBUTTONSEDIT_H
