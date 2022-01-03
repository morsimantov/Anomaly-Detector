cmake_minimum_required(VERSION 3.17)
project(anomaly_detection_util)

set(CMAKE_CXX_STANDARD 14)

add_executable(anomalyDetector anomaly_detection_util.h anomaly_detection_util.cpp AnomalyDetector.h SimpleAnomalyDetector.cpp
        SimpleAnomalyDetector.h timeseries.cpp timeseries.h MainTrain.cpp minCircle.h minCircle.cpp HybridAnomalyDetector.cpp HybridAnomalyDetector.h CLI.h CLI.cpp commands.h)