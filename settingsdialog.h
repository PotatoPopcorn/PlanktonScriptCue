#ifndef SETTINGSDIALOG_H
#define SETTINGSDIALOG_H

#include <QDialog>

#include "keyboardhandler.h"

namespace Ui {
class SettingsDialog;
}

class SettingsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SettingsDialog(QWidget *parent = 0);
    ~SettingsDialog();

    void setKeyboardHandler(KeyboardHandler* keyboard);
    KeyboardHandler* updateKeyboardHandler();

private:
    Ui::SettingsDialog *ui;

    KeyboardHandler *m_keyboardHandler;
};

/*TODO:
 * +Key Bindings
 * +Skins
*/
#endif // SETTINGSDIALOG_H
