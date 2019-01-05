#include <QtCore>
#include "imagehandler.h"

ImageHandler::ImageHandler()
{
    images.resize(SupportedLayersCount);
}

Image ImageHandler::gluedImage(int shiftX)
{
    Image result = background();
    QPoint pos;

    int modelWidht = model().asQImage().width();
    int modelHeight = model().asQImage().height();
    int backgroundWidth = background().asQImage().width();
    int backgroundHeight = background().asQImage().height();

    if (modelHeight < backgroundHeight)
    {
        pos.setX((backgroundWidth-modelWidht)/2+shiftX);
        pos.setY(backgroundHeight-modelHeight);
    }
    else
    {
        pos.setX((backgroundWidth-modelWidht)/2  + shiftX);
        pos.setY(0);
    }
    result.imposeImages(model(), pos);
    return result;
}

void ImageHandler::loadImages(QString backgroundFileName, QString modelFileName)
{
    background().load(backgroundFileName);
    model().load(modelFileName);
}
