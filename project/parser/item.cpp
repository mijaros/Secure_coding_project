#include "item.h"

item::item()
{
}

std::string item::scaledInt(int value, std::string suffix)
{
    if(value > 0)
        return std::to_string(floor(value)) + suffix;
    return std::to_string(-1)+ suffix;
}
