#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QColor>
#include <QDebug>
#include <QFileDialog>
#include <QMainWindow>
#include <QVector>

#include "basecue.h"
#include "editcue.h"
#include "filehandler.h"
#include "programhandler.h"
#include "quickbuttonsedit.h"
#include "settingsdialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_editCueButton_clicked();

    void on_addCueButton_clicked();

    void on_removeCueButton_clicked();

    void on_actionNew_triggered();

    void on_actionSettings_triggered();

    void on_cueListWidget_currentRowChanged(int currentRow);

    void on_moveCueUpButton_clicked();

    void on_moveCueDownButton_clicked();

    void on_stopButton_clicked();

    void on_startButton_clicked();

    void on_nextButton_clicked();

    void on_prevButton_clicked();

    void on_actionSave_triggered();

    void on_editQuickButton_clicked();

    void on_actionOpen_triggered();

    void on_actionSave_As_triggered();

private:
    int m_activeCue = -1;

    Ui::MainWindow *ui;
    QVector<BaseCue> m_cues;

    EditCue *m_editCue;
    FileHandler m_file;
    ProgramHandler m_program;
    QuickButtonsEdit *m_quickButtonEdit;
    SettingsDialog *m_settings;


    void updateCuelist();
    void setActiveCue(int i);

};

/*TODO:
 * UI:
 * +Undo/Redo
 * +Cut, Copy and Paste Cues
 *
 * Cues:
 * +Templates
*/
#endif // MAINWINDOW_H
