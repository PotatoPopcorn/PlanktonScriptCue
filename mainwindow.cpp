#include "mainwindow.h"
#include "ui_mainwindow.h"

//TODO Comment Code

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_activeCue = new BaseCue();
    connect(m_activeCue, SIGNAL(nextCue()), this, SLOT(nextCue()));
    m_qbPages.append(new QuickButtonPage());
    for(int i = 0; i < m_qbPages.length(); ++i){
        ui->quickButtonPageBox->addItem("Page " + QString::number(i+1));
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::nextCue()
{
    if(m_activeCueNumber +1 < m_cues.length()){
        setActiveCue(m_activeCueNumber +1);
    }
    else
    {
        qDebug() << "At End Of Cuelist";
    }
}

void MainWindow::prevCue()
{
    if(m_activeCueNumber != 0)
    {
        setActiveCue(m_activeCueNumber -1);
    }
}


//Re-render cuelist, used to keep vector the same as GUI
void MainWindow::updateCuelist()
{
    ui->cueListWidget->clear();
    for(int i = 0; i < m_cues.length(); i++)
    {   
        ui->cueListWidget->addItem(QString(m_cues[i]->getDisplayName()));
    }
    if(m_cues.length() > m_activeCueNumber+1 && m_activeCueNumber != -1)
    {
        ui->cueListWidget->setCurrentRow(m_activeCueNumber+1);
        ui->cueListWidget->currentItem()->setTextColor(QColor(255, 127 ,0));
    }
    if(m_cues.length() > m_activeCueNumber && m_activeCueNumber != -1)
    {
        ui->cueListWidget->setCurrentRow(m_activeCueNumber);
        ui->cueListWidget->currentItem()->setTextColor(QColor(0,255,0));
        ui->cueListWidget->setCurrentRow(m_activeCueNumber);
    }

    ui->editCueButton->setEnabled(false);
    ui->removeCueButton->setEnabled(false);
    ui->moveCueDownButton->setEnabled(false);
    ui->moveCueUpButton->setEnabled(false);
    ui->startButton->setEnabled(false);
}

//Update Active Cue, Ensures appropriate buttons are up to date.
void MainWindow::setActiveCue(int i)
{
    if(i > m_cues.length())
    {
        qDebug() << "WARN: Set Active Cue is Out of Bounds";
        return;
    }
    m_activeCue->endCue();
    disconnect(m_activeCue, SIGNAL(nextCue()), this, SLOT(nextCue()));
    m_activeCueNumber = i;
    if(i >= 0)
    {
        m_activeCue = m_cues.at(m_activeCueNumber);
        connect(m_activeCue, SIGNAL(nextCue()), this, SLOT(nextCue()));
        m_activeCue->startCue();
    }
    updateCuelist();
    if(i == -1)
    {
        ui->nextButton->setEnabled(false);
        ui->prevButton->setEnabled(false);
        ui->stopButton->setEnabled(false);
        ui->addCueButton->setEnabled(true);
    }
    else
    {
        ui->nextButton->setEnabled(true);
        ui->prevButton->setEnabled(true);
        ui->stopButton->setEnabled(true);
        ui->addCueButton->setEnabled(false);
        ui->editCueButton->setEnabled(false);
        ui->removeCueButton->setEnabled(false);
        ui->moveCueDownButton->setEnabled(false);
        ui->moveCueUpButton->setEnabled(false);
        ui->startButton->setEnabled(false);
    }
    if (i == m_cues.length()-1)
    {
        ui->nextButton->setEnabled(false);
    }
    if (i == 0)
    {
        ui->prevButton->setEnabled(false);
    }

}

//Start GUI Button Handlers
void MainWindow::on_editCueButton_clicked()
{
    int cueNum = ui->cueListWidget->currentIndex().row();
    BaseCue *cue = m_cues.at(cueNum);
    m_editCue = new EditCue(this);
    m_editCue->setCue(cue);
    if(m_editCue->exec())
    {
        m_cues.replace(cueNum, m_editCue->getCue());
    }
    updateCuelist();
}

void MainWindow::on_addCueButton_clicked()
{
    //TODO: Disable when playing
    //TODO: Add in selected position
    BaseCue *cue = new BaseCue;
    m_editCue = new EditCue(this);
    m_editCue->setCue(cue);
    if(m_editCue->exec())
    {
        cue = m_editCue->getCue();
        m_cues.push_back(cue);
    }
    updateCuelist();
}

void MainWindow::on_removeCueButton_clicked()
{
    //TODO Ask if sure cue delete is wanted
    int cueNum = ui->cueListWidget->currentIndex().row();
    m_cues.removeAt(cueNum);
    updateCuelist();
}

void MainWindow::on_actionNew_triggered()
{
    //TODO: Ask if user wants to save / sure want to create new file
    m_cues.clear();
    m_file.setFileOpen(false);
    updateCuelist();
}

void MainWindow::on_actionSettings_triggered()
{
    m_settings = new SettingsDialog();
    m_settings->exec();
}

void MainWindow::on_cueListWidget_currentRowChanged(int currentRow)
{
    if(m_activeCueNumber != -1){
        return;
    }
    else
    {
        ui->addCueButton->setEnabled(true);
    }
    if(currentRow == -1)
    {
        ui->editCueButton->setEnabled(false);
        ui->removeCueButton->setEnabled(false);
        ui->moveCueDownButton->setEnabled(false);
        ui->moveCueUpButton->setEnabled(false);
        ui->startButton->setEnabled(false);
    }
    else
    {
        if(currentRow == 0)
        {
            ui->moveCueUpButton->setEnabled(false);
        }
        else
        {
            ui->moveCueUpButton->setEnabled(true);
        }

        if(currentRow == m_cues.length() -1)
        {
            ui->moveCueDownButton->setEnabled(false);
        }
        else
        {
            ui->moveCueDownButton->setEnabled(true);
        }
        ui->editCueButton->setEnabled(true);
        ui->removeCueButton->setEnabled(true);
        ui->startButton->setEnabled(true);
    }
}

void MainWindow::on_moveCueUpButton_clicked()
{
    int cueNum = ui->cueListWidget->currentIndex().row();
    m_cues.move(cueNum, cueNum -1);
    updateCuelist();
    ui->cueListWidget->setCurrentRow(cueNum -1);
}

void MainWindow::on_moveCueDownButton_clicked()
{
    int cueNum = ui->cueListWidget->currentIndex().row();
    m_cues.move(cueNum, cueNum +1);
    updateCuelist();
    ui->cueListWidget->setCurrentRow(cueNum +1);
}

void MainWindow::on_stopButton_clicked()
{
//    BaseCue *tCue = m_cues.at(m_activeCueNumber);
//    tCue->endCue();
    setActiveCue(-1);
}

void MainWindow::on_startButton_clicked()
{
    setActiveCue(ui->cueListWidget->currentRow());
//    BaseCue *uCue = m_cues.at(m_activeCueNumber);
//    uCue->startCue();
}

void MainWindow::on_nextButton_clicked()
{
    nextCue();
}

void MainWindow::on_prevButton_clicked()
{
    prevCue();
}

void MainWindow::on_actionSave_triggered()
{
    m_file.save(m_cues, this);
}

void MainWindow::on_editQuickButton_clicked()
{
    m_quickButtonEdit = new QuickButtonsEdit();
    m_quickButtonEdit->setQBVector(m_qbPages);
    if(m_quickButtonEdit->exec()){

    }
}

void MainWindow::on_actionOpen_triggered()
{
    m_file.open(m_cues, QFileDialog::getOpenFileName(this, tr("Open"), "", tr("ScriptCue (*.planksc)")));
    updateCuelist();
}

void MainWindow::on_actionSave_As_triggered()
{
    QString path = QFileDialog::getSaveFileName(this, tr("Save File"),
                                                "",
                                                tr("ScriptCue (*.planksc)"));
    m_file.saveAs(m_cues, path);
}
