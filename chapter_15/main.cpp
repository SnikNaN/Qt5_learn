#include <QtWidgets>
#include "MyFilter.h"

// ----------------------------------------------------------------------
int main (int argc, char** argv)
{
    QApplication app(argc, argv);

    QLineEdit txt("Try to type any text");
    txt.installEventFilter(new MyFilter(&txt));
    txt.resize(300, 100);
    txt.show();

    return app.exec();
}
