#ifndef DOFMANAGER_H
#define DOFMANAGER_H

#include <QStringList>
#include "propertylist.h"
//#include "mathlib.h"  //as an object

class DOFManager
{

private:
    PropertyList pl;
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

    double getDistance();
    void setDistance(double value);

    double getFocalLength();
    void setFocalLength(double value);

    QStringList getAperturesList();
    int  getApertureIndex();
    void setApertureIndex(int index);

};

#endif // DOFMANAGER_H
