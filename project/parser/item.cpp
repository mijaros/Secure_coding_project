#include "item.h"
#include <map>
#include "mediaTypes.h"

item::item()
{

    definitions.insert( std::pair<std::string,DataTypes>("id",Integer) );
    definitions.insert( std::pair<std::string,DataTypes>("path",String) );
    definitions.insert( std::pair<std::string,DataTypes>("album_id",Integer) );
    definitions.insert( std::pair<std::string,DataTypes>("title",String) );
    definitions.insert( std::pair<std::string,DataTypes>("artist",String) );
    definitions.insert( std::pair<std::string,DataTypes>("artist_sort",String) );
    definitions.insert( std::pair<std::string,DataTypes>("artist_credit",String) );
    definitions.insert( std::pair<std::string,DataTypes>("album",String) );
    definitions.insert( std::pair<std::string,DataTypes>("albumartist",String) );
    definitions.insert( std::pair<std::string,DataTypes>("albumartist_sort",String) );
    definitions.insert( std::pair<std::string,DataTypes>("albumartist_credit",String) );
    definitions.insert( std::pair<std::string,DataTypes>("genre",String) );
    definitions.insert( std::pair<std::string,DataTypes>("composer",String) );
    definitions.insert( std::pair<std::string,DataTypes>("grouping",String) );
    definitions.insert( std::pair<std::string,DataTypes>("year",Integer) );
    definitions.insert( std::pair<std::string,DataTypes>("month",Integer) );
    definitions.insert( std::pair<std::string,DataTypes>("day",Integer) );
    definitions.insert( std::pair<std::string,DataTypes>("track",Integer) );
    definitions.insert( std::pair<std::string,DataTypes>("tracktotal",Integer) );
    definitions.insert( std::pair<std::string,DataTypes>("disc",Integer) );
    definitions.insert( std::pair<std::string,DataTypes>("disctotal",Integer) );
    definitions.insert( std::pair<std::string,DataTypes>("lyrics",String) );
    definitions.insert( std::pair<std::string,DataTypes>("comments",String) );
    definitions.insert( std::pair<std::string,DataTypes>("bpm",Integer) );
    definitions.insert( std::pair<std::string,DataTypes>("comp",Bool) );
    definitions.insert( std::pair<std::string,DataTypes>("mb_trackid",String) );
    definitions.insert( std::pair<std::string,DataTypes>("mb_albumid",String) );
    definitions.insert( std::pair<std::string,DataTypes>("mb_artistid",String) );
    definitions.insert( std::pair<std::string,DataTypes>("mb_albumartistid",String) );
    definitions.insert( std::pair<std::string,DataTypes>("albumtype",String) );
    definitions.insert( std::pair<std::string,DataTypes>("label",String) );
    definitions.insert( std::pair<std::string,DataTypes>("acoustid_fingerprInteger",String) );
    definitions.insert( std::pair<std::string,DataTypes>("acoustid_id",String) );
    definitions.insert( std::pair<std::string,DataTypes>("mb_releasegroupid",String) );
    definitions.insert( std::pair<std::string,DataTypes>("asin",String) );
    definitions.insert( std::pair<std::string,DataTypes>("catalognum",String) );
    definitions.insert( std::pair<std::string,DataTypes>("script",String) );
    definitions.insert( std::pair<std::string,DataTypes>("language",String) );
    definitions.insert( std::pair<std::string,DataTypes>("country",String) );
    definitions.insert( std::pair<std::string,DataTypes>("albumstatus",String) );
    definitions.insert( std::pair<std::string,DataTypes>("media",String) );
    definitions.insert( std::pair<std::string,DataTypes>("albumdisambig",String) );
    definitions.insert( std::pair<std::string,DataTypes>("disctitle",String) );
    definitions.insert( std::pair<std::string,DataTypes>("encoder",String) );
    definitions.insert( std::pair<std::string,DataTypes>("rg_track_gain",FloatNull) );
    definitions.insert( std::pair<std::string,DataTypes>("rg_track_peak",FloatNull) );
    definitions.insert( std::pair<std::string,DataTypes>("rg_album_gain",FloatNull) );
    definitions.insert( std::pair<std::string,DataTypes>("rg_album_peak",FloatNull) );
    definitions.insert( std::pair<std::string,DataTypes>("original_year",Integer) );
    definitions.insert( std::pair<std::string,DataTypes>("original_month",Integer) );
    definitions.insert( std::pair<std::string,DataTypes>("original_day",Integer) );
    definitions.insert( std::pair<std::string,DataTypes>("initial_key",String) );
    definitions.insert( std::pair<std::string,DataTypes>("length",Float) );
    definitions.insert( std::pair<std::string,DataTypes>("bitrate",String) );
    definitions.insert( std::pair<std::string,DataTypes>("format",String) );
    definitions.insert( std::pair<std::string,DataTypes>("samplerate",String) );
    definitions.insert( std::pair<std::string,DataTypes>("bitdepth",Integer) );
    definitions.insert( std::pair<std::string,DataTypes>("channels",Integer) );
    definitions.insert( std::pair<std::string,DataTypes>("mtime",Float) );
    definitions.insert( std::pair<std::string,DataTypes>("added",Float) );

}

