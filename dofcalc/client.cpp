#include "client.h"
#include "jansson.h"
#include <iostream>

QJsonObject Client::getStrategies() {
    return makeRequestForStrategies("0.0.0.0", "12345", "/strategies");
}

QJsonObject Client::getImagesNames(const QString& strategyName) {
    return getParams("0.0.0.0", "12345", "/images_list", strategyName, "strategy_name");
}

QJsonObject Client::makeRequestForStrategies(const string& serverName, const string& port,
                                            const string& getCommand) {
    QStringList result;
    boost::asio::io_service io_service;
    tcp::resolver resolver(io_service);
    tcp::resolver::query query(serverName, port);
    tcp::resolver::iterator endpoint_iterator = resolver.resolve(query);
    tcp::resolver::iterator end;

    tcp::socket socket(io_service);
    boost::asio::connect(socket, endpoint_iterator);
    boost::asio::streambuf request;
    std::ostream request_stream(&request);

    request_stream << "GET " << getCommand << " HTTP/1.0\r\n";
    request_stream << "Host: " << serverName << "\r\n";
    request_stream << "Accept: */*\r\n";
    request_stream << "Connection: close\r\n\r\n";

       // Send the request.
    boost::asio::write(socket, request);

       // Read the response status line.
    boost::asio::streambuf response;
    boost::asio::read_until(socket, response, "\r\n");

       // Check that response is OK.
    std::istream response_stream(&response);
    std::string http_version;
    response_stream >> http_version;
    unsigned int status_code;
    response_stream >> status_code;
    std::string status_message;
    std::getline(response_stream, status_message);

    QJsonObject obj;

    if (!response_stream || http_version.substr(0, 5) != "HTTP/") {
        std::cerr << "Invalid response\n";
        return obj;
     }

     if (status_code != 200) {
        std::cout << "Response returned with status code " << status_code << "\n";
        return obj;
     }

       // Read the response headers, which are terminated by a blank line.
    boost::asio::read_until(socket, response, "\r\n\r\n");

       // Process the response headers.
    std::string header;
    while (std::getline(response_stream, header) && header != "\r") { std::cout << header << "\n"; }
    std::cout << "\n";

       // Write whatever content we already have to output.
    QString jsonQString = "";
    while (response.size() > 0) {
      //  std::cout << &response;
          std::istream is(&response);
          string line;
          is >> line;
          jsonQString += QString::fromStdString(line);
    }
       // Read until EOF, writing data to output as we go.
    boost::system::error_code error;
    while (boost::asio::read(socket, response, boost::asio::transfer_at_least(1), error)) {
        //      std::cout << &response;
        while (response.size() > 0) {
                std::istream is(&response);
                string line;
                is >> line;
                jsonQString += QString::fromStdString(line);
        }
    }
    if (error != boost::asio::error::eof)
          throw boost::system::system_error(error);

    QJsonDocument doc = QJsonDocument::fromJson(jsonQString.toUtf8());
    // check validity of the document
    if (!doc.isNull()) {
       if (doc.isObject()) {
           obj = doc.object();
       } else {
           return obj;
       }
    } else {
       return obj;
    }
    return obj;
}

bool Client::getBackgroud(const string& fileName) {
    return getPicture("0.0.0.0", "12345", "/background_image", fileName, "background_name");
}

bool Client::getModel(const string& fileName) {
    return getPicture("0.0.0.0", "12345", "/model_image", fileName, "model_name");
}

