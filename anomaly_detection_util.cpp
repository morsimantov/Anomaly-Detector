#include <cmath>

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
    double standardDeviationY = sqrt(var(x, size));
    return cov(x, y, size) / (standardDeviationX *standardDeviationY);
}


int main() {
    return 0;
}