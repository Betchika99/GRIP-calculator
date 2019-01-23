#include "strategies.h"

const QString DefaultBackgroundImage = "Default.Background.png";
const QString DefaultModelImage = "Default.Model.png";

void StrategyList::updatePropertyList(PropertyList &pl)
{
    if (strategies.index() < 0) return;
    pl.background = strategies.value().background;
    pl.model = strategies.value().model;
    pl.modelDistance = strategies.value().modelDistance;
    pl.backgroundDistance = strategies.value().backgroundDistance;
    pl.focalLength = strategies.value().focalLength;
    pl.diaphragm = strategies.value().diaphragm;
}

void StrategyList::loadDefaultStrategy()
{
    Strategy s;
    s.background.addEntry("Задний план", DefaultBackgroundImage);
    s.background.setIndex(0);
    s.model.addEntry("Модель", DefaultModelImage);
    s.model.setIndex(0);
    s.modelDistance.set(1, 10, 3);
    s.backgroundDistance.set(1, 100, 50);
    s.focalLength.set(8, 300, 50);
    s.diaphragm.set(1, 16, 5.6);
    strategies.clear();
    strategies.addEntry("По умолчанию", s);
    strategies.setIndex(0);
}

bool StrategyList::importFromJSON(const QJsonObject &json)
{
    bool compatible = false;
    QJsonArray array = json["list"].toArray();
    QJsonValue currentIndex = json["currentIndex"];
    strategies.clear();
    for (int i = 0; i < array.count(); i++)
    {
        QJsonObject obj = array[i].toObject();
        QJsonValue title = obj["strategy_name"];
        if (!title.isString()) continue;
        Strategy strategy;
        if (!strategy.background.importFromJSON(obj["background"].toObject())) continue;
        if (!strategy.model.importFromJSON(obj["model"].toObject())) continue;
        if (!strategy.modelDistance.importFromJSON(obj["destination_to_model"].toObject())) continue;
        if (!strategy.backgroundDistance.importFromJSON(obj["destination_to_background"].toObject())) continue;
        if (!strategy.focalLength.importFromJSON(obj["focus_destination"].toObject())) continue;
        if (!strategy.diaphragm.importFromJSON(obj["aperture"].toObject())) continue;
        strategies.addEntry(title.toString(), strategy);
        compatible = true;
    }
    if (compatible)
    {
        strategies.setIndex(currentIndex.isDouble() ? currentIndex.toInt() : 0);
    }
    return compatible;
}

QJsonObject StrategyList::exportToJSON()
{
    QJsonArray array;
    for (int i = 0; i < strategies.count(); i++)
    {
        QJsonObject obj =
        {
            {"strategy_name", strategies[i].title},
            {"background", strategies[i].value.background.exportToJSON()},
            {"model", strategies[i].value.model.exportToJSON()},
            {"destination_to_model", strategies[i].value.modelDistance.exportToJSON()},
            {"destination_to_background", strategies[i].value.backgroundDistance.exportToJSON()},
            {"focus_destination", strategies[i].value.focalLength.exportToJSON()},
            {"aperture", strategies[i].value.diaphragm.exportToJSON()}
        };
        array.append(obj);
    }
    QJsonObject json =
    {
        {"list", array},
        {"currentIndex", strategies.index()}
    };
    return json;
}
