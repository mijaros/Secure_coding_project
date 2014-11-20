#ifndef MEDIAMANAGER_H
#define MEDIAMANAGER_H

#include <list>
#include "jvalue.h"
#include "item.h"
#include "album.h"

class MediaManager
{
private:
    JValue * base;
    std::list<item*> items;
    std::list<album*> albums;
    bool processAlbums(JObject * albums);
    bool processItems(JObject * items);
public:
    MediaManager(JValue * input);
    bool process();

};

#endif // MEDIAMANAGER_H
