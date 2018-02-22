#ifndef KEYBOARDHANDLER_H
#define KEYBOARDHANDLER_H

#include <QShortcut>
#include <QKeySequence>

class KeyboardHandler : QObject
{
    Q_OBJECT

public:
    KeyboardHandler();

signals:
    nextPressed();
    prevPressed();
    startPressed();
    stopPressed();
    nextQBPagePressed();
    prevQBPagePressed();
    run0Pressed();
    run1Pressed();
    run2Pressed();
    run3Pressed();
    run4Pressed();
    run5Pressed();
    run6Pressed();
    run7Pressed();
    run8Pressed();
    run9Pressed();

private:
    QKeySequence *m_nextKey;
    QKeySequence *m_prevKey;
    QKeySequence *m_startKey;
    QKeySequence *m_stopKey;
    QKeySequence *m_nextQBPageKey;
    QKeySequence *m_prevQBPageKey;
    QKeySequence *m_run0Key;
    QKeySequence *m_run1Key;
    QKeySequence *m_run2Key;
    QKeySequence *m_run3Key;
    QKeySequence *m_run4Key;
    QKeySequence *m_run5Key;
    QKeySequence *m_run6Key;
    QKeySequence *m_run7Key;
    QKeySequence *m_run8Key;
    QKeySequence *m_run9Key;

    QShortcut *m_nextShortcut;
    QShortcut *m_prevShortcut;
    QShortcut *m_startShortcut;
    QShortcut *m_stopShortcut;
    QShortcut *m_nextQBPageShortcut;
    QShortcut *m_prevQBPageShortcut;
    QShortcut *m_run0Shortcut;
    QShortcut *m_run1Shortcut;
    QShortcut *m_run2Shortcut;
    QShortcut *m_run3Shortcut;
    QShortcut *m_run4Shortcut;
    QShortcut *m_run5Shortcut;
    QShortcut *m_run6Shortcut;
    QShortcut *m_run7Shortcut;
    QShortcut *m_run8Shortcut;
    QShortcut *m_run9Shortcut;
};

#endif // KEYBOARDHANDLER_H
