#include <QApplication>
#include "Widget.h"
#include "dropwidget.h"

// ----------------------------------------------------------------------
int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    Widget       wgt1;
    Widget       wgt2;
    DropWidget  dropWgt;

    QFile file(":/style/simple.qss");
    file.open(QFile::ReadOnly);
    QString strCSS = QLatin1String(file.readAll());

    wgt1.setWindowTitle("Widget1");
    wgt1.resize(200, 100);
    wgt1.show();
    wgt1.setText("widget1");
    wgt1.setStyleSheet(strCSS);

    wgt2.setWindowTitle("Widget2");
    wgt2.resize(200, 100);
    wgt2.show();
    wgt2.setText("widget2");
    wgt2.setStyleSheet(strCSS);

    dropWgt.show();

    return app.exec();
}
