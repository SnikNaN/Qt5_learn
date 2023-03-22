#include <QtWidgets>
#include "CustomWidget.h"

// ----------------------------------------------------------------------
int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    QWidget      wgt;

    CustomWidget* pcw  = new CustomWidget;
    QDial*  phsb = new QDial;

    phsb->setRange(0, 100);
    phsb->setNotchesVisible(true);

    QObject::connect(phsb, SIGNAL(valueChanged(int)), 
                     pcw, SLOT(slotSetProgress(int))
                    );

    //Layout setup
    QVBoxLayout* pvbxLayout = new QVBoxLayout;
    pvbxLayout->addWidget(pcw);
    pvbxLayout->addWidget(phsb);
    wgt.setLayout(pvbxLayout);

    wgt.show();

    return app.exec();
}
