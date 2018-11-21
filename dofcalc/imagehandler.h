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
    int imagesCount() { return images.size(); }
    QImage getImageOrigin(size_t index) { return images[index].first; } //математика работает с ним же
    void setImageResult(QImage img, size_t index) { images[index].second = img; }
     QImage getImageResult(size_t index) { return images[index].second; }

private:
    vector< pair<QImage,QImage> > images;

//    class Con //подкласс
};

#endif // IMAGEHANDLER_H
