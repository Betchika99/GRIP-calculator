#ifndef APIPROVIDER_H
#define APIPROVIDER_H

#include "properties.h"
#include "strategies.h"

class APIProvider
{
private:
    bool online; //todo

public:
    APIProvider();

    bool serverOnline();

    bool login(QString login, QString password);
    bool createUser(QString login, QString password);
    void logout();
    bool userOnline();

    void loadStrategyList(StrategyList &sl);
    void loadFavoriteList(PropertySwitch<QString> &fl);
    bool loadFavorite(QString title, StrategyList &sl, PropertyList &pl);
    bool saveFavorite(QString title, const StrategyList &sl, const PropertyList &pl);
    bool deleteFavorite(QString title);

protected:
    bool loadFromFile(QString fileName);


};

#endif // APIPROVIDER_H
