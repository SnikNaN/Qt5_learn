// ======================================================================
//  GrabWidget.cpp
// ======================================================================
//                   This file is a part of the book 
//             "Qt 5.10 Professional programming with C++"
//                       http://qt-book.com
// ======================================================================
//  Copyright (c) 2017 by Max Schlee
// ======================================================================

#include <QtWidgets>
#include "GrabWidget.h"
#include <QScreen>

// ----------------------------------------------------------------------
GrabWidget::GrabWidget(QWidget* pwgt /*=0*/) : QWidget(pwgt)
{
    resize(640, 480);

    m_plbl = new QLabel();

    QPushButton* pcmd = new QPushButton("Capture Screen");
    connect(pcmd, SIGNAL(clicked()), SLOT(slotGrabScreen()));

    //Layout setup
    QVBoxLayout* pvbxLayout = new QVBoxLayout;    
    pvbxLayout->addWidget(pcmd);
    pvbxLayout->addWidget(m_plbl);
    setLayout(pvbxLayout);
}

// ----------------------------------------------------------------------
void GrabWidget::slotGrabScreen()
{
    QScreen* pscreen = qApp->primaryScreen();

    QPixmap pic = pscreen->grabWindow(0);

    m_plbl->setPixmap(pic.scaled(m_plbl->size()));
}
