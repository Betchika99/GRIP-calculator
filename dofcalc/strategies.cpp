#include <strategies.h>
#include <QFileInfo>
#include <QDir>
#include <QApplication>


QStringList Strategy::scanDirForFriendlyName(QString fileMask)
{
    QStringList files = scanDirForFileName(fileMask);
    QStringList result;
    for (int i = 0; i < files.count(); ++i) {
        result.append(files[i].split('.')[1]);
    }
    return result;
}

QStringList Strategy::scanDirForFileName(QString fileMask)
{
    QString path = QDir::toNativeSeparators(QApplication::applicationDirPath() + "/");
    QDir d(path);
    d.setNameFilters(QStringList() << fileMask);
    QStringList files;
    for (int i = 0; i < d.entryList().count(); ++i) {
        files.append(path + d.entryList()[i]);
    }

    return files;
}


QStringList Portrait::getModelFileNames()
{
    QString fileMask = StrategyName() + ".*.*.Model.png";
    return scanDirForFileName(fileMask);
}


QStringList Portrait::getBackgroundFileNames()
{
    QString fileMask = StrategyName() + ".*.*.Background.png";
    return scanDirForFileName(fileMask);
}

QString Portrait::StrategyName()
{
    return "Портретная съемка";     //friendly name for strategy
}

QStringList Portrait::getModel()
{
    QString fileMask = StrategyName() + ".*.*.Model.png";
    return scanDirForFriendlyName(fileMask);
}

QStringList Portrait::getBackground()
{
    QString fileMask = StrategyName() + ".*.*.Background.png";
    return scanDirForFriendlyName(fileMask);
}

Triple<double> Portrait::FocalLenght()
{
    return Triple<double>(35,300,85);    //для кропа = 1
}

Triple<double> Portrait::Diaphragm()
{
    return Triple<double>(0.95,8,1.8);
}

Triple<double> Portrait::ModelDistance()
{
    return Triple<double>(1,10,3);
}

Triple<double> Portrait::BackgroundDistance()
{
    return Triple<double>(1,100,50);
}
