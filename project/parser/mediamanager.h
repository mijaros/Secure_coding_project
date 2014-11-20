#ifndef MEDIAMANAGER_H
#define MEDIAMANAGER_H

#include "jvalue.h"

class MediaManager
{
private:
    JValue base;
    bool processAlbums(JObject * albums);
    bool processItems(JObject * items);
public:
    MediaManager(JValue input);
    bool process();
};

#endif // MEDIAMANAGER_H
