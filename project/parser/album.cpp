#include "album.h"
#include "mediaTypes.h"

album::album()
{
    definitions.insert( std::pair<std::string,DataTypes>("id",Integer) );
    definitions.insert( std::pair<std::string,DataTypes>("artpath",String) );
    definitions.insert( std::pair<std::string,DataTypes>("added",Float) );
    definitions.insert( std::pair<std::string,DataTypes>("albumartist",String) );
    definitions.insert( std::pair<std::string,DataTypes>("albumartist_sort",String) );
    definitions.insert( std::pair<std::string,DataTypes>("albumartist_credit",String) );
    definitions.insert( std::pair<std::string,DataTypes>("album_n",String) );
    definitions.insert( std::pair<std::string,DataTypes>("genre",String) );
    definitions.insert( std::pair<std::string,DataTypes>("year",Integer) );
    definitions.insert( std::pair<std::string,DataTypes>("month",Integer) );
    definitions.insert( std::pair<std::string,DataTypes>("day",Integer) );
    definitions.insert( std::pair<std::string,DataTypes>("tracktotal",Integer) );
    definitions.insert( std::pair<std::string,DataTypes>("disctotal",Integer) );
    definitions.insert( std::pair<std::string,DataTypes>("comp",Bool) );
    definitions.insert( std::pair<std::string,DataTypes>("mb_albumid",String) );
    definitions.insert( std::pair<std::string,DataTypes>("mb_albumartistid",String) );
    definitions.insert( std::pair<std::string,DataTypes>("albumtype",String) );
    definitions.insert( std::pair<std::string,DataTypes>("label",String) );
    definitions.insert( std::pair<std::string,DataTypes>("mb_releasegroupid",String) );
    definitions.insert( std::pair<std::string,DataTypes>("asin",String) );
    definitions.insert( std::pair<std::string,DataTypes>("catalognum",String) );
    definitions.insert( std::pair<std::string,DataTypes>("script",String) );
    definitions.insert( std::pair<std::string,DataTypes>("language",String) );
    definitions.insert( std::pair<std::string,DataTypes>("country",String) );
    definitions.insert( std::pair<std::string,DataTypes>("albumstatus",String) );
    definitions.insert( std::pair<std::string,DataTypes>("albumdisambig",String) );
    definitions.insert( std::pair<std::string,DataTypes>("rg_album_gain",FloatNull) );
    definitions.insert( std::pair<std::string,DataTypes>("rg_album_peak",FloatNull) );
    definitions.insert( std::pair<std::string,DataTypes>("original_year",Integer) );
    definitions.insert( std::pair<std::string,DataTypes>("original_month",Integer) );
    definitions.insert( std::pair<std::string,DataTypes>("original_day",Integer) );

}
