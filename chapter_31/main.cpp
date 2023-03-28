#include <QApplication>
#include "ContextMenu.h"
#include <QVBoxLayout>
#include <QWidget>

// ----------------------------------------------------------------------
int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    QWidget wgt;

    QVBoxLayout* pvbxLayout = new QVBoxLayout;
    ContextMenu*  contextMenu = new ContextMenu;
    QMenuBar* mnuBar = new QMenuBar;
    QMenu*   pmnu   = new QMenu("&Menu");

    pmnu->addAction("&About Qt",
                    &app,
                    SLOT(aboutQt()),
                    Qt::CTRL + Qt::Key_Q
                   );

    pmnu->addSeparator();

    QAction* pCheckableAction = pmnu->addAction("&CheckableItem");
    pCheckableAction->setCheckable(true);
    pCheckableAction->setChecked(true);

    pmnu->addAction(QPixmap(":/img4.png"), "&IconItem");

    QMenu* pmnuSubMenu = new QMenu("&SubMenu", pmnu);
    pmnu->addMenu(pmnuSubMenu);
    pmnuSubMenu->addAction("&Test");

    QAction* pDisabledAction = pmnu->addAction("&DisabledItem");
    pDisabledAction->setEnabled(false);

    pmnu->addSeparator();

    pmnu->addAction("&Exit", &app, SLOT(quit()), Qt::CTRL + Qt::Key_E);

    mnuBar->addMenu(pmnu);

    pvbxLayout->addWidget(mnuBar);
    pvbxLayout->addWidget(contextMenu);

    wgt.setLayout(pvbxLayout);
    wgt.show();

    return app.exec();
}
