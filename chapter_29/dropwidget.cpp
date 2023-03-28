#include "dropwidget.h"

DropWidget::DropWidget(QWidget* parent) : QWidget(parent)
{
    setAcceptDrops(true);
    setLayout(&m_vbxLayout);
    resize(300, 300);
}

// ----------------------------------------------------------------------
/*virtual*/ void DropWidget::dragEnterEvent(QDragEnterEvent* pe)
{
    if (pe->mimeData()->hasFormat(WidgetMimeData::mimeType())) {
        pe->acceptProposedAction();
    }
}

// ----------------------------------------------------------------------
/*virtual*/ void DropWidget::dropEvent(QDropEvent* pe)
{
    const WidgetMimeData* pmmd =
        dynamic_cast<const WidgetMimeData*>(pe->mimeData());
    if (pmmd) {
        QWidget* pwgt = pmmd->widget();
        Widget* wgt = new Widget();
        wgt->setText(dynamic_cast<Widget*>(pwgt)->text());
        wgt->setStyleSheet(pwgt->styleSheet());
        m_vbxLayout.addWidget(wgt);
    }
}
