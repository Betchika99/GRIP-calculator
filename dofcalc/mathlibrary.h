#ifndef MATHLIBRARY_H
#define MATHLIBRARY_H

#include "propertylist.h"
#include "imagehandler.h"

<<<<<<< HEAD
<<<<<<< HEAD
template<class T>
=======
>>>>>>> Updated dofManager part
=======
>>>>>>> Updated Manager part
class MathLibrary {
public:
    MathLibrary();
    ~MathLibrary();
<<<<<<< HEAD
<<<<<<< HEAD
    bool CheckerNull(const T &object);
=======
>>>>>>> Updated dofManager part
=======
>>>>>>> Updated Manager part
    double FindCrop(PropertyList *values);
    double FindHyperFocal(PropertyList *values);
    double FindNearestPointOfSharpness(PropertyList *values);
    double FindFarestPointOfSharpness(PropertyList *values);
    double FindGRIP(PropertyList *values);
    void Scale(PropertyList *values, ImageHandler* image);
    void Blur(PropertyList *values, ImageHandler* image);
};

#endif // MATHLIBRARY_H
