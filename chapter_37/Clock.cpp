#include "Clock.hpp"

Clock::Clock(QWidget* parent) : QWidget(parent)
{
    m_time = new QLCDNumber(8);
    m_date = new QLCDNumber(10);

    m_plbl = new QLabel;

    m_pvbxLayout = new QVBoxLayout;

    m_time->setSegmentStyle(QLCDNumber::Filled);
    m_date->setSegmentStyle(QLCDNumber::Filled);

    m_pvbxLayout->addWidget(m_time, 3);
    m_pvbxLayout->addWidget(m_date, 1);

    this->setLayout(m_pvbxLayout);

    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Clock::showTime);
    timer->start(500);

    showTime();
}

void Clock::showTime()
{

    m_time->display(QTime::currentTime().toString("hh:mm:ss"));
    m_date->display(QDate::currentDate().toString("dd-MM-yyyy"));
}
