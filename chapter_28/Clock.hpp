#ifndef CLOCK_HPP
#define CLOCK_HPP

#include <QtWidgets>
#include <QTime>

class Clock : public QWidget
{
private:
    QLCDNumber* _hours;
    QLCDNumber* _minutes;
    QLCDNumber* _seconds;
    QLCDNumber* _sep1;
    QLCDNumber* _sep2;
    QHBoxLayout* _phbxLayout;
    QProgressBar* _prgBar;
    QVBoxLayout* _pvbxLayout;

    QString format(int num);
    void showTime();

public:
    Clock(QWidget* parent = nullptr);
};


#endif // CLOCK_HPP
