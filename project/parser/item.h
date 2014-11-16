#ifndef ITEM_H
#define ITEM_H

class item
{
private:
   int id;
   //'path': PathType(),
   int album_id;
   std::string title;
   std::string artist;
   std::string artist_sort;
   std::string artist_credit;
   std::string album;
   std::string albumartist;
   std::string albumartist_sort;
   std::string albumartist_credit;
   std::string genre;
   std::string composer;
   std::string grouping;
   // is PaddedInt necessary?
   int year; //types.PaddedInt(4),
   int month; //types.PaddedInt(2),
   int day; //types.PaddedInt(2),
   int track; //types.PaddedInt(2),
   int tracktotal; //types.PaddedInt(2),
   int disc; //types.PaddedInt(2),
   int disctotal; //types.PaddedInt(2),
   std::string lyrics;
   std::string comments;
   int bpm;
   bool comp;
   std::string mb_trackid;
   std::string mb_albumid;
   std::string mb_artistid;
   std::string mb_albumartistid;
   std::string albumtype;
   std::string label;
   std::string acoustid_fingerprint;
   std::string acoustid_id;
   std::string mb_releasegroupid;
   std::string asin;
   std::string catalognum;
   std::string script;
   std::string language;
   std::string country;
   std::string albumstatus;
   std::string media;
   std::string albumdisambig;
   std::string disctitle;
   std::string encoder;
   //'rg_track_gain': types.NULL_FLOAT,
   //'rg_track_peak': types.NULL_FLOAT,
   //'rg_album_gain': types.NULL_FLOAT,
   //'rg_album_peak': types.NULL_FLOAT,
   int original_year; //types.PaddedInt(4),
   int original_month; //types.PaddedInt(2),
   int original_day; //types.PaddedInt(2),
   std::string initial_key; //MusicalKey(), looks like enum, probably string is better in C lang
   float length;
   std::string bitrate; //types.ScaledInt(1000, u'kbps')
   std::string format;
   std::string samplerate; //types.ScaledInt(1000, u'kHz'),
   int bitdepth;
   int channels;
   //'mtime': DateType(),
   //'added': DateType(),
public:
    item();
    std::string scaledInt(int, std::string);
};

#endif // ITEM_H
