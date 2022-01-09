/*
 * Server.h
 *
 * Authors:
 * Mor Siman Tov, ID: 208682484
 * Shai Fisher, ID: 315150342
 *
 */

#ifndef SERVER_H_
#define SERVER_H_

#include "CLI.h"
#include <string.h>
#include <stdio.h>
#include <sys/socket>
#include <stdlib.h>
#include <pthread.h>
#include <thread>
#include <IOstream>


using namespace std;

// edit your ClientHandler interface here:
class ClientHandler{
public:
    virtual void handle(int clientID)=0;
};


// you can add helper classes here and implement on the cpp file
class socketIO:public DefaultIO {
    int clientId;
public:
    socketIO(int clientId) : clientId(clientId) {
    }

    virtual string read();
    virtual void read(float* number);
    virtual void write(float number);
    virtual void write(string data);

};

// edit your AnomalyDetectionHandler class here
class AnomalyDetectionHandler:public ClientHandler{
public:
    virtual void handle(int clientID){

    }
};


// implement on Server.cpp
class Server {
    thread* t; // the thread to run the start() method in
    // you may add data members
    volatile bool stopped;
    //sockaddr_in server;
    //sockaddr_in client;

public:
    Server(int port) throw (const char*);
    virtual ~Server();
    void start(ClientHandler& ch)throw(const char*);
    void stop();
};

#endif /* SERVER_H_ */
