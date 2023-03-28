#include <QtWidgets>
#include "Widget.h"
#include "WidgetDrag.h"

// ----------------------------------------------------------------------
Widget::Widget(QWidget* pwgt/*=0*/) : QLabel(pwgt)
{
//    setAcceptDrops(true);
//    setLayout(&m_vbxLayout);
}

// ----------------------------------------------------------------------
void Widget::startDrag()
{
    WidgetDrag* pDrag = new WidgetDrag(this);
    pDrag->setWidget(this);
    pDrag->exec(Qt::CopyAction);
}

// ----------------------------------------------------------------------
/*virtual*/ void Widget::mousePressEvent(QMouseEvent* pe)
{
    if (pe->button() == Qt::LeftButton) {
        m_ptDragPos = pe->pos();
    }
    QWidget::mousePressEvent(pe);
}

// ----------------------------------------------------------------------
/*virtual*/ void Widget::mouseMoveEvent(QMouseEvent* pe)
{
    if (pe->buttons() & Qt::LeftButton) {
        int distance = (pe->pos() - m_ptDragPos).manhattanLength();
        if (distance > QApplication::startDragDistance()) {
            startDrag();
        }
    }
    QWidget::mouseMoveEvent(pe);
}

