#include "keyboardhandler.h"

KeyboardHandler::KeyboardHandler()
{
    m_nextKey = new QKeySequence(Qt::Key_Enter);
    m_prevKey = new QKeySequence(Qt::Key_Backslash);
    m_startKey = new QKeySequence();
    m_stopKey = new QKeySequence();
    m_nextQBPageKey = new QKeySequence(Qt::Key_Equal);
    m_prevQBPageKey = new QKeySequence(Qt::Key_Minus);
    m_run0Key = new QKeySequence(Qt::Key_0);
    m_run1Key = new QKeySequence(Qt::Key_1);
    m_run2Key = new QKeySequence(Qt::Key_2);
    m_run3Key = new QKeySequence(Qt::Key_3);
    m_run4Key = new QKeySequence(Qt::Key_4);
    m_run5Key = new QKeySequence(Qt::Key_5);
    m_run6Key = new QKeySequence(Qt::Key_6);
    m_run7Key = new QKeySequence(Qt::Key_7);
    m_run8Key = new QKeySequence(Qt::Key_8);
    m_run9Key = new QKeySequence(Qt::Key_9);

    m_nextShortcut = new QShortcut(m_nextKey);
    m_prevShortcut = new QShortcut(m_prevKey);
    m_startShortcut = new QShortcut(m_startKey);
    m_stopShortcut = new QShortcut(m_stopKey);
    m_nextQBPageShortcut = new QShortcut(m_nextQBPageKey);
    m_prevQBPageShortcut = new QShortcut(m_prevQBPageKey);
    m_run0Shortcut = new QShortcut(m_run0Key);
    m_run1Shortcut = new QShortcut(m_run1Key);
    m_run2Shortcut = new QShortcut(m_run2Key);
    m_run3Shortcut = new QShortcut(m_run3Key);
    m_run4Shortcut = new QShortcut(m_run4Key);
    m_run5Shortcut = new QShortcut(m_run5Key);
    m_run6Shortcut = new QShortcut(m_run6Key);
    m_run7Shortcut = new QShortcut(m_run7Key);
    m_run8Shortcut = new QShortcut(m_run8Key);
    m_run9Shortcut = new QShortcut(m_run9Key);

    connect(m_nextShortcut, QShortcut::activated(), this, nextPressed());
    connect(m_prevShortcut, QShortcut::activated(), this, prevPressed());
    connect(m_startShortcut, QShortcut::activated(), this, startPressed());
    connect(m_stopShortcut, QShortcut::activated(), this, stopPressed());
    connect(m_nextQBPageShortcut, QShortcut::activated(), this, nextQBPagePressed());
    connect(m_prevQBPageShortcut, QShortcut::activated(), this, prevQBPagePressed());
    connect(m_run0Shortcut, QShortcut::activated(), this, run0Pressed());
    connect(m_run1Shortcut, QShortcut::activated(), this, run1Pressed());
    connect(m_run2Shortcut, QShortcut::activated(), this, run2Pressed());
    connect(m_run3Shortcut, QShortcut::activated(), this, run3Pressed());
    connect(m_run4Shortcut, QShortcut::activated(), this, run4Pressed());
    connect(m_run5Shortcut, QShortcut::activated(), this, run5Pressed());
    connect(m_run6Shortcut, QShortcut::activated(), this, run6Pressed());
    connect(m_run7Shortcut, QShortcut::activated(), this, run7Pressed());
    connect(m_run8Shortcut, QShortcut::activated(), this, run8Pressed());
    connect(m_run9Shortcut, QShortcut::activated(), this, run9Pressed());

}

QKeySequence* KeyboardHandler::getNextKey()
{
    return m_nextKey;
}

void KeyboardHandler::setNextKey(QKeySequence *key)
{
    m_nextKey = key;
    m_nextShortcut->setKey(m_nextKey);
}

QKeySequence* KeyboardHandler::getPrevKey()
{
    return m_prevKey;
}

