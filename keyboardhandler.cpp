#include "keyboardhandler.h"

KeyboardHandler::KeyboardHandler(QWidget *parent)
{
    QSettings m_settings("Plankton", "ScriptCue");
    m_nextKey = QKeySequence(m_settings.value("keyboardShortcuts/nextKey").toString());
    m_prevKey = QKeySequence(m_settings.value("keyboardShortcuts/prevKey").toString());
    m_startKey = QKeySequence(m_settings.value("keyboardShortcuts/startKey").toString());
    m_stopKey = QKeySequence(m_settings.value("keyboardShortcuts/stopKey").toString());
    m_nextQBPageKey = QKeySequence(m_settings.value("keyboardShortcuts/nextQBPageKey").toString());
    m_prevQBPageKey = QKeySequence(m_settings.value("keyboardShortcuts/prevQBPageKey").toString());
    m_run0Key = QKeySequence(m_settings.value("keyboardShortcuts/runQB0Key").toString());
    m_run1Key = QKeySequence(m_settings.value("keyboardShortcuts/runQB1Key").toString());
    m_run2Key = QKeySequence(m_settings.value("keyboardShortcuts/runQB2Key").toString());
    m_run3Key = QKeySequence(m_settings.value("keyboardShortcuts/runQB3Key").toString());
    m_run4Key = QKeySequence(m_settings.value("keyboardShortcuts/runQB4Key").toString());
    m_run5Key = QKeySequence(m_settings.value("keyboardShortcuts/runQB5Key").toString());
    m_run6Key = QKeySequence(m_settings.value("keyboardShortcuts/runQB6Key").toString());
    m_run7Key = QKeySequence(m_settings.value("keyboardShortcuts/runQB7Key").toString());
    m_run8Key = QKeySequence(m_settings.value("keyboardShortcuts/runQB8Key").toString());
    m_run9Key = QKeySequence(m_settings.value("keyboardShortcuts/runQB9Key").toString());

    m_nextShortcut = new QShortcut(m_nextKey, parent);
    m_prevShortcut = new QShortcut(m_prevKey, parent);
    m_startShortcut = new QShortcut(m_startKey, parent);
    m_stopShortcut = new QShortcut(m_stopKey, parent);
    m_nextQBPageShortcut = new QShortcut(m_nextQBPageKey, parent);
    m_prevQBPageShortcut = new QShortcut(m_prevQBPageKey, parent);
    m_run0Shortcut = new QShortcut(m_run0Key, parent);
    m_run1Shortcut = new QShortcut(m_run1Key, parent);
    m_run2Shortcut = new QShortcut(m_run2Key, parent);
    m_run3Shortcut = new QShortcut(m_run3Key, parent);
    m_run4Shortcut = new QShortcut(m_run4Key, parent);
    m_run5Shortcut = new QShortcut(m_run5Key, parent);
    m_run6Shortcut = new QShortcut(m_run6Key, parent);
    m_run7Shortcut = new QShortcut(m_run7Key, parent);
    m_run8Shortcut = new QShortcut(m_run8Key, parent);
    m_run9Shortcut = new QShortcut(m_run9Key, parent);

    connect(m_nextShortcut, SIGNAL(activated()), this, SLOT(emitNextPressed()));
    connect(m_prevShortcut, SIGNAL(activated()), this, SLOT(emitPrevPressed()));
    connect(m_startShortcut, SIGNAL(activated()), this, SLOT(emitStartPressed()));
    connect(m_stopShortcut, SIGNAL(activated()), this, SLOT(emitStopPressed()));
    connect(m_nextQBPageShortcut, SIGNAL(activated()), this, SLOT(emitNextQBPagePressed()));
    connect(m_prevQBPageShortcut, SIGNAL(activated()), this, SLOT(emitPrevQBPagePressed()));
    connect(m_run0Shortcut, SIGNAL(activated()), this, SLOT(emitRun0Pressed()));
    connect(m_run1Shortcut, SIGNAL(activated()), this, SLOT(emitRun1Pressed()));
    connect(m_run2Shortcut, SIGNAL(activated()), this, SLOT(emitRun2Pressed()));
    connect(m_run3Shortcut, SIGNAL(activated()), this, SLOT(emitRun3Pressed()));
    connect(m_run4Shortcut, SIGNAL(activated()), this, SLOT(emitRun4Pressed()));
    connect(m_run5Shortcut, SIGNAL(activated()), this, SLOT(emitRun5Pressed()));
    connect(m_run6Shortcut, SIGNAL(activated()), this, SLOT(emitRun6Pressed()));
    connect(m_run7Shortcut, SIGNAL(activated()), this, SLOT(emitRun7Pressed()));
    connect(m_run8Shortcut, SIGNAL(activated()), this, SLOT(emitRun8Pressed()));
    connect(m_run9Shortcut, SIGNAL(activated()), this, SLOT(emitRun9Pressed()));

}

