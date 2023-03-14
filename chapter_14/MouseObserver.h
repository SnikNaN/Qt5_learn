#pragma once

#include <QtWidgets>

// ======================================================================
class MouseObserver : public QLabel {
private:
    QLabel  wheelLabel;

public:
    MouseObserver(QWidget* pwgt = 0); 

protected:
    virtual void mousePressEvent  (QMouseEvent* pe);
    virtual void mouseReleaseEvent(QMouseEvent* pe);
    virtual void mouseMoveEvent   (QMouseEvent* pe);
    virtual void wheelEvent       (QWheelEvent* pe);

    void    dumpMouseEvent     (QMouseEvent* pe, const QString& strMessage);
    void    dumpWheelEvent     (QWheelEvent* pe, const QString& strMessage);
    QString modifiersInfo (QMouseEvent* pe                           );
    QString buttonsInfo   (QMouseEvent* pe                           );
};

