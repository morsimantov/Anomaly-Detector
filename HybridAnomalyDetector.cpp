/*
 * HybridAnomalyDetector.cpp
 *
 * Authors:
 * Mor Siman Tov, ID: 208682484
 * Shai Fisher, ID: 315150342
 *
 */

#include "HybridAnomalyDetector.h"


HybridAnomalyDetector::HybridAnomalyDetector() {
    // TODO Auto-generated constructor stub
}

HybridAnomalyDetector::~HybridAnomalyDetector() {
    // TODO Auto-generated destructor stub
}

void HybridAnomalyDetector::findCorrelation(const TimeSeries& ts, string first_ftr, string second_ftr,
                                            Point **points_array, float p) {
    // if correlation is lower than the threshold but higher than 0.5
    if (p < threshold && p > 0.5) {
        correlatedFeatures correlated_ft;
        correlated_ft.feature1 = first_ftr;
        correlated_ft.feature2 = second_ftr;
        correlated_ft.corrlation = p;
        correlated_ft.lin_reg = linear_reg(points_array, ts.getSizeOfTableRows());
        Circle min_circle = findMinCircle(points_array,  ts.getSizeOfTableRows());
        // the threshold will be the minimal radius * 1.1
        correlated_ft.threshold = min_circle.radius * 1.1;
        cf.push_back(correlated_ft);
    }
    // when correlation is higher than the threshold
    else if (p >= threshold) {
        SimpleAnomalyDetector::findCorrelation(ts, first_ftr, second_ftr, points_array, p);
    }
}

bool HybridAnomalyDetector::isAnomalousDetection(float place, float y, correlatedFeatures cf_detected) {
    float corrlation = cf_detected.corrlation;
    float distance = sqrt((pow((cf_detected.center_x - place), 2) + pow((cf_detected.center_y - y), 2)));
    return (corrlation >= this->threshold && SimpleAnomalyDetector::isAnomalousDetection(place, y, cf_detected))
           || (corrlation < this->threshold && corrlation > 0.5 && distance > cf_detected.threshold);
}