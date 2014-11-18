#ifndef JSONOBJECT_H
#define JSONOBJECT_H
#include <iterator>
#include <map>
#include "jvalue.h"
/**
 * @brief The JsonObject class
 */
class JObject
{

public:
    class iterator;
    class const_iterator;

    JObject();

    JValue& operator[](std::string);
    const JValue& operator[] (std::string) const;
private:

public:

    class iterator: public std::iterator<std::forward_iterator_tag,
            std::pair<std::string, JValue>>
    {

    };

    class const_iterator: public std::iterator<std::forward_iterator_tag,
            const std::pair<std::string,JValue>>
    {

    };

    iterator begin();

    const_iterator begin() const;

    iterator end();

    const_iterator end() const;


};

#endif // JSONOBJECT_H
