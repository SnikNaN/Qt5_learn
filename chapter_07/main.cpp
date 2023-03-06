// ======================================================================
// LCD Clock with milliseconds as progress bar
// ======================================================================

#include "Headers/Clock.hpp"

// ----------------------------------------------------------------------
int main (int argc, char** argv)
{
    QApplication app(argc, argv);

    Clock wgt;

    wgt.resize(800, 250);
    wgt.show();

    return app.exec();
}
