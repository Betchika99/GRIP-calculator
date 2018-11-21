#ifndef IMAGEHANDLER_H
#define IMAGEHANDLER_H
#include <QVector>
#include <QImage>

#include <vector>

using std::vector;
using std::pair;


class ImageHandler
{

public:
    ImageHandler();
    //bool loadFromFile(QString filemask);
    //void clean() { images.clear(); }
    //int layersCount() { return images.count(); }
    QImage getImage(size_t index) { return images[index].first; } //математика работает с ним же
    void setImage(QImage img, size_t index) { images[index].second = img; }

private:

    vector< pair<QImage,QImage> > images;

//    class Con //подкласс
};

#endif // IMAGEHANDLER_H
