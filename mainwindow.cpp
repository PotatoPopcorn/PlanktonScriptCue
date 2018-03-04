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
    m_keyboardHandler = new KeyboardHandler(this);
    connect(m_keyboardHandler, SIGNAL(nextPressed()), this, SLOT(nextCue()));
    connect(m_keyboardHandler, SIGNAL(prevPressed()), this, SLOT(prevCue()));
    connect(m_keyboardHandler, SIGNAL(nextQBPagePressed()), this, SLOT(nextQBPage()));
    connect(m_keyboardHandler, SIGNAL(prevQBPagePressed()), this, SLOT(prevQBPage()));
    connect(m_keyboardHandler, SIGNAL(stopPressed()), this, SLOT(stopCues()));
    connect(m_keyboardHandler, SIGNAL(run0Pressed()), this, SLOT(runQB0()));
    connect(m_keyboardHandler, SIGNAL(run1Pressed()), this, SLOT(runQB1()));
    connect(m_keyboardHandler, SIGNAL(run2Pressed()), this, SLOT(runQB2()));
    connect(m_keyboardHandler, SIGNAL(run3Pressed()), this, SLOT(runQB3()));
    connect(m_keyboardHandler, SIGNAL(run4Pressed()), this, SLOT(runQB4()));
    connect(m_keyboardHandler, SIGNAL(run5Pressed()), this, SLOT(runQB5()));
    connect(m_keyboardHandler, SIGNAL(run6Pressed()), this, SLOT(runQB6()));
    connect(m_keyboardHandler, SIGNAL(run7Pressed()), this, SLOT(runQB7()));
    connect(m_keyboardHandler, SIGNAL(run8Pressed()), this, SLOT(runQB8()));
    connect(m_keyboardHandler, SIGNAL(run9Pressed()), this, SLOT(runQB9()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateQuickCues(){
    while(m_qbPages.length() != ui->quickButtonPageBox->count()){
        if(m_qbPages.length() < ui->quickButtonPageBox->count())
        {
            ui->quickButtonPageBox->removeItem(ui->quickButtonPageBox->count()-1);
        }
        else if(m_qbPages.length() > ui->quickButtonPageBox->count())
        {
            ui->quickButtonPageBox->addItem("Page " + QString::number(ui->quickButtonPageBox->count()+1));
        }
    }
    ui->prevPageQuickButton->setEnabled(m_qbActivePage > 0);
    ui->nextPageQuickButton->setEnabled(m_qbActivePage < ui->quickButtonPageBox->count()-1);

    if(m_qbPages.at(m_qbActivePage)->getCueExists(0)){
        ui->quickButton0->setEnabled(true);
        ui->quickButton0->setText(m_qbPages.at(m_qbActivePage)->getCue(0)->getName());
    }
    else
    {
        ui->quickButton0->setEnabled(false);
        ui->quickButton0->setText("None");
    }

    if(m_qbPages.at(m_qbActivePage)->getCueExists(1)){
        ui->quickButton1->setEnabled(true);
        ui->quickButton1->setText(m_qbPages.at(m_qbActivePage)->getCue(1)->getName());
    }
    else
    {
        ui->quickButton1->setEnabled(false);
        ui->quickButton1->setText("None");
    }

    if(m_qbPages.at(m_qbActivePage)->getCueExists(2)){
        ui->quickButton2->setEnabled(true);
        ui->quickButton2->setText(m_qbPages.at(m_qbActivePage)->getCue(2)->getName());
    }
    else
    {
        ui->quickButton2->setEnabled(false);
        ui->quickButton2->setText("None");
    }

    if(m_qbPages.at(m_qbActivePage)->getCueExists(3)){
        ui->quickButton3->setEnabled(true);
        ui->quickButton3->setText(m_qbPages.at(m_qbActivePage)->getCue(3)->getName());
    }
    else
    {
        ui->quickButton3->setEnabled(false);
        ui->quickButton3->setText("None");
    }
    if(m_qbPages.at(m_qbActivePage)->getCueExists(4)){
        ui->quickButton4->setEnabled(true);
        ui->quickButton4->setText(m_qbPages.at(m_qbActivePage)->getCue(4)->getName());
    }
    else
    {
        ui->quickButton4->setEnabled(false);
        ui->quickButton4->setText("None");
    }
    if(m_qbPages.at(m_qbActivePage)->getCueExists(5)){
        ui->quickButton5->setEnabled(true);
        ui->quickButton5->setText(m_qbPages.at(m_qbActivePage)->getCue(5)->getName());
    }
    else
    {
        ui->quickButton5->setEnabled(false);
        ui->quickButton5->setText("None");
    }
    if(m_qbPages.at(m_qbActivePage)->getCueExists(6)){
        ui->quickButton6->setEnabled(true);
        ui->quickButton6->setText(m_qbPages.at(m_qbActivePage)->getCue(6)->getName());
    }
    else
    {
        ui->quickButton6->setEnabled(false);
        ui->quickButton6->setText("None");
    }
    if(m_qbPages.at(m_qbActivePage)->getCueExists(7)){
        ui->quickButton7->setEnabled(true);
        ui->quickButton7->setText(m_qbPages.at(m_qbActivePage)->getCue(7)->getName());
    }
    else
    {
        ui->quickButton7->setEnabled(false);
        ui->quickButton7->setText("None");
    }
    if(m_qbPages.at(m_qbActivePage)->getCueExists(8)){
        ui->quickButton8->setEnabled(true);
        ui->quickButton8->setText(m_qbPages.at(m_qbActivePage)->getCue(8)->getName());
    }
    else
    {
        ui->quickButton8->setEnabled(false);
        ui->quickButton8->setText("None");
    }
    if(m_qbPages.at(m_qbActivePage)->getCueExists(9)){
        ui->quickButton9->setEnabled(true);
        ui->quickButton9->setText(m_qbPages.at(m_qbActivePage)->getCue(9)->getName());
    }
    else
    {
        ui->quickButton9->setEnabled(false);
        ui->quickButton9->setText("None");
    }
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

void MainWindow::stopCues()
{
    //    BaseCue *tCue = m_cues.at(m_activeCueNumber);
    //    tCue->endCue();
        setActiveCue(-1);
}

void MainWindow::nextQBPage()
{
    if(m_qbActivePage+1 < m_qbPages.length())
    {
        ui->quickButtonPageBox->setCurrentIndex(m_qbActivePage+1);
    }
}

void MainWindow::prevQBPage()
{
    if(m_qbActivePage > 0)
    {
        ui->quickButtonPageBox->setCurrentIndex(m_qbActivePage-1);
    }
}

void MainWindow::runQB0()
{
    if(m_qbPages.at(m_qbActivePage)->getCueExists(0))
    {
        m_qbPages.at(m_qbActivePage)->getCue(0)->startCue();
    }
}

void MainWindow::runQB1()
{
    if(m_qbPages.at(m_qbActivePage)->getCueExists(1))
    {
        m_qbPages.at(m_qbActivePage)->getCue(1)->startCue();
    }
}

void MainWindow::runQB2()
{
    if(m_qbPages.at(m_qbActivePage)->getCueExists(2))
    {
        m_qbPages.at(m_qbActivePage)->getCue(2)->startCue();
    }
}

void MainWindow::runQB3()
{
    if(m_qbPages.at(m_qbActivePage)->getCueExists(3))
    {
        m_qbPages.at(m_qbActivePage)->getCue(3)->startCue();
    }
}

void MainWindow::runQB4()
{
    if(m_qbPages.at(m_qbActivePage)->getCueExists(4))
    {
        m_qbPages.at(m_qbActivePage)->getCue(4)->startCue();
    }
}

void MainWindow::runQB5()
{
    if(m_qbPages.at(m_qbActivePage)->getCueExists(5))
    {
        m_qbPages.at(m_qbActivePage)->getCue(5)->startCue();
    }
}

void MainWindow::runQB6()
{
    if(m_qbPages.at(m_qbActivePage)->getCueExists(6))
    {
        m_qbPages.at(m_qbActivePage)->getCue(6)->startCue();
    }
}

void MainWindow::runQB7()
{
    if(m_qbPages.at(m_qbActivePage)->getCueExists(7))
    {
        m_qbPages.at(m_qbActivePage)->getCue(7)->startCue();
    }
}

void MainWindow::runQB8()
{
    if(m_qbPages.at(m_qbActivePage)->getCueExists(8))
    {
        m_qbPages.at(m_qbActivePage)->getCue(8)->startCue();
    }
}

void MainWindow::runQB9()
{
    if(m_qbPages.at(m_qbActivePage)->getCueExists(9))
    {
        m_qbPages.at(m_qbActivePage)->getCue(9)->startCue();
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
    m_qbPages.clear();
    m_qbPages.append(new QuickButtonPage());
    updateCuelist();
    updateQuickCues();

}

void MainWindow::on_actionSettings_triggered()
{
    m_settings = new SettingsDialog();
    m_settings->setKeyboardHandler(m_keyboardHandler);
    if(m_settings->exec())
    {
        m_settings->updateKeyboardHandler();
    }
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
    stopCues();
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
    m_file.save(m_cues, m_qbPages, this);
}

void MainWindow::on_editQuickButton_clicked()
{
    m_quickButtonEdit = new QuickButtonsEdit();
    m_quickButtonEdit->setQBVector(m_qbPages);
    if(m_quickButtonEdit->exec()){
        m_qbPages = m_quickButtonEdit->getQBVector();
        updateQuickCues();
    }
}

void MainWindow::on_actionOpen_triggered()
{
    m_file.open(m_cues, m_qbPages, QFileDialog::getOpenFileName(this, tr("Open"), "", tr("ScriptCue (*.planksc)")));
    updateCuelist();
    updateQuickCues();
}

void MainWindow::on_actionSave_As_triggered()
{
    QString path = QFileDialog::getSaveFileName(this, tr("Save File"),
                                                "",
                                                tr("ScriptCue (*.planksc)"));
    m_file.saveAs(m_cues, m_qbPages, path);
}

void MainWindow::on_quickButtonPageBox_currentIndexChanged(int index)
{
    m_qbActivePage = index;
    updateQuickCues();
}

void MainWindow::on_prevPageQuickButton_clicked()
{
    prevQBPage();
}

void MainWindow::on_nextPageQuickButton_clicked()
{
    nextQBPage();
}

void MainWindow::on_quickButton0_clicked()
{
    runQB0();
}

void MainWindow::on_quickButton1_clicked()
{
    runQB1();
}

void MainWindow::on_quickButton2_clicked()
{
    runQB2();
}

void MainWindow::on_quickButton3_clicked()
{
    runQB3();
}

void MainWindow::on_quickButton4_clicked()
{
    runQB4();
}

void MainWindow::on_quickButton5_clicked()
{
    runQB5();
}

void MainWindow::on_quickButton6_clicked()
{
    runQB6();
}

void MainWindow::on_quickButton7_clicked()
{
    runQB7();
}

void MainWindow::on_quickButton8_clicked()
{
    runQB8();
}

void MainWindow::on_quickButton9_clicked()
{
    runQB9();
}
