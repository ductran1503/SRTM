#ifndef TERRAINALTITUDE_H
#define TERRAINALTITUDE_H
#define SRTMGL1 1
#include <iostream>
#include <string>
#include<fstream>
#include <vector>

typedef union {
    unsigned char c[2];
    int16_t i;
} convertByteToInt;

typedef union {
    unsigned char c[4];
    int16_t f;
} convertByteToFloat;

class TerrainAltitude{
    private:

    int datatype =1;
    float lat;
    float lon;
    int current_grid_lat = 200;
    int current_grid_lon = 200;
    std::vector <int16_t> database;
    int16_t altitude;
    std::string datafolder_path;
    std::string database_name;
    void updateLatLon(float lat_deg, float lon_deg);
    bool isInCurrentGrid();
    bool _isInCurrentSubGrid();
    void updateGrid();
 
    void readAltitude();
    // read whole data from data file to an array of float variables
    // return -1 if could not open file, 1 if could open file
    int getDataBase();

    public:
    TerrainAltitude(std::string path);
    float getLat();
    float getLon();
    int16_t getAltitude(float lat_deg, float lon_deg);
    
    

};

#endif