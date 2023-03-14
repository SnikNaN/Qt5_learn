#pragma once

#include <QObject>

// ======================================================================
class MyFilter : public QObject {
protected:
    virtual bool eventFilter(QObject*, QEvent*);

public:
    MyFilter(QObject* pobj = 0);

};

