#ifndef CLOCK_HPP
#define CLOCK_HPP

#include <QtWidgets>
#include <QDateTime>

class Clock : public QWidget
{
private:
    QLCDNumber* m_time;
    QLCDNumber* m_date;
    QLabel* m_plbl;
    QVBoxLayout* m_pvbxLayout;

    void showTime();

public:
    Clock(QWidget* parent = nullptr);
};


#endif // CLOCK_HPP
