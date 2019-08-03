#include <iostream>

using std::cout;
using std::endl;

#include "serv_conf.h"

int main(){
    // 获取配置类的实例
    ServConf* conf = ServConf::GetInstance();
    if (conf->Load("./serv.conf") == false){
        cout << "Load error!!" << endl;
        return 1;
    }
    
    return 0;
}

