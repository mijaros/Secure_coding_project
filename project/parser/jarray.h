#ifndef JARRAY_H
#define JARRAY_H
#include <iterator>

#include "jvalue.h"
class JArray
{
public:
    class iterator;
    class const_iterator;

    JArray();

    JValue& operator[] (int);

    const JValue& operator[] (int) const;

private:

public:
    class iterator: public std::iterator<std::forward_iterator_tag, JValue>
    {

    };
    class const_iterator: public std::iterator<std::forward_iterator_tag, JValue>
    {

    };

    iterator begin();

    const_iterator begin() const;

    iterator end();

    const_iterator end() const;
};

#endif // JARRAY_H
