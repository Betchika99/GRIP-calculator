#ifndef PROPERTYLIST_H
#define PROPERTYLIST_H

#include <QStringList>
#include <vector>
#include "strategies.h"

using std::vector;

//enum Strategy {Portrait, Macro, LandScape, CloseUp};
enum Orientation {Book, Album};

class PropertyList
{
private:
    double focalLenght;
    double diaphragm;
    double crop;
    double distanceModel;
    double distanceBackgroud;
//    QString strategy;
    Orientation orientation;
    QStringList models;
    QStringList backgrounds;
//    QStringList strategies;
    QStringList crops;

    int currentModelIndex;
    int currentBackgroundIndex;
    int currentStrategyIndex;
    int currentCropIndex;

    QString settingsFile;
    QString imagesPath;


    vector<Strategy*> strategies;
    Strategy* currentStrategy;
public:
    PropertyList();
    ~PropertyList();

protected:
//    QStringList scanPath(QString path, QString mask);
    template <class T>
    T setRange(T value, Triple<T> range);
    template <class T>
    T setRange(T value, T min, T max);

public:
    void setFocalLenght(double value);
    double getFocalLenght() { return focalLenght; }

    void setDiaphragm(double value);
    double getDiaphragm() { return diaphragm; }

    void setCrop(double value);
    double getCrop() { return crop; }
    void setCurrentCropIndex(int value);
    int getCurrentCropIndex() { return currentCropIndex; }
    QStringList getCrops();


    void setDistanceModel(double value);
    double getDistanceModel() { return distanceModel; }

    void setDistanceBackgroud(double value);
    double getDistanceBackgroud() { return distanceBackgroud; }

//    void setStrategy(int index);
//    int getStrategy() { return currentStrategyIndex; }

    void setOrientation(Orientation value);
    Orientation getOrientation() { return orientation; }

    QStringList getModels();
    void setCurrentModelIndex(int value);
    int getCurrentModelIndex() { return currentModelIndex; }

    QStringList getBackgrounds();
    void setCurrentBackgroundIndex(int value);
    int getCurrentBackgroundIndex() { return currentBackgroundIndex; }

    QStringList getStrategies();
    void setCurrentStrategyIndex(int value);
    int getCurrentStrategyIndex() { return currentStrategyIndex; }
    QString getCurrentStrategyModelFileName();
    QString getCurrentStrategyBackgroundFileName();
    Strategy* getCurrentStrategy() {return currentStrategy;}

    void setDefault();
    bool saveToFile(QString& filename); //погуглить
    bool loadFromFile(QString& fiename);

};

#endif // PROPERTYLIST_H
