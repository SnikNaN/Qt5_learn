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
    if (pe->type() == QEvent::MouseButtonPress) {
        if (static_cast<QMouseEvent*>(pe)->button() == Qt::LeftButton) {
            QString strClassName = pobj->metaObject()->className();
            QMessageBox::information(0, "Class Name", strClassName);
            return true;
        }
    }
    if (QString(pobj->metaObject()->className()) == ("QLineEdit"))
    {
        if (pe->type() == QEvent::KeyPress)
        {
            int key = static_cast<QKeyEvent*>(pe)->key();
            if (key >= Qt::Key_A && key <= Qt::Key_Z)
                QMessageBox::information(0, "Key pressed", static_cast<QKeyEvent*>(pe)->text());
            return false;
        }
    }
    return false;
}