void KeyboardHandler::setprevKey(QKeySequence *key)
{
    m_prevKey = key;
    m_prevShortcut->setKey(m_prevKey);
}

QKeySequence* KeyboardHandler::getStartKey()
{
    return m_startKey;
}

void KeyboardHandler::setStartKey(QKeySequence *key)
{
    m_startKey = key;
    m_startShortcut->setKey(m_nextKey);
}

QKeySequence* KeyboardHandler::getStopKey()
{
    return m_stopKey;
}

void KeyboardHandler::setStopKey(QKeySequence *key)
{
    m_stopKey = key;
    m_stopShortcut->setKey(m_stopKey);
}

QKeySequence* KeyboardHandler::getNextQBPageKey()
{
    return m_nextQBPageKey;
}

void KeyboardHandler::setNextQBPageKey(QKeySequence *key)
{
    m_nextQBPageKey = key;
    m_nextQBPageShortcut->setKey(m_nextQBPageKey);
}

QKeySequence* KeyboardHandler::getPrevQBPageKey()
{
    return m_prevQBPageKey;
}

void KeyboardHandler::setPrevQBPageKey(QKeySequence *key)
{
    m_prevQBPageKey = key;
    m_prevQBPageShortcut->setKey(m_prevQBPageKey);
}

QKeySequence* KeyboardHandler::getRun0Key()
{
    return m_run0Key;
}

void KeyboardHandler::setRun0Key(QKeySequence *key)
{
    m_run0Key = key;
    m_run0Shortcut->setKey(m_run0Key);
}

QKeySequence* KeyboardHandler::getRun1Key()
{
    return m_run1Key;
}

void KeyboardHandler::setRun1Key(QKeySequence *key)
{
    m_run1Key = key;
    m_run1Shortcut->setKey(m_run1Key);
}

QKeySequence* KeyboardHandler::getRun2Key()
{
    return m_run2Key;
}

void KeyboardHandler::setRun2Key(QKeySequence *key)
{
    m_run2Key = key;
    m_run2Shortcut->setKey(m_run2Key);
}

QKeySequence* KeyboardHandler::getRun3Key()
{
    return m_run3Key;
}

void KeyboardHandler::setRun3Key(QKeySequence *key)
{
    m_run3Key = key;
    m_run3Shortcut->setKey(m_run3Key);
}

QKeySequence* KeyboardHandler::getRun4Key()
{
    return m_run4Key;
}

void KeyboardHandler::setRun4Key(QKeySequence *key)
{
    m_run4Key = key;
    m_run4Shortcut->setKey(m_run4Key);
}

QKeySequence* KeyboardHandler::getRun5Key()
{
    return m_run5Key;
}

void KeyboardHandler::setRun5Key(QKeySequence *key)
{
    m_run5Key = key;
    m_run5Shortcut->setKey(m_run5Key);
}

QKeySequence* KeyboardHandler::getRun6Key()
{
    return m_run6Key;
}

void KeyboardHandler::setRun6Key(QKeySequence *key)
{
    m_run6Key = key;
    m_run6Shortcut->setKey(m_run6Key);
}

QKeySequence* KeyboardHandler::getRun7Key()
{
    return m_run7Key;
}

void KeyboardHandler::setRun7Key(QKeySequence *key)
{
    m_run7Key = key;
    m_run7Shortcut->setKey(m_run7Key);
}

QKeySequence* KeyboardHandler::getRun8Key()
{
    return m_run8Key;
}

void KeyboardHandler::setRun8Key(QKeySequence *key)
{
    m_run8Key = key;
    m_run8Shortcut->setKey(m_run0Key);
}

QKeySequence* KeyboardHandler::getRun9Key()
{
    return m_run9Key;
}

void KeyboardHandler::setRun9Key(QKeySequence *key)
{
    m_run9Key = key;
    m_run9Shortcut->setKey(m_run9Key);
}
