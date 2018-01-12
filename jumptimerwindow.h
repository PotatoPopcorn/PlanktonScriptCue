#ifndef JUMPTIMERWINDOW_H
#define JUMPTIMERWINDOW_H

#include <QDebug>
#include <QDialog>
#include <QString>
#include <QTimer>

namespace Ui {
class JumpTimerWindow;
}

class JumpTimerWindow : public QDialog
{
    Q_OBJECT

public:
    explicit JumpTimerWindow(QWidget *parent = 0);
    ~JumpTimerWindow();

    void setQTimer(QTimer *timer);
    void startBackground();
    void stopBackground();

public slots:
    void updateUI();

private:
    Ui::JumpTimerWindow *ui;

    QTimer *m_Timer;
    QTimer *m_UpdateTimer;
};

#endif // JUMPTIMERWINDOW_H
