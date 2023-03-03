// ======================================================================
// QVBoxLayout for result records was added at the bottom of QGridLayout
// ======================================================================

#pragma once

#include <QWidget>
#include <QStack>
#include <QVBoxLayout>

class QLCDNumber;
class QPushButton;

// ======================================================================
class Calculator : public QWidget {
    Q_OBJECT
private:
    QLCDNumber*     m_plcd;
    QStack<QString> m_stk;
    QString         m_strDisplay;
    QVBoxLayout*    m_pvbxLayout;

public:
    Calculator(QWidget* pwgt = 0);

    QPushButton* createButton(const QString& str);
    void         calculate   (                  );

public slots:
    void slotButtonClicked();
};