QKeySequence KeyboardHandler::getNextKey()
{
    return m_nextKey;
}

void KeyboardHandler::setNextKey(QKeySequence key)
{
    m_nextKey = key;
    m_nextShortcut->setKey(m_nextKey);
    QSettings m_settings("Plankton", "ScriptCue");
    m_settings.setValue("keyboardShortcuts/nextKey", m_nextKey.toString());
}

QKeySequence KeyboardHandler::getPrevKey()
{
    return m_prevKey;
}

void KeyboardHandler::setPrevKey(QKeySequence key)
{
    m_prevKey = key;
    m_prevShortcut->setKey(m_prevKey);
    QSettings m_settings("Plankton", "ScriptCue");
    m_settings.setValue("keyboardShortcuts/prevKey", m_prevKey.toString());
}

QKeySequence KeyboardHandler::getStartKey()
{
    return m_startKey;
}

void KeyboardHandler::setStartKey(QKeySequence key)
{
    m_startKey = key;
    m_startShortcut->setKey(m_startKey);
    QSettings m_settings("Plankton", "ScriptCue");
    m_settings.setValue("keyboardShortcuts/startKey", m_startKey.toString());
}

QKeySequence KeyboardHandler::getStopKey()
{
    return m_stopKey;
}

void KeyboardHandler::setStopKey(QKeySequence key)
{
    m_stopKey = key;
    m_stopShortcut->setKey(m_stopKey);
    QSettings m_settings("Plankton", "ScriptCue");
    m_settings.setValue("keyboardShortcuts/stopKey", m_stopKey.toString());
}

QKeySequence KeyboardHandler::getNextQBPageKey()
{
    return m_nextQBPageKey;
}

void KeyboardHandler::setNextQBPageKey(QKeySequence key)
{
    m_nextQBPageKey = key;
    m_nextQBPageShortcut->setKey(m_nextQBPageKey);
    QSettings m_settings("Plankton", "ScriptCue");
    m_settings.setValue("keyboardShortcuts/nextQBPageKey", m_nextQBPageKey.toString());
}

QKeySequence KeyboardHandler::getPrevQBPageKey()
{
    return m_prevQBPageKey;
}

void KeyboardHandler::setPrevQBPageKey(QKeySequence key)
{
    m_prevQBPageKey = key;
    m_prevQBPageShortcut->setKey(m_prevQBPageKey);
    QSettings m_settings("Plankton", "ScriptCue");
    m_settings.setValue("keyboardShortcuts/prevQBPageKey", m_prevQBPageKey.toString());
}

QKeySequence KeyboardHandler::getRun0Key()
{
    return m_run0Key;
}

void KeyboardHandler::setRun0Key(QKeySequence key)
{
    m_run0Key = key;
    m_run0Shortcut->setKey(m_run0Key);
    QSettings m_settings("Plankton", "ScriptCue");
    m_settings.setValue("keyboardShortcuts/runQB0Key", m_run0Key.toString());
}

QKeySequence KeyboardHandler::getRun1Key()
{
    return m_run1Key;
}

void KeyboardHandler::setRun1Key(QKeySequence key)
{
    m_run1Key = key;
    m_run1Shortcut->setKey(m_run1Key);
    QSettings m_settings("Plankton", "ScriptCue");
    m_settings.setValue("keyboardShortcuts/runQB1Key", m_run1Key.toString());
}

QKeySequence KeyboardHandler::getRun2Key()
{
    return m_run2Key;
}

void KeyboardHandler::setRun2Key(QKeySequence key)
{
    m_run2Key = key;
    m_run2Shortcut->setKey(m_run2Key);
    QSettings m_settings("Plankton", "ScriptCue");
    m_settings.setValue("keyboardShortcuts/runQB2Key", m_run2Key.toString());
}

