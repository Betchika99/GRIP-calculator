#include <QApplication>
#include "toolslibrary.h"

QString AppPath()
{
    return QApplication::applicationDirPath() + "/";
}

QString AppName()
{
    QString appName = QApplication::applicationFilePath();
    if (!appName.contains(".")) appName += "."; //for Linux
    return QFileInfo(appName).baseName();
}

QString UserDocumentsPath()
{
    return QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) + "/";
}

QString AppDataPath()
{
    QString docPath = UserDocumentsPath() + AppName() + "/";
    return QDir(docPath).exists() ? docPath : AppPath();
}

QString LogPath()
{
    QString path = AppDataPath() + "logs/";
    bool success = QDir().mkpath(path);
    return success ? path : AppPath();
}

QString FavoritePath()
{
    QString path = AppDataPath() + "favorites/";
    bool success = QDir().mkpath(path);
    return success ? path : AppPath();
}

QString ImagePath()
{
    QString path = AppDataPath() + "images/";
    bool success = QDir().mkpath(path);
    return success ? path : AppPath();
}

QString SettingsPath()
{
    QString path = AppDataPath() + "settings/";
    bool success = QDir().mkpath(path);
    return success ? path : AppPath();
}
