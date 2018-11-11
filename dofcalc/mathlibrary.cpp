#include "mathlibrary.h"

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
    return (dF - dN);
}

void MathLibrary::Scale(PropertyList *values, ImageHandler* image) {}
void MathLibrary::Blur(PropertyList *values, ImageHandler* image) {}
