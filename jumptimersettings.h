#ifndef JUMPTIMERSETTINGS_H
#define JUMPTIMERSETTINGS_H

#include <QDialog>

namespace Ui {
class JumpTimerSettings;
}

class JumpTimerSettings : public QDialog
{
    Q_OBJECT

public:
    explicit JumpTimerSettings(QWidget *parent = 0);
    ~JumpTimerSettings();

    void setTime(float time);
    float getTime();

private:
    Ui::JumpTimerSettings *ui;
};

#endif // JUMPTIMERSETTINGS_H
