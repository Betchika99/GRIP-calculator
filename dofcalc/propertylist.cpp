#include "propertylist.h"
#include <QApplication>
#include <QDir>
#include <QFileInfo>
#include <QSettings>

PropertyList::PropertyList()
{
    strategies.resize(1);
    strategies[0] = new Portrait;
//    strategies[1] = new Macro;
//    strategies[2] = new CloseUp;
//    strategies[3] = new Landscape;



    QFileInfo fi(QApplication::applicationFilePath());
    settingsFile = QDir::toNativeSeparators(QApplication::applicationDirPath() + "/" + fi.baseName() + ".settings");
//    imagesPath =  QDir::toNativeSeparators(QApplication::applicationDirPath() + "/images/");
//    models = scanPath(imagesPath, "*.model.*.png");     //load list of models
//    backgrounds = scanPath(imagesPath, "*.background.png");     //load list of backgrounds
    /*if (!loadFromFile(settingsFile))*/ setCurrentStrategyIndex(0);
}

PropertyList::~PropertyList()
{
    saveToFile(settingsFile);
    for (int i = 0; i < strategies.size(); i++) delete strategies[i];
}

bool PropertyList::saveToFile(QString& filename)
{
    QSettings settings(filename, QSettings::IniFormat);
    settings.setValue("focalLenght", focalLenght);
    settings.setValue("diaphragm", diaphragm);
    settings.setValue("crop", crop);
    settings.setValue("distanceModel", distanceModel);
    settings.setValue("distanceBackgroud", distanceBackgroud);
    settings.setValue("strategy", currentStrategyIndex);
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
    setCurrentStrategyIndex(v.toInt());

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

//QStringList PropertyList::scanPath(QString path, QString mask)
//{
//    return QStringList();
//}

void PropertyList::setFocalLenght(double value)
{
    focalLenght = setRange(value, currentStrategy->FocalLenght());
}

void PropertyList::setDiaphragm(double value)
{
    diaphragm = setRange(value, currentStrategy->Diaphragm());
}

void PropertyList::setCrop(double value)
{
    crop = setRange(value, 0.1, 16.0);
}

void PropertyList::setCurrentCropIndex(int value)
{
    currentCropIndex = value;
}

QStringList PropertyList::getCrops()
{
    crops.append("Full Frame");
    crops.append("APC-C");
    crops.append("Four Thirds");
    return crops;
}

void PropertyList::setDistanceModel(double value)
{
    if (value > getDistanceBackgroud()) value = getDistanceBackgroud();
    distanceModel = setRange(value, currentStrategy->ModelDistance());
}

void PropertyList::setDistanceBackgroud(double value)
{
    if (value < getDistanceModel()) value = getDistanceModel();
    distanceBackgroud = setRange(value, currentStrategy->BackgroundDistance());
}

//void PropertyList::setStrategy(int index)
//{
//    currentStrategyIndex = index;
//    currentStrategy = strategies[index];
//}

void PropertyList::setOrientation(Orientation value)
{
    orientation = value;
}

QStringList PropertyList::getModels()
{
//    models.append("Катя");
//    models.append("Лиза");
//    models.append("Виталя");
    models = currentStrategy->getModel();
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
    backgrounds.append("Какая-то улица");
    backgrounds.append("Красная площадь");
    backgrounds.append("Офис Mail.ru");
    return backgrounds;
}

void PropertyList::setCurrentBackgroundIndex(int value)
{
//    if (backgrounds.count() == 0) currentBackgroundIndex = -1;
//    else currentBackgroundIndex = setRange(value, 0, backgrounds.count()-1);
    currentBackgroundIndex = value;
}

QStringList PropertyList::getStrategies()
{
    QStringList result;
    for (int i = 0; i < strategies.size(); ++i) {
        result.append(strategies[i]->StrategyName());
    }
    return result;
}

QString PropertyList::getCurrentStrategyModelFileName()
{
    QStringList result = currentStrategy->getModelFileNames();
    return result[currentModelIndex];
}

QString PropertyList::getCurrentStrategyBackgroundFileName()
{
    QStringList result = currentStrategy->getBackgroundFileNames();
    return result[currentBackgroundIndex];
}

void PropertyList::setCurrentStrategyIndex(int value)
{
   if (value >= strategies.size() || value < 0) value = 0;
   currentStrategyIndex = value;
   currentStrategy = strategies[currentStrategyIndex];
   setDefault(); //todo: нужно сделать восстановление из dofcalk.settings
}

void PropertyList::setDefault()
{
    setFocalLenght(currentStrategy->FocalLenght().defaultValue);
    setDiaphragm(currentStrategy->Diaphragm().defaultValue);
    setCrop(1);
    setDistanceModel(currentStrategy->ModelDistance().defaultValue);
    setDistanceBackgroud(currentStrategy->BackgroundDistance().defaultValue);
    setCurrentModelIndex(0);
    setCurrentBackgroundIndex(0);
//    setCurrentStrategyIndex(0);
    setOrientation(Book);
}

template<class T>
T PropertyList::setRange(T value, Triple<T> range)
{
    if (value < range.min) value = range.min;
    else if (value > range.max) value = range.max;
    return value;
}

template<class T>
T PropertyList::setRange(T value, T min, T max)
{
    if (value < min) value = min;
    else if (value > max) value = max;
    return value;
}
