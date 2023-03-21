#include <QApplication>
#include "OGLPyramid.h"

// ----------------------------------------------------------------------
int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    OGLPyramid   oglPyramid;

    oglPyramid.resize(600, 600);
    oglPyramid.show();

    return app.exec();
}
