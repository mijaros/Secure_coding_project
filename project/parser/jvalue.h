#ifndef JVALUE_H
#define JVALUE_H

class JArray;
#include "jarray.h"
#include "jobject.h"
#include "jparser.h"

#include <string>
#include <exception>

class JObject;


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



private:
    friend class JParser;
    JObject *obj;
    JArray *arr;
    std::string str;
    int i_val;
    float f_val;

    DataTypes type;

public:

    operator std::string();

    operator int();

    operator float();

    operator JArray *();

    operator JObject *();

    DataTypes getDataType() const;

private:
    JValue(DataTypes d);

};

#endif // JVALUE_H
