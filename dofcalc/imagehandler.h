#ifndef IMAGEHANDLER_H
#define IMAGEHANDLER_H

#include "image.h"
#include <vector>

using std::vector;

class ImageHandler
{
private:
    const unsigned int SupportedLayersCount = 2;

public:
    ImageHandler();
    ImageHandler(const ImageHandler& source) { images = source.images; }
    ImageHandler& operator = (const ImageHandler& source) { images = source.images; return *this; }
    unsigned int layersCount() { return images.size(); }
    Image gluedImage(int shiftX = 0);
    Image& background() { return images[0]; }
    Image& model() { return images[1]; }
    bool isValid() { return model().isValid() && background().isValid(); }
    void loadImages(QString backgroundFileName, QString modelFileName);

private:
    vector<Image> images;
};

#endif // IMAGEHANDLER_H