bool Client::getPicture(const string& serverName, const string& port,
                        const string& getCommand, const string& fileName,
                        const string& pictureType) {
    bool result = false;
    boost::asio::io_service io_service;
    tcp::resolver resolver(io_service);
    tcp::resolver::query query(serverName, port);
    tcp::resolver::iterator endpoint_iterator = resolver.resolve(query);
    tcp::resolver::iterator end;

    tcp::socket socket(io_service);
//    boost::system::error_code error = boost::asio::error::host_not_found;
//    while (error && endpoint_iterator != end) {
//       socket.close();
//       socket.connect(*endpoint_iterator++, error);
//    }
    boost::asio::connect(socket, endpoint_iterator);
    boost::asio::streambuf request;
    std::ostream request_stream(&request);

    json_t *root = json_object();
    json_object_set_new(root, pictureType.c_str(), json_string(fileName.c_str()));
    string requestData = string(json_dumps(root, JSON_INDENT(3)));

    request_stream << "POST " << getCommand << " HTTP/1.0\r\n";
    request_stream << "Host: " << serverName << "\r\n";
    request_stream << "User-Agent: C/1.0";
    request_stream << "Content-Type: application/json; charset=utf-8 \r\n";
    request_stream << "Accept: */*\r\n";
    request_stream << "Content-Length: " << requestData.length() << "\r\n";
    request_stream << "Connection: close\r\n\r\n";
    request_stream << requestData;

       // Send the request.
    boost::asio::write(socket, request);

       // Read the response status line.
    boost::asio::streambuf response;
    boost::asio::read_until(socket, response, "\r\n");

       // Check that response is OK.
    std::istream response_stream(&response);
    std::string http_version;
    response_stream >> http_version;
    unsigned int status_code;
    response_stream >> status_code;
    std::string status_message;
    std::getline(response_stream, status_message);

    if (!response_stream || http_version.substr(0, 5) != "HTTP/") {
        std::cerr << "Invalid response\n";
        return false;
    }
    if (status_code != 200) {
        std::cerr << "Response returned with status code " << status_code << "\n";
        return false;
    }
       // Read the response headers, which are terminated by a blank line.
    boost::asio::read_until(socket, response, "\r\n\r\n");

       // Process the response headers.
    std::string header;
    while (std::getline(response_stream, header) && header != "\r") {}

       // Write whatever content we already have to output.
    std::ofstream outFile("/Users/e_dobryanskaya/Desktop/testBack.png", std::ofstream::out | std::ofstream::binary);
    while (response.size() > 0) {
        outFile << &response;
    }
       // Read until EOF, writing data to output as we go.
    boost::system::error_code error;
    while (boost::asio::read(socket, response, boost::asio::transfer_at_least(1), error)) {
        outFile << &response;
    }
    if (error != boost::asio::error::eof)
          throw boost::system::system_error(error);
    result = true;
    return result;
}

QJsonObject Client::getLastParams(const QJsonObject& userInfo) {
    return getParams("0.0.0.0", "12345", "/get_last_params", userInfo);
}

QJsonObject Client::getParams(const string& serverName, const string& port,
                              const string& getCommand, const QJsonObject& userInfo) {
    QStringList result;
    boost::asio::io_service io_service;
    tcp::resolver resolver(io_service);
    tcp::resolver::query query(serverName, port);
    tcp::resolver::iterator endpoint_iterator = resolver.resolve(query);
    tcp::resolver::iterator end;

    tcp::socket socket(io_service);
    boost::asio::connect(socket, endpoint_iterator);
    boost::asio::streambuf request;
    std::ostream request_stream(&request);

    request_stream << "POST " << getCommand << " HTTP/1.0\r\n";
    request_stream << "Host: " << serverName << "\r\n";
    request_stream << "User-Agent: C/1.0";
    request_stream << "Content-Type: application/json; charset=utf-8 \r\n";
    request_stream << "Accept: */*\r\n";
    request_stream << "Content-Length: " << userInfo.length() << "\r\n";
    request_stream << "Connection: close\r\n\r\n";
    request_stream << userInfo;

       // Send the request.
    boost::asio::write(socket, request);

       // Read the response status line.
    boost::asio::streambuf response;
    boost::asio::read_until(socket, response, "\r\n");

       // Check that response is OK.
    std::istream response_stream(&response);
    std::string http_version;
    response_stream >> http_version;
    unsigned int status_code;
    response_stream >> status_code;
    std::string status_message;
    std::getline(response_stream, status_message);

    QJsonObject obj;

    if (!response_stream || http_version.substr(0, 5) != "HTTP/") {
        std::cerr << "Invalid response\n";
        return obj;
     }

     if (status_code != 200) {
        std::cout << "Response returned with status code " << status_code << "\n";
        return obj;
     }

       // Read the response headers, which are terminated by a blank line.
    boost::asio::read_until(socket, response, "\r\n\r\n");

       // Process the response headers.
    std::string header;
    while (std::getline(response_stream, header) && header != "\r") { std::cout << header << "\n"; }
    std::cout << "\n";

       // Write whatever content we already have to output.
    QString jsonQString = "";
    while (response.size() > 0) {
  //      std::cout << &response;
          std::istream is(&response);
          string line;
          is >> line;
          jsonQString += QString::fromStdString(line);
    }
       // Read until EOF, writing data to output as we go.
    boost::system::error_code error;
    while (boost::asio::read(socket, response, boost::asio::transfer_at_least(1), error)) {
        //      std::cout << &response;
        while (response.size() > 0) {
                std::istream is(&response);
                string line;
                is >> line;
                jsonQString += QString::fromStdString(line);
        }
    }
    if (error != boost::asio::error::eof)
          throw boost::system::system_error(error);

    QJsonDocument doc = QJsonDocument::fromJson(jsonQString.toUtf8());
    // check validity of the document
    if (!doc.isNull()) {
       if (doc.isObject()) {
           obj = doc.object();
       } else {
           return obj;
       }
    } else {
       return obj;
    }
    return obj;
}










