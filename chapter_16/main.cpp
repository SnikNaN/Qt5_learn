#include <QtWidgets>
#include "MyFilter.h"

// ----------------------------------------------------------------------
int main (int argc, char** argv)
{
    QApplication app(argc, argv);

    QTextEdit txt("Try to press Shift + any letter: ");
    txt.installEventFilter(new MyFilter(&txt));
    txt.resize(500, 100);
    txt.show();

    return app.exec();
}
