#ifndef PAINTSCENE_H
#define PAINTSCENE_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>

#include <QApplication>
#include <QPalette>

class PaintScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit PaintScene(QObject *parent = nullptr);
    ~PaintScene();
private:
    int m_wide;
    QPointF m_prevPoint;
    QColor  m_color;
    int     m_opacity;

private:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);

public slots:
    void setBrushSize(int value)
    {
        m_wide = value;
    }
    void setRed(int value)
    {
        m_color.setRed(value);
        QPalette palette = qApp->palette();
        palette.setColor(QPalette::ColorRole::Button, m_color);

        qApp->setPalette(palette);
    }
    void setGreen(int value)
    {
        m_color.setGreen(value);
        QPalette palette = qApp->palette();
        palette.setColor(QPalette::ColorRole::Button, m_color);

        qApp->setPalette(palette);
    }
    void setBlue(int value)
    {
        m_color.setBlue(value);
        QPalette palette = qApp->palette();
        palette.setColor(QPalette::ColorRole::Button, m_color);

        qApp->setPalette(palette);
    }
    void setOpacity(int value)
    {
        m_opacity = value;
        m_color.setAlpha(m_opacity);
    }
};

#endif // PAINTSCENE_H
