#include "jparser.h"
#include <cctype>
#include <ios>
#include <iostream>
#include <map>


JParser::JParser():
    stack(), parsed(0), currentVal(),
    status(Statuses::NEW_DOCUMENT)
{
}

std::istream& operator>> (std::istream& in, JParser& where)
{
    try {
        while (in.good()) {
            char c;
            in >> std::noskipws >> c;
            where.addChar(c);
        }
        where.addChar(-1);

    } catch (std::exception &ex) {
        where.destroyStack();
        throw ex;
    }

    return in;
}

void JParser::destroyStack()
{
    for(JValue *j : stack) {
        delete j;
    }
}

void JParser::endObjectState(int c)
{
    JValue *top = stack.back();
    stack.pop_back();

    if (stack.empty() && (c == -1 || isspace(c))) {
        parsed = top;
        status = ROOT_ELEMENT_FOUND;
        return;
    }
    if (isspace(c)) {
        stack.push_back(top);
        return;
    }

    JValue *curr_top = stack.back();
    switch (curr_top->type) {
    case DataTypes::ARRAY:
    {
        if (c == ',') {
            curr_top->arr->array.push_back(top);
            status = NEXT_ITEM;
        } else if (c == ']') {
            curr_top->arr->array.push_back(top);
            status = END_ARRAY;
        } else {
            throw std::exception();
        }
    }
    case DataTypes::STRING:
    {
        JValue *key = curr_top;
        stack.pop_back();
        curr_top = stack.back();

        if (curr_top->type != DataTypes::OBJECT) {
            delete key;
            throw std::exception();
        }

        curr_top->obj->objDef[key->str] = top;
        delete key;

        switch (c) {
        case ',':
            status = NEXT_ITEM;
            break;
        case '}':
            status = END_OBJECT;
            break;
        default:
            throw std::exception();
        }
    }
    default:
        throw std::exception();
    }
}

void JParser::newDocState(int c)
{
    if (!stack.empty()){
        throw std::exception();
    }

    if (isspace(c)) {
        return;
    }

    if (c == '{') {
        JValue *v = new JValue(DataTypes::OBJECT);
        v->obj = new JObject;
        stack.push_back(v);
        status = START_OBJECT;
        return;
    } else if (c == '[') {
        JValue *v = new JValue(DataTypes::ARRAY);
        v->arr = new JArray;
        status = START_ARRAY;
        return;
    } else {
        throw std::exception();
    }
}

void JParser::createObject(char c, char expected, DataTypes type, Statuses status)
{
    if (c != expected)
        throw std::exception();
    stack.push_back(new JValue(type));
    this->status = status;
}

void JParser::nextItemState(int c)
{
    if (isspace(c))
        return;
    switch (stack.back()->type) {
    case DataTypes::OBJECT:
        if (c != '"')
            throw std::exception();
        stack.push_back(new JValue(DataTypes::STRING));
        break;
    case DataTypes::ARRAY:
    {
        JValue *array = stack.back();
        switch (array->arr->type) {
        case DataTypes::ARRAY:
            createObject(c, '[', DataTypes::ARRAY, START_ARRAY);
            break;
        case DataTypes::OBJECT:
            createObject(c, '{', DataTypes::OBJECT, START_OBJECT);
            break;
        case DataTypes::STRING:
            createObject(c, '"', DataTypes::STRING, READING_STRING);
            break;
        case DataTypes::FLOAT:
        {
            if (!isdigit(c) && c != '-')
                throw std::exception();
            JValue *add = new JValue(DataTypes::FLOAT);
            add->str += c;
            stack.push_back(add);
        }
        default:
            break;
        }

    }
    default:
        throw std::exception();
    }
}

