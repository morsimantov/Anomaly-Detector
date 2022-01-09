/*
 * Server.cpp
 *
 * Authors:
 * Mor Siman Tov, ID: 208682484
 * Shai Fisher, ID: 315150342
 *
 */

#include "Server.h"

Server::Server(int port)throw (const char*) {

}

void Server::start(ClientHandler& ch)throw(const char*){
}

void Server::stop(){
    stopped = true;
    t->join(); // do not delete this!
}

Server::~Server() {
}

// functions that override defaultIO

string socketIO::read() {
    char letter = 0;
    string data = "";
    size_t size = 0;
    while(letter != '\n') {
        recv(this->clientId, &letter, sizeof(char), 0);
        data += letter;
    }
    return data;
}

void socketIO::read(float* number) {

}

void socketIO::write(float number) {
    ostringstream s;
    s << number;
    string data(s.str());
    write(data);
}

void socketIO::write(string text) {
    const char* data = text.c_str();
    int lenData = strlen(data);
    send(this->clientId, data, lenData,  0);
}