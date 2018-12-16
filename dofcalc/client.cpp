#include "client.h"

string Client::getStrategies() {
    return this->getParams("0.0.0.0", "12345", "/strategies");
}

string Client::getImagesNames() {
    return this->getParams("0.0.0.0", "12345", "/images_list");
}

bool Client::getBackgroud(const string& fileName) {
    return getPicture("0.0.0.0", "12345", "/background_image", fileName);
}

bool Client::getModel(const string& fileName) {
    return getPicture("0.0.0.0", "12345", "/model_image", fileName);
}

string Client::getLastParams() {
    return this->getParams("0.0.0.0", "12345", "/get_last_params");
}

string Client::getParams(const string& serverName, const string& port, const string& getCommand) {
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


       // Read the response headers, which are terminated by a blank line.
    boost::asio::read_until(socket, response, "\r\n\r\n");

       // Process the response headers.
    std::string header;
    while (std::getline(response_stream, header) && header != "\r") {}

       // Write whatever content we already have to output.
    string result = "";
    while (response.size() > 0) {
        std::istream is(&response);
        string line;
        std::getline(is, line);
        result += line;
    }
       // Read until EOF, writing data to output as we go.
    while (boost::asio::read(socket, response, boost::asio::transfer_at_least(1), error)) {
        std::istream is(&response);
        string line;
        std::getline(is, line);
        result += line;
    }
    return result;
}

bool Client::getPicture(const string& serverName, const string& port, const string& getCommand, const string& fileName) {
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


       // Read the response headers, which are terminated by a blank line.
    boost::asio::read_until(socket, response, "\r\n\r\n");

       // Process the response headers.
    std::string header;
    while (std::getline(response_stream, header) && header != "\r") {}

       // Write whatever content we already have to output.
    std::ofstream outFile("/Users/e_dobryanskaya/Desktop/testOut.png", std::ofstream::out | std::ofstream::binary);
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
