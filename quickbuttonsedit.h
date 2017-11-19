#ifndef QUICKBUTTONSEDIT_H
#define QUICKBUTTONSEDIT_H

#include <QDialog>

namespace Ui {
class QuickButtonsEdit;
}

class QuickButtonsEdit : public QDialog
{
    Q_OBJECT

public:
    explicit QuickButtonsEdit(QWidget *parent = 0);
    ~QuickButtonsEdit();

private:
    Ui::QuickButtonsEdit *ui;
};

#endif // QUICKBUTTONSEDIT_H
