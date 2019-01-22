#include "ui_mainwindow.h"
#include "mathlibrary.h"
const int mathERROR = -1;

MathLibrary::MathLibrary() {}

MathLibrary::~MathLibrary() {}

template<class T>
bool MathLibrary::CheckerNull(const T *object) {
    if (object == nullptr)
        return false;
    return true;
}

double MathLibrary::FindCrop(PropertyList *values) {
    if (this->CheckerNull(values)) {
        double crop = values->cropFactor.value();
        double c = 0.03/crop;
        return c;
    }
    return mathERROR;
}

double MathLibrary::FindHyperFocal(PropertyList *values) {
    if (this->CheckerNull(values)) {
        double f = values->focalLength.value();
        double c = this->FindCrop(values);
        double d = values->diaphragm.value();
        double h = (f*f/(c*d))/1000;
        return h;
    }
    return mathERROR;
}

double MathLibrary::FindFarestPointOfSharpness(PropertyList *values) {
    if (this->CheckerNull(values)) {
        double s0 = values->modelDistance.value();
        double f = values->focalLength.value();
        double d = values->diaphragm.value();
        double c = this->FindCrop(values);
        double dN = (s0 * f * f)/(f * f + (f/d * c) * (s0 - f));
        return dN;
    }
    return mathERROR;
}

double MathLibrary::FindNearestPointOfSharpness(PropertyList *values) {
    if (this->CheckerNull(values)) {
        double s0 = values->modelDistance.value();
        double f = values->focalLength.value();
        double d = values->diaphragm.value();
        double c = this->FindCrop(values);
        double dF = (s0 * f * f)/(f * f - (f/d * c) * (s0 - f));
        return dF;
    }
    return mathERROR;
}

double MathLibrary::FindGRIP(PropertyList *values) {
    if (this->CheckerNull(values)) {
        double dF = this->FindFarestPointOfSharpness(values);
        double dN = this->FindNearestPointOfSharpness(values);
        return (dF - dN);
    }
    return mathERROR;
}

void MathLibrary::Scale(PropertyList *values, ImageHandler& ih) {

    if (this->CheckerNull(values) && ih.isValid())  {
        Image& model = ih.model();
        double scaleFactor = ( values->focalLength.value() / values->modelDistance.value() ) / 10.0;
        QSize realImageSize = model.asQImage().size();
        model = model.scale(scaleFactor * realImageSize);
    }
}

void MathLibrary::Blur(PropertyList *values, ImageHandler& ih) {

    double dF = this->FindFarestPointOfSharpness(values);
    double dN = this->FindNearestPointOfSharpness(values);
    double grip = this->FindGRIP(values);

    if (this->CheckerNull(values) && ih.isValid())  {
        Image& backgroud = ih.background();
        Image& model = ih.model();
        qreal blurFactor = grip;

        QT_BEGIN_NAMESPACE
        extern Q_WIDGETS_EXPORT void qt_blurImage(QImage &blurImage, qreal radius, bool quality, int transposed = 0 );
        QT_END_NAMESPACE

        if (dF > values->modelDistance.value() && dN < values->modelDistance.value() )
        {
            if (!(dF > values->backgroundDistance.value() && dN < values->backgroundDistance.value() ))
            {
                QImage qimg = backgroud.asQImage();
                qt_blurImage(qimg, blurFactor*100, true);
                backgroud = qimg;
                return;
            }
        } else {
            QImage qimg = model.asQImage();
            qt_blurImage(qimg, blurFactor*100, true);
            model = qimg;
            if (!(dF > values->backgroundDistance.value() && dN < values->backgroundDistance.value() )) {
                QImage qimg = backgroud.asQImage();
                qt_blurImage(qimg, blurFactor*100, true);
                backgroud = qimg;
                return;
            }
        }
    }
}
