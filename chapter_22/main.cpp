#include <QtWidgets>

// ----------------------------------------------------------------------
int main(int argc, char** argv)
{
    QApplication app(argc, argv);    
    QLabel       lbl;
    QMovie*      mov = new QMovie(":/anim.mng");

    lbl.setAttribute(Qt::WA_TranslucentBackground);
    lbl.setWindowFlag(Qt::FramelessWindowHint);
    lbl.setWindowFlag(Qt::WindowStaysOnTopHint);

    mov->start();

    lbl.setMovie(mov);

    QPropertyAnimation* anim1 = new QPropertyAnimation(mov, "speed");
    anim1->setStartValue(100);
    anim1->setKeyValueAt(0.25f, 200);
    anim1->setKeyValueAt(0.5f, 400);
    anim1->setKeyValueAt(0.75f, 150);
    anim1->setEndValue(100);
    anim1->setDuration(12000);
    anim1->setLoopCount(-1);

    QPropertyAnimation* anim2 = new QPropertyAnimation(&lbl, "geometry");
    anim2->setStartValue(QRect(0, 0, 128, 128));
    anim2->setKeyValueAt(0.25f, QRect(800, 200, 128, 128));
    anim2->setKeyValueAt(0.5f, QRect(qApp->screens().at(0)->size().width() - 128,
                                    qApp->screens().at(0)->size().width() - 128,
                                    128, 128));
    anim2->setKeyValueAt(0.75f, QRect(200, 500, 128, 128));
    anim2->setEndValue(QRect(0, 0, 128, 128));
    anim2->setDuration(15000);
    anim2->setLoopCount(-1);
    anim2->setEasingCurve(QEasingCurve::InOutBounce);

    QParallelAnimationGroup* agroup = new QParallelAnimationGroup(&lbl);
    agroup->addAnimation(anim1);
    agroup->addAnimation(anim2);

    agroup->start();

    lbl.show();

    return app.exec();
}

