#include "window.h"

void Window::mousePressEvent(QMouseEvent* pe)
{
    m_ptPosition = pe->pos();
    if (m_ptPosition.x() > rect().width() - 30 && m_ptPosition.y() < 30)
        qApp->quit();
}

void Window::mouseMoveEvent(QMouseEvent* pe)
{
    move(pe->globalPos() - m_ptPosition);
}

Window::Window(QWidget* pwgt)
    : QLabel(pwgt,  Qt::FramelessWindowHint | Qt::Window),
      m_lineWidth(10),
      m_col_1(Qt::red),
      m_col_2(Qt::green),
      m_col_3(Qt::blue)
{
    m_col_1.setAlpha(100);
    m_col_2.setAlpha(100);
    m_col_3.setAlpha(100);
}

void Window::paintEvent(QPaintEvent*)
{
    QImage   img(size(), QImage::Format_ARGB32_Premultiplied);
    QPainter painter;

    QPen pen(Qt::red);
    pen.setWidth(m_lineWidth);

    QBrush brush1(m_col_1, Qt::Dense5Pattern);
    QBrush brush2(m_col_2, Qt::Dense3Pattern);
    QBrush brush3(m_col_3, Qt::Dense2Pattern);

    painter.begin(&img);

    painter.eraseRect(rect());
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.drawPixmap(rect(), QPixmap(":/window.png"));

    painter.setPen(pen);
    painter.setBrush(brush1);
    painter.drawEllipse(0, 0, size().width(), size().height());

    painter.setBrush(brush2);
    QPolygon triangle;
    triangle << QPoint(rect().center().x(), 0) << rect().bottomLeft() << rect().bottomRight();
    painter.drawPolygon(triangle);

    painter.setBrush(brush3);
    QPolygon square;
    square << QPoint(rect().center().x(), 0)
           << QPoint(0, rect().center().y())
           << QPoint(rect().center().x(), rect().height())
           << QPoint(rect().width(), rect().center().y());

    painter.drawPolygon(square);
    painter.end();

    painter.begin(this);
    painter.drawImage(0, 0, img);
    painter.end();
}

void Window::setWidth(int width)
{
    m_lineWidth = width;
    update();
}

void Window::changeColor1()
{
    m_col_1 = Qt::GlobalColor(m_rnd.bounded(2, 19));
    m_col_3.setAlpha(100);
    update();
}

void Window::changeColor2()
{
    m_col_2 = Qt::GlobalColor(m_rnd.bounded(2, 19));
    m_col_3.setAlpha(100);
    update();
}

void Window::changeColor3()
{
    m_col_3 = Qt::GlobalColor(m_rnd.bounded(2, 19));
    m_col_3.setAlpha(100);
    update();
}
