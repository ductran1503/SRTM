#include<iostream>
#include<fstream>
#include<string>
#include "TerrainAltitude.h"


int main(){
    TerrainAltitude terrain("./../Data/");
    std::cout << std::to_string(terrain.getAltitude(20.961619326513347,105.74745833873749))<< std::endl;
    return 0;

}