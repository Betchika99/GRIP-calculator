#include "imagehandler.h"
#include <QDir>
#include <QFileInfo>

bool ImageHandler::loadFromFile(QString filemask)
{
    clean();
    QFileInfo fi(filemask);
    QDir d(fi.path());
    d.setNameFilters( QStringList() << fi.fileName() );
    QStringList files = d.entryList();

    images.resize(files.count());
    for (int i=0; i < files.count(); i++)
    {
        bool res = images[i].load( QDir::toNativeSeparators(fi.path()+'/'+files[i]));
        if (!res)
        {
            clean();
            return false;
        }
    }
    return true;
}
