#include<iostream>
#include<fstream>
#include<string>
#include "TerrainAltitude.h"

int main(){
    TerrainAltitude terrain("./../Data/",SRTMGL1);
    std::cout << std::to_string(terrain.getAltitude(48.85159956038229,2.3289299011230473))<< std::endl;
    return 0;

}