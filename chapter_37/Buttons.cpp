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

    connect(m_pradRed, SIGNAL(clicked()), SLOT(slotButtonClicked()));
    connect(m_pradGreen, SIGNAL(clicked()), SLOT(slotButtonClicked()));
    connect(m_pradBlue, SIGNAL(clicked()), SLOT(slotButtonClicked()));

    m_pchk = new QCheckBox("&Light");

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

    readSettings();

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

void Buttons::readSettings()
{
    m_settings.beginGroup("/Settings");
    bool    gCheck = m_settings.value("/green", true).toBool();
    bool    rCheck = m_settings.value("/red", false).toBool();
    bool    bCheck = m_settings.value("/blue", false).toBool();
    bool    lCheck = m_settings.value("/light", true).toBool();

    int     nWidth     = m_settings.value("/width", width()).toInt();
    int     nHeight    = m_settings.value("/height", height()).toInt();
    m_settings.endGroup();

    m_pradGreen->setChecked(gCheck);
    m_pradRed->setChecked(rCheck);
    m_pradBlue->setChecked(bCheck);
    m_pchk->setChecked(lCheck);

    resize(nWidth, nHeight);
}

void Buttons::writeSettings()
{
    m_settings.beginGroup("/Settings");
    m_settings.setValue("/red", m_pradRed->isChecked());
    m_settings.setValue("/green", m_pradGreen->isChecked());
    m_settings.setValue("/blue", m_pradBlue->isChecked());
    m_settings.setValue("/light", m_pchk->isChecked());
    m_settings.setValue("/width", width());
    m_settings.setValue("/height", height());
    m_settings.endGroup();
}

Buttons::~Buttons()
{
    writeSettings();
}
