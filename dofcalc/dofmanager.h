#ifndef DOFMANAGER_H
#define DOFMANAGER_H

#include <QStringList>
#include "propertylist.h"
#include "mathlibrary.h"

class DOFManager
{

public:
    DOFManager();
    ~DOFManager();

public:
    QStringList getBackgroundsList();
    int  getBackgroundIndex();
    void setBackgroundIndex(int index);

    QStringList getModelsList();
    int  getModelIndex();
    void setModelIndex(int index);

    QStringList getSensorsList();
    int  getSensorIndex();
    void setSensorIndex(int index);

    double getCropFactor();
    void setCropFactor(double crop);

    double getBackgroundDistance();
    void setBackgroundDistance(double value);

    double getModelDistance();
    void setModelDistance(double value);

    double getFocalLength();
    void setFocalLength(double value);

    double getAperture();
    void setAperture(double Value);


    double getGRIP();
    double getHyperFocal();
    double getNearestPointOfSharpness();
    double getFarestPointOfSharpness();


private:
    PropertyList pl;
    MathLibrary ml;

};

#endif // DOFMANAGER_H
