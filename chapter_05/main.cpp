#include <QtWidgets>
#include <QStackedWidget>
// ----------------------------------------------------------------------
// QStackedWidget, QScrollArea, QCursor, QPalette
// ----------------------------------------------------------------------
class AutoToggle: public QStackedWidget
{
private:
    int idx;
    int cnt;

protected:
    virtual void timerEvent(QTimerEvent*)
    {
        idx++;
        if (idx == cnt)
            idx = 0;
        setCurrentIndex(idx);
    }

public:
    AutoToggle(int nInterval, QWidget* pwgt = 0) : QStackedWidget(pwgt), idx(0), cnt(0)
    {
        startTimer(nInterval);
    }
    int add(QWidget *w)
    {
        cnt++;
        return addWidget(w);
    }
};

int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    QWidget      wgt;
    AutoToggle* st = new AutoToggle(1000, &wgt);

    QPixmap      pix1(":/clock.png");
    QCursor      cur(pix1);

    st->setCursor(cur);

    QScrollArea* sa = new QScrollArea(&wgt);

    QWidget* pwgt = new QWidget;
    QPixmap      pix2(":/img.jpg");

    QPalette pal;
    pal.setBrush(pwgt->backgroundRole(), QBrush(pix2));
    pwgt->setPalette(pal);
    pwgt->setAutoFillBackground(true);
    pwgt->setFixedSize(pix2.width(), pix2.height());

    sa->setWidget(pwgt);
    sa->resize(350, 500);
    sa->move(500, 0);

    QWidget pwgt1;
    QPalette pal1;
    pal1.setColor(pwgt1.backgroundRole(), Qt::blue);
    pwgt1.setPalette(pal1);
    pwgt1.setAutoFillBackground(true);

    QWidget pwgt2;
    QPalette pal2;
    pal2.setBrush(pwgt2.backgroundRole(), QBrush(QPixmap(":/stone.jpg")));
    pwgt2.setPalette(pal2);
    pwgt2.setAutoFillBackground(true);

    QWidget pwgt3;
    QPalette pal3;
    pal3.setColor(pwgt3.backgroundRole(), Qt::red);
    pwgt3.setPalette(pal3);
    pwgt3.setAutoFillBackground(true);

    QWidget pwgt4;
    QPalette pal4;
    pal4.setColor(pwgt4.backgroundRole(), Qt::green);
    pwgt4.setPalette(pal4);
    pwgt4.setAutoFillBackground(true);

    st->add(&pwgt1);
    st->add(&pwgt2);
    st->add(&pwgt3);
    st->add(&pwgt4);
    st->resize(500, 500);
    st->move(0, 0);
    st->setFrameStyle(QFrame::Box | QFrame::Raised);
    st->setLineWidth(5);

    wgt.resize(900, 600);
    wgt.show();


    return app.exec();
}
