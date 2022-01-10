/*
 * CLI.cpp
 *
 * Authors:
 * Mor Siman Tov, ID: 208682484
 * Shai Fisher, ID: 315150342
 *
 */

#include "CLI.h"

CLI::CLI(DefaultIO *dio) {
    this->dio = dio;
    // here we will push to the commands_lst all the option functions
    this->commands_lst.push_back(new UploadCSVFile(dio));
    this->commands_lst.push_back(new AlgorithmSettings(dio));
    this->commands_lst.push_back(new DetectAnomalies(dio));
    this->commands_lst.push_back(new ResultsDisplay(dio));
    this->commands_lst.push_back(new UploadAnomAndAnalyzeRes(dio));
    this->commands_lst.push_back(new Exit(dio));
}

void CLI::start(){
    InnerState innerState;
    int option=-1;
    char zero = '0';
    while(option!=5){
        dio->write("Welcome to the Anomaly Detection Server.\n");
        dio->write("Please choose an option:\n");
        int listSize = commands_lst.size();
        // printing the options list
        for(size_t i=0;i<listSize;i++){
            string s("1.");
            s[0]=((char)(i+1+zero));
            dio->write(s);
            dio->write(commands_lst[i]->des+"\n");
        }
        string input = dio->read();
        option=input[0]-zero-1;
        if(option<=6 && option>=0)
            commands_lst[option]->execute(&innerState);
    }
}

CLI::~CLI() {
    // deallocatng the allocated memory of the commands vector
    for (int i = 0; i < commands_lst.size(); ++i) {
        delete commands_lst[i];
    }
}