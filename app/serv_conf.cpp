#include "serv_conf.h"
#include "serv_string.h"

#include <iostream>

ServConf::GC gc;
ServConf* ServConf::_instance = nullptr;

ServConf::ServConf(){}
ServConf::~ServConf(){}

// 加载配置文件的配置项到内存 
// 成功返回 true 表示加载配置成功 ; 失败返回 false 程序应该停止运行
// confName : 配置文件名, 在根目录下 serv.conf
bool ServConf::Load(const std::string& confName){
    // 打开文件写流
    std::ifstream ifs(confName);
    if (ifs && !ifs.is_open()){
        // 打开失败, 写入错误日志, 程序应该停止
        return false;
    }

    // 每次读取一行
    std::string line;
    while(std::getline(ifs, line)){
        //空行
        if (line[0] == 0){
            continue;
        }
        // 注释行或其他类型空行
        if (line[0] == '#' || line[0] == ' ' || line[0] == '\n' || line[0] == '\t' || line[0] == '\r' || line[0] == '['){
            continue;
        }

        //正常的配置项, 去左右空格
        StringUtil::Trim(line);

        // 查找配置项中的 = , =前面的作为key, 等号后面的作为value, 插入map, 在内存中保存
        size_t pos = line.find("=");
        if (pos != std::string::npos){
            std::string key, value;
            key = line.substr(0, pos);
            value = line.substr(pos + 1);
            StringUtil::Trim(key);
            StringUtil::Trim(value);
            if (InsertConfItem(key, value) == false){
                // 记录日志, 配置文件中可能有重复配置项
                std::cout << "Warning: " << "配置文件中可能存在相同的配置项" << key << std::endl;
            }
        }
        else{
            // 写日志, 错误配置, 一行中没有 = , 配置文件的配置项格式不符合要求
            std::cout << "Error: " << "ServConf::Load" << line << std::endl;
        }  
    }
    
    ifs.close();
    return true; // 关闭写流, 配置文件加载成功
}

// 将 key-value的配置项插入到 map中, 方便使用
// 返回 true插入成功; 返回 false 插入失败, 应该记录错误, 可能有重复的配置项, 程序继续运行
bool ServConf::InsertConfItem(const std::string& key, const std::string& value){
    auto isInsert = _confItem.insert(std::make_pair(key, value));
    return isInsert.second;   
}