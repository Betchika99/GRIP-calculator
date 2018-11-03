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
    list.append("Background 2");
    list.append("Background 3");
    return list;
}

int DOFManager::getBackgroundIndex()
{
    return 0;
}

void DOFManager::setBackgroundIndex(int index)
{

}

QStringList DOFManager::getModelsList()
{
    QStringList list;
    list.append("Model 1");
    list.append("Model 2");
    list.append("Model 3");
    return list;
}

int DOFManager::getModelIndex()
{
    return 0;
}

void DOFManager::setModelIndex(int index)
{

}

QStringList DOFManager::getSensorsList()
{
    QStringList list;
    list.append("Full Frame");
    list.append("APC-C");
    list.append("Four Thirds");
    return list;
}

int DOFManager::getSensorIndex()
{
    return 0;
}

void DOFManager::setSensorIndex(int index)
{

}

double DOFManager::getCropFactor()
{
    return 1;
}

void DOFManager::setCropFactor(double crop)
{

}

double DOFManager::getDistance()
{
    return pl.getDistanceModel();   //todo
}

void DOFManager::setDistance(double value)
{
    pl.setDistanceModel(value);
}

double DOFManager::getFocalLength()
{
    return 10;
}

void DOFManager::setFocalLength(double value)
{

}

QStringList DOFManager::getAperturesList()
{
    QStringList list;
    list.append("F/1.0");
    list.append("F/1.4");
    list.append("F/1.6");
    return list;
}

int DOFManager::getApertureIndex()
{
    return 0;
}

void DOFManager::setApertureIndex(int index)
{

}