QKeySequence KeyboardHandler::getRun3Key()
{
    return m_run3Key;
}

void KeyboardHandler::setRun3Key(QKeySequence key)
{
    m_run3Key = key;
    m_run3Shortcut->setKey(m_run3Key);
    QSettings m_settings("Plankton", "ScriptCue");
    m_settings.setValue("keyboardShortcuts/runQB3Key", m_run3Key.toString());
}

QKeySequence KeyboardHandler::getRun4Key()
{
    return m_run4Key;
}

void KeyboardHandler::setRun4Key(QKeySequence key)
{
    m_run4Key = key;
    m_run4Shortcut->setKey(m_run4Key);
    QSettings m_settings("Plankton", "ScriptCue");
    m_settings.setValue("keyboardShortcuts/runQB4Key", m_run4Key.toString());
}

QKeySequence KeyboardHandler::getRun5Key()
{
    return m_run5Key;
}

void KeyboardHandler::setRun5Key(QKeySequence key)
{
    m_run5Key = key;
    m_run5Shortcut->setKey(m_run5Key);
    QSettings m_settings("Plankton", "ScriptCue");
    m_settings.setValue("keyboardShortcuts/runQB5Key", m_run5Key.toString());
}

QKeySequence KeyboardHandler::getRun6Key()
{
    return m_run6Key;
}

void KeyboardHandler::setRun6Key(QKeySequence key)
{
    m_run6Key = key;
    m_run6Shortcut->setKey(m_run6Key);
    QSettings m_settings("Plankton", "ScriptCue");
    m_settings.setValue("keyboardShortcuts/runQB6Key", m_run6Key.toString());
}

QKeySequence KeyboardHandler::getRun7Key()
{
    return m_run7Key;
}

void KeyboardHandler::setRun7Key(QKeySequence key)
{
    m_run7Key = key;
    m_run7Shortcut->setKey(m_run7Key);
    QSettings m_settings("Plankton", "ScriptCue");
    m_settings.setValue("keyboardShortcuts/runQB7Key", m_run7Key.toString());
}

QKeySequence KeyboardHandler::getRun8Key()
{
    return m_run8Key;
}

void KeyboardHandler::setRun8Key(QKeySequence key)
{
    m_run8Key = key;
    m_run8Shortcut->setKey(m_run8Key);
    QSettings m_settings("Plankton", "ScriptCue");
    m_settings.setValue("keyboardShortcuts/runQB8Key", m_run8Key.toString());
}

QKeySequence KeyboardHandler::getRun9Key()
{
    return m_run9Key;
}

void KeyboardHandler::setRun9Key(QKeySequence key)
{
    m_run9Key = key;
    m_run9Shortcut->setKey(m_run9Key);
    QSettings m_settings("Plankton", "ScriptCue");
    m_settings.setValue("keyboardShortcuts/runQB9Key", m_run9Key.toString());
}

void KeyboardHandler::emitNextPressed()
{
    emit nextPressed();
}

void KeyboardHandler::emitPrevPressed()
{
    emit prevPressed();
}

void KeyboardHandler::emitStartPressed()
{
    emit startPressed();
}

void KeyboardHandler::emitStopPressed()
{
    emit stopPressed();
}

void KeyboardHandler::emitNextQBPagePressed()
{
    emit nextQBPagePressed();
}

void KeyboardHandler::emitPrevQBPagePressed()
{
    emit prevQBPagePressed();
}

void KeyboardHandler::emitRun0Pressed()
{
    emit run0Pressed();
}

void KeyboardHandler::emitRun1Pressed()
{
    emit run1Pressed();
}

void KeyboardHandler::emitRun2Pressed()
{
    emit run2Pressed();
}

void KeyboardHandler::emitRun3Pressed()
{
    emit run3Pressed();
}

void KeyboardHandler::emitRun4Pressed()
{
    emit run4Pressed();
}

void KeyboardHandler::emitRun5Pressed()
{
    emit run5Pressed();
}

void KeyboardHandler::emitRun6Pressed()
{
    emit run6Pressed();
}

void KeyboardHandler::emitRun7Pressed()
{
    emit run7Pressed();
}

void KeyboardHandler::emitRun8Pressed()
{
    emit run8Pressed();
}

void KeyboardHandler::emitRun9Pressed()
{
    emit run9Pressed();
}
