#include "propertylist.h"
#include <QApplication>
#include <QDir>
#include <QFileInfo>
#include <QSettings>

PropertyList::PropertyList()
{
    QFileInfo fi(QApplication::applicationFilePath());
    settingsFile = QDir::toNativeSeparators(QApplication::applicationDirPath() + "/" + fi.baseName() + ".settings");
    imagesPath =  QDir::toNativeSeparators(QApplication::applicationDirPath() + "/images/");
    models = scanPath(imagesPath, "*.model.*.png");     //load list of models
    backgrounds = scanPath(imagesPath, "*.background.png");     //load list of backgrounds
    if (!loadFromFile(settingsFile)) setDefault();
}

PropertyList::~PropertyList()
{
    saveToFile(settingsFile);
}

bool PropertyList::saveToFile(QString& filename)
{
    QSettings settings(filename, QSettings::IniFormat);
    settings.setValue("focalLenght", focalLenght);
    settings.setValue("diaphragm", diaphragm);
    settings.setValue("crop", crop);
    settings.setValue("distanceModel", distanceModel);
    settings.setValue("distanceBackgroud", distanceBackgroud);
    settings.setValue("strategy", strategy);
    settings.setValue("orientation", orientation);
    settings.setValue("currentModelIndex", currentModelIndex);
    settings.setValue("currentBackgroundIndex", currentBackgroundIndex);
    return true;
}

bool PropertyList::loadFromFile(QString& filename)
{
    QSettings settings(filename, QSettings::IniFormat);
    QVariant v = settings.value("focalLenght");
    if (!v.isValid()) return false;
    setFocalLenght(v.toDouble());

    v = settings.value("diaphragm");
    if (!v.isValid()) return false;
    setDiaphragm(v.toDouble());

    v = settings.value("crop");
    if (!v.isValid()) return false;
    setCrop(v.toDouble());

    v = settings.value("distanceModel");
    if (!v.isValid()) return false;
    setDistanceModel(v.toDouble());

    v = settings.value("distanceBackgroud");
    if (!v.isValid()) return false;
    setDistanceBackgroud(v.toDouble());

    v = settings.value("strategy");
    if (!v.isValid()) return false;
    setStrategy(static_cast<Strategy>(v.toInt()) );

    v = settings.value("orientation");
    if (!v.isValid()) return false;
    setOrientation(static_cast<Orientation>(v.toInt()) );

    v = settings.value("currentModelIndex");
    if (!v.isValid()) return false;
    setCurrentModelIndex(v.toInt());

    v = settings.value("currentBackgroundIndex");
    if (!v.isValid()) return false;
    setCurrentBackgroundIndex(v.toInt());

    return true;
}

QStringList PropertyList::scanPath(QString path, QString mask)
{
    return QStringList();
}

void PropertyList::setFocalLenght(double value)
{
    focalLenght = setRange(value, 1.0, 1000.0);
}

void PropertyList::setDiaphragm(double value)
{
    diaphragm = setRange(value, 0.95, 32.0);
}

void PropertyList::setCrop(double value)
{
    crop = setRange(value, 0.1, 16.0);
}

void PropertyList::setDistanceModel(double value)
{
    if (value > getDistanceBackgroud()) value = getDistanceBackgroud();
    distanceModel = setRange(value, 0.5, 50.0);
}

void PropertyList::setDistanceBackgroud(double value)
{
    if (value < getDistanceModel()) value = getDistanceModel();
    distanceBackgroud = setRange(value, 1.0, 500.0);
}

void PropertyList::setStrategy(Strategy value)
{
    strategy = value;
}

void PropertyList::setOrientation(Orientation value)
{
    orientation = value;
}

QStringList PropertyList::getModels()
{
    models.append("Model 1");
    models.append("Model 2");
    models.append("Model 3");
    return models;
}

void PropertyList::setCurrentModelIndex(int value)
{
//    if (models.count() == 0) currentModelIndex = -1;
//    else currentModelIndex = setRange(value, 0, models.count()-1);
    currentModelIndex = value;
}

QStringList PropertyList::getBackgrounds()
{
    backgrounds.append("Background 1");
    backgrounds.append("Background 2");
    backgrounds.append("Background 3");
    return backgrounds;
}

void PropertyList::setCurrentBackgroundIndex(int value)
{
//    if (backgrounds.count() == 0) currentBackgroundIndex = -1;
//    else currentBackgroundIndex = setRange(value, 0, backgrounds.count()-1);
    currentBackgroundIndex = value;
}

void PropertyList::setDefault()
{
    setFocalLenght(50);
    setDiaphragm(1.4);
    setCrop(1);
    setDistanceModel(3);
    setDistanceBackgroud(50);
    setCurrentModelIndex(0);
    setCurrentBackgroundIndex(0);
    setStrategy(Portrait);
    setOrientation(Book);
}

template<class T>
T PropertyList::setRange(T value, T min, T max)
{
    if (value < min) value = min;
    else if (value > max) value = max;
    return value;
}
