#include "jarray.h"

JArray::JArray()
{
}

JValue* JArray::operator [](int name)
{

}

const JValue* JArray::operator [](int name) const
{

}

JArray::iterator JArray::begin()
{

}

JArray::const_iterator JArray::begin() const
{

}

JArray::iterator JArray::end()
{

}

JArray::const_iterator JArray::end() const
{

}

JArray::~JArray()
{
    for (auto x : this->array) {
        delete x;
    }
}
