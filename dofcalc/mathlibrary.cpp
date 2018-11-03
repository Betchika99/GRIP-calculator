#include "mathlibrary.h"

MathLibrary::MathLibrary(){}
MathLibrary::~MathLibrary(){}
double MathLibrary::FindCrop(PropertyList *values) { return 0; }
double MathLibrary::FindHyperFocal(PropertyList *values) { return 1.0; }
double MathLibrary::FindNearestPointOfSharpness(PropertyList *values) { return 1.0; }
double MathLibrary::FindFarestPointOfSharpness(PropertyList *values) { return 1.0; }
double MathLibrary::FindGRIP(PropertyList *values) { return 0; }
void MathLibrary::Scale(PropertyList *values, ImageHandler* image) {}
void MathLibrary::Blur(PropertyList *values, ImageHandler* image) {}
