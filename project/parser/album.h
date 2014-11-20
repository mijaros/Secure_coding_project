#ifndef ALBUM_H
#define ALBUM_H
#include <string>
#include "mediaTypes.h"
#include <map>
/*
 * List of keys that are set on an album's items.
'added',
'albumartist',
'albumartist_sort',
'albumartist_credit',
'album',
'genre',
'year',
'month',
'day',
'tracktotal',
'disctotal',
'comp',
'mb_albumid',
'mb_albumartistid',
'albumtype',
'label',
'mb_releasegroupid',
'asin',
'catalognum',
'script',
'language',
'country',
'albumstatus',
'albumdisambig',
'rg_album_gain',
'rg_album_peak',
'original_year',
'original_month',
'original_day',
*/


class album
{
private:
    static std::map<std::string,DataTypes> definitions;
    std::map<std::string,int> integers;
    std::map<std::string,std::string> strings;
    std::map<std::string,float> floats;
    std::map<std::string,floatNull> floatNulls;
public:
    album();
};

#endif // ALBUM_H
