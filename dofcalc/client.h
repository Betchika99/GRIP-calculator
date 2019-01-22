#ifndef CLIENT_H
#define CLIENT_H
#include <QStringList>
#include <string>
#include <fstream>
#include "boost/asio.hpp"
#include <QJsonObject>
#include <QJsonDocument>

using namespace std;
using namespace boost::asio;
using boost::asio::ip::tcp;

class Client {
public:
    Client() = default;
    ~Client() = default;
    QJsonObject static getStrategies();
    QJsonObject static getImagesNames(const QString& strategyName);
    // пока ищут картинку по захардокеднному урлу
    bool static getBackgroud(const string& fileName);
    bool static getModel(const string& fileName);
    QJsonObject static getLastParams(const QJsonObject& userInfo);







    string static getFavorite();
    bool static setLastParams(const string& jsonParams);
    bool static setFavorite(const string& jsonParams);
    bool static deleteFavorite(const string& jsonParams);

private:
    QJsonObject static makeRequestForStrategies(const string& serverName, const string& port,
                                                const string& getCommand);
    QJsonObject static getParams(const string& serverName, const string& port,
                                 const string& getCommand, const QJsonObject& userInfo);





    bool static getPicture(const string& serverName, const string& port,
                    const string& getCommand, const string& fileName,
                    const string& pictureType);
    bool static setParams(const string& serverName, const string& port, const string& getCommand, const string& jsonParams);
};

#endif // CLIENT_H
