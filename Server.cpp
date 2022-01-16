//Noam Gini ID: 208375642
//Noa Ziv ID: 208462457

#include "Server.h"


string SocketIO::read() {
    char charToCheck = 0;
    string strToRead = "";
    int charS = sizeof(char);
    char c = '\n';
    while (charToCheck != c) {
        recv(clientID, &charToCheck, charS, 0);
        if (charToCheck == c) {
            break;
        }
        strToRead = strToRead + charToCheck;
    }
    return strToRead;
}


void SocketIO::write(string text) {
    const char *txt = text.c_str();
    send(clientID, txt, strlen(txt), 0);
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
    threadStopped = false;
    x = socket(AF_INET, SOCK_STREAM, 0);
    if (x < 0)
        throw "socket failed";

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY; //  IP server (local host)
    server.sin_port = htons(port); // server port
    if (bind(x, (struct sockaddr *) &server, sizeof(server)) < 0)
        throw "bind failure";
    if (listen(x, 3) < 0)
        throw "listen failure";
}

void sigHandler(int signalNum) {
    cout << "signal handler" << endl;
}


void Server::start(ClientHandler &ch) throw(const char *) {
    t = new thread([&ch, this]() {
        signal(SIGALRM, sigHandler);
        while (!threadStopped) {
            socklen_t clientSize = sizeof(client);
            alarm(1);
            // ac  is file descriptor
            int ac = accept(x, (struct sockaddr *) &client, &clientSize);
            // client is connected
            if (ac > 0) {
                ch.handle(ac);
                close(ac);
            }
            alarm(0);
        }
        close(x);
    });
}


void Server::stop() {
    threadStopped = true;
    t->join(); // do not delete this!
}

Server::~Server() = default;


