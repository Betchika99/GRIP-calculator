#include "mathlibrary.h"
<<<<<<< HEAD
<<<<<<< HEAD
const int ERROR = -1;

template<class T>
MathLibrary<T>::MathLibrary() {}

template<class T>
MathLibrary<T>::~MathLibrary() {}

template<class T>
bool MathLibrary<T>::CheckerNull(const T &object) {
    if (object == nullptr)
            return false;
    return true;
}

template<class T>
double MathLibrary<T>::FindCrop(PropertyList *values) {
    if (this->CheckerNull()) {
        double crop = values->getCrop();
        double c = 0.03/crop;
        return c;
    }
    return ERROR;
}

template<class T>
double MathLibrary<T>::FindHyperFocal(PropertyList *values) {
    if (this->CheckerNull()) {
        double f = values->getFocalLenght();
        double c = this->FindCrop(values);
        double d = values->getDiaphragm();
        double h = f*f/(c*d);
        return h;
    }
    return ERROR;
}

template<class T>
double MathLibrary<T>::FindNearestPointOfSharpness(PropertyList *values) {
    if (this->CheckerNull()) {
        double s0 = values->getDistanceModel();
        double f = values->getFocalLenght();
        double d = values->getDiaphragm();
        double c = this->FindCrop(values);
        double dN = (s0 * f * f)/(f * f + (f/d * c) * (s0 - f));
        return dN;
    }
    return ERROR;
}

template<class T>
double MathLibrary<T>::FindFarestPointOfSharpness(PropertyList *values) {
    if (this->CheckerNull()) {
        double s0 = values->getDistanceModel();
        double f = values->getFocalLenght();
        double d = values->getDiaphragm();
        double c = this->FindCrop(values);
        double dF = (s0 * f * f)/(f * f - (f/d * c) * (s0 - f));
        return dF;
    }
    return ERROR;
}

template<class T>
double MathLibrary<T>::FindGRIP(PropertyList *values) {
    if (this->CheckerNull()) {
        double dF = this->FindFarestPointOfSharpness(values);
        double dN = this->FindNearestPointOfSharpness(values);
        return (dF - dN);
    }
    return ERROR;
}

template<class T>
void MathLibrary<T>::Scale(PropertyList *values, ImageHandler* image) {}

template<class T>
void MathLibrary<T>::Blur(PropertyList *values, ImageHandler* image) {}
=======
=======
>>>>>>> Updated Manager part

MathLibrary::MathLibrary() {}

MathLibrary::~MathLibrary() {}

double MathLibrary::FindCrop(PropertyList *values) {
    double crop = values->getCrop();
    double c = 0.03/crop;
    return c;
}

double MathLibrary::FindHyperFocal(PropertyList *values) {
    double f = values->getFocalLenght();
    double c = this->FindCrop(values);
    double d = values->getDiaphragm();
    double h = f*f/(c*d);
    return h;
}

double MathLibrary::FindNearestPointOfSharpness(PropertyList *values) {
    double s0 = values->getDistanceModel();
    double f = values->getFocalLenght();
    double d = values->getDiaphragm();
    double c = this->FindCrop(values);
    double dN = (s0 * f * f)/(f * f + (f/d * c) * (s0 - f));
    return dN;
}

double MathLibrary::FindFarestPointOfSharpness(PropertyList *values) {
    double s0 = values->getDistanceModel();
    double f = values->getFocalLenght();
    double d = values->getDiaphragm();
    double c = this->FindCrop(values);
    double dF = (s0 * f * f)/(f * f - (f/d * c) * (s0 - f));
    return dF;
}

double MathLibrary::FindGRIP(PropertyList *values) {
    double dF = this->FindFarestPointOfSharpness(values);
    double dN = this->FindNearestPointOfSharpness(values);
    return -(dF - dN);
}

void MathLibrary::Scale(PropertyList *values, ImageHandler* image) {}
void MathLibrary::Blur(PropertyList *values, ImageHandler* image) {}
<<<<<<< HEAD
>>>>>>> Updated dofManager part
=======
>>>>>>> Updated Manager part
