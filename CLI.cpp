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
}


void CLI::start() {
    int optionNumber = -1;
    bool finishCLI = false;
    string options = "Welcome to the Anomaly Detection Server.\n"
                     "Please choose an option:\n"
                     "1. upload a time series csv file\n"
                     "2. algorithm settings\n"
                     "3. detect anomalies\n"
                     "4. display results\n"
                     "5. upload anomalies and analyze results\n"
                     "6. exit\n";
//    while (!finishCLI) {
//    }
}


CLI::~CLI() {
    // deallocatng the allocated memory of the commands vector
    int lenOfCommands = commands_lst.size();
    for (int i = 0; i < lenOfCommands; ++i) {
        delete commands_lst[i];
    }
}
