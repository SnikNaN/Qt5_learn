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
#include "SyntaxHighlighter.h"
#include "TextEditor.h"

// ----------------------------------------------------------------------
int main (int argc, char** argv)
{
    QApplication app(argc, argv);

    QWidget wgt;
    QVBoxLayout* pvbxLayout = new QVBoxLayout;
    TextEditor  txt;
    QLineEdit* pline = new QLineEdit;
    pline->setMaxLength(16);
    pline->setPlaceholderText("Enter filename");
    pline->setFixedWidth(200);
    QPushButton* pbtnSave = new QPushButton("&Save as pdf");
    pbtnSave->setFixedWidth(200);

    QObject::connect(pline, SIGNAL(textChanged(const QString&)),
                     &txt, SLOT(set_filename(const QString&)));
    QObject::connect(pbtnSave, SIGNAL(clicked()),
                     &txt, SLOT(save_as_pdf()));

    pvbxLayout->addWidget(pline);
    pvbxLayout->addWidget(pbtnSave);
    pvbxLayout->addWidget(&txt);
    QFont fnt("Lucida Console", 10, QFont::Normal);
    txt.document()->setDefaultFont(fnt);

    new SyntaxHighlighter(txt.document());

    QPalette pal = txt.palette();
    pal.setColor(QPalette::Base, Qt::darkBlue);
    pal.setColor(QPalette::Text, Qt::yellow);
    txt.setPalette(pal);

    wgt.setLayout(pvbxLayout);
    wgt.show();
    wgt.resize(1000, 700);

    QFile file(":/SyntaxHighlighter.cpp");
    file.open(QFile::ReadOnly);
    txt.setPlainText(QLatin1String(file.readAll()));

    return app.exec();
}
