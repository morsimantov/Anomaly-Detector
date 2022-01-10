/*
 * commands.h
 *
 * Authors:
 * Mor Siman Tov, ID: 208682484
 * Shai Fisher, ID: 315150342
 *
 */
#ifndef COMMANDS_H_
#define COMMANDS_H_

#include<iostream>
#include <string.h>
#include <fstream>
#include <vector>
#include "HybridAnomalyDetector.h"

using namespace std;

class DefaultIO {
public:
    virtual string read() = 0;

    virtual void write(string text) = 0;

    virtual void write(float f) = 0;

    virtual void read(float *f) = 0;

    virtual ~DefaultIO() {}

    void readFile(string fileName){
        ofstream out(fileName);
        string str="";
        string done = "done";
        while((str=read())!=done){
            out<<str<<endl;
        }
        out.close();
    }

    // you may add additional methods here
};

// you may add here helper classes

// will save the report with time steps
struct fullReport {
    bool truePositive;
    int startAnomaly;
    int endAnomaly;
    string des;
};

// will save the inner state
struct InnerState {
    float threshold;
    vector<AnomalyReport> anomalyReport;
    vector<fullReport> fullReports;
    int testSize;
    InnerState(){
        threshold=0.9;
        testSize=0;
    }
};

// you may edit this class
class Command {
protected: // added this
    DefaultIO *dio;
public:
    // the description of the command
    const string des;

    Command(DefaultIO *dio, const string des) : dio(dio), des(des) {}

    virtual void execute(InnerState *innerState) = 0;

    virtual ~Command() {}
};

// implement here your command classes

class UploadCSVFile : public Command {
public:
    UploadCSVFile(DefaultIO *dio) : Command(dio, "upload a time series csv file") {
    }

    virtual void execute(InnerState* sharedState){
        dio->write("Please upload your local train CSV file.\n");
        dio->readFile("anomalyTrain.csv");
        dio->write("Upload complete.\n");
        dio->write("Please upload your local test CSV file.\n");
        dio->readFile("anomalyTest.csv");
        dio->write("Upload complete.\n");
    }
};


class AlgorithmSettings : public Command {
public:
    AlgorithmSettings(DefaultIO *dio) : Command(dio, "algorithm settings") {
    }

    // todo remove comment if ok
//    virtual void execute(InnerState *innerState) {
//        bool run= false;
//        // present the option to change the threshold as long as the entered value is not valid
//        while (!run) {
//            dio->write("The current correlation threshold is ");
//            dio->write(innerState->threshold);
//            dio->write("\nType a new threshold\n");
//            // let the user to write a new threshold
//            float newThreshold;
//            dio->read(&newThreshold);
//            // if the threshold that the user entered is valid, save it and break
//            if (newThreshold <= 1 && newThreshold > 0) {
//                innerState->threshold = newThreshold;
//                run=true;
//            } else
//            // if the threshold that the user entered is not valid
//                dio->write("Please choose a value between 0 and 1.\n");
//
//        }
//
//    }

    virtual void execute(InnerState *innerState) {
        float newThreshold;
        // present the option to change the threshold as long as the entered value is not valid
        while (true) {
            this->dio->write("The current correlation threshold is ");
            this->dio->write(innerState->threshold);
            this->dio->write("\nType a new threshold\n");
            // let the user to write a new threshold
            this->dio->read(&newThreshold);
            // if the threshold that the user entered is valid, save it and break
            if (newThreshold <= 1 && newThreshold > 0) {
                innerState->threshold = newThreshold;
                break;
            }
            // if the threshold that the user entered is not valid
            this->dio->write("Please choose a value between 0 and 1.\n");

        }

    }
};


class DetectAnomalies : public Command {
public:
    DetectAnomalies(DefaultIO *dio) : Command(dio, "detect anomalies") {
    }

