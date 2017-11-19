#ifndef EDITARGUMENT_H
#define EDITARGUMENT_H

#include <QDialog>
#include <QString>

namespace Ui {
class EditArgument;
}

class EditArgument : public QDialog
{
    Q_OBJECT

public:
    explicit EditArgument(QWidget *parent = 0);
    ~EditArgument();

    QString getText();
    void setText(QString arg);

private:
    Ui::EditArgument *ui;
};

#endif // EDITARGUMENT_H
