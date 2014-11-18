#ifndef ALBUM_H
#define ALBUM_H
#include <string>
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
   int id;
   //'artpath': PathType(),

   // DateType format %Y-%m-%d %H:%M:%S
   //'added': DateType(),
   std::string albumartist;
   std::string albumartist_sort;
   std::string albumartist_credit;
   std::string album_n;
   std::string genre;
   // is PaddedInt necessary?
   int year; //types.PaddedInt(4),
   int month; //types.PaddedInt(2),
   int day; //types.PaddedInt(2),
   int tracktotal; //types.PaddedInt(2),
   int disctotal; //types.PaddedInt(2),
   bool comp;
   std::string mb_albumid;
   std::string mb_albumartistid;
   std::string albumtype;
   std::string label;
   std::string mb_releasegroupid;
   std::string asin;
   std::string catalognum;
   std::string script;
   std::string language;
   std::string country;
   std::string albumstatus;
   std::string albumdisambig;
   //'rg_album_gain': types.NULL_FLOAT,
   //'rg_album_peak': types.NULL_FLOAT,
   int original_year; //types.PaddedInt(4),
   int original_month; //types.PaddedInt(2),
   int original_day; //types.PaddedInt(2),
public:
    album();
};

#endif // ALBUM_H
