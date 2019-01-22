#ifndef STRATEGIES_H
#define STRATEGIES_H

#include "properties.h"

class Strategy
{
public:
    PropertySwitch<QString> background;
    PropertySwitch<QString> model;
    PropertyValue<double> modelDistance;
    PropertyValue<double> backgroundDistance;
    PropertyValue<double> focalLength;
    PropertyValue<double> diaphragm;
};

class StrategyList
{
public:
    PropertySwitch<Strategy> strategies;
public:
    StrategyList() {loadDefaultStrategy();}
    void updatePropertyList(PropertyList &pl);
    bool importFromJSON(const QJsonObject &json);
    QJsonObject exportToJSON();
protected:
    void loadDefaultStrategy();
};


#endif // STRATEGIES_H
