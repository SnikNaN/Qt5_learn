#include "MouseObserver.h"

// ----------------------------------------------------------------------
MouseObserver::MouseObserver(QWidget* pwgt /*= 0*/) : QLabel(pwgt) 
{
    setAlignment(Qt::AlignCenter);
    setText("Mouse interactions\n(Press a mouse button\n"
            "or touch the wheel)");
    wheelLabel.resize(200, 100);
    wheelLabel.move(600, 200);
    wheelLabel.setAlignment(Qt::AlignCenter);
}   

// ----------------------------------------------------------------------
/*virtual*/void MouseObserver::mousePressEvent(QMouseEvent* pe)
{
    dumpMouseEvent(pe, "Mouse Pressed");
}

// ----------------------------------------------------------------------
/*virtual*/void MouseObserver::mouseReleaseEvent(QMouseEvent* pe)
{
    dumpMouseEvent(pe, "Mouse Released");
}
// ----------------------------------------------------------------------
/*virtual*/ void MouseObserver::mouseMoveEvent(QMouseEvent* pe)
{
    dumpMouseEvent(pe, "Mouse Is Moving");
}

/*virtual*/ void MouseObserver::wheelEvent(QWheelEvent *pe)
{
    dumpWheelEvent(pe, "Wheel Is Moving");
}

// ----------------------------------------------------------------------
void MouseObserver::dumpMouseEvent(QMouseEvent* pe, const QString& strMsg)
{
    wheelLabel.hide();
    setText(strMsg
            + "\n buttons()=" + buttonsInfo(static_cast<QMouseEvent*>(pe))
            + "\n x()=" + QString::number(static_cast<QMouseEvent*>(pe)->x())
            + "\n y()=" + QString::number(static_cast<QMouseEvent*>(pe)->y())
            + "\n globalX()=" + QString::number(static_cast<QMouseEvent*>(pe)->globalX())
            + "\n globalY()=" + QString::number(static_cast<QMouseEvent*>(pe)->globalY())
            + "\n modifiers()=" + modifiersInfo(static_cast<QMouseEvent*>(pe))
           );
}
// ----------------------------------------------------------------------
void MouseObserver::dumpWheelEvent(QWheelEvent *pe, const QString &strMsg)
{
    wheelLabel.setText(strMsg
                       + "\n wheel direction = " +
                       ((static_cast<QWheelEvent*>(pe)->angleDelta().y()) < 0 ?
                           "to user" : "from user"));
    wheelLabel.show();
}
// ----------------------------------------------------------------------
QString MouseObserver::modifiersInfo(QMouseEvent* pe)
{
    QString strModifiers;

    if(pe->modifiers() & Qt::ShiftModifier) {
        strModifiers += "Shift ";
    }
    if(pe->modifiers() & Qt::ControlModifier) {
        strModifiers += "Control ";
    }
    if(pe->modifiers() & Qt::AltModifier) {
        strModifiers += "Alt";
    }
    return strModifiers;
}

// ----------------------------------------------------------------------
QString MouseObserver::buttonsInfo(QMouseEvent* pe)
{
    QString strButtons;

    if(pe->buttons() & Qt::LeftButton) {
        strButtons += "Left ";
    }
    if(pe->buttons() & Qt::RightButton) {
        strButtons += "Right ";
    }
    if(pe->buttons() & Qt::MiddleButton) {
        strButtons += "Middle";
    }
    return strButtons;        
}

