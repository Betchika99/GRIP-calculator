#ifndef IMAGEHANDLER_H
#define IMAGEHANDLER_H
#include <QVector>
#include <QImage>


class ImageHandler
{
public:
    ImageHandler() {}

public:
    bool loadFromFile(QString filemask);
    void clean() { images.clear(); }
    int layersCount() { return images.count(); }
    QImage& getLayer(int index) { return images[index]; } //математика работает с ним же

private:
    QVector<QImage> images;

//    class Con //подкласс
};

#endif // IMAGEHANDLER_H
