#ifndef IMAGE_H
#define IMAGE_H

#include "logger.h"
#include "toolslibrary.h"
#include <QImage>
#include <QPixmap>
#include <QPainter>

class Image{
public:
    Image() { painter.begin(&pixmap); }
    //инициализация через file
    Image(QString fileName) { pixmap.load(fileName); painter.begin(&pixmap); } //проверить на валидность //
    //инициализация через QImage
    Image(QImage image) { pixmap.convertFromImage(image); painter.begin(&pixmap); }
    //инициализация через QPixmap
    Image(QPixmap pm) { pixmap = pm; painter.begin(&pixmap); }
    Image(const Image &img) { pixmap = img.asQPixmap(); painter.begin(&pixmap); }
    ~Image() { painter.end(); }

    QImage asQImage() { return pixmap.toImage(); }
    const QPainter& asQPainter() const { return painter; }
    const QPixmap& asQPixmap() const { return pixmap; }

    //накладывает картинку на саму себя
    void imposeImages(const Image& imgFon, QPoint pos){ painter.drawPixmap(pos, imgFon.asQPixmap()); }

    void fill(const QColor &color = Qt::white) { pixmap.fill(color); }
    bool isValid() const { return !pixmap.isNull(); }
    Image scale(const QSize& size) { QPixmap pm = pixmap.scaled(size, Qt::KeepAspectRatio, Qt::SmoothTransformation); return Image(pm); }
    Image scale(int widht, int height) { return scale(QSize(widht, height)); }
    void load(QString fileName)
    {
        bool success = pixmap.load(fileName);
        if (!success) Log("Image.load(): failed to load %s", fileName.toUtf8().data());
    }
    Image& operator=(const Image &img) { pixmap = img.asQPixmap(); return *this; }
    Image& operator=(const QImage &img) { pixmap.convertFromImage(img); return *this; }


private:
    QPixmap pixmap;
    QPainter painter;
};


#endif // IMAGE_H

