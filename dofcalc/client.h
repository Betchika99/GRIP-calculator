#ifndef CLIENT_H
#define CLIENT_H
#include <QStringList>
#include <string>
#include <fstream>
#include "boost/asio.hpp"
#include "json_parser.hpp"

using namespace std;
using namespace boost::asio;
using boost::asio::ip::tcp;

class Client {
public:
    Client() = default;
    ~Client() = default;
    string static getStrategies();
    QStringList static getImagesNames(const QString& strategyName);
    // пока ищут картинку по захардокеднному урлу
    bool static getBackgroud(const string& fileName);
    bool static getModel(const string& fileName);
    string static getLastParams();
    string static getFavorite();
    bool static setLastParams(const string& jsonParams);
    bool static setFavorite(const string& jsonParams);
    bool static deleteFavorite(const string& jsonParams);

private:
    QStringList static getParams(const string& serverName, const string& port,
                                 const string& getCommand, const QString& paramName,
                                 const string& paramType);
    bool static getPicture(const string& serverName, const string& port,
                    const string& getCommand, const string& fileName,
                    const string& pictureType);
    bool static setParams(const string& serverName, const string& port, const string& getCommand, const string& jsonParams);
};

#endif // CLIENT_H
