#pragma once

#include <QGroupBox>
#include "Clock.hpp"

class QDial;
class QRadioButton;

// ======================================================================
class Buttons : public QGroupBox {
    Q_OBJECT
private:
    QRadioButton* m_pradRed;
    QRadioButton* m_pradGreen;
    QRadioButton* m_pradBlue;
    QDial*  m_pdial;
    QLabel* m_label;

    Clock*  clock;

public:
    Buttons(QWidget* pwgt = 0);

public slots:
    void slotButtonClicked();
};

