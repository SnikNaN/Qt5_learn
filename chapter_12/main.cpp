#include <QtWidgets>

#include "mylabel.h"

class MyListView : public QListView {
public:
    MyListView(QWidget* pobj = 0) : QListView(pobj)
    {
        lbl.setText("Show text");
        connect(this, SIGNAL(clicked(const QModelIndex &)),
                &lbl, SLOT(doub(const QModelIndex &)));
    }

private:
    MyLabel lbl;
};

class MyDelegate1 : public QStyledItemDelegate {
public:
    MyDelegate1(QObject* pobj = 0) : QStyledItemDelegate(pobj)
    {
    }

    void paint(QPainter*                   pPainter,
               const QStyleOptionViewItem& option,
               const QModelIndex&          index
              ) const
    {
        if (option.state & QStyle::State_MouseOver) {
            QRect           rect = option.rect;
            QLinearGradient gradient(0, 0, rect.width(), rect.height());

            gradient.setColorAt(0, Qt::white);
            gradient.setColorAt(0.5, Qt::blue);
            gradient.setColorAt(1, Qt::red);
            pPainter->setBrush(gradient);
            pPainter->drawRect(rect);
        }
        QRect rect(25, 50, 50, 50);
        pPainter->drawPixmap(rect, index.data(Qt::DecorationRole).value<QPixmap>());
        pPainter->drawText(0, 0, 100, 20, Qt::AlignCenter, "Click me!");
        pPainter->drawText(0, 0, 100, 80, Qt::AlignCenter, index.data(Qt::DisplayRole).toString());
    }

    QSize sizeHint(const QStyleOptionViewItem& /*option*/,
                   const QModelIndex&/*index*/
                  ) const
    {
        return QSize(100, 100);
    }
};

class MyDelegate2 : public QStyledItemDelegate {
public:
    MyDelegate2(QObject* pobj = 0) : QStyledItemDelegate(pobj)
    {
    }

    void paint(QPainter*                   pPainter,
               const QStyleOptionViewItem& option,
               const QModelIndex&          index
              ) const
    {
        if (option.state & QStyle::State_MouseOver) {
            QRect   rect(option.rect.x(), option.rect.y(), 100, 100);
            QLinearGradient gradient(option.rect.x(), 0, option.rect.x() + 100, 100);
            gradient.setColorAt(0, Qt::white);
            gradient.setColorAt(0.5, Qt::yellow);
            gradient.setColorAt(1, Qt::green);
            pPainter->setBrush(gradient);
            pPainter->drawRect(rect);
        }
        QStyledItemDelegate::paint(pPainter, option, index);
    }

    QSize sizeHint(const QStyleOptionViewItem& /*option*/,
                   const QModelIndex&/*index*/
                  ) const
    {
        return QSize(100, 100);
    }
};
// ----------------------------------------------------------------------
int main(int argc, char** argv) 
{
    QApplication app(argc, argv);
    QStringList  lst;
    lst << "Linux" << "Windows" << "MacOSX" << "Android";

    QStandardItemModel model(lst.size(), 1);
    for (int i = 0; i < model.rowCount(); ++i) {
        QModelIndex index = model.index(i, 0);
        QString     str   = lst.at(i);
        model.setData(index, str, Qt::DisplayRole);
        model.setData(index, "ToolTip for " + str, Qt::ToolTipRole);
        model.setData(index, QPixmap(":/" + str + ".jpg"), Qt::DecorationRole);
    }

    MyListView listView;

    listView.setViewMode(QListView::IconMode);
    listView.setModel(&model);
    listView.setIconSize(QSize(100, 100));
    listView.setGridSize(QSize(100, 100));
    listView.resize(420, 110);
    listView.setItemDelegateForRow(0, new MyDelegate1(&listView));
    listView.setItemDelegateForRow(1, new MyDelegate2(&listView));
    listView.setItemDelegateForRow(2, new MyDelegate2(&listView));
    listView.setItemDelegateForRow(3, new MyDelegate2(&listView));
    listView.viewport()->setAttribute(Qt::WA_Hover);
    listView.setDragEnabled(false);
    listView.show();

    return app.exec();
}
