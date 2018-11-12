#ifndef MATHLIBRARY_H
#define MATHLIBRARY_H

#include "propertylist.h"
#include "imagehandler.h"

template<class T>
class MathLibrary {
public:
    MathLibrary();
    ~MathLibrary();
    bool CheckerNull(const T &object);
    double FindCrop(PropertyList *values);
    double FindHyperFocal(PropertyList *values);
    double FindNearestPointOfSharpness(PropertyList *values);
    double FindFarestPointOfSharpness(PropertyList *values);
    double FindGRIP(PropertyList *values);
    void Scale(PropertyList *values, ImageHandler* image);
    void Blur(PropertyList *values, ImageHandler* image);
};

#endif // MATHLIBRARY_H
