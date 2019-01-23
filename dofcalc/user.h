#ifndef USER_H
#define USER_H
#include <QString>
#include <QtCore>


class User
{
public:
    User();

//    QString login;
//    QString password;

    static QJsonObject exportToJSON(QString login, QString password)
    {
        QJsonObject json =
        {
            {"email", login},
            {"password", password}
        };
        return json;
    }
    static QJsonObject exportToJSON(QString login, QString password, QString title)
    {
        QJsonObject json =
        {
            {"email", login},
            {"password", password},
            {"title", title}
        };
        return json;
    }
};

#endif // USER_H
