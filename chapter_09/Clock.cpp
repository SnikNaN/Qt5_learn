#include "Clock.hpp"

Clock::Clock(QWidget* parent) : QWidget(parent)
{
    _hours = new QLCDNumber(2);
    _minutes = new QLCDNumber(2);
    _seconds = new QLCDNumber(2);
    _sep1 = new QLCDNumber(1);
    _sep2 = new QLCDNumber(1);

    _prgBar = new QProgressBar;

    _phbxLayout = new QHBoxLayout;
    _pvbxLayout = new QVBoxLayout;

    _hours->setSegmentStyle(QLCDNumber::Filled);
    _minutes->setSegmentStyle(QLCDNumber::Filled);
    _seconds->setSegmentStyle(QLCDNumber::Filled);
    _sep1->setSegmentStyle(QLCDNumber::Filled);
    _sep2->setSegmentStyle(QLCDNumber::Filled);

    _sep1->display(":");
    _sep2->display(":");

    _phbxLayout->addWidget(_hours, 2);
    _phbxLayout->addWidget(_sep1, 1);
    _phbxLayout->addWidget(_minutes, 2);
    _phbxLayout->addWidget(_sep2, 1);
    _phbxLayout->addWidget(_seconds, 2);

    _pvbxLayout->addLayout(_phbxLayout);
    _pvbxLayout->addWidget(_prgBar);

    this->setLayout(_pvbxLayout);

    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Clock::showTime);
    timer->start(10);

    showTime();
}

void Clock::showTime()
{
    QTime time = QTime::currentTime();

    _hours->display(format(time.hour()));
    _minutes->display(format(time.minute()));
    _seconds->display(format(time.second()));

    _prgBar->setValue(time.msec() / 10);
}

QString Clock::format(int num)
{
    if (num < 10)
        return ("0" + QString::number(num));
    else
        return (QString::number(num));
}
