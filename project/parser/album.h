#ifndef ALBUM_H
#define ALBUM_H
#include <string>
#include "mediaTypes.h"
#include <map>


class album
{
private:
    std::map<std::string,int> integers;
    std::map<std::string,std::string> strings;
    std::map<std::string,float> floats;
public:
    static std::map<std::string,MediaDataTypes> definitions;
    album();
    void addint(std::string s,int i);
    void addstr(std::string s,std::string str);
    void addfloat(std::string s,float f);
};

#endif // ALBUM_H
