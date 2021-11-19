
#include "SimpleAnomalyDetector.h"

SimpleAnomalyDetector::SimpleAnomalyDetector() {
	// TODO Auto-generated constructor stub
}

SimpleAnomalyDetector::~SimpleAnomalyDetector() {
	// TODO Auto-generated destructor stub
}


void SimpleAnomalyDetector::learnNormal(const TimeSeries& ts){
	// TODO Auto-generated destructor stub
	// save the vector of features
	vector<string> features = ts.getFeaturesNames();
	// create an array of values that will store the values of all the features (the rows are the features)
	float values[features.size()][ts.getSizeOfTableRows()];
	// loop through all the features
    for (auto feature : features) {
        int ft = 0;
        // inside a feature loop through all the rows
        for (int i = 0; i < ts.getSizeOfTableRows(); i++) {
            // save the value in index i of the feature ft in the array
            values[ft][i] = ts.getDataPerFeature(feature)[i];
        }
        ft++;
    }
    // save the size of the features
    int size_features = features.size();
    // loop through all the features and check the correlation between the values of every two features
    for (int i = 0; i < size_features; i++) {
        float max_value = 0;
        int max_index_j = -1;
        for (int j = i + 1; j < size_features; j++) {
            if (float p = abs(pearson(values[i], values[j], ts.getSizeOfTableRows())) > max_value) {
                max_value = p;
                max_index_j = j;
            }
        }

    }
}

vector<AnomalyReport> SimpleAnomalyDetector::detect(const TimeSeries& ts){
	// TODO Auto-generated destructor stub
}

