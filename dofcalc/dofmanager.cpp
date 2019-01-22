#include "dofmanager.h"
#include "toolslibrary.h"
#include <QtCore>

const std::vector<PropertySwitch<Orientation>::SwitchPair> Orientations =
{
    {"Альбомная", Album},
    {"Книжная", Book},
};

const std::vector<PropertySwitch<double>::SwitchPair> Crops =
{
    {"Full Frame", 1.0},
    {"APC-H", 1.3},
    {"Nikon DX", 1.5},
    {"APC-C", 1.6},
    {"Four Thirds", 2.0},
    {"1 дюйм", 2.7},
    {"2/3 дюйма", 4.0},
};

DOFManager::DOFManager()
{
    loadConstantProperties();
    api.loadStrategyList(sl);
    sl.updatePropertyList(pl);
    api.loadFavoriteList(fl);
    reloadImages();
}

void DOFManager::loadConstantProperties()
{
    for (size_t i = 0; i < Orientations.size(); i++)
        pl.orientation.addEntry(Orientations[i].title, Orientations[i].value);
    for (size_t i = 0; i < Crops.size(); i++)
        pl.crop.addEntry(Crops[i].title, Crops[i].value);
    pl.orientation.setIndex(0);
    pl.crop.setIndex(0);
    pl.cropFactor.set(0.5, 10, pl.crop.value());
}

void DOFManager::setStrategy(int index)
{
    sl.strategies.setIndex(index);
    sl.updatePropertyList(pl);
    reloadImages();
}

void DOFManager::setBackground(int index)
{
    pl.background.setIndex(index);
    reloadImages();
}

void DOFManager::setModel(int index)
{
    pl.model.setIndex(index);
    reloadImages();
}

void DOFManager::setOrientation(int index)
{
    pl.orientation.setIndex(index);
    reloadImages();
}

void DOFManager::setCrop(int index)
{
    pl.crop.setIndex(index);
    pl.cropFactor.setValue(roundTo(pl.crop.value(), 2));
}

void DOFManager::setCropFactor(double value)
{
    pl.cropFactor.setValue(value);
    pl.crop.setIndexByValue(roundTo(pl.cropFactor.value(), 2));
}

void DOFManager::setModelDistance(double value)
{
    pl.modelDistance.setValue(value);
}

void DOFManager::setBackgroundDistance(double value)
{
    pl.backgroundDistance.setValue(value);
}

void DOFManager::setFocalLength(double value)
{
    pl.focalLength.setValue(value);
}

void DOFManager::setDiaphragm(double value)
{
    pl.diaphragm.setValue(value);
}

bool DOFManager::loadFavorite(QString title)
{
    fl.setIndexByTitle(title);
    bool success = fl.index() >= 0 && api.loadFavorite(fl.title(), sl, pl);
    if (success)
    {
        setCropFactor(pl.cropFactor.value());
        reloadImages();
    }
    return success;
}

bool DOFManager::saveFavorite(QString title)
{
    bool success = api.saveFavorite(title, sl, pl);
    if (success)
    {
        api.loadFavoriteList(fl);
        fl.setIndexByTitle(title);
    }
    return success;
}

void DOFManager::deleteFavorite(QString title)
{
    if (api.deleteFavorite(title))
    {
        api.loadFavoriteList(fl);
        fl.setIndex(-1);
    }
}

void DOFManager::resetToDefaults()
{
    pl.modelDistance.reset();
    pl.backgroundDistance.reset();
    pl.focalLength.reset();
    pl.diaphragm.reset();
}

void DOFManager::performImageProcessing()
{
    result = origin;
    ml.Blur(&pl, result);
    ml.Scale(&pl, result);
}

void DOFManager::reloadImages()
{
    origin.loadImages(ImagePath()+pl.background.value(), ImagePath()+pl.model.value());
}

double DOFManager::roundTo(double value, int precision)
{
    double multiplier = pow(10, precision);
    return qRound(value * multiplier) / multiplier;
}

double DOFManager::getGRIP()
{
    return ml.FindGRIP(&pl);
}

double DOFManager::getHyperFocal()
{
    return ml.FindHyperFocal(&pl);
}

double DOFManager::getNearestPointOfSharpness()
{
    return ml.FindNearestPointOfSharpness(&pl);
}

double DOFManager::getFarestPointOfSharpness()
{
    return ml.FindFarestPointOfSharpness(&pl);
}
