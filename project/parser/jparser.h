#ifndef JPARSER_H
#define JPARSER_H

#include <istream>
#include "jvalue.h"

std::istream& operator>>(std::istream& in, JParser& where);

class JParser
{
    friend std::istream& operator>>(std::istream&, JParser& where);

public:
    JParser();

    JValue& getParsed();

    bool parse();


};

#endif // JPARSER_H
