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
        album * i = new album();
        if (i->definitions.count(al.first) != 0)
        {
            switch (i->definitions[al.first]) {
            case (MediaDataTypes::Integer):
            {
                int tmpi = *al.second;
                i->addint(al.first, tmpi);
                break;
            }
            case (MediaDataTypes::String):
            {
                std::string tmps = *al.second;
                i->addstr(al.first, tmps);
                break;
            }
            case MediaDataTypes::Float:
            {
                float tmp = *al.second;
                i->addfloat(al.first, tmp);
                break;
            }
            }
        }
        this->albums.push_back(i);
    }
    return true;
}

bool MediaManager::processItems(JObject * items)
{
    for(auto it : *items)
    {
        item * i = new item();
        if (i->definitions.count(it.first) != 0)
        {
            switch (i->definitions[it.first]) {
            case MediaDataTypes::Integer:
            {
                int tmpi = *it.second;
                i->addint(it.first, tmpi);
                break;
            }
            case MediaDataTypes::String:
            {
                std::string tmps = *it.second;
                i->addstr(it.first, tmps);
                break;
            }
            case MediaDataTypes::Float:
            {
                float tmp = *it.second;
                i->addfloat(it.first, tmp);
                break;
            }
            }
        }
        this->items.push_back(i);
    }
    return true;
}