void JParser::startArrayState(int c)
{
    if (stack.back()->type != DataTypes::ARRAY) {
        throw std::exception();
    }

    if (isspace(c))
        return;
    JValue *v = stack.back();

    if (!v->arr->array.empty()) {
        throw std::exception();
    }
    DataTypes types;
    switch (c) {
    case '{':
        types = DataTypes::OBJECT;
        break;
    case '[':
        types = DataTypes::ARRAY;
        break;
    case '"':
        types = DataTypes::STRING;
        break;
    default:
        if (isdigit(c) || c == '-') {
            types = DataTypes::FLOAT;
        } else {
            throw std::exception();
        }
    }
    v->arr->type = types;
    JValue *newObj = new JValue(types);
    if (types == DataTypes::FLOAT) {
        newObj->str+=c;
    }
    stack.push_back(newObj);
    switch (types) {
    case DataTypes::ARRAY:
        status = START_ARRAY;
        break;
    case DataTypes::OBJECT:
        status = START_OBJECT;
        break;
    case DataTypes::STRING:
        status = READING_STRING;
        break;
    case DataTypes::FLOAT:
        status = READING_NUMBER;
        break;
    default:
        throw std::exception();
    }
}

void JParser::endArrayState(int c)
{
    if (stack.back()->type != DataTypes::ARRAY)
        throw std::exception();

    JValue *v = stack.back();
    stack.pop_back();



    if (stack.empty() && (c == -1 || isspace(c))) {
        status = ROOT_ELEMENT_FOUND;
        parsed = v;
        return;
    }
    JValue *cur_top = stack.back();

    if (isspace(c)) {
        stack.push_back(v);
        return;
    }

    switch (cur_top->type) {
    case DataTypes::ARRAY:
    {
        if (cur_top->arr->type != v->type)
            throw std::exception();

        switch (c) {
        case ',':
            status = NEXT_ITEM;
            break;
        case ']':
            status = END_ARRAY;
            break;
        default:
            delete v;
            throw std::exception();
        }
        cur_top->arr->array.push_back(v);
    }
    case DataTypes::STRING:
    {
        JValue *key = stack.back();
        stack.pop_back();

        if (stack.back()->type != DataTypes::OBJECT) {

            delete key;
            delete v;
            throw std::exception();
        }
        JValue *obj = stack.back();
        obj->obj->objDef[key->str] = v;
        delete key;
        switch (c) {
        case ',':
            status = NEXT_ITEM;
            break;
        case '}':
            status = END_OBJECT;
            break;
        default:
            throw std::exception();
        }
    }
    default:
        throw std::exception();
    }

}

void JParser::readingStringState(int c)
{
    if (stack.back()->type != DataTypes::STRING) {
        throw std::exception();
    }

    if (c == '\\') {
        status = ESCAPED;
        return;
    }

    if (c == '"') {
        status = END_STRING;
        return;
    }
    JValue *j = stack.back();
    j->str += c;
    return;

}

void JParser::endStringState(int c)
{
    if (isspace(c)) {
        return;
    }

    JValue *str = stack.back();
    stack.pop_back();
    if ( stack.empty()) {
        if (c == -1) {
            parsed = str;
            status = ROOT_ELEMENT_FOUND;
        } else {
            delete str;
            throw std::exception();
        }
    }
    JValue *parent = stack.back();
    switch (parent->type) {
    case DataTypes::ARRAY:
        switch (c) {
        case ']':
            parent->arr->array.push_back(str);
            status = END_ARRAY;
            return;
        case ',':
            parent->arr->array.push_back(str);
            status = NEXT_ITEM;
            return;
        default:
            throw std::exception();
        }
    case DataTypes::STRING:
    {
        JValue *key = parent;
        stack.pop_back();
        parent = stack.back();
        if (parent->type != DataTypes::OBJECT) {
            delete str;
            delete key;
            throw std::exception();
        }

        switch (c) {
        case ',':
            parent->obj->objDef[key->str] = str;
            delete key;
            status = NEXT_ITEM;
            return;
        case '}':
            parent->obj->objDef[key->str] = str;
            delete key;
            status = END_OBJECT;
            return;
        default:
            delete str;
            delete key;
            throw std::exception();
        }
    }
    case DataTypes::OBJECT:
    {
        if (c != ':') {
            delete str;
            throw std::exception();
        }

        stack.push_back(str);
        status = PAIR_DELIM;
        return;

    }
    default:
        delete str;
        throw std::exception();
    }
}

