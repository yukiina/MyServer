#ifndef SREV_CONF_H
#define SREV_CONF_H

#include <vector>
#include <fstream>
#include <string>
// 功能: 读配置文件 -- 单例
class ServConf{
private:
    ServConf();
    ServConf(const ServConf&) = delete;
    ServConf& operator=(const ServConf&) = delete;
public:
    ~ServConf();
public: 
    static ServConf* GetInstance(){
        if (_instance == nullptr){
            // 锁
            if (_instance == nullptr){
                _instance = new ServConf();
            }
            // 锁
        }
        return _instance;
    }

    // 垃圾回收类
    class GC{
    public:
        ~GC(){
            if (_instance){
                delete ServConf::_instance;
                ServConf::_instance = nullptr;
            }
        }
    };
    static GC gc;
public:
    bool Load(const std::string& confName);
    int GetConfInt(const std::string& key);
    std::string GetConfStr(const std::string& key);
private:
    static ServConf* _instance;
};


#endif 