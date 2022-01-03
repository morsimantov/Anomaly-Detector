#include "minCircle.h"

/**
 * We will use welzel's algorithm.
 * The input to the algorithm is a set P of points.
 * The algorithm selects one point p randomly and uniformly from P, and recursively finds the minimal circle
 * containing P – {p}, (all of the other points in P except p).
 * If the returned circle also encloses p, it is the minimal circle for the whole of P and we will return the circle.
 * Otherwise, point p must lie on the boundary of the result circle.
 * then we will recurse, with set of R of points known to be on the boundary as an additional parameter.
 * The recursion stops when P is empty, and the solution is found from the points in R: for 0 or 1 points
 * the solution is trivial, for 2 points the minimal circle has its center at the midpoint between the two points,
 * and for 3 points the circle is the circumcircle of the triangle described by the points.
 *
 */


/**
 * function gets two points and returns the middle point of the line the points represent
 * @param a one point
 * @param b another point
 * @return the middle point of the line represented points a,b
 */
Point midLinePoint(Point a, Point b) {
    float xValue = (a.x + b.x) / 2;
    float yValue = (a.y + b.y) / 2;
    return Point(xValue, yValue);
}


/**
 * function returns the minimum circle from 0 points
 * @return
 */
Circle minCircleFrom0Points() {
    return Circle(Point(0, 0), 0);
}

/**
 * function returns the minimum circle from 1 point
 * @param a one point
 * @return the min circle received from point a
 */
Circle minCircleFrom1Points(Point a) {
    return Circle(a, 0);
}

/**
 * function returns the minimum circle from 2 points
 * @param a one point
 * @param b another point
 * @return the min circle received from points a,b
 */
Circle minCircleFrom2Points(Point a, Point b) {
    float radius = sqrt((pow((a.x - b.x), 2) + pow((a.y - b.y), 2))) / 2;
    return Circle(midLinePoint(a, b), radius);
}


/**
 * function returns the minimum circle from 3 points.
 * for 3 points the circle is the the circumcircle (The circumcircle of the triangle is the circle that passes
 * through all of the three vertices of the triangle) of the triangle described by the points.
 *
 * @param a
 * @param b
 * @param c
 * @return the min circle received from points a,b,c
 */
Circle minCircleFrom3Points(Point a, Point b, Point c) {

    /**
     * we will start by defining the lines AB and BC which describe the triangle from points a,b,c
     * we will calculate the slope of the lines and their vertical slopes
     */
    float ABslope = (b.y - a.y) / (b.x - a.x); // the slope of the line AB
    float verticalABslope = -1 / ABslope; // the vertical slope of the line AB

    float BCslope = (c.y - b.y) / (c.x - b.x); // the slope of the line AB
    float verticalBCslope = -1 / BCslope; // the vertical slope of the line AB

    // the middle point of both lines AB, BC
    Point middleOfAB = midLinePoint(a, b);
    Point middleOfBC = midLinePoint(b, c);

    float xValueOfCircle =
            (-verticalBCslope * middleOfBC.x + middleOfBC.y - (-verticalABslope * middleOfAB.x + middleOfAB.y)) /
            (verticalABslope - verticalBCslope);
    float yValueOfCircle = verticalABslope * (xValueOfCircle - middleOfAB.x) + middleOfAB.y;
    Point circleCenter(xValueOfCircle, yValueOfCircle);
    float radius = sqrt((pow((circleCenter.x - a.x), 2) + pow((circleCenter.y - a.y), 2)));
    return Circle(circleCenter, radius);
}

/**
 * This is the trivial case in the algorithm (specified above)
 * @param P the points
 * @return the minimum circle
 */
Circle findMinCircleTrivial(vector<Point> &P) {

    if (P.size() == 0) // if there is 0 points
        return minCircleFrom0Points();
    else if (P.size() == 1) // if there is 1 point
        return minCircleFrom1Points(P[0]);
    else if (P.size() == 2) // if there is 2 points
        return minCircleFrom2Points(P[0], P[1]);

    /**
     * there might be a chance that the remaining points in P must lie within the circle described by R
     * and then the recursion will finish when the sixe of R is 3. we will handle this case:
     */
    Circle circleFrom2Points = minCircleFrom2Points(P[0], P[1]);
    Point thirdPoint = P[2];
    if ((sqrt((pow((thirdPoint.x - circleFrom2Points.center.x), 2) +
               pow((thirdPoint.y - circleFrom2Points.center.y), 2)))) <= circleFrom2Points.radius)
        return circleFrom2Points;

    circleFrom2Points = minCircleFrom2Points(P[1], P[2]);
    thirdPoint = P[0];
    if ((sqrt((pow((thirdPoint.x - circleFrom2Points.center.x), 2) +
               pow((thirdPoint.y - circleFrom2Points.center.y), 2)))) <= circleFrom2Points.radius)
        return circleFrom2Points;

    circleFrom2Points = minCircleFrom2Points(P[0], P[2]);
    thirdPoint = P[1];
    if ((sqrt((pow((thirdPoint.x - circleFrom2Points.center.x), 2) +
               pow((thirdPoint.y - circleFrom2Points.center.y), 2)))) <= circleFrom2Points.radius)
        return circleFrom2Points;

    // if the case is not the case above than return the circle from three points
    return minCircleFrom3Points(P[0], P[1], P[2]);
}

/**
 * the algorithm:
    algorithm welzl is[8]
    input: Finite sets P and R of points in the plane |R| ≤ 3.
    output: Minimal disk enclosing P with R on the boundary.

    if P is empty or |R| = 3 then
        return trivial(R)
    choose p in P (randomly and uniformly)
    D := welzl(P − {p}, R)
    if p is in D then
        return D

    return welzl(P − {p}, R ∪ {p})

 * end of algorithm

 * @param P (sets)
 * @param R (points in bounder)
 * @param size
 * @return the min circle
 */
Circle welzelAlgorithmRun(Point **P, vector<Point> R, size_t size) {
    if (size == 0 || R.size() == 3)
        return findMinCircleTrivial(R);
    int randomPointIndex = rand() % size;

    // create the random point (the p that will be removed from the calculation of the circle)
    float xValue = P[randomPointIndex]->x;
    float yValue = P[randomPointIndex]->y;
    Point p(xValue, yValue);

    // we want to remove the point p from the points, we will use swap
    swap(P[randomPointIndex], P[size - 1]);

    // the recursive call
    Circle minCircle = welzelAlgorithmRun(P, R, size - 1);

    if ((sqrt((pow((p.x - minCircle.center.x), 2) + pow((p.y - minCircle.center.y), 2)))) <= minCircle.radius)
        return minCircle;
    R.push_back(p);
    return welzelAlgorithmRun(P, R, size - 1);
}

/**
 * find min circle given points using welzl algorithm
 * @param points
 * @param size
 * @return return the min circle
 */
Circle findMinCircle(Point **points, size_t size) {
    return welzelAlgorithmRun(points, {}, size);
}