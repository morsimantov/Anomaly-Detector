//Noam Gini ID: 208375642
//Noa Ziv ID: 208462457

#ifndef EX1_SERVER_H
#define EX1_SERVER_H


#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>

#include <pthread.h>
#include <thread>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <signal.h>
#include <sstream>

#include "CLI.h"

using namespace std;

// edit your ClientHandler interface here:
class ClientHandler {
public:
    virtual void handle(int clientID) = 0;
};

// you can add helper classes

class SocketIO : public DefaultIO {
    int clientID;
public:

    explicit SocketIO(int clientID) : clientID(clientID) {}

    virtual string read();

    virtual void write(string text);

    virtual void write(float f);

    virtual void read(float *f);

};

// edit your AnomalyDetectionHandler class here
class AnomalyDetectionHandler : public ClientHandler {
public:
    /**
     * Method handle - handles the beginning of the communication process between the
     * server and the client that is connected.
     * @param clientID - (type int) the port number of the client.
     */
    virtual void handle(int clientID) {
        SocketIO sio(clientID);
        CLI cli(&sio);
        cli.start();
    }
};

// implement on Server.cpp
class Server {
    // you may add data members
    int x;
    sockaddr_in server;
    sockaddr_in client;
    thread *t;
    volatile bool threadStopped;

public:
    Server(int port) throw(const char *);

    virtual ~Server();

    void start(ClientHandler &ch) throw(const char *);

    void stop();
};

#endif //EX1_SERVER_H
