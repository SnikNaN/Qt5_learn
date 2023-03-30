#ifndef PAINTSCENE_H
#define PAINTSCENE_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsSceneMouseEvent>

#include <QApplication>
#include <QPalette>
#include <QColorDialog>
#include <QFileDialog>
#include <QMessageBox>
#include <QWhatsThis>

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
    void setColor()
    {
        QColor color = QColorDialog::getColor(m_color);
        if (color.isValid())
        {
            m_color = color;
            m_color.setAlpha(m_opacity);
            QPalette palette = qApp->palette();
            palette.setColor(QPalette::ColorRole::Button, m_color);
            qApp->setPalette(palette);
        }
    }
    void setOpacity(int value)
    {
        m_opacity = value;
        m_color.setAlpha(m_opacity);
    }

    void saveFile()
    {
        QString str = QFileDialog::getSaveFileName(0, tr("Save"), "Pixmap", "*.png");
        if (!str.isEmpty())
        {
            QPixmap pix = (*views().begin())->grab();
            if (str.contains(".png"))
                pix.save(str, "PNG");
            else
                pix.save(str + ".png", "PNG");
        }
    }

    void exit()
    {
        QMessageBox* msg = new QMessageBox(QMessageBox::Warning,
                                           "Warning",
                                           "All unsaved changes will be lost.\nDo you really want to exit now?",
                                           QMessageBox::Yes | QMessageBox::No);
        if (msg->exec() == QMessageBox::Yes)
        {
            qApp->quit();
        }
        delete msg;
    }

    void whatsthis()
    {
        QWhatsThis::enterWhatsThisMode();
    }
};

#endif // PAINTSCENE_H
