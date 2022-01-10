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


//void CLI::start() {
//    int optionNumber = -1;
//    string inputClient;
//    InnerState innerState;
//    string options = "Welcome to the Anomaly Detection Server.\n"
//                     "Please choose an option:\n"
//                     "1. upload a time series csv file\n"
//                     "2. algorithm settings\n"
//                     "3. detect anomalies\n"
//                     "4. display results\n"
//                     "5. upload anomalies and analyze results\n"
//                     "6. exit\n";
//    while (optionNumber != 5) {
//        // print the menu
//        this->dio->write(options);
//        // read the option the client chose
//        inputClient = this->dio->read();
//        // convert the option to integer
//        optionNumber = inputClient[0] - '0' - 1;
//        // if the option is valid (in range of 1-6)
//        if (optionNumber >= 0 && optionNumber <= 5) {
//            // execute the command according to the option chosen
//            commands_lst[optionNumber]->execute(&innerState);
//        }
//    }
//}


void CLI::start(){
    InnerState innerState;
    int sign=-1;
    while(sign!=5){
        dio->write("Welcome to the Anomaly Detection Server.\n");
        dio->write("Please choose an option:\n");
        for(size_t i=0;i<commands_lst.size();i++){
            string s("1.");
            s[0]=((char)(i+1+'0'));
            dio->write(s);
            dio->write(commands_lst[i]->des+"\n");
        }
        string input = dio->read();
        sign=input[0]-'0'-1;
        if(sign>=0 && sign<=6)
            commands_lst[sign]->execute(&innerState);
    }
}


CLI::~CLI() {
    // deallocatng the allocated memory of the commands vector
    for (int i = 0; i < commands_lst.size(); ++i) {
        delete commands_lst[i];
    }
}