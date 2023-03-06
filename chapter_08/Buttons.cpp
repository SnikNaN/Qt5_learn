#include <QtWidgets>
#include "Buttons.h"

// ----------------------------------------------------------------------
Buttons::Buttons(QWidget* pwgt/*= 0*/) : QGroupBox(pwgt)
{
    resize(600, 350);

    clock = new Clock;
    m_pradRed   = new QRadioButton("&Red");
    m_pradGreen = new QRadioButton("&Green");
    m_pradBlue  = new QRadioButton("&Blue");

    m_pradGreen->setChecked(true);

    connect(m_pradRed, SIGNAL(clicked()), SLOT(slotButtonClicked()));
    connect(m_pradGreen, SIGNAL(clicked()), SLOT(slotButtonClicked()));
    connect(m_pradBlue, SIGNAL(clicked()), SLOT(slotButtonClicked()));

    m_pchk = new QCheckBox("&Light");
    m_pchk->setChecked(true);
    connect(m_pchk, SIGNAL(clicked()), SLOT(slotButtonClicked()));

    QPushButton* pcmd = new QPushButton("&Exit");
    connect(pcmd, SIGNAL(clicked()), qApp, SLOT(quit()));

    //Layout setup 
    QVBoxLayout* pvbxLayout = new QVBoxLayout;
    pvbxLayout->addWidget(m_pradRed);
    pvbxLayout->addWidget(m_pradGreen);
    pvbxLayout->addWidget(m_pradBlue);
    pvbxLayout->addWidget(m_pchk);
    pvbxLayout->addWidget(pcmd);
    pvbxLayout->addWidget(clock);
    setLayout(pvbxLayout);    

    slotButtonClicked();
}

// ----------------------------------------------------------------------
void Buttons::slotButtonClicked()
{
    QPalette pal    = palette();    
    int      nLight = m_pchk->isChecked() ? 150 : 80;
    if(m_pradRed->isChecked()) {
        pal.setColor(backgroundRole(), QColor(Qt::red).lighter(nLight));
        pal.setColor(foregroundRole(), QColor(Qt::green));
    }
    else if(m_pradGreen->isChecked()) {
        pal.setColor(backgroundRole(), QColor(Qt::green).lighter(nLight));
        pal.setColor(foregroundRole(), QColor(Qt::blue));
    }
    else {
        pal.setColor(backgroundRole(), QColor(Qt::blue).lighter(nLight));
        pal.setColor(foregroundRole(), QColor(Qt::red));
    }
    setPalette(pal);
}

