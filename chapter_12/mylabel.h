#ifndef MYLABEL_H
#define MYLABEL_H

#include <QLabel>
#include <QModelIndex>

class MyLabel : public QLabel {
    Q_OBJECT
public:
    MyLabel(QWidget* pobj = 0) : QLabel(pobj)
    {}
public slots:
    void doub(const QModelIndex &index)
    {
        if (index.row() == 0)
        {
            QPixmap pix = index.data(Qt::DecorationRole).value<QPixmap>().scaled(500, 500);
            setPixmap(pix);
            this->resize(500, 500);
            show();
        }
    }
};
#endif // MYLABEL_H
