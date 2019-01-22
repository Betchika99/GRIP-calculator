#ifndef MATHLIBRARY_H
#define MATHLIBRARY_H

#include "properties.h"
#include "imagehandler.h"

class MathLibrary {
public:
    MathLibrary();
    ~MathLibrary();
    template<class T> bool CheckerNull(const T *object);
    double FindCrop(PropertyList *values);
    double FindHyperFocal(PropertyList *values);
    double FindNearestPointOfSharpness(PropertyList *values);
    double FindFarestPointOfSharpness(PropertyList *values);
    double FindGRIP(PropertyList *values);
    void Scale(PropertyList *values, ImageHandler& ih);
    void Blur(PropertyList *values, ImageHandler& ih);
};

#endif // MATHLIBRARY_H
