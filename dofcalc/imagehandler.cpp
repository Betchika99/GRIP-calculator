#include "imagehandler.h"
#include <QDir>
#include <QFileInfo>
#include <QApplication>
#include <QPixmap>
#include <QPainter>
#include <QPoint>

ImageHandler::ImageHandler()
{
    QString modelBodyPath = QDir::toNativeSeparators(QApplication::applicationDirPath() + "/Model1.png");
    QString backgroundPath = QDir::toNativeSeparators(QApplication::applicationDirPath() + "/Background1.png");
    images.resize(2);

    background().load(backgroundPath);
    model().load(modelBodyPath);
}

Image ImageHandler::gluedImage(int shiftX)
{
    Image result = background();
    QPoint pos;

//    int modelWidht = model().asQImage().width();
    int modelHeight = model().asQImage().height();
    int backgroundWidth = background().asQImage().width();
    int backgroundHeight = background().asQImage().height();

    if (modelHeight > backgroundHeight)
    {
        pos.setX(backgroundWidth/3 + shiftX);
        pos.setY(backgroundHeight/2);
    }
    else
    {
        pos.setX(backgroundWidth/3  + shiftX);
        pos.setY(backgroundHeight - modelHeight);
    }
//    img.setCompositionMode(QPainter::CompositionMode_SourceIn);
    result.imposeImages(model(),pos);
    return result;
}

//void ImageHandler::UpdateImages(int indexModel, int indexBack)
//{
//    QString tempModel = QString::number(indexModel+1);
//    QString tempBack = QString::number(indexBack+1);

//    QString modelBodyPath = QDir::toNativeSeparators(QApplication::applicationDirPath() + "/Model"+tempModel+".png");
//    QString backgroundPath = QDir::toNativeSeparators(QApplication::applicationDirPath() + "/Background"+tempBack+".png");

//    background().load(backgroundPath);
//    model().load(modelBodyPath);
//}

void ImageHandler::UpdateImages(QString modelBodyPath, QString backgroundPath)
{
    background().load(backgroundPath);
    model().load(modelBodyPath);
}


//bool ImageHandler::loadFromFile(QString filemask)
//{
//    clean();
//    QFileInfo fi(filemask);
//    QDir d(fi.path());
//    d.setNameFilters( QStringList() << fi.fileName() );
//    QStringList files = d.entryList();

//    images.resize(files.count());
//    for (int i=0; i < files.count(); i++)
//    {
//        bool res = images[i].load( QDir::toNativeSeparators(fi.path()+'/'+files[i]));
//        if (!res)
//        {
//            clean();
//            return false;
//        }
//    }
//    return true;
//}
