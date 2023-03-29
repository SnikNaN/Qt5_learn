//================================================
//  Simple paint app
//================================================

#include <QtWidgets>
#include "MyView.h"
#include "paintscene.h"
#include <QMenuBar>

// ----------------------------------------------------------------------
int main(int argc, char** argv)
{
    QApplication   app(argc, argv);
    QWidget        wgt;
    PaintScene scene;
    scene.setSceneRect(QRectF(0, 0, 800, 700));

    QMenuBar* mnuBar = new QMenuBar;
    QMenu* mnFile = new QMenu("&File");
    mnFile->addAction("&Save...", &scene, SLOT(saveFile()),
                      Qt::CTRL + Qt::Key_S);
    mnFile->addSeparator();
    mnFile->addAction("&Exit", &scene, SLOT(exit()), Qt::CTRL + Qt::Key_Q);
    mnuBar->addMenu(mnFile);

    MyView*      pView = new MyView(&scene);

    QLabel* plblZoom = new QLabel("Zoom:");
    QLabel* plblBrush = new QLabel("Brush:");
    plblBrush->setAlignment(Qt::AlignCenter);
    QLabel* plblSize = new QLabel("Size:");
    QLabel* plblOp = new QLabel("Opacity:");

    QLabel* plblColor = new QLabel("Color:");
    plblColor->setAlignment(Qt::AlignCenter);

    QLabel* plblRed = new QLabel("R:");
    QLabel* plblGreen = new QLabel("G:");
    QLabel* plblBlue = new QLabel("B:");

    pView->setCursor(Qt::CursorShape::CrossCursor);

    QSlider*    pZoom = new QSlider(Qt::Horizontal);
    pZoom->setMinimum(10);
    pZoom->setMaximum(500);
    pZoom->setValue(100);

    QHBoxLayout* pLZoom = new QHBoxLayout;
    pLZoom->addWidget(plblZoom);
    pLZoom->addWidget(pZoom);

    QSlider*    pbrushSize = new QSlider(Qt::Horizontal);
    pbrushSize->setMinimum(1);
    pbrushSize->setMaximum(100);
    pbrushSize->setValue(50);

    QHBoxLayout* pLSize = new QHBoxLayout;
    pLSize->addWidget(plblSize);
    pLSize->addWidget(pbrushSize);

    QSlider*    pOpacity = new QSlider(Qt::Horizontal);
    pOpacity->setMinimum(1);
    pOpacity->setMaximum(255);
    pOpacity->setValue(100);

    QHBoxLayout* pLOpac = new QHBoxLayout;
    pLOpac->addWidget(plblOp);
    pLOpac->addWidget(pOpacity);

    QSlider*    pRed = new QSlider(Qt::Horizontal);
    pRed->setMinimum(0);
    pRed->setMaximum(255);
    pRed->setValue(255);

    QHBoxLayout* pLRed = new QHBoxLayout;
    pLRed->addWidget(plblRed);
    pLRed->addWidget(pRed);

    QSlider*    pGreen = new QSlider(Qt::Horizontal);
    pGreen->setMinimum(0);
    pGreen->setMaximum(255);
    pGreen->setValue(0);

    QHBoxLayout* pLGreen = new QHBoxLayout;
    pLGreen->addWidget(plblGreen);
    pLGreen->addWidget(pGreen);

    QSlider*    pBlue = new QSlider(Qt::Horizontal);
    pBlue->setMinimum(0);
    pBlue->setMaximum(255);
    pBlue->setValue(0);

    QHBoxLayout* pLBlue = new QHBoxLayout;
    pLBlue->addWidget(plblBlue);
    pLBlue->addWidget(pBlue);

    QPushButton* pbSetColor = new QPushButton("Set &color...");

    pView->setRenderHint(QPainter::Antialiasing, true);

    QObject::connect(pZoom, SIGNAL(valueChanged(int)),
                     pView,      SLOT(slotZoom(int))
                    );

    QObject::connect(pbrushSize, SIGNAL(valueChanged(int)),
                     &scene,      SLOT(setBrushSize(int))
                    );

    QObject::connect(pOpacity, SIGNAL(valueChanged(int)),
                     &scene,      SLOT(setOpacity(int))
                    );

    QObject::connect(pRed, SIGNAL(valueChanged(int)),
                     &scene,      SLOT(setRed(int))
                    );
    QObject::connect(pGreen, SIGNAL(valueChanged(int)),
                     &scene,      SLOT(setGreen(int))
                    );
    QObject::connect(pBlue, SIGNAL(valueChanged(int)),
                     &scene,      SLOT(setBlue(int))
                    );
    QObject::connect(pbSetColor, SIGNAL(clicked()), &scene, SLOT(setColor()));

    //Layout setup
    QVBoxLayout* pvbxLayout = new QVBoxLayout;
    pvbxLayout->addWidget(mnuBar);
    pvbxLayout->addWidget(pView);
    pvbxLayout->addLayout(pLZoom);
    pvbxLayout->addWidget(plblBrush);
    pvbxLayout->addLayout(pLSize);
    pvbxLayout->addLayout(pLOpac);
    pvbxLayout->addWidget(plblColor);
    pvbxLayout->addLayout(pLRed);
    pvbxLayout->addLayout(pLGreen);
    pvbxLayout->addLayout(pLBlue);
    pvbxLayout->addWidget(pbSetColor);
    wgt.setLayout(pvbxLayout);
    wgt.resize(1000, 1000);
    wgt.show();
  
    return app.exec();
} 
