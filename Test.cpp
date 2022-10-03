#include<iostream>
#include<string>
#include "TerrainAltitude.h"

int main(){
    TerrainAltitude terrain;
    terrain.setLatLon(10.0,10.0);
    std::cout << "Lat: "<<terrain.getLat() << "\n";
    std::cout << "Lon: "<<terrain.getLon() << "\n";
    //std::cout<<"heheh"<<std::endl;
}