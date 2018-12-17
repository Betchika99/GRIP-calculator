#ifndef CLIENT_H
#define CLIENT_H
#include <string>
#include <fstream>
#include "boost/asio.hpp"

using namespace std;
using namespace boost::asio;
using boost::asio::ip::tcp;

class Client {
public:
    Client() = default;
    ~Client() = default;
    string getStrategies();
    string getImagesNames();
    // пока ищут картинку по захардокеднному урлу
    bool getBackgroud(const string& fileName);
    bool getModel(const string& fileName);
    string getLastParams();
    string getFavorite();
    bool setLastParams(const string& jsonParams);
    bool setFavorite(const string& jsonParams);
    bool deleteFavorite(const string& jsonParams);

private:
    string getParams(const string& serverName, const string& port, const string& getCommand);
    bool getPicture(const string& serverName, const string& port,
                    const string& getCommand, const string& fileName,
                    const string& pictureType);
    bool setParams(const string& serverName, const string& port, const string& getCommand, const string& jsonParams);
};

#endif // CLIENT_H
