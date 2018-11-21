#ifndef MATHLIBRARY_H
#define MATHLIBRARY_H

#include "ui_mainwindow.h"
#include "propertylist.h"
#include "imagehandler.h"

#include <QPainter>
#include <QPixmap>

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
    void Scale(PropertyList *values, ImageHandler* image);
    void Blur(PropertyList *values, ImageHandler* image);
};

#endif // MATHLIBRARY_H
