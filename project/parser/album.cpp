#include "album.h"
#include "mediaTypes.h"

std::map<std::string, MediaDataTypes> album::definitions = {
    {"id",Integer},
    {"artpath",String},
    {"added",Float},
    {"albumartist",String},
    {"albumartist_sort",String},
    {"albumartist_credit",String},
    {"album_n",String},
    {"genre",String},
    {"year",Integer},
    {"month",Integer},
    {"day",Integer},
    {"tracktotal",Integer},
    {"disctotal",Integer},
    {"comp",String},
    {"mb_albumid",String},
    {"mb_albumartistid",String},
    {"albumtype",String},
    {"label",String},
    {"mb_releasegroupid",String},
    {"asin",String},
    {"catalognum",String},
    {"script",String},
    {"language",String},
    {"country",String},
    {"albumstatus",String},
    {"albumdisambig",String},
    {"rg_album_gain",Float},
    {"rg_album_peak",Float},
    {"original_year",Integer},
    {"original_month",Integer},
    {"original_day",Integer}
};

album::album()
{
}

void album::addint(std::string s, int i)
{
   this->integers.insert(std::pair<std::string,int> (s,i));
}

void album::addstr(std::string s,std::string str)
{
   this->strings.insert(std::pair<std::string,std::string> (s,str));
}
void album::addfloat(std::string s,float f)
{
   this->floats.insert(std::pair<std::string,float> (s,f));
}
