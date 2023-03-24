// ======================================================================
// Digital clock with different colour schemes from chapter_08
// + added settings saving for size & color scheme
// ======================================================================

#include <QApplication>
#include "Buttons.h"

// ----------------------------------------------------------------------
int main (int argc, char** argv)
{
    QApplication app(argc, argv);

    Buttons buttons;

    buttons.show();

    return app.exec();
}
