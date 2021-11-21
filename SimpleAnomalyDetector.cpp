/*
 * SimpleAnomalyDetector.cpp
 *
 * Authors:
 * Mor Siman Tov, ID: 208682484
 * Shai Fisher, ID: 315150342
 *
 */
#include "SimpleAnomalyDetector.h"

#define THRESHOLD 0.9

SimpleAnomalyDetector::SimpleAnomalyDetector() {
//    threshold = 0.9;
//	// TODO Auto-generated constructor stub

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
        float max_value = 0;
        string first_ftr = features[i];
        int max_index_j = 0;
        for (int j = i + 1; j < size_features; j++) {
            float pearson_val = abs(pearson(values[i], values[j], ts.getSizeOfTableRows()));
            if(pearson_val>max_value){
                max_value = pearson_val;
                max_index_j=j;
            }

        }
        string second_ftr = features[max_index_j];

        // create an array of points that will store the values of f1, f2
        int size = ts.getDataPerFeature(first_ftr).size();
        Point* points_array[size];
        for (int i = 0; i < size; i++) {
            points_array[i] = new Point(ts.getDataPerFeature(first_ftr)[i], ts.getDataPerFeature(second_ftr)[i]);
        }
        // find correlation between features f1, f2
        findCorrelation(ts, first_ftr, second_ftr, points_array, max_value);

        // destructor for the points_array
        for(int i = 0; i < ts.getSizeOfTableRows(); i++)
            delete points_array[i];
    }
}

void SimpleAnomalyDetector::findCorrelation(const TimeSeries& ts, string first_ftr, string second_ftr, Point **points_array, float p) {

    // if correlation is higher than the threshold
    if (p > THRESHOLD) {
        correlatedFeatures correlated_ft;
        correlated_ft.feature1 = first_ftr;
        correlated_ft.feature2 = second_ftr;
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
    vector<AnomalyReport> deviations_vector;
    for_each(cf.begin(), cf.end(),[&deviations_vector,&ts, this](correlatedFeatures cf_detected){
        string first_ftr = cf_detected.feature1;
        string second_ftr = cf_detected.feature2;

        // creating vectors of the 2d points
        vector<float> x = ts.getDataPerFeature(first_ftr);
        vector<float> y = ts.getDataPerFeature(second_ftr);

        // in order to know how many 2d points are there
        int num_of_points = x.size();

        // going through all the points
        for( int i=0; i<num_of_points; i++){

            // from 'Line' class: float f(float x){return a*x+b;}
            float place = cf_detected.lin_reg.f(x[i]);
            if(abs(y[i]-place>cf_detected.threshold)){
                string des = first_ftr + "-" + second_ftr;
                deviations_vector.push_back(AnomalyReport(des,(i+1)));
            }
        }
    });
    return deviations_vector;
}


