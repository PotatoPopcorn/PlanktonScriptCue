#include "settingsdialog.h"
#include "ui_settingsdialog.h"

SettingsDialog::SettingsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingsDialog)
{
    ui->setupUi(this);
}

SettingsDialog::~SettingsDialog()
{
    delete ui;
}

void SettingsDialog::setKeyboardHandler(KeyboardHandler* keyboard)
{
    m_keyboardHandler = keyboard;
    ui->nextKeySequenceEdit->setKeySequence(m_keyboardHandler->getNextKey());
    ui->prevKeySequenceEdit->setKeySequence(m_keyboardHandler->getPrevKey());
    ui->startKeySequenceEdit->setKeySequence(m_keyboardHandler->getStartKey());
    ui->stopKeySequenceEdit->setKeySequence(m_keyboardHandler->getStopKey());
    ui->nextQBPageKeySequenceEdit->setKeySequence(m_keyboardHandler->getNextQBPageKey());
    ui->prevQBPageKeySequenceEdit->setKeySequence(m_keyboardHandler->getPrevQBPageKey());
    ui->run0KeySequenceEdit->setKeySequence(m_keyboardHandler->getRun0Key());
    ui->run1KeySequenceEdit->setKeySequence(m_keyboardHandler->getRun1Key());
    ui->run2KeySequenceEdit->setKeySequence(m_keyboardHandler->getRun2Key());
    ui->run3KeySequenceEdit->setKeySequence(m_keyboardHandler->getRun3Key());
    ui->run4KeySequenceEdit->setKeySequence(m_keyboardHandler->getRun4Key());
    ui->run5KeySequenceEdit->setKeySequence(m_keyboardHandler->getRun5Key());
    ui->run6KeySequenceEdit->setKeySequence(m_keyboardHandler->getRun6Key());
    ui->run7KeySequenceEdit->setKeySequence(m_keyboardHandler->getRun7Key());
    ui->run8KeySequenceEdit->setKeySequence(m_keyboardHandler->getRun8Key());
    ui->run9KeySequenceEdit->setKeySequence(m_keyboardHandler->getRun9Key());
}

KeyboardHandler* SettingsDialog::updateKeyboardHandler()
{
    m_keyboardHandler->setNextKey(ui->nextKeySequenceEdit->keySequence());
    m_keyboardHandler->setPrevKey(ui->prevKeySequenceEdit->keySequence());
    m_keyboardHandler->setStartKey(ui->startKeySequenceEdit->keySequence());
    m_keyboardHandler->setStopKey(ui->stopKeySequenceEdit->keySequence());
    m_keyboardHandler->setNextQBPageKey(ui->nextQBPageKeySequenceEdit->keySequence());
    m_keyboardHandler->setPrevQBPageKey(ui->prevQBPageKeySequenceEdit->keySequence());
    m_keyboardHandler->setRun0Key(ui->run0KeySequenceEdit->keySequence());
    m_keyboardHandler->setRun1Key(ui->run1KeySequenceEdit->keySequence());
    m_keyboardHandler->setRun2Key(ui->run2KeySequenceEdit->keySequence());
    m_keyboardHandler->setRun3Key(ui->run3KeySequenceEdit->keySequence());
    m_keyboardHandler->setRun4Key(ui->run4KeySequenceEdit->keySequence());
    m_keyboardHandler->setRun5Key(ui->run5KeySequenceEdit->keySequence());
    m_keyboardHandler->setRun6Key(ui->run6KeySequenceEdit->keySequence());
    m_keyboardHandler->setRun7Key(ui->run7KeySequenceEdit->keySequence());
    m_keyboardHandler->setRun8Key(ui->run8KeySequenceEdit->keySequence());
    m_keyboardHandler->setRun9Key(ui->run9KeySequenceEdit->keySequence());

    return m_keyboardHandler;
}
