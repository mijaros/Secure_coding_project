#include "jarray.h"

JArray::JArray()
{
}

JValue* JArray::operator [](int name)
{
    return this->array[name];
}

const JValue* JArray::operator [](int name) const
{
    return this->array[name];
}

JArray::iterator JArray::begin()
{
    return (this->array).begin();
}

JArray::const_iterator JArray::begin() const
{
    return this->array.begin();
}

JArray::iterator JArray::end()
{
    return this->array.end();
}

JArray::const_iterator JArray::end() const
{
    return this->array.end();
}

JArray::~JArray()
{
    for (auto x : this->array) {
        delete x;
    }
}
