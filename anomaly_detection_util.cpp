/*
 * anomaly_detection_util.cpp
 *
 * Authors:
 * Mor Siman Tov, ID: 208682484
 * Shai Fisher, ID: 315150342
 *
 */

#include <math.h>
#include "anomaly_detection_util.h"

// returns the average
float avg(float *x, int size) {
    float sum = 0;
    for (int i = 0; i < size; i++) {
        sum += x[i];
    }
    return sum / float(size);
}

// returns the variance of X and Y
float var(float *x, int size) {
    float sum = 0, average;
    average = avg(x, size); // the u in the equation
    for (int i = 0; i < size; i++) {
        sum += (x[i] * x[i]);
    }
    sum = sum / float(size); // the average of x^2
    return sum - (average * average);
}

// returns the covariance of X and Y, the equation: (COV(x,y) = E(XY)-(E(X)*E(y))
float cov(float *x, float *y, int size) {
    float sum = 0;
    float avgOfX = avg(x, size);
    float avgOfY = avg(y, size);
    for (int i = 0; i < size; i++) {
        sum += x[i] * y[i];
    }
    sum = sum / (float) size;
    return sum - (avgOfX * avgOfY);
}


// returns the Pearson correlation coefficient of X and Y, the equation: cov(x,y)/sqrt(var(x))*sqrt(var(y))
float pearson(float *x, float *y, int size) {
    double standardDeviationX = sqrt(var(x, size));
    double standardDeviationY = sqrt(var(y, size));
    return cov(x, y, size) / (standardDeviationX * standardDeviationY);
}

// performs a linear regression and returns the line equation
Line linear_reg(Point **points, int size) {
    float XValues[size], YValues[size]; // two arrays that will store x and y values
    float a, b;
    for (int i = 0; i < size; i++) {
        XValues[i] = points[i]->x;
        YValues[i] = points[i]->y;
    }
    a = cov(XValues, YValues, size) / var(XValues, size);
    b = avg(YValues, size) - (a * (avg(XValues, size)));
    return Line(a, b);
}

// returns the deviation between point p and the line equation of the points
float dev(Point p, Point **points, int size) {
    Line lineEquation = linear_reg(points,size); // creating the line equation of the points received from function
    return dev(p,lineEquation);
}

// returns the deviation between point p and the line (between the red point y value and the f(x))
float dev(Point p, Line l) {
    float pointYValue = p.y;
    float lineYValue = l.f(p.x); // the value of the line at p.x
    float distance = pointYValue-lineYValue;
    if(distance<0){
        distance=distance*-1; // in order to get the absolute value
    }
    return distance;
}