// DataHarvester.h
#ifndef DATAHARVESTER_H
#define DATAHARVESTER_H

#include <string>

class DataHarvester {
public:
    DataHarvester();
    ~DataHarvester();

    // Harvest data from input (e.g., extract URL)
    std::string harvest(const std::string& inputData);
};

#endif // DATAHARVESTER_H
