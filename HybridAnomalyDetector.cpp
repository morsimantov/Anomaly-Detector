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
//    threshold = 0.9;
    // TODO Auto-generated constructor stub

}

void HybridAnomalyDetector::findCorrelation(const TimeSeries& ts, string first_ftr, string second_ftr,
                                            Point **points_array, float p) {
    // if correlation is lower than the threshold but higher than 0.5
    if (p < threshold && p > 0.5) {
        correlatedFeatures correlated_ft;
        correlated_ft.feature1 = first_ftr;
        correlated_ft.feature2 = second_ftr;
        correlated_ft.correlation = p;
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
    float correlation = cf_detected.correlation;
    // todo first we need to implement minCircle
//    return (correlation >= this->threshold && SimpleAnomalyDetector::isAnomalousDetection(place, y, cf_detected))
//    || (correlation < this->threshold && correlation > 0.5 && findDistance() > this->threshold);
}