#include "paintscene.h"

PaintScene::PaintScene(QObject *parent)
    : QGraphicsScene(parent),
      m_wide(50),
      m_prevPoint(QPointF(0,0)),
      m_color(Qt::red),
      m_opacity(100)
{
    m_color.setAlpha(m_opacity);
    QPalette palette = qApp->palette();
    palette.setColor(QPalette::ColorRole::Button, m_color);

    qApp->setPalette(palette);
}

PaintScene::~PaintScene()
{

}

void PaintScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    addEllipse(event->scenePos().x() - m_wide / 2,
               event->scenePos().y() - m_wide / 2,
               m_wide, m_wide, QPen(Qt::NoPen), QBrush(m_color));
    m_prevPoint = event->scenePos();
}

void PaintScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    addLine(m_prevPoint.x(), m_prevPoint.y(), event->scenePos().x(), event->scenePos().y(), QPen(m_color, m_wide, Qt::SolidLine, Qt::RoundCap));
    m_prevPoint = event->scenePos();
}
