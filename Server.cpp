/*
 * Server.cpp
 *
 * Authors:
 * Mor Siman Tov, ID: 208682484
 * Shai Fisher, ID: 315150342
 *
 */

#include "Server.h"

Server::Server(int port) throw(const char *) {
    this->stopped = false;
    this->s = socket(AF_INET, SOCK_STREAM, 0);
    // if socket failed
    if (this->s < 0) {
        throw "socket failed";
    }
    server.sin_family = AF_INET;
    // if the binding failed
    if (bind(this->s, (struct sockaddr *) &server, sizeof(server)) < 0) {
        throw "bind failure";
    }
    // if listen failed
    if (listen(s, 3) < 0) {
        throw "listen failure";
    }
}

void sigHandler(int sigNum){
    cout<<"sidH"<<endl;
}

void Server::start(ClientHandler &ch) throw(const char *) {
    th = new thread[&ch, this]()
    {
        signal(SIGALRM, sigHandler);
        while (!this->stopped) {
            socklen_t SizeOfClient = sizeof(client);
            alarm(1);
            int acception = accept(this->s, (struct sockaddr *) &client, &SizeOfClient)
            if (acception > 0) {
                ch.handle(acception);
                close(acception);
            }
            alarm(0);

        }
        close(this->s)

    }
}

void Server::stop() {
    this->stopped = true;
    t->join(); // do not delete this!
}

Server::~Server() {
}

// functions that override defaultIO

string socketIO::read() {
    char letter = 0;
    string data = "";
    size_t size = 0;
    while (letter != '\n') {
        recv(this->clientId, &letter, sizeof(char), 0);
        data += letter;
    }
    return data;
}

void socketIO::read(float *number) {
// todo do we need this? is it working?
    recv(this->clientId, number, sizeof(*number), 0);
}

void socketIO::write(float number) {
    ostringstream s;
    s << number;
    string data(s.str());
    write(data);
}

void socketIO::write(string text) {
    const char *data = text.c_str();
    int lenData = strlen(data);
    send(this->clientId, data, lenData, 0);
}