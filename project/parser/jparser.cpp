#include "jparser.h"
#include <cctype>
JParser::JParser():
    stack(), parsed(0), currentVal(),
    status(Statuses::NEW_DOCUMENT)
{
}

void JParser::endObjectState(char c)
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

void JParser::newDocState(char c)
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

void JParser::addChar(char c)
{
    switch (status) {
    case NEW_DOCUMENT:
    {
        newDocState(c);
    }
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
    {
        endObjectState(c);
    }
    case START_ARRAY:
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
            if (isalnum(c) || c == '-') {
                types = DataTypes::FLOAT;
            } else {
                throw std::exception();
            }
        }
        v->arr->type = types;
        JValue *newObj = new JValue(types);
        stack.push_back(newObj);
        status = START_OBJECT;
    }
    case END_ARRAY:
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

                delete key, v;
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
        }

    }
    case NEXT_ITEM:
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
                break;
            }
        }
        default:
            throw std::exception();
        }
    }
    case START_STRING:
    case READING_STRING:
    case END_STRING:
    case PAIR_DELIM:
    case READING_NUMBER:
        break;
    }
}
