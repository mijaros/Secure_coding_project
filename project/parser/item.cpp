#include "item.h"
#include <map>
#include "mediaTypes.h"

std::map<std::string, MediaDataTypes> item::definitions = {
    {"id",Integer},
    {"path",String},
    {"album_id",Integer},
    {"title",String},
    {"artist",String},
    {"artist_sort",String},
    {"artist_credit",String},
    {"album",String},
    {"albumartist",String},
    {"albumartist_sort",String},
    {"albumartist_credit",String},
    {"genre",String},
    {"composer",String},
    {"grouping",String},
    {"year",Integer},
    {"month",Integer},
    {"day",Integer},
    {"track",Integer},
    {"tracktotal",Integer},
    {"disc",Integer},
    {"disctotal",Integer},
    {"lyrics",String},
    {"comments",String},
    {"bpm",Integer},
    {"comp",String},
    {"mb_trackid",String},
    {"mb_albumid",String},
    {"mb_artistid",String},
    {"mb_albumartistid",String},
    {"albumtype",String},
    {"label",String},
    {"acoustid_fingerprInteger",String},
    {"acoustid_id",String},
    {"mb_releasegroupid",String},
    {"asin",String},
    {"catalognum",String},
    {"script",String},
    {"language",String},
    {"country",String},
    {"albumstatus",String},
    {"media",String},
    {"albumdisambig",String},
    {"disctitle",String},
    {"encoder",String},
    {"rg_track_gain",Float},
    {"rg_track_peak",Float},
    {"rg_album_gain",Float},
    {"rg_album_peak",Float},
    {"original_year",Integer},
    {"original_month",Integer},
    {"original_day",Integer},
    {"initial_key",String},
    {"length",Float},
    {"bitrate",String},
    {"format",String},
    {"samplerate",String},
    {"bitdepth",Integer},
    {"channels",Integer},
    {"mtime",Float},
    {"added",Float}
};

item::item()
{
}

void item::addint(std::string s, int i)
{
   this->integers.insert(std::pair<std::string,int> (s,i));
}

void item::addstr(std::string s,std::string str)
{
   this->strings.insert(std::pair<std::string,std::string> (s,str));
}
void item::addfloat(std::string s,float f)
{
   this->floats.insert(std::pair<std::string,float> (s,f));
}
