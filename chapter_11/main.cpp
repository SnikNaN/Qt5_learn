// ======================================================================
//  main.cpp
// ======================================================================
//                   This file is a part of the book 
//             "Qt 5.10 Professional programming with C++"
//                       http://qt-book.com
// ======================================================================
//  Copyright (c) 2017 by Max Schlee
// ======================================================================

#include <QtWidgets>

QTreeWidget* prepare_pqtree()
{
    QTreeWidget*  twg = new QTreeWidget;
    QStringList  lst;

    lst << "Folders" << "Used Space";
    twg->setHeaderLabels(lst);
    twg->setSortingEnabled(true);
    twg->setColumnWidth(0, 200);

    QTreeWidgetItem* ptwgItem = new QTreeWidgetItem(twg);
    ptwgItem->setText(0, "Local Disk(C)");
    ptwgItem->setIcon(0, QPixmap(":/drive.bmp"));
    ptwgItem->setFlags(Qt::ItemIsSelectable | Qt::ItemIsUserCheckable | Qt::ItemIsDragEnabled | Qt::ItemIsDropEnabled | Qt::ItemIsEnabled);

    QTreeWidgetItem* ptwgItemDir = 0;
    for (int i = 1; i < 20; ++i) {
        ptwgItemDir = new QTreeWidgetItem(ptwgItem);
        ptwgItemDir->setCheckState(0, Qt::Checked);
        ptwgItemDir->setIcon(0, QPixmap(":/folder.bmp"));
        ptwgItemDir->setText(0, "Directory" + QString::number(i));
        ptwgItemDir->setText(1, QString::number(i) + "MB");
        ptwgItemDir->setFlags(Qt::ItemIsSelectable | Qt::ItemIsUserCheckable | Qt::ItemIsDragEnabled | Qt::ItemIsDropEnabled | Qt::ItemIsEnabled);
    }
    ptwgItem->setExpanded(true);
    twg->setDragDropMode(QAbstractItemView::DragDrop);
    twg->setDefaultDropAction(Qt::DropAction::MoveAction);

    ptwgItem->setFlags(ptwgItem->flags() ^ Qt::ItemIsDragEnabled ^ Qt::ItemIsDropEnabled);

    return twg;
}

// ----------------------------------------------------------------------
int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    QTabWidget   tab;
    QStringList  lst;
    QTreeWidget* ptrw = prepare_pqtree();

    QListWidget*     lwg = new QListWidget;
    QListWidgetItem* pitem = 0;

    lwg->setIconSize(QSize(48, 48));
    lwg->setSelectionMode(QAbstractItemView::SingleSelection);
    lwg->setViewMode(QListView::IconMode);
    lst << "Linux" << "Windows" << "MacOSX" << "Android";
    foreach(QString str, lst) {
        pitem = new QListWidgetItem(str, lwg);
        pitem->setIcon(QPixmap(":/" + str + ".jpg"));
        pitem->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable | Qt::ItemIsDragEnabled  | Qt::ItemIsDropEnabled | Qt::ItemIsAutoTristate);
    }

    lwg->setDefaultDropAction(Qt::DropAction::MoveAction);

    tab.addTab(lwg, "Icons");
    tab.addTab(ptrw, "Folders");

                                                                
    tab.resize(600, 600);
    tab.show();

    return app.exec();
}
