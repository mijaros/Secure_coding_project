#ifndef ITEM_H
#define ITEM_H
#include <string>
#include <map>
#include "mediaTypes.h"

class item
{
private:
    static std::map<std::string,DataTypes> definitions;
    std::map<std::string,int> integers;
    std::map<std::string,std::string> strings;
    std::map<std::string,float> floats;
    std::map<std::string,floatNull> floatNulls;
public:
    item();
};

#endif // ITEM_H
