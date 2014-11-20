#include "jvalue.h"

JValue::JValue(DataTypes d):
    obj(0), arr(0), str(), i_val(0), f_val(0), type(d)
{
    switch (d) {
    case OBJECT:
        obj = new JObject;
        break;
    case ARRAY:
        arr = new JArray;
    default:
        break;
    }

}

JValue::~JValue()
{
    switch (type) {
    case DataTypes::OBJECT:
        delete obj;
        break;
    case DataTypes::ARRAY:
        delete arr;
        break;
    }
}

DataTypes JValue::getDataType() const
{
    return this->type;
}

JValue::operator std::string () {
    if (type != DataTypes::STRING){
        throw std::exception();
    }
    return str;
}

JValue::operator int() {
    if (type != DataTypes::INT)
        throw std::exception();
    return i_val;
}

JValue::operator float() {
    if (type != DataTypes::FLOAT)
        throw std::exception();
    return f_val;
}

JValue::operator JArray* () {
    if (type != DataTypes::ARRAY)
        throw std::exception();
    return arr;
}

JValue::operator JObject*  () {
    if (type != DataTypes::OBJECT)
        throw std::exception();
    return obj;
}



