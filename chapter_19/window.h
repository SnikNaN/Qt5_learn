#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QLabel>
#include <QPainter>
#include <QEvent>
#include <QMouseEvent>
#include <QApplication>
#include <QRandomGenerator>

class Window : public QLabel {
private:
    QPoint m_ptPosition;
    int m_lineWidth;
    QColor  m_col_1;
    QColor  m_col_2;
    QColor  m_col_3;
    QRandomGenerator m_rnd;

protected:
    virtual void mousePressEvent(QMouseEvent* pe);

    virtual void mouseMoveEvent(QMouseEvent* pe);

public:
    Window(QWidget* pwgt = 0);

    void paintEvent(QPaintEvent*);

public slots:
    void setWidth(int width);
    void changeColor1();
    void changeColor2();
    void changeColor3();
};

#endif // WINDOW_H
