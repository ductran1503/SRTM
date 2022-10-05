#include<iostream>
#include<fstream>
#include<string>
#include <chrono>
#include "TerrainAltitude.h"



int main(){
    int16_t altitude;

    TerrainAltitude terrain("./../Data/");

    auto start = std::chrono::steady_clock::now();
    altitude = terrain.getAltitude(20.701487049707335,105.55973052978517);
    std::cout << "Kim boi: " <<std::to_string(altitude)<< std::endl;
    auto end = std::chrono::steady_clock::now();

    altitude = terrain.getAltitude(20.84853512242709,105.77851295471193);
    std::cout << "Thanh oai: " <<std::to_string(altitude)<< std::endl;

    altitude = terrain.getAltitude(21.06398705131511,105.36841392517091);
    std::cout << "Ba vif: " <<std::to_string(altitude)<< std::endl;

    altitude = terrain.getAltitude(22.304276,103.777063);
    std::cout << "Phan xi pang: " <<std::to_string(altitude)<< std::endl;

    altitude = terrain.getAltitude(20.821308584857476,106.72563314437868);
    std::cout << "San bay cat bi: " <<std::to_string(altitude)<< std::endl;

    altitude = terrain.getAltitude(19.910072137436426,104.94535446166992);
    std::cout << "NGhe an: " <<std::to_string(altitude)<< std::endl;

    altitude = terrain.getAltitude(16.223565071057493,107.27076530456544);
    std::cout << "Hue:" <<std::to_string(altitude)<< std::endl;

    altitude = terrain.getAltitude(14.964645079717837,108.94763946533205);
    std::cout << "Biển quảng ngãi : " <<std::to_string(altitude)<< std::endl;

    altitude = terrain.getAltitude(10.80023708131617,105.58771133422853);
    std::cout << "Long an: " <<std::to_string(altitude)<< std::endl;

    altitude = terrain.getAltitude(10.813736968493853,106.65501594543457);
    std::cout << "Sai gon: " <<std::to_string(altitude)<< std::endl;

    altitude = terrain.getAltitude(21.012556891457148,105.86228370666505);
    std::cout << "Ha noi: " <<std::to_string(altitude)<< std::endl;

    altitude = terrain.getAltitude(20.961619326513347,105.74745833873749);
    std::cout << "Phenikaa: " <<std::to_string(altitude)<< std::endl;

    altitude = terrain.getAltitude(20.32523,105.64728);
    std::cout << "Ninh Binh" <<std::to_string(altitude)<< std::endl;

    altitude = terrain.getAltitude(48.85159956038229,2.3289299011230473);
    std::cout << "Paris: " <<std::to_string(altitude)<< std::endl;

    altitude = terrain.getAltitude(21.03518,105.90928);
    std::cout << "Sai Dong: " <<std::to_string(altitude)<< std::endl;

    altitude = terrain.getAltitude(20.95907,105.93352);
    std::cout << "Ecopark: " <<std::to_string(altitude)<< std::endl;

    std::chrono::duration<double> time = end -start;
    std::cout << std::to_string(altitude)<< std::endl;
    std::cout << "elapsed time: " << std::to_string(time.count())<< "(s)"<< std::endl;
    return 0;
}