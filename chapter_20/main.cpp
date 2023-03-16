#include <QtWidgets>

// ======================================================================
class DrawTextWidget : public QWidget {
protected:
    virtual void paintEvent(QPaintEvent*)
    {
        QPainter painter(this);

        QLinearGradient gradient(0, 0, 500, 0);
        gradient.setColorAt(0, Qt::darkCyan);
        gradient.setColorAt(0.5, Qt::magenta);
        gradient.setColorAt(1, Qt::green);
        painter.setPen(QPen(gradient, 0));
        painter.setFont(QFont("Verdana", 9, QFont::Bold));
        QString  str = "This is a long gradient text. Please, resize the window";
        QString  strElided =
            fontMetrics().elidedText(str, Qt::ElideMiddle, width());

        painter.drawText(rect(), !Qt::TextWordWrap, strElided);
    }

public:
    DrawTextWidget(QWidget* pwgt = 0) : QWidget(pwgt)
    {
        resize(200, 20);
    }
};


// ----------------------------------------------------------------------
int main(int argc, char** argv)
{
    QApplication app(argc, argv);

    DrawTextWidget dtw;

    dtw.show();

    return app.exec();
}
