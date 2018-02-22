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
