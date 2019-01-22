#ifndef TOOLSLIBRARY_H
#define TOOLSLIBRARY_H

#include <QtCore>

QString AppPath();           // путь запуска приложения
QString AppName();           // имя приложения без расширения
QString UserDocumentsPath(); // путь к системной папке "документы"
QString AppDataPath();       // путь к данным приложения
QString LogPath();           // путь к файлам логов
QString FavoritePath();      // путь к файлам избранных настроек
QString ImagePath();         // путь к файлам изображений
QString SettingsPath();      // путь к файлам настроек

#endif // TOOLSLIBRARY_H
