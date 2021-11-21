/*
 * timeseries.h
 *
 * Authors:
 * Mor Siman Tov, ID: 208682484
 * Shai Fisher, ID: 315150342
 *
 */

#ifndef TIMESERIES_H_
#define TIMESERIES_H_

#include <string.h>
#include <map>
#include <vector>
#include <iostream>
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

class TimeSeries {

    // to map the strings to vectors
    map<string, vector<float>> timeSeriesTable;

    //
    size_t sizeOfTableRows;

    // the features (we get them from the first row of the table)
    vector<string> features;

public:

    TimeSeries(const char *CSVfileName) {

        // to read from the file
        ifstream in(CSVfileName);
        string header;
        in >> header;
        stringstream hss(header); // read the header first
        string feature;
        // the values are seperated by ',', saving the features in out table
        while (getline(hss,feature,',')){
            vector<float> value_from_table;
            timeSeriesTable[feature] = value_from_table;

            // push_back(feature) pushes elements into the vector feature (from the back)
            features.push_back(feature);
        }

        // saving the data
        while (in.eof()!= true){
            int ftr = 0;
            string value;
            string cur_row;
            in>>cur_row;
            stringstream lss(cur_row);
            while (getline(lss,value,',')){
                timeSeriesTable[features[ftr]].push_back(stof(value));
                ftr = ftr+1;
            }
        }
        in.close();

        // which is actually the size of the vector
        sizeOfTableRows = timeSeriesTable[features[0]].size();
    }

    // a function that will return a list of all the features names
    const vector<string>& getFeaturesNames() const{
        return features;
    }

    // returns the size of the rows in the table
    size_t getSizeOfTableRows() const{
        return sizeOfTableRows;
    }

    // returns a vector of all the data that is per the received feature name
    const vector<float>& getDataPerFeature(string featureName) const{
        return timeSeriesTable.at(featureName);
    }

    ~TimeSeries(){

    }
};

#endif /* TIMESERIES_H_ */