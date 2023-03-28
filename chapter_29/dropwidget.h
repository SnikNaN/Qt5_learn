#ifndef DROPWIDGET_H
#define DROPWIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QDragEnterEvent>
#include "WidgetDrag.h"
#include <QLabel>
#include <QSplitter>
#include <QMetaType>
#include "Widget.h"

class DropWidget : public QWidget
{
    Q_OBJECT
private:
    QVBoxLayout m_vbxLayout;
public:
    DropWidget(QWidget* parent = nullptr);
    virtual void dragEnterEvent (QDragEnterEvent*);
    virtual void dropEvent      (QDropEvent*     );
};

#endif // DROPWIDGET_H
