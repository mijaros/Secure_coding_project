#ifndef MEDIATYPES_H
#define MEDIATYPES_H

struct floatNull
{
    float num;
    bool isNull;
};
enum DataTypes
{
    Integer,
    String,
    Float,
    FloatNull,
    Bool
};

#endif // MEDIATYPES_H