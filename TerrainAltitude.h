#ifndef TERRAINALTITUDE_H
#define TERRAINALTITUDE_H
#include <iostream>
#include <string>
#include<fstream>
#define SRTMGL1 1
#define NASADEM_SHHP 2


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
    int16_t altitude;
    std::string datafolder_path;
    std::string database_name;
    int16_t findAltitude_SRTMGL1();
    float findAltitude_NASADEM_SHHP();
    // read whole data from data file to an array of float variables
    // return -1 if could not open file, 1 if could open file
    int getDataBase();

    public:
    TerrainAltitude(std::string path, int data_type );
    void setLatLon(float lat_deg, float lon_deg);
    float getLat();
    float getLon();
    int16_t getAltitude(float lat_deg, float lon_deg);
    
    

};

#endif