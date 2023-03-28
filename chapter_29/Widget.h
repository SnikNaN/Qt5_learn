// ======================================================================
#pragma once

#include <QPoint>
#include <QLabel>
#include <QVBoxLayout>

// ======================================================================
class Widget : public QLabel {
Q_OBJECT
private:
    QPoint m_ptDragPos;

    void startDrag();

protected:
    virtual void mousePressEvent(QMouseEvent*    );
    virtual void mouseMoveEvent (QMouseEvent*    );

public:
    Widget(QWidget* pwgt = 0);
};

