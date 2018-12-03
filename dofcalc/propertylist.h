#ifndef PROPERTYLIST_H
#define PROPERTYLIST_H

#include <QStringList>

enum Strategy {Portrait, Macro, LandScape, CloseUp};
enum Orientation {Book, Album};

class PropertyList
{
private:
    double focalLenght;
    double diaphragm;
    double crop;
    double distanceModel;
    double distanceBackgroud;
    Strategy strategy;
    Orientation orientation;
    QStringList models;
    QStringList backgrounds;
    QStringList crops;

    int currentModelIndex;
    int currentBackgroundIndex;
    int currentCropIndex;

    QString settingsFile;
    QString imagesPath;

public:
    PropertyList();
    ~PropertyList();

protected:
    bool saveToFile(QString& filename); //погуглить
    bool loadFromFile(QString& fiename);

    QStringList scanPath(QString path, QString mask);
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

    void setStrategy(Strategy value);
    Strategy getStrategy() { return strategy; }

    void setOrientation(Orientation value);
    Orientation getOrientation() { return orientation; }

    QStringList getModels();
    void setCurrentModelIndex(int value);
    int getCurrentModelIndex() { return currentModelIndex; }

    QStringList getBackgrounds();
    void setCurrentBackgroundIndex(int value);
    int getCurrentBackgroundIndex() { return currentBackgroundIndex; }

    void setDefault();
};

#endif // PROPERTYLIST_H
