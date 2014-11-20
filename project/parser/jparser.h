#ifndef JPARSER_H
#define JPARSER_H

#include <istream>
#include "jvalue.h"

class JParser;

std::istream& operator>>(std::istream& in, JParser& where);

class JParser
{
    friend std::istream& operator>>(std::istream&, JParser& where);
   enum Statuses {
       NEW_DOCUMENT,
       START_OBJECT,
       END_OBJECT,
       START_ARRAY,
       END_ARRAY,
       NEXT_ITEM,
       START_STRING,
       READING_STRING,
       END_STRING,
       PAIR_DELIM,
       READING_NUMBER,
       ROOT_ELEMENT_FOUND
   };

   void addChar(char c);
   void newDocState(char c);
   void endObjectState(char c);

public:
    JParser();

    JValue* getParsed();

    bool parse();
private:

   std::vector<JValue*> stack;
   JValue *parsed;
   std::string currentVal;
   std::pair<std::string, JValue*> currPair;
   Statuses status;

};

#endif // JPARSER_H
