#ifndef ITEM_H
#define ITEM_H
#include <string>
#include <map>
#include "mediaTypes.h"

class item
{
private:

    std::map<std::string,int> integers;
    std::map<std::string,std::string> strings;
    std::map<std::string,float> floats;
public:
    item();
    static std::map<std::string,MediaDataTypes> definitions;
    void addint(std::string s,int i);
    void addstr(std::string s,std::string str);
    void addfloat(std::string s,float f);
};

#endif // ITEM_H
