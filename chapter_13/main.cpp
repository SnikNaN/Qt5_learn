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

// ----------------------------------------------------------------------
int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    QSpinBox     spb;
    QMessageBox  msgb;

    msgb.setWindowTitle("Message box");
    msgb.setText("This is a black message box");

    QPalette pal = spb.palette();

    pal.setBrush(QPalette::Button, QBrush(Qt::red, Qt::CrossPattern));
    pal.setColor(QPalette::ButtonText, Qt::blue);
    pal.setColor(QPalette::Text, Qt::magenta);
    pal.setColor(QPalette::Active, QPalette::Base, Qt::green);
    pal.setColor(QPalette::Inactive, QPalette::Base, Qt::red);
    
    spb.setPalette(pal);
    spb.resize(150, 74);
    spb.show();

    pal = msgb.palette();
    pal.setBrush(QPalette::Button, QBrush(Qt::red, Qt::Dense4Pattern));
    pal.setColor(QPalette::ButtonText, Qt::white);
    pal.setColor(QPalette::WindowText, Qt::lightGray);
    pal.setColor(QPalette::Window, Qt::black);

    msgb.setPalette(pal);
    msgb.show();

    app.setStyle("Windows");

    return app.exec();
}
