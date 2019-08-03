#include "serv_string.h"

void StringUtil::Trim(std::string& str){
    if (!str.empty()){
        str.erase(0, str.find_first_not_of(" "));
        str.erase(str.find_last_not_of(" ") + 1);
    }
}