void JParser::pairDelimState(int c)
{
    if (stack.back()->type != DataTypes::STRING) {
        throw std::exception();
    }
    if (isspace(c)) {
        return;
    }

    switch (c) {
    case '[':
        stack.push_back(new JValue(DataTypes::ARRAY));
        status = START_ARRAY;
        break;
    case '{':
        stack.push_back(new JValue(DataTypes::OBJECT));
        status = START_OBJECT;
        break;
    case '"':
        stack.push_back(new JValue(DataTypes::STRING));
        status = READING_STRING;
        break;
    default:
        if (isdigit(c) || c == '-') {
            JValue *val = new JValue(DataTypes::FLOAT);
            val->str += c;
            stack.push_back(val);
        }
    }
}

void JParser::readindNumberState(int c)
{
    if (stack.back()->type != DataTypes::FLOAT) {
        throw std::exception();
    }

    if (isspace(c)){
        status = NUMBER_READ;
        return;
    }
    if (c == ',' || c == ']' || c == '}') {
        status = NUMBER_READ;

    }

    if (isdigit(c) || c == '.'){
        JValue *cur = stack.back();
        cur->str += c;
    }
}

void JParser::numberReadState(int c)
{
    if (isspace(c)) {
        return;
    }

    JValue *s = stack.back();
    stack.pop_back();
    JValue *parent = stack.back();
    s->f_val = atof(s->str.c_str());
    s->str.clear();

    switch (parent->type) {
    case DataTypes::ARRAY:
        if (parent->arr->type != DataTypes::FLOAT){
            delete s;
            throw std::exception();
        }

        parent->arr->array.push_back(s);
        return;
    case DataTypes::STRING:
    {
        JValue *key = parent;
        stack.pop_back();
        parent = stack.back();

        if (parent->type != DataTypes::OBJECT) {
            delete key;
            delete s;
            throw std::exception();
        }
        parent->obj->objDef[key->str] = s;
        delete key;
        return;
    }
    default:
        throw std::exception();
    }
}

void JParser::escapedState(int c)
{
    if (stack.back()->type != DataTypes::STRING)
        throw std::exception();

    JValue *val = stack.back();
    val->str += c;
    status = READING_STRING;
}

void JParser::addChar(int c)
{
    switch (status) {
    case NEW_DOCUMENT:
        newDocState(c);
        break;
    case START_OBJECT:
    {
        if (stack.back()->type != DataTypes::OBJECT) {
            throw std::exception();
        }

        if (isspace(c)) {
            return;
        }

        if (c != '"') {
            throw std::exception();
        }

        JValue *v = new JValue(DataTypes::STRING);
        stack.push_back(v);
        status = READING_STRING;
        return;
    }
    case END_OBJECT:
        endObjectState(c);
        break;
    case START_ARRAY:
        startArrayState(c);
        break;
    case END_ARRAY:
        endArrayState(c);
        break;
    case NEXT_ITEM:
        nextItemState(c);
        break;
        //case START_STRING:
    case READING_STRING:
        readingStringState(c);
        break;
    case END_STRING:
        endStringState(c);
        break;
    case PAIR_DELIM:
        pairDelimState(c);
        break;
    case READING_NUMBER:
        readindNumberState(c);
        break;
    case NUMBER_READ:
        numberReadState(c);
        break;
    case ESCAPED:
        escapedState(c);
        break;
    case ROOT_ELEMENT_FOUND:
        if (isspace(c) || c == -1)
            return;
        throw std::exception();

    }
}

JValue* JParser::getParsed()
{
    return this->parsed;
}
