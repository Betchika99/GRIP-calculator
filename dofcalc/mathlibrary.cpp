#include "mathlibrary.h"
const int ERROR = -1;

MathLibrary::MathLibrary() {}

MathLibrary::~MathLibrary() {}

bool MathLibrary::CheckerNull(const PropertyList *object) {
    if (object == nullptr)
            return false;
    return true;
}

double MathLibrary::FindCrop(PropertyList *values) {
    if (this->CheckerNull(values)) {
        double crop = values->getCrop();
        double c = 0.03/crop;
        return c;
    }
    return ERROR;
}

double MathLibrary::FindHyperFocal(PropertyList *values) {
    if (this->CheckerNull(values)) {
        double f = values->getFocalLenght();
        double c = this->FindCrop(values);
        double d = values->getDiaphragm();
        double h = f*f/(c*d);
        return h;
    }
    return ERROR;
}

double MathLibrary::FindNearestPointOfSharpness(PropertyList *values) {
    if (this->CheckerNull(values)) {
        double s0 = values->getDistanceModel();
        double f = values->getFocalLenght();
        double d = values->getDiaphragm();
        double c = this->FindCrop(values);
        double dN = (s0 * f * f)/(f * f + (f/d * c) * (s0 - f));
        return dN;
    }
    return ERROR;
}

double MathLibrary::FindFarestPointOfSharpness(PropertyList *values) {
    if (this->CheckerNull(values)) {
        double s0 = values->getDistanceModel();
        double f = values->getFocalLenght();
        double d = values->getDiaphragm();
        double c = this->FindCrop(values);
        double dF = (s0 * f * f)/(f * f - (f/d * c) * (s0 - f));
        return dF;
    }
    return ERROR;
}

double MathLibrary::FindGRIP(PropertyList *values) {
    if (this->CheckerNull(values)) {
        double dF = this->FindFarestPointOfSharpness(values);
        double dN = this->FindNearestPointOfSharpness(values);
        return (dF - dN);
    }
    return ERROR;
}

void MathLibrary::Scale(PropertyList *values, ImageHandler* image) {}

void MathLibrary::Blur(PropertyList *values, ImageHandler* image) {}
