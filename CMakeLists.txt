#cmake_minimum_required(VERSION 3.17)
#project(anomaly_detection_util)
#
#set(CMAKE_CXX_STANDARD 14)
#
#add_executable(anomaly_detection_util anomaly_detection_util.cpp SimpleAnomalyDetector.cpp SimpleAnomalyDetector.h timeseries.cpp timeseries.h AnomalyDetector.h MainTrain.cpp)


cmake_minimum_required(VERSION 3.17)
project(anomaly_detection_util)

set(CMAKE_CXX_STANDARD 14)

add_executable(anomaly_detection_util.h Anomaly_detection_util.cpp SimpleAnomalyDetector.cpp SimpleAnomalyDetector.h timeseries.cpp timeseries.h AnomalyDetector.h MainTrain.cpp)