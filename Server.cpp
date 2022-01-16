/*
 * Server.cpp
 *
 * Authors:
 * Mor Siman Tov, ID: 208682484
 * Shai Fisher, ID: 315150342
 *
 */

#include "Server.h"

string SocketIO::read() {
    char charToRead = 0;
    string strToRead;
    int charS = sizeof(char);
    char c = '\n';
    while (charToRead != c) {
        recv(this->clientID, &charToRead, charS, 0);
        if (charToRead == c) {
            break;
        }
        strToRead = strToRead + charToRead;
    }
    return strToRead;
}


void SocketIO::write(string text) {
    const char *txt = text.c_str();
    send(this->clientID, txt, strlen(txt), 0);
}


void SocketIO::write(float f) {
    ostringstream strStream;
    strStream << f;
    string strToRead(strStream.str());
    write(strToRead);
}

void SocketIO::read(float *f) {
    //  will be shown in the string line
}


Server::Server(int port) throw(const char *) {
    this->tStopped = false;
    // create a new socket
    this->sSocket = socket(AF_INET, SOCK_STREAM, 0);
    // if socket failed
    if (this->sSocket < 0)
        throw "socket failed";
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(port);
    // if the binding failed
    if (bind(sSocket, (struct sockaddr *) &server, sizeof(server)) < 0)
        throw "bind failure";
    // if listen failed
    if (listen(this->sSocket, 3) < 0)
        throw "listen failure";
}

void sigHandler(int signalNum) {
    cout << "signal handler" << endl;
}


void Server::start(ClientHandler &ch) throw(const char *) {
    this->t = new thread([&ch, this]() {
        signal(SIGALRM, sigHandler);
        // while the thread hasn't stopped
        while (!this->tStopped) {
            socklen_t clientSize = sizeof(client);
            alarm(1);
            // accept the client
            int cSocket = accept(sSocket, (struct sockaddr *) &client, &clientSize);
            // if the fd is valid
            if (cSocket > 0) {
                ch.handle(cSocket);
                close(cSocket);
            }
            alarm(0);
        }
        // close the socket
        close(this->sSocket);
    });
}


void Server::stop() {
    this->tStopped = true;
    this->t->join(); // do not delete this!
}

Server::~Server() = default;