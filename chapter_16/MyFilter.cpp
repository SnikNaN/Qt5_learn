#include <QtWidgets>
#include "MyFilter.h"

// ----------------------------------------------------------------------
MyFilter::MyFilter(QObject* pobj/*= 0*/)
    : QObject(pobj)
{
}

// ----------------------------------------------------------------------
/*virtual*/bool MyFilter::eventFilter(QObject* pobj, QEvent* pe)
{
    if (pe->type() == QEvent::KeyPress && (static_cast<QKeyEvent*>(pe)->modifiers() & Qt::ShiftModifier))
    {
        int key = static_cast<QKeyEvent*>(pe)->key();
        if (key >= Qt::Key_A && key <= Qt::Key_Z)
        {
            for (int i = key - Qt::Key_A; i < Qt::Key_Z - Qt::Key_A + 1; ++i) {
                QChar ch    = 'A' + i;
                int   nKey  = Qt::Key_A + i;
                QKeyEvent keyPress(QEvent::KeyPress, nKey, Qt::NoModifier, ch);
                QApplication::sendEvent(pobj, &keyPress);

                QKeyEvent keyRelease(QEvent::KeyRelease, nKey, Qt::NoModifier, ch);
                QApplication::sendEvent(pobj, &keyRelease);
            }
            QKeyEvent keyPress(QEvent::KeyPress, Qt::Key_Enter, Qt::NoModifier, "\n");
            QApplication::sendEvent(pobj, &keyPress);

            QKeyEvent keyRelease(QEvent::KeyRelease, Qt::Key_Enter, Qt::NoModifier, "\n");
            QApplication::sendEvent(pobj, &keyRelease);
            return true;
        }
    }
    return false;
}
