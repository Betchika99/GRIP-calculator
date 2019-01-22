#include "properties.h"

template<class T>
bool PropertyValue<T>::importFromJSON(const QJsonObject &json)
{
    QVariant min = json["min"].toVariant();
    QVariant max = json["max"].toVariant();
    QVariant defaults = json["defaults"].toVariant();
    QVariant value = json["value"].toVariant();
    bool compatible = min.canConvert<T>() && max.canConvert<T>() && defaults.canConvert<T>();
    if (compatible)
    {
        if (value.canConvert<T>())
            set(min.value<T>(), max.value<T>(), defaults.value<T>(), value.value<T>());
        else
            set(min.value<T>(), max.value<T>(), defaults.value<T>());
    }
    return compatible && valid();
}

template<class T>
QJsonObject PropertyValue<T>::exportToJSON() const
{
    QJsonObject json =
    {
        {"min", min()},
        {"max", max()},
        {"defaults", defaults()},
        {"value", value()}
    };
    return json;
}

template<class T>
bool PropertySwitch<T>::importFromJSON(const QJsonObject &json)
{
    bool compatible = false;
    QJsonArray array = json["list"].toArray();
    QJsonValue currentIndex = json["currentIndex"];
    clear();
    for (int i = 0; i < array.count(); i++)
    {
        QJsonObject obj = array[i].toObject();
        QJsonValue title = obj["title"];
        QVariant value = obj["value"].toVariant();
        if (title.isString() && value.canConvert<T>())
        {
            addEntry(title.toString(), value.value<T>());
            compatible = true;
        }
    }
    if (compatible)
    {
        setIndex(currentIndex.isDouble() ? currentIndex.toInt() : 0);
    }
    return compatible;
}

template<class T>
QJsonObject PropertySwitch<T>::exportToJSON() const
{
    QJsonArray array;
    for (int i = 0; i < count(); i++)
    {
        QJsonObject obj =
        {
            {"title", list.at(i).title},
            {"value", list.at(i).value}
        };
        array.append(obj);
    }
    QJsonObject json =
    {
        {"list", array},
        {"currentIndex", index()}
    };
    return json;
}

bool PropertyList::importFromJSON(const QJsonObject &json)
{
    return background.importFromJSON(json["background"].toObject()) &&
           model.importFromJSON(json["model"].toObject()) &&
           orientation.importFromJSON(json["orientation"].toObject()) &&
           crop.importFromJSON(json["crop"].toObject()) &&
           cropFactor.importFromJSON(json["cropFactor"].toObject()) &&
           modelDistance.importFromJSON(json["modelDistance"].toObject()) &&
           backgroundDistance.importFromJSON(json["backgroundDistance"].toObject()) &&
           focalLength.importFromJSON(json["focalLength"].toObject()) &&
           diaphragm.importFromJSON(json["diaphragm"].toObject());
}

QJsonObject PropertyList::exportToJSON() const
{
    QJsonObject json =
    {
        {"background", background.exportToJSON()},
        {"model", model.exportToJSON()},
        {"orientation", orientation.exportToJSON()},
        {"crop", crop.exportToJSON()},
        {"cropFactor", cropFactor.exportToJSON()},
        {"modelDistance", modelDistance.exportToJSON()},
        {"backgroundDistance", backgroundDistance.exportToJSON()},
        {"focalLength", focalLength.exportToJSON()},
        {"diaphragm", diaphragm.exportToJSON()},
    };
    return json;
}
