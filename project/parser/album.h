#ifndef ALBUM_H
#define ALBUM_H
#include <string>
#include "mediaTypes.h"
#include <map>


class album
{
private:
    static std::map<std::string,MediaDataTypes> definitions;
    std::map<std::string,int> integers;
    std::map<std::string,std::string> strings;
    std::map<std::string,float> floats;
    std::map<std::string,floatNull> floatNulls;
public:
    album();
};

#endif // ALBUM_H
