#include <iostream>

using std::cout;
using std::endl;

#include "serv_conf.h"

int main(){
    // 获取配置类的实例
    ServConf* conf = ServConf::GetInstance();
    if (conf->Load("./serv.conf") == false){
        cout << "配置文件无法加载, 检查配置文件!!程序退出" << endl;
        return 1;
    }
    
    for(const auto e : conf->_confItem){
        cout << "key: " << e.first << " " << e.first.size() << endl;
        cout << "key: " << e.second << " " << e.second.size() << endl;
    }

    return 0;
}

