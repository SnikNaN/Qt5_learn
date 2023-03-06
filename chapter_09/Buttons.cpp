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

    m_label = new QLabel("Light:");

    m_pdial = new QDial;
    m_pdial->setRange(50, 150);
    m_pdial->setValue(100);
    m_pdial->setNotchTarget(10);
    m_pdial->setNotchesVisible(true);
    m_pdial->setWrapping(false);
    m_pdial->setMaximumSize(100, 100);

    connect(m_pdial, SIGNAL(valueChanged(int)), SLOT(slotButtonClicked()));

    QPushButton* pcmd = new QPushButton("&Exit");
    connect(pcmd, SIGNAL(clicked()), qApp, SLOT(quit()));

    //Layout setup 
    QVBoxLayout* mainLayout = new QVBoxLayout;
    QHBoxLayout* phbxLayout = new QHBoxLayout;
    QVBoxLayout* pvbxLayout = new QVBoxLayout;

    pvbxLayout->addWidget(m_pradRed);
    pvbxLayout->addWidget(m_pradGreen);
    pvbxLayout->addWidget(m_pradBlue);

    phbxLayout->addLayout(pvbxLayout, 5);
    phbxLayout->addWidget(m_label, 1);
    phbxLayout->addWidget(m_pdial, 1);

    mainLayout->addLayout(phbxLayout);
    mainLayout->addWidget(pcmd);
    mainLayout->addWidget(clock);
    setLayout(mainLayout);

    slotButtonClicked();
}

// ----------------------------------------------------------------------
void Buttons::slotButtonClicked()
{
    QPalette pal    = palette();    
    int      nLight = m_pdial->value();
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

