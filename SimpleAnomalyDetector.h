/*
 * SimpleAnomalyDetector.h
 *
 * Authors:
 * Mor Siman Tov, ID: 208682484
 * Shai Fisher, ID: 315150342
 *
 */

#ifndef SIMPLEANOMALYDETECTOR_H_
#define SIMPLEANOMALYDETECTOR_H_

#include "anomaly_detection_util.h"
#include "AnomalyDetector.h"
#include <vector>
#include <algorithm>
#include <string.h>
#include <math.h>

struct correlatedFeatures{
    // names of the correlated features
    string feature1,feature2;
    float corrlation;
    Line lin_reg;
    float threshold;
    float center_x;
    float center_y;
};

class SimpleAnomalyDetector:public TimeSeriesAnomalyDetector{
protected:
    vector<correlatedFeatures> cf;
    float threshold;
  //  float threshold; // added
public:
    SimpleAnomalyDetector();
    virtual ~SimpleAnomalyDetector();
    void setThreshold(float threshold) {
        this->threshold = threshold;
    }
    virtual void learnNormal(const TimeSeries& ts);
    virtual vector<AnomalyReport> detect(const TimeSeries& ts);

    vector<correlatedFeatures> getNormalModel(){
        return cf;
    }

// these are the help methods used in 'SimpleAnomalyDetector.cpp'
    virtual void findCorrelation(const TimeSeries& ts, string f1, string f2, Point **points_array, float p);
    float findMaxDev(int size, Point **points_array, Line linReg);
    virtual bool isAnomalousDetection(float place, float y, correlatedFeatures cf_detected);

};

#endif /* SIMPLEANOMALYDETECTOR_H_ */