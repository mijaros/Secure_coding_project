#include "album.h"
#include "mediaTypes.h"

std::map<std::string, DataTypes> album::definitions = {
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
    {"comp",Bool},
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
    {"rg_album_gain",FloatNull},
    {"rg_album_peak",FloatNull},
    {"original_year",Integer},
    {"original_month",Integer},
    {"original_day",Integer}
};

album::album()
{
}
