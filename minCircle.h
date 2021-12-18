
#ifndef MINCIRCLE_H_
#define MINCIRCLE_H_

#include <iostream>
#include <vector>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "anomaly_detection_util.h"
#include <math.h>

using namespace std;


// ------------ DO NOT CHANGE -----------

class Circle {
public:
    Point center;
    float radius;

    Circle(Point c, float r) : center(c), radius(r) {}
};
// --------------------------------------

Circle findMinCircle(Point **points, size_t size);

// you can add here additional methods

Point midLinePoint(Point a, Point b);

Circle minCircleFrom0Points();

Circle minCircleFrom1Points(Point a);

Circle minCircleFrom2Points(Point a, Point b);

Circle minCircleFrom3Points(Point a, Point b, Point c);

Circle findMinCircleTrivial(vector<Point> &P);

Circle welzelAlgorithmRun(Point **P, vector<Point> R, size_t size);


#endif /* MINCIRCLE_H_ */
