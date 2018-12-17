#include "properties.h"


QJsonObject PropertySet::asJSON()
{
    QJsonObject json;
    json["name"] = name;
    json["background"] = background.asJson();
    json["model"] = model.asJson();
    //json["orientation"] = orientation.asJson(); todo
    json["crop"] = crop.asJson();
    json["backgroudDistance"] = backgroudDistance.asJson();
    json["modelDistance"] = modelDistance.asJson();
    json["focalLenght"] = focalLenght.asJson();
    json["diaphragm"] = diaphragm.asJson();
    return json;
}

bool PropertySet::loadFromJSON(QJsonObject &json)
{

}
