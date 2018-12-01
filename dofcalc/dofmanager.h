#ifndef DOFMANAGER_H
#define DOFMANAGER_H

#include <QStringList>
#include "propertylist.h"
#include "mathlibrary.h"
#include "imagehandler.h"

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

    QImage getResultImage(int index) {return ih.getImageResult(index);}



    double getGRIP();
    double getHyperFocal();
    double getNearestPointOfSharpness();
    double getFarestPointOfSharpness();

    void Blur();
    void Scale();
    void UpdateImages(int indexModel, int indexBack) { ih.UpdateImages(indexModel, indexBack); }


private:
    PropertyList pl;
    MathLibrary ml;
    ImageHandler ih;

};

#endif // DOFMANAGER_H
