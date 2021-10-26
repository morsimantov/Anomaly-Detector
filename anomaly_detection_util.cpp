#include <cmath>

// (Shai) test to see in which branch
float avg(float* x, int size) {
    float sum = 0;
    for (int i = 0; i < size; i++) {
        sum += x[i];
    }
    return sum * (1 / float(size));
}

float var(float* x, int size) {
    float sum = 0, average;
    for (int i = 0; i < size; i++) {
        sum += (x[i] * x[i]);
    }
    sum *= (1 / float(size));
    average = avg(x, size);
    return sum - (average * average);
}

float cov(float* x, float* y, int size) {
    float sum = 0;
    for (int i = 0; i <= size; i++) {
        sum += ((x[i] - avg(x, size)) * (y[i] - avg(y, size)));
    }
    return sum * (1 / float(size));
}

float pearson(float* x, float* y, int size) {
    return cov(x, y, size) / (sqrt(var(x, size)) * sqrt(var(y, size)));
}

int main() {
    return 0;
}