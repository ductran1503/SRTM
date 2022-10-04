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

int16_t TerrainAltitude::getAltitude(float lat_deg, float lon_deg){
    lat = lat_deg;
    lon = lon_deg;
    switch(datatype){
        case 1:     // hgt file 
            database_name = datafolder_path + "N" + std::to_string(int(lat)) + "E" + std::to_string(int(lon)) + ".hgt";
            findAltitude_SRTMGL1();
            break;
        case 2:
            database_name = datafolder_path + "n" + std::to_string(int(lat)) + "e" + std::to_string(int(lon)) + ".hgts";
            findAltitude_NASADEM_SHHP();
            break;
        default:
            break;
    }
    return altitude;
}

TerrainAltitude::TerrainAltitude(std::string path, int data_type ){
    datafolder_path = path;
    TerrainAltitude::datatype = data_type;
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

// return -1 if the datafile does not exist
int16_t TerrainAltitude::findAltitude_SRTMGL1(){
    int col,row;
    char c;

    convertByteToInt convert;
    std::ifstream databasefile;
    row = int((lat - int(lat))*3600.0);
    col = int((lon - int(lon))*3600.0);
    // test

    //test
    databasefile.open(database_name, std::ios::binary | std::ios::in);
    
    if (!databasefile){
        std::cerr << "Could not open file";
        return -1;
    }

    // Move file pointer
    databasefile.seekg(3601*2*(3601-row-1)+(col-1)*2, std::ios::beg);
    // read 2 byte from the file and union to convert 2-byte data to int value
    // data of HGT is big endian
    databasefile.read(&c,1);
    convert.c[1] = c;
    databasefile.read(&c,1);
    convert.c[0] = c;
    databasefile.close();

    //convert 2-byte data to int
    altitude = convert.i;
    return 0;
}

float TerrainAltitude::findAltitude_NASADEM_SHHP(){
    int col,row;
    char c;

    convertByteToFloat convert;
    std::ifstream databasefile;
    row = int((lat - int(lat))*3600.0);
    col = int((lon - int(lon))*3600.0);

    databasefile.open(database_name, std::ios::binary | std::ios::in); 
    if (!databasefile){
        std::cerr << "Could not open file";
        return -1;
    }

    // Move file pointer
    databasefile.seekg(3601*4*(3601-row-1)+(col-1)*4, std::ios::beg);
    // read 2 byte from the file and union to convert 2-byte data to int value
    // data of HGT is big endian
    databasefile.read(&c,1);
    convert.c[3] = c;
    databasefile.read(&c,1);
    convert.c[2] = c;
    databasefile.read(&c,1);
    convert.c[1] = c;
    databasefile.read(&c,1);
    convert.c[0] = c;
    databasefile.close();
    //convert 4-byte data to float
    altitude = convert.f;
    return 0;
}
