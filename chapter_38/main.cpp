#include <QtConcurrent/QtConcurrent>
#include <QtWidgets>

// ----------------------------------------------------------------------
static QVector<QRgb> colorTable;

struct GrayscaleTaskInput
{
    QImage srcImg;
    int xFrom;
    int xTo;
    int yFrom;
    int yTo;
    QImage* destImg;
};

void makeRegionGrayscale(const GrayscaleTaskInput& task)
{
    for (int y = task.yFrom; y < task.yTo; ++y)
    {
        uchar* line = task.destImg->scanLine(y);
        for (int x = task.xFrom; x < task.xTo; ++x)
        {
            QRgb srcImgPixel = task.srcImg.pixel(x, y);
            QRgb* grayImgPixel = reinterpret_cast<QRgb*>(line + x);
            *grayImgPixel = qGray(srcImgPixel);
        }
    }
}

QImage convertToGrayscale(const QImage& img)
{
    QImage grayImg(img.size(), QImage::Format_Indexed8);
    grayImg.setColorTable(colorTable);

    int dy = img.height() / QThread::idealThreadCount();
    int y = 0;

    QVector<GrayscaleTaskInput> tasks;
    while (y < img.height() - dy)
    {
        tasks << GrayscaleTaskInput{img, 0, img.width(), y, y + dy, &grayImg};
        y += dy;
    }

    QFuture<void> future = QtConcurrent::map(tasks, makeRegionGrayscale);
    makeRegionGrayscale(GrayscaleTaskInput{img, 0, img.width(), y, img.height(), &grayImg});
    future.waitForFinished();

    return grayImg;
}

// ----------------------------------------------------------------------
int main(int argc, char** argv)
{
    QApplication app(argc, argv);

    QGraphicsScene  scn;
    QGraphicsView view(&scn);

    QImage img(QFileDialog::getOpenFileName(0, "Choose image", "./", "*.png *.jpg"));

    scn.addPixmap(QPixmap::fromImage(convertToGrayscale(img)));

    view.resize(img.size());
    view.show();

    return app.exec();
}

