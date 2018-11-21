#include "imagehandler.h"
#include <QDir>
#include <QFileInfo>
#include <QApplication>
#include <QPixmap>

ImageHandler::ImageHandler()
{
    //QString modelFacePath = QDir::toNativeSeparators(QApplication::applicationDirPath() + "/Model1.png");
    QString modelBodyPath = QDir::toNativeSeparators(QApplication::applicationDirPath() + "/Model1.png");
    QString backgroundPath = QDir::toNativeSeparators(QApplication::applicationDirPath() + "/Background1.png");

    QPixmap model(modelBodyPath);
    QPixmap background(backgroundPath);

    images.resize(3);

    images[0].first = model.toImage();
    images[1].first = model.toImage();
    images[2].first = background.toImage();
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
