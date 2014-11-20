#include "mediamanager.h"
#include "jvalue.h"
#include "jarray.h"
#include "jobject.h"

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
    for(auto album : *albums)
    {

    }
    return true;
}

bool MediaManager::processItems(JObject * items)
{
    for(auto item : *items)
    {

    }
    return true;
}
