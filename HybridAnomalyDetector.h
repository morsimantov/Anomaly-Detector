/*
 * HybridAnomalyDetector.h
 *
 * Authors:
 * Mor Siman Tov, ID: 208682484
 * Shai Fisher, ID: 315150342
 *
 */

#ifndef HYBRIDANOMALYDETECTOR_H_
#define HYBRIDANOMALYDETECTOR_H_

#include "SimpleAnomalyDetector.h"
#include "minCircle.h"


class HybridAnomalyDetector:public SimpleAnomalyDetector {
public:
    HybridAnomalyDetector();
    virtual ~HybridAnomalyDetector();
    virtual void findCorrelation(const TimeSeries& ts, string f1, string f2, Point **points_array, float p);
    virtual bool isAnomalousDetection(float place, float y, correlatedFeatures cf_detected);
};

#endif /* HYBRIDANOMALYDETECTOR_H_ */