

#ifndef COMMANDS_H_
#define COMMANDS_H_

#include<iostream>
#include <string.h>
#include <fstream>
#include <vector>
#include "HybridAnomalyDetector.h"

using namespace std;

class DefaultIO{
public:
    virtual string read()=0;
    virtual void write(string text)=0;
    virtual void write(float f)=0;
    virtual void read(float* f)=0;
    virtual ~DefaultIO(){}

    // you may add additional methods here
};

// you may add here helper classes

// will save the inner state
struct State {
    float threshold = 0.9;
};

// you may edit this class
class Command{
protected: // added this
    DefaultIO* dio;
public:
    // the description of the command
    const string des;
    Command(DefaultIO* dio, const string des) : dio(dio), des(des){}
    virtual void execute(State* state)=0;
    virtual ~Command(){}
};

// implement here your command classes

class UploadCSVFile: public Command{
public:
    UploadCSVFile(DefaultIO* dio) : Command(dio, "upload a time series csv file.\n") {
    }

    virtual void execute() {
        // array of strings to save the instructions of the server
        string instruction[2] = {"Please upload your local train CSV file.\n",
                      "Please upload your local test CSV file.\n"};
        // array of strings to save the CSV's file names
        string CSVfileName[2] = {"anomalyTrain.csv", "anomalyTest.csv"};
        // upload twice (two files) - first the train file and then the test file
        for (int i = 0; i < 2; i++) {
            dio->write(instruction[i]);
            // to read from the file
            string fileName = CSVfileName[i];
            ofstream out(fileName);
            string data = "";
            while (out.eof()!= true){
                out<<data<<endl;
            }
            out.close();
            dio->write("Upload complete.\n");
        }
    }
};



class AlgorithmSettings: public Command{
public:
    AlgorithmSettings(DefaultIO* dio) : Command(dio, "algorithm settings.\n") {
    }

    virtual void execute(State* state) {
        float newThreshold;
        // present the option to change the threshold as long as the entered value is not valid
        while (true) {
            dio->write("The current correlation threshold is");
            dio->write(state->threshold);
            dio->write("\nType a new threshold\n");
            // let the user to write a new threshold
            dio->read(&newThreshold);
            // if the threshold that the user entered is valid, save it and break
            if (newThreshold <= 1 && newThreshold > 0) {
                state->threshold = newThreshold;
                break;
            }
            // if the threshold that the user entered is not valid
            dio->write("Please choose a value between 0 and 1.\n");

        }

    }
};



class DetectAnomalies: public Command{

};



class ResultsDisplay: public Command{

};



class UploadAnomAndAnalyzeRes: public Command{

};



class Exit: public Command{
public:
    Exit(DefaultIO* dio) : Command(dio, "Exit.\n") {
    }

    virtual void execute(State* state) {
        cout<<this->des<<endl;
    }
};



#endif /* COMMANDS_H_ */