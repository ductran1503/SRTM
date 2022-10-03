#ifndef TERRAINALTITUDE_H
#define TERRAINALTITUDE_H
#include <iostream>
#include <string>
class TerrainAltitude{
    private:

    float lat;
    float lon;
    float altitude;
    std::string database_name;
    int findAltitude();
    int findGrid();
    int findDatabaseName();

    public:
    
    void setLatLon(float lat_deg, float lon_deg);
    float getLat();
    float getLon();
    float getAltitude();
    
    

};

#endif