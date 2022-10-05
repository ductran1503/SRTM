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
    std::ifstream databasefile;
    char c;
    convertByteToInt convert;
 
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

    //test
    std::cout << "datafilename:" << database_name << std::endl; 
    //

    databasefile.open(database_name, std::ios::binary | std::ios::in);
    if(!databasefile){
        std::cerr << "could not open file" << std::endl;
        return;
    }
    for(int i = 0; i<3601; i++){
        for( int j = 0; j<3601; j++){
            databasefile.read(&c,1);
            convert.c[1] = c;
            databasefile.read(&c,1);
            convert.c[0] = c;
            database.push_back(convert.i);
        }
    }
    databasefile.close();
}   

void TerrainAltitude::readAltitude(){
    int col,row;
    row = int((lat - int(lat))*3600.0);
    col = int((lon - int(lon))*3600.0);
    altitude = database[(3601-row-1)*3601+col-1];
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

// find the data file that contain data for the current postition (lat, lon)
// filename format: N+SW_lat+E+SW_lon+".hgt"
int TerrainAltitude::getDataBase(){
    switch(datatype){
        case 1:     // hgt file 
            database_name = datafolder_path + "N" + std::to_string(int(lat)) + "E" + std::to_string(int(lon)) + ".hgt";
            break;
        case 2:
            database_name = datafolder_path + "n" + std::to_string(int(lat)) + "e" + std::to_string(int(lon)) + ".hgts";
            break;
    }
    return 0;
}
