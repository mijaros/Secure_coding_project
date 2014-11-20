#ifndef JOBJECT_H
#define JOBJECT_H
#include <iterator>
#include <map>

class JArray;
class JValue;

//enum JValue::DataTypes;

#include "jvalue.h"
#include "jparser.h"
/**
 * @brief The JsonObject class
 */



class JObject
{

public:
//    class iterator;
//    class const_iterator;

    typedef std::map<std::string, JValue*>::iterator iterator;
    typedef std::map<std::string, JValue*>::const_iterator const_iterator;

    JObject();

    ~JObject();

    JValue& operator[](std::string);
    const JValue& operator[] (std::string) const;
private:
    friend class JParser;
public:

//    class iterator: public std::iterator<std::forward_iterator_tag,
//            std::pair<std::string, JValue>>
//    {

//    };

//    class const_iterator: public std::iterator<std::forward_iterator_tag,
//            const std::pair<std::string,JValue>>
//    {

//    };

    iterator begin();

    const_iterator begin() const;

    iterator end();

    const_iterator end() const;

private:
    std::map<std::string, JValue*> objDef;
};

#endif // JSONOBJECT_H
