#ifndef JARRAY_H
#define JARRAY_H
#include <iterator>
#include <vector>

class JValue;
#include "jvalue.h"

#include "jparser.h"

class JArray
{
public:
    /*
     * Forward declarations and public methods
     */
    typedef std::vector<JValue*>::iterator iterator;
    typedef std::vector<JValue*>::const_iterator const_iterator;

    JArray();
    ~JArray();

    JValue* operator[] (int);

    const JValue* operator[] (int) const;

private:
    friend class JParser;
    /*
     * Private methods and other stuff
     */
public:

    /*
     * Iterators section
     */


    iterator begin();

    const_iterator begin() const;

    iterator end();

    const_iterator end() const;
private:
    /*
     * The attributes section
     */

    std::vector<JValue*> array;
    DataTypes type;

};

#endif // JARRAY_H
