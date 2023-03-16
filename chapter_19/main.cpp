#include <QtWidgets>

#include "window.h"
// ======================================================================

// ----------------------------------------------------------------------
int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    Window       wnd;

    wnd.setAttribute(Qt::WA_TranslucentBackground);
    QPixmap pix(":/window.png");

    wnd.setPixmap(pix);

    QHBoxLayout* pgl = new QHBoxLayout;
    QVBoxLayout* vbxl = new QVBoxLayout;

    QPushButton* btn1 = new QPushButton("col1");
    QPushButton* btn2 = new QPushButton("col2");
    QPushButton* btn3 = new QPushButton("col3");

    QSlider* slider = new QSlider(Qt::Horizontal);
    slider->setMaximum(20);
    slider->setMinimum(1);
    slider->setValue(10);

    wnd.connect(slider, &QSlider::valueChanged, &wnd, &Window::setWidth);
    wnd.connect(btn1, &QPushButton::clicked, &wnd, &Window::changeColor1);
    wnd.connect(btn2, &QPushButton::clicked, &wnd, &Window::changeColor2);
    wnd.connect(btn3, &QPushButton::clicked, &wnd, &Window::changeColor3);

    QSpacerItem* sp = new QSpacerItem(wnd.rect().width(), wnd.rect().height());
    vbxl->addSpacerItem(sp);
    vbxl->addLayout(pgl);

    pgl->addWidget(btn1);
    pgl->addWidget(btn2);
    pgl->addWidget(btn3);
    pgl->addWidget(slider);

    wnd.setLayout(vbxl);

    wnd.show();

    return app.exec();
}
