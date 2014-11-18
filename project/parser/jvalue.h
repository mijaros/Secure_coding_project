#ifndef JVALUE_H
#define JVALUE_H
#include "jsonobject.h"
#include "jarray.h"

#include <string>
#include <exception>
class JValue
{
public:
    enum DataTypes {
        ARRAY,
        OBJECT,
        INT,
        FLOAT,
        STRING
    };

    class iterator;
    class const_iterator;

private:
    JArray arr;
    JObject obj;
    std::string str;
    int i_val;
    float f_val;

    DataTypes type;

public:
    JValue();

    operator std::string () {
        if (type != DataTypes::STRING){
            throw std::exception();
        }
        return str;
    }

    operator int() {
        if (type != DataTypes::INT)
            throw std::exception();
        return i_val;
    }

    operator float() {
        if (type != DataTypes::FLOAT)
            throw std::exception();
        return f_val;
    }

    operator JArray () {
        if (type != DataTypes::ARRAY)
            throw std::exception();
        return arr;
    }

    operator JObject  () {
        if (type != DataTypes::OBJECT)
            throw std::exception();
        return obj;
    }

    DataTypes getDataType() const;

    iterator &begin();

    const_iterator &begin() const;
};

#endif // JVALUE_H
