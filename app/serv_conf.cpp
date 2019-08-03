#include "serv_conf.h"

#include <iostream>

ServConf::GC gc;
ServConf* ServConf::_instance = nullptr;

ServConf::ServConf(){}
ServConf::~ServConf(){}

bool ServConf::Load(const std::string& confName){
    std::ifstream ifs(confName);
    if (ifs && !ifs.is_open()){
        return false;
    }

    std::string line;
    while(std::getline(ifs, line)){
        std::cout << line << std::endl;
    }


    ifs.close();
    return true;
}