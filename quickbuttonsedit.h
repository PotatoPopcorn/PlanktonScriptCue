#ifndef QUICKBUTTONSEDIT_H
#define QUICKBUTTONSEDIT_H

#include <QDialog>
#include <QVector>

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

private:
    Ui::QuickButtonsEdit *ui;

    QVector<QuickButtonPage*> m_qbPages;
};

#endif // QUICKBUTTONSEDIT_H
