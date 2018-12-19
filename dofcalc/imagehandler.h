#ifndef IMAGEHANDLER_H
#define IMAGEHANDLER_H
#include "image.h"

#include <vector>

using std::vector;

class ImageHandler
{
public:
    ImageHandler();
    ImageHandler(const ImageHandler& source) { images = source.images; }
    unsigned int layersCount() { return images.size(); }
//    Image getImage(unsigned int index) { return images[index]; } //математика работает с ним же
//    void setImage(Image img, unsigned  int index) { images[index] = img; }
    Image gluedImage(int shiftX = 0);
    Image& model() { return images[1]; }
    Image& background() { return images[0]; }
    bool isValid() { return model().isValid() && background().isValid(); }
    void UpdateImages(QString modelBodyPath, QString backgroundPath);
//    void UpdateImages(QString fileName);

private:
    vector<Image> images;

//    class Con //подкласс
};

#endif // IMAGEHANDLER_H
