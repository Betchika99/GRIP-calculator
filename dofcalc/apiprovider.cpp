#include "apiprovider.h"
#include "toolslibrary.h"
#include "logger.h"
#include "client.h"

APIProvider::APIProvider()
{
    online = false;
}

bool APIProvider::serverOnline()
{
    //todo something like ping or request
    return true;
}

bool APIProvider::login(QString login, QString password)
{
    if ( userOnline() ) return true;
    //todo check if this login and password in DB
    online = login.size() && password.size();   //set true is exists
    return userOnline();
}

bool APIProvider::createUser(QString login, QString password)
{
    //make request to create user
    return login.size() && password.size();
}

void APIProvider::logout()
{
    online = false;
}

bool APIProvider::userOnline()
{
    return online;
}

void APIProvider::loadStrategyList(StrategyList &sl)
{
    QString settingsName = "strategies.settings";
    if (serverOnline())
    {
      //  sl.strategies.clear();
        QString strategyName = "Portrait";
        //todo requestS
        //get strategies and pictures
        sl.importFromJSON(Client::getImagesNames(strategyName));
        settingsName = "remotestrategies.settings";
    }
    Log("APIProvider.loadStrategyList(): Server unavailable, load local");
    QFile file(SettingsPath() + settingsName); //in if-branch create new file for server
    if (file.open(QIODevice::ReadOnly|QIODevice::Text) && file.size())
    {
        QByteArray content = file.readAll();
        QJsonDocument doc = QJsonDocument::fromJson(content);
        bool success = sl.importFromJSON(doc.object());
        const char *logmsg = success ?
            "APIProvider.loadStrategyList(): Loaded from JSON %s" :
            "APIProvider.loadStrategyList(): JSON parsing error $s";
        Log(logmsg, doc.toJson(QJsonDocument::Compact).data());

    }
}

void APIProvider::loadFavoriteList(PropertySwitch<QString> &fl)
{
    fl.clear();
//    if (userOnline()) //will work anyway
//    {
//        //without
//    }
//    else
    {
        Log("APIProvider.loadFavoriteList(): Server unavailable, scan local");
        QDir dirBrowser(FavoritePath(), "*.settings", QDir::Time|QDir::Reversed);
        for (int i = 0; i < dirBrowser.entryList().count(); i++)
        {
            QFileInfo fi(dirBrowser.entryList()[i]);
            fl.addEntry(fi.baseName(), fi.fileName());  //"asx"(friendlt name), asx.setting
        }
        const char *logmsg = fl.count() ?
            "APIProvider.loadFavoriteList(): Successfully added %d favorites" :
            "APIProvider.loadFavoriteList(): No favorites %d";
        Log(logmsg, fl.count());
    }
}

bool APIProvider::loadFavorite(QString title, StrategyList &sl, PropertyList &pl)
{
//    if (userOnline()) //will work anyway
//    {
//        //todo
//        return false;
//    }
//    else
    {
        Log("APIProvider.loadFavorite(): Server unavailable, load local");
        QFile file(FavoritePath() + title + ".settings");
        if (!file.open(QIODevice::ReadOnly|QIODevice::Text))
        {
            Log("APIProvider.loadFavorite(): file not found %s", file.fileName().toUtf8().data());
            return false;
        }
        QByteArray content = file.readAll();
        if (!content.size())
        {
            Log("APIProvider.loadFavorite(): file is empty %s", file.fileName().toUtf8().data());
            return false;
        }
        QJsonDocument doc = QJsonDocument::fromJson(content);
        QJsonObject settings = doc.object();
        if (settings.empty())
        {
            Log("APIProvider.loadFavorite(): JSON parsing error");
            return false;
        }
        sl.strategies.setIndex(settings["strategy"].toInt());
        sl.updatePropertyList(pl);
        pl.background.setIndex(settings["background"].toInt());
        pl.model.setIndex(settings["model"].toInt());
        pl.orientation.setIndex(settings["orientation"].toInt());
        pl.cropFactor.setValue(settings["cropFactor"].toDouble());
        pl.modelDistance.setValue(settings["modelDistance"].toDouble());
        pl.backgroundDistance.setValue(settings["backgroundDistance"].toDouble());
        pl.focalLength.setValue(settings["focalLength"].toDouble());
        pl.diaphragm.setValue(settings["diaphragm"].toDouble());
        Log("APIProvider.loadFavorite(): Loaded from JSON %s", doc.toJson(QJsonDocument::Compact).data());
        return true;
    }
}

bool APIProvider::saveFavorite(QString title, const StrategyList &sl, const PropertyList &pl)
{
//    if (userOnline()) //will work anyway
//    {
//        //todo
//        return false;
//    }
//    else
    {
        Log("APIProvider.saveFavorite(): Server unavailable, save local");
        QJsonObject settings =
        {
            {"strategy", sl.strategies.index()},
            {"background", pl.background.index()},
            {"model", pl.model.index()},
            {"orientation", pl.orientation.index()},
            {"cropFactor", pl.cropFactor.value()},
            {"modelDistance", pl.modelDistance.value()},
            {"backgroundDistance", pl.backgroundDistance.value()},
            {"focalLength", pl.focalLength.value()},
            {"diaphragm", pl.diaphragm.value()}
        };
        QJsonDocument doc(settings);
        QFile file(FavoritePath() + title + ".settings");
        file.open(QIODevice::WriteOnly | QIODevice::Text);
        bool success = file.write(doc.toJson().data()) > 0;
        const char *logmsg = success ?
            "APIProvider.saveFavorite(): Saved to file %s" :
            "APIProvider.saveFavorite(): File write error %s";
        Log(logmsg, file.fileName().toUtf8().data());
        return success;
    }
}

bool APIProvider::deleteFavorite(QString title)
{
//    if (userOnline()) //will work anyway
//    {
//        //todo
//    }
//    else
    {
        Log("APIProvider.deleteFavorite(): Delete local favorite");
        QFile(FavoritePath() + title + ".settings").remove();
    }
    return true;
}
