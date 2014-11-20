#include "mediamanager.h"
#include "jvalue.h"
#include "jarray.h"
#include "jobject.h"
#include "item.h"
#include "album.h"

MediaManager::MediaManager(JValue * input) : base(input)
{ }

bool MediaManager::process()
{
    //probably not required
    if (base->getDataType() != DataTypes::OBJECT)
        throw std::exception();

    JObject *baseObject = *base;
    for(auto objectItems : *baseObject)
    {
        //probably not required
        if (objectItems.second->getDataType() != DataTypes::ARRAY)
            throw std::exception();

        if(objectItems.first.compare("albums") == 0)
        {
            JArray * arr = *objectItems.second;
            for(auto arrItems : *arr)
            {
                JObject *album = *arrItems;
                processAlbums(album);
            }
        }
        else if (objectItems.first.compare("items") == 0)
        {
            JArray * arr = *objectItems.second;
            for(auto arrItems : *arr)
            {
                JObject *item = *arrItems;
                processItems(item);
            }
        }
        else
        {
            throw std::exception();
        }
    }
    return true;
}

bool MediaManager::processAlbums(JObject * albums)
{
    for(auto al : *albums)
    {
        album i;
        if (i.definitions.count(al.first) != 0)
        {
            switch (i.definitions[al.first]) {
            case (MediaDataTypes::Integer):
                int tmpi = *al.second;
                i.addint(al.first, tmpi);
                break;
            case (MediaDataTypes::String):
                std::string tmps = *al.second;
                i.addstr(al.first, tmps);
                break;
            case MediaDataTypes::Float:
                float tmp = *al.second;
                i.addfloat(al.first, tmp);
                break;
            }
        }
        this->albums.push_back(i);
    }
    return true;
}

bool MediaManager::processItems(JObject * items)
{
    for(auto item : *items)
    {
        item i;
        if (i.definitions.count(album.first) != 0)
        {
            switch (i.definitions[album.first]) {
            case MediaDataTypes::Integer:
                int tmpi = *album.second;
                item.addint(album.first, tmpi);
                break;
            case MediaDataTypes::String:
                std::string tmps = *album.second;
                item.addstr(album.first, tmps);
                break;
            case MediaDataTypes::Float:
                float tmp = *album.second;
                item.addfloat(album.first, tmp);
                break;
            }
        }
        this->items.push_back(i);
    }
    return true;
}
