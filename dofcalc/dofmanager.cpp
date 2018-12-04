#include "dofmanager.h"

DOFManager::DOFManager()
{

}

DOFManager::~DOFManager()
{

}

QStringList DOFManager::getBackgroundsList()
{
    return pl.getBackgrounds();
}

int DOFManager::getBackgroundIndex()
{
    return pl.getCurrentBackgroundIndex();
}

void DOFManager::setBackgroundIndex(int index)
{
    return pl.setCurrentBackgroundIndex(index);
}

QStringList DOFManager::getModelsList()
{
    return pl.getModels();
}

int DOFManager::getModelIndex()
{
    return pl.getCurrentModelIndex();
}

void DOFManager::setModelIndex(int index)
{
    pl.setCurrentModelIndex(index);
    UpdateImages();
}

QStringList DOFManager::getSensorsList()
{
    return pl.getCrops();
}

int DOFManager::getSensorIndex()
{
    return pl.getCurrentCropIndex();
}

void DOFManager::setSensorIndex(int index)
{
    pl.setCurrentCropIndex(index);
}

double DOFManager::getCropFactor()
{
    return pl.getCrop();
}

void DOFManager::setCropFactor(double crop)
{
    return pl.setCrop(crop);
}

QStringList DOFManager::getStrategyList()
{
    return pl.getStrategies();
}

int DOFManager::getStrategyIndex()
{
    return pl.getCurrentStrategyIndex();
}

void DOFManager::setStrategyIndex(int index)
{
    pl.setCurrentStrategyIndex(index);
}

double DOFManager::getBackgroundDistance()
{
    return pl.getDistanceBackgroud();
}
void DOFManager::setBackgroundDistance(double value)
{
    pl.setDistanceBackgroud(value);
    UpdateImages();
}


double DOFManager::getModelDistance()
{
    return pl.getDistanceModel();
}
void DOFManager::setModelDistance(double value)
{
    return pl.setDistanceModel(value);
}

double DOFManager::getFocalLength()
{
    return pl.getFocalLenght();
}

void DOFManager::setFocalLength(double value)
{
    return pl.setFocalLenght(value);
}

//QStringList DOFManager::getAperturesList()
//{
//    QStringList list;
//    list.append("F/1.0");
//    list.append("F/1.4");
//    list.append("F/1.6");
//    return list;
//}

double DOFManager::getAperture()
{
    return pl.getDiaphragm();
}

void DOFManager::setAperture(double value)
{
    return pl.setDiaphragm(value);
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

void DOFManager::UpdateImages()
{
   QString fileNameModel = pl.getCurrentStrategyModelFileName();
   QString fileNameBackground = pl.getCurrentStrategyBackgroundFileName();
   origin.UpdateImages(fileNameModel, fileNameBackground);
}

void DOFManager::PerformImageProcessing()
{
    result = origin;
    ml.Blur(&pl, result);
    ml.Scale(&pl, result);
}

//void DOFManager::Blur()
//{
//    ml.Blur(&pl, origin, result);
//}

//void DOFManager::Scale()
//{
//    ml.Scale(&pl, origin, result);
//}

