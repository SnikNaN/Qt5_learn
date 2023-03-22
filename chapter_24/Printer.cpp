#include <QtWidgets>
#include <QtPrintSupport>
#include "Printer.h"

// ----------------------------------------------------------------------
Printer::Printer(QWidget* pwgt/*=0*/) : QWidget(pwgt) 
{
    m_pprinter = new QPrinter;
    m_pix = new QPixmap(QFileDialog::getOpenFileName
                        (this,"Choose image file to print",
                                                 "./", "*.png *.jpg"));
    if (m_pix->isNull())
        m_pix = new QPixmap(":/screenshot.png");
}

// ----------------------------------------------------------------------
/*virtual*/Printer::~Printer()
{
    delete m_pprinter;
    delete m_pix;
}

// ----------------------------------------------------------------------
/*virtual*/ void Printer::paintEvent(QPaintEvent*) 
{
    draw(this);
}

// ----------------------------------------------------------------------
void Printer::slotPrint()
{
    QPrintDialog dlg(m_pprinter, this);

    dlg.setMinMax(1, 1);
    if (dlg.exec() == QDialog::Accepted) {
        draw(m_pprinter);
    }
}

// ----------------------------------------------------------------------
void Printer::draw(QPaintDevice* ppd)
{
    QPainter painter(ppd);
    QRect    r(painter.viewport());
    QBrush   brush(Qt::gray, Qt::Dense3Pattern);

    //QPixmap pix_out = m_pix->scaled(r.size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);

    painter.setRenderHint(QPainter::SmoothPixmapTransform);

    painter.setBrush(brush);
    painter.drawRect(r);
    painter.drawPixmap(0, 0,m_pix->scaled(r.size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
}