string Client::getFavorite() {
   // return getParams("0.0.0.0", "12345", "/favorites_list");
    return "Hello, World";
}

bool Client::setLastParams(const string& jsonParams) {
    return setParams("0.0.0.0", "12345", "/set_last_params", jsonParams);
}

bool Client::setFavorite(const string& jsonParams) {
    return setParams("0.0.0.0", "12345", "/set_favorite", jsonParams);
}

bool Client::deleteFavorite(const string& jsonParams) {
    return setParams("0.0.0.0", "12345", "/delete_favorite", jsonParams);
}


bool Client::setParams(const string& serverName, const string& port, const string& getCommand, const string& jsonParams) {
    bool result = false;
    boost::asio::io_service io_service;
    tcp::resolver resolver(io_service);
    tcp::resolver::query query(serverName, port);
    tcp::resolver::iterator endpoint_iterator = resolver.resolve(query);
    tcp::resolver::iterator end;

    tcp::socket socket(io_service);
    boost::system::error_code error = boost::asio::error::host_not_found;
    while (error && endpoint_iterator != end) {
       socket.close();
       socket.connect(*endpoint_iterator++, error);
    }
    boost::asio::streambuf request;
    std::ostream request_stream(&request);

    request_stream << "POST " << getCommand << " HTTP/1.0\r\n";
    request_stream << "Host: " << serverName << "\r\n";
    request_stream << "User-Agent: C/1.0";
    request_stream << "Content-Type: application/json; charset=utf-8 \r\n";
    request_stream << "Accept: */*\r\n";
    request_stream << "Content-Length: " << jsonParams.length() << "\r\n";
    request_stream << "Connection: close\r\n\r\n";
    request_stream << jsonParams;

       // Send the request.
    boost::asio::write(socket, request);

       // Read the response status line.
    boost::asio::streambuf response;
    boost::asio::read_until(socket, response, "\r\n");

       // Check that response is OK.
    std::istream response_stream(&response);
    std::string http_version;
    response_stream >> http_version;
    unsigned int status_code;
    response_stream >> status_code;
    std::string status_message;
    std::getline(response_stream, status_message);


       // Read the response headers, which are terminated by a blank line.
    boost::asio::read_until(socket, response, "\r\n\r\n");

       // Process the response headers.
    std::string header;
    while (std::getline(response_stream, header) && header != "\r") {}

       // Write whatever content we already have to output.
    std::ofstream outFile("/Users/e_dobryanskaya/Desktop/testBack.png", std::ofstream::out | std::ofstream::binary);
    while (response.size() > 0) {
        outFile << &response;
    }
       // Read until EOF, writing data to output as we go.
    while (boost::asio::read(socket, response, boost::asio::transfer_at_least(1), error)) {
        outFile << &response;
    }
    result = true;
    return result;
}
