
#include "SimpleAnomalyDetector.h"

#define THRESHOLD 0.9

SimpleAnomalyDetector::SimpleAnomalyDetector() {
	// TODO Auto-generated constructor stub

}

SimpleAnomalyDetector::~SimpleAnomalyDetector() {
	// TODO Auto-generated destructor stub
}


void SimpleAnomalyDetector::learnNormal(const TimeSeries& ts) {
	// TODO Auto-generated destructor stub

	// save the vector of features
	vector<string> features = ts.getFeaturesNames();

	// create an array of values that will store the values of all the features (the rows are the features)
	float values[features.size()][ts.getSizeOfTableRows()];

	// loop through all the features
    int ft = 0;
    for (auto feature : features) {

        // inside a feature loop through all the rows
        for (int i = 0; i < ts.getSizeOfTableRows(); i++) {

            // save the value in index i of the feature ft in the array
            values[ft][i] = ts.getDataPerFeature(feature)[i];
        }
        ft++;
    }

    // save the size of the features
    int size_features = features.size();

    // loop through all the features and check the correlation between the values of every two features using Pearson
    for (int i = 0; i < size_features; i++) {
        string f1 = features[i];
        float max_value = 0;
        int max_index_j = -1;
        for (int j = i + 1; j < size_features; j++) {
            if (float p = abs(pearson(values[i], values[j], ts.getSizeOfTableRows())) > max_value) {
                max_value = p;
                max_index_j = j;
            }
        }
        string f2 = features[max_index_j];

        // create an array of points that will store the values of f1, f2
        int size = ts.getDataPerFeature(f1).size();
        Point* points_array[size];
        for (int i = 0; i < size; i++) {
            points_array[i] = new Point(ts.getDataPerFeature(f1)[i], ts.getDataPerFeature(f2)[i]);
        }

        // find correlation between features f1, f2
        findCorrelation(ts, f1, f2, points_array, max_value);

        // destructor for the points_array
        for(int i = 0; i < ts.getSizeOfTableRows(); i++)
            delete points_array[i];
    }
}

void SimpleAnomalyDetector::findCorrelation(const TimeSeries& ts, string f1, string f2, Point **points_array, float p) {

    // if correlation is higher than the threshold
    if (p > THRESHOLD) {
        correlatedFeatures correlated_ft;
        correlated_ft.feature1 = f1;
        correlated_ft.feature2 = f2;
        correlated_ft.corrlation = p;
        correlated_ft.lin_reg = linear_reg(points_array, ts.getSizeOfTableRows());

        // the threshold will be the maximum deviation * 1.1
        correlated_ft.threshold = findMaxDev(ts.getSizeOfTableRows(), points_array, correlated_ft.lin_reg) * 1.1;
        cf.push_back(correlated_ft);
    }
}

float SimpleAnomalyDetector::findMaxDev(int size, Point **points_array, Line lin_reg) {
    float max_dev = 0;
    float d;

    // loop through array of points
    for (int i = 0; i < size; i++) {

        // find the deviation between each point and lin_reg
        d = dev(*points_array[i], lin_reg);
        if (d > max_dev)
            max_dev = d;
    }

    // return the maximal deviation
    return max_dev;
}


vector<AnomalyReport> SimpleAnomalyDetector::detect(const TimeSeries& ts){
	// TODO Auto-generated destructor stub
}

