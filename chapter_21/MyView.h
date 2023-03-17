// ======================================================================
//  MyView.h
// ======================================================================
//                   This file is a part of the book 
//             "Qt 5.10 Professional programming with C++"
//                       http://qt-book.com
// ======================================================================
//  Copyright (c) 2017 by Max Schlee
// ======================================================================

#pragma once

#include <QGraphicsView>

// ======================================================================
class MyView: public QGraphicsView {
Q_OBJECT
public:
    MyView(QGraphicsScene* pScene, QWidget* pwgt = 0) 
        : QGraphicsView(pScene, pwgt)
    {
    }

public slots:
    void slotZoom(int value)
    {
        setTransform(QTransform::fromScale(0.01 * value, 0.01 * value));
    }

    void slotRotateLeft()
    {
        rotate(-5);
    }

    void slotRotateRight()
    {
        rotate(5);
    }
};
