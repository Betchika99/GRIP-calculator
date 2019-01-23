#ifndef DOFMANAGER_H
#define DOFMANAGER_H

#include "apiprovider.h"
#include "properties.h"
#include "strategies.h"
#include "imagehandler.h"
#include "mathlibrary.h"
#include "user.h"

class DOFManager
{
public:
    DOFManager();

public:
    bool login(QString name, QString password) {return api.login(name, password);}
    bool createUser(QString name, QString password) {return api.createUser(name, password);}
    void logout() {api.logout();}
    bool userOnline() {return api.userOnline();}

    void setStrategy(int index);
    void setBackground(int index);
    void setModel(int index);
    void setOrientation(int index);
    void setCrop(int index);
    void setCropFactor(double value);
    void setModelDistance(double value);
    void setBackgroundDistance(double value);
    void setFocalLength(double value);
    void setDiaphragm(double value);

    const PropertySwitch<Strategy>& strategy() {return sl.strategies;}
    const PropertySwitch<QString>& background() {return pl.background;}
    const PropertySwitch<QString>& model() {return pl.model;}
    const PropertySwitch<Orientation>& orientation() {return pl.orientation;}
    const PropertySwitch<double>& crop() {return pl.crop;}
    const PropertyValue<double>& cropFactor() {return pl.cropFactor;}
    const PropertyValue<double>& modelDistance() {return pl.modelDistance;}
    const PropertyValue<double>& backgroundDistance() {return pl.backgroundDistance;}
    const PropertyValue<double>& focalLength() {return pl.focalLength;}
    const PropertyValue<double>& diaphragm() {return pl.diaphragm;}

    bool loadFavorite(QString title);
    bool saveFavorite(QString title);
    void deleteFavorite(QString title);
    const PropertySwitch<QString>& favorite() {return fl;}

    void resetToDefaults();
    void performImageProcessing();

    Image getResultImage() {return result.gluedImage();}
    double getGRIP();
    double getHyperFocal();
    double getNearestPointOfSharpness();
    double getFarestPointOfSharpness();



protected:
    void loadConstantProperties();
    void reloadImages();
    double roundTo(double value, int precision);

private:
    APIProvider api;
    StrategyList sl;
    PropertyList pl;
    PropertySwitch<QString> fl;
    MathLibrary ml;
    ImageHandler origin;
    ImageHandler result;
    User user;
};

#endif // DOFMANAGER_H
