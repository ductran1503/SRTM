#include "TerrainAltitude.h"

void TerrainAltitude::setLatLon(float lat_deg, float lon_deg){
    lat = lat_deg;
    lon = lon_deg;
}

float TerrainAltitude::getLat(){
    return lat;
}

float TerrainAltitude::getLon(){
    return lon;
}