    virtual void execute(InnerState *innerState) {
        // the server will run the hybrid algorithm on the CSV files
        TimeSeries tsTrain("anomalyTrain.csv");
        TimeSeries tsTest("anomalyTest.csv");
        HybridAnomalyDetector ad;
        // create a new full report with time steps
        fullReport fullReport;
        fullReport.truePositive = false;
        fullReport.startAnomaly = 0;
        fullReport.endAnomaly = 0;
        fullReport.des = "";
        // update the inner state
        innerState->testSize = tsTest.getSizeOfTableRows();
        // set the threshold of the hybrid anomaly detector
        ad.setThreshold(innerState->threshold);
        // learn normal on the train file
        ad.learnNormal(tsTrain);
        // detect on the test file
        innerState->anomalyReport = ad.detect(tsTest);
        // go through the reports of the inner state
        for_each(innerState->anomalyReport.begin(), innerState->anomalyReport.end(),
                 [&fullReport, innerState](AnomalyReport &anomalyReport) {
                     // if the anomalies have the same description and at the same time step
                     if ((anomalyReport.timeStep == fullReport.endAnomaly + 1) &&
                         (anomalyReport.description == fullReport.des)) {
                         fullReport.endAnomaly++;
                         // if not, save the report
                     } else {
                         innerState->fullReports.push_back(fullReport);
                         fullReport.startAnomaly = anomalyReport.timeStep;
                         fullReport.endAnomaly = fullReport.startAnomaly;
                         fullReport.des = anomalyReport.description;
                     }
                 });
        // add the full report
        innerState->fullReports.push_back(fullReport);
        innerState->fullReports.erase(innerState->fullReports.begin());
        // at the end of the hybrid algorithm
        this->dio->write("anomaly detection complete.\n");
    }
};


class ResultsDisplay : public Command {
public:
    ResultsDisplay(DefaultIO *dio) : Command(dio, "display results") {
    }

    virtual void execute(InnerState *innerState) {
        for_each(innerState->anomalyReport.begin(), innerState->anomalyReport.end(),
                 [this](AnomalyReport &anomalyReport) {
                     dio->write(anomalyReport.timeStep);
                     dio->write("\t " + anomalyReport.description + "\n");
                 });
        dio->write("Done.\n");
    }
};


class UploadAnomAndAnalyzeRes : public Command {
public:
    UploadAnomAndAnalyzeRes(DefaultIO *dio) : Command(dio, "upload anomalies and analyze results") {
    }

    bool TruePositive(int startTime, int endTime, InnerState *innerState) {
        int fullReportsLen = innerState->fullReports.size();
        for (int i = 0; i < fullReportsLen; i++) {
            fullReport f = innerState->fullReports[i];
            if (f.endAnomaly >= startTime && endTime >= f.startAnomaly) {
                innerState->fullReports[i].truePositive = true;
                return true;
            }
        }
        return false;
    }

    virtual void execute(InnerState *innerState) {
        int fullReportsLen = innerState->fullReports.size();

        // initialize true Positive to be false, before detecting if true
        for (int i = 0; i < fullReportsLen; i++) {
            innerState->fullReports[i].truePositive = false;
        }

        dio->write("Please upload your local anomalies file.\n");
        string clientSring = "";
        float P = 0, TP = 0, N = 0, FP = 0, total = 0; //positive and negative
        while ((clientSring = dio->read()) != "done") {
            int clientSringLen = clientSring.length();
            int timeStep = 0;
            for (; clientSring[timeStep] != ','; timeStep++);
            string start = clientSring.substr(0, timeStep);
            string end = clientSring.substr(timeStep + 1, clientSringLen);
            int startTime = stoi(start);
            int endTime = stoi(end);
            if (TruePositive(startTime, endTime, innerState)) {
                TP = TP + 1;
            }
            total = total + endTime - startTime + 1;
            P++;
        }
        dio->write("Upload complete.\n");
        fullReportsLen = innerState->fullReports.size();
        for (int i = 0; i < fullReportsLen; i++) {
            if (innerState->fullReports[i].truePositive == false) {
                FP = FP + 1;
            }
        }
        N = innerState->testSize - total;
        float tpr = ((int) (1000.0 * TP / P)) / 1000.0f;
        float fpr = ((int) (1000.0 * FP / N)) / 1000.0f;
        dio->write("True Positive Rate: ");
        dio->write(tpr);
        dio->write("\nFalse Positive Rate: ");
        dio->write(fpr);
        dio->write("\n");
    }
};


class Exit : public Command {
public:
    Exit(DefaultIO *dio) : Command(dio, "exit") {
    }

    virtual void execute(InnerState *innerState) {
        //cout << des << endl;
    }
};


#endif /* COMMANDS_H_ */