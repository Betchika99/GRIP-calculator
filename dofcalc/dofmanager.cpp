#include "dofmanager.h"

DOFManager::DOFManager()
{

}

DOFManager::~DOFManager()
{

}

QStringList DOFManager::getBackgroundsList()
{
    QStringList list;
    list.append("Background 1");
//    list.append("Background 2");
//    list.append("Background 3");
    return list;
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
    return pl.setCurrentModelIndex(index);
}

QStringList DOFManager::getSensorsList()
{
    QStringList list;
    list.append("Full Frame");
    list.append("APC-C");
    list.append("Four Thirds");
    return list;
}

int DOFManager::getSensorIndex()    //in pl
{
//    switch (index) {
//    case 0:

//        break;
//    case 1:

//        break;
//    case 2:

//        break;
//    default:
//        break;
//    }
//    return 0;
}

void DOFManager::setSensorIndex(int index)
{
//    switch (index) {
//    case 0:
//        pl.setCrop();
//        break;
//    case 1:
//        pl.setCrop();
//        break;
//    case 2:
//        pl.setCrop();
//        break;
//    default:
//        break;
//    }
}

double DOFManager::getCropFactor()
{
    return pl.getCrop();
}

void DOFManager::setCropFactor(double crop)
{
    return pl.setCrop(crop);
}

double DOFManager::getBackgroundDistance()
{
    return pl.getDistanceBackgroud();
}
void DOFManager::setBackgroundDistance(double value)
{
    return pl.setDistanceBackgroud(value);
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

