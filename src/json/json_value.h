#ifndef JSON_VALUE_H
#define JSON_VALUE_H

#include "../global.h"
#include <string>

TOOSKA_BEGIN_NAMESPACE(core)
class string_renderer;
TOOSKA_END_NAMESPACE

TOOSKA_BEGIN_NAMESPACE(serialization)
class token_serializer;
TOOSKA_END_NAMESPACE

TOOSKA_BEGIN_NAMESPACE(json)
class json_array;
class json_object;
class json_value
{
    int _n;
    float _f;
    bool _b;
    std::string _s;

public:
    enum class type_t{
        invalid,
        bool_t,
        int_t,
        float_t,
        string_t,
        object_t,
        array_t
    };
    json_value();
    json_value(const bool &b);
    json_value(const int &n);
    json_value(const float &f);
    json_value(const std::string &value);
    virtual ~json_value();

    type_t type() const;

    int to_int() const;
    float to_float() const;
    bool to_bool() const;
    std::string to_string() const;
    json_object *to_object();
    json_array *to_array();

//    template<class T>
//    T to();

//    template<>
//    int to<int>();

//    template<>
//    float to<float>();

//    template<>
//    std::string to<std::string>();

protected:
    type_t _type;

private:
    virtual void render(core::string_renderer &r);

    friend class json_object;
    friend class json_array;
    friend class json_document;
    friend class tooska::serialization::token_serializer;
};

TOOSKA_END_NAMESPACE

#endif // JSON_VALUE_H