#include "jobject.h"

JObject::JObject()
{
}

JObject::iterator JObject::begin()
{
    return this->objDef.begin();
}

JObject::iterator JObject::end()
{
    return this->objDef.end();
}

JObject::const_iterator JObject::begin() const
{
    return this->objDef.begin();
}

JObject::const_iterator JObject::end() const
{
    return this->objDef.end();
}

JObject::~JObject()
{
    for(auto x : this->objDef){
        delete x.second;

    }
}
