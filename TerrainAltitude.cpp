#include "TerrainAltitude.h"

void TerrainAltitude::updateLatLon(float lat_deg, float lon_deg){
    lat = lat_deg;
    lon = lon_deg;
}

float TerrainAltitude::getLat(){
    return lat;
}

float TerrainAltitude::getLon(){
    return lon;
}

bool TerrainAltitude::isInCurrentGrid(){
    if((lat < current_grid_lat) || (lat >= current_grid_lat+1) || (lon < current_grid_lon) || (lon >= current_grid_lon))
        return false;
    else    
        return true;
}

void TerrainAltitude::updateGrid(){
    current_grid_lat = int(lat);
    current_grid_lon = int (lon);
    std::string lat_word;
    std::string lon_word;

 
    if(current_grid_lon<10){
        lon_word = "E00" + std::to_string(current_grid_lon);
    }
    else if(current_grid_lon<100){
        lon_word = "E0" + std::to_string(current_grid_lon);
    }
    else {
        lon_word = "E" + std::to_string(current_grid_lon);
        
    }

    if(current_grid_lat < 10){
        lat_word = "N0" + std::to_string(current_grid_lat);
    }
    else{
        lat_word = "N" + std::to_string(current_grid_lat);
    }  
    database_name = datafolder_path + lat_word + lon_word + ".hgt";

}   

void TerrainAltitude::readAltitude(){
    int col,row;
    std::ifstream databasefile;
    convertByteToInt convert;
    char c;
    row = int((lat - int(lat))*3600.0);
    col = int((lon - int(lon))*3600.0);

    databasefile.open(database_name, std::ios::binary | std::ios::in);
    if(!databasefile){
        std::cerr << "could not open file" << std::endl;
        return;
    }

    databasefile.seekg((3601-row -1)*3601*2+col*2,databasefile.beg);
    databasefile.read(&c,1);
    convert.c[1] = c;
    databasefile.read(&c,1);
    convert.c[0] = c;
    database.push_back(convert.i);
    databasefile.close();
    altitude = convert.i;
}



int16_t TerrainAltitude::getAltitude(float lat_deg, float lon_deg){
    updateLatLon(lat_deg,lon_deg);

    if(isInCurrentGrid()){
        readAltitude();
    }
    else{
        updateGrid();
        readAltitude();
    }
    return altitude;

}

TerrainAltitude::TerrainAltitude(std::string path){
    datafolder_path = path;
}
