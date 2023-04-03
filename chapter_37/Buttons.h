#pragma once

#include <QGroupBox>
#include "Clock.hpp"

class QCheckBox;
class QRadioButton;

// ======================================================================
class Buttons : public QGroupBox {
    Q_OBJECT
private:
    QCheckBox*    m_pchk;
    QRadioButton* m_pradRed;
    QRadioButton* m_pradGreen;
    QRadioButton* m_pradBlue;

    QSettings  m_settings;

    Clock*  clock;

public:
    Buttons(QWidget* pwgt = 0);

    virtual ~Buttons();

    void writeSettings();
    void readSettings();

public slots:
    void slotButtonClicked();
};
