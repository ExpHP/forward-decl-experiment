#ifndef PARSE_HPP
#define PARSE_HPP

#include "parse.tpp"

#include "dummy.hpp"
#include "json.hpp"

#include <vector>

//-------------
// Simple functions;
// Declared in HPP, defined in CPP

int parse_json_as_int(const Json& json);

//-------------
// Template functions;
// Declared in TPP, defined in HPP

static int parse_json(const Json& json, dummy<int> d)
{
    d.silence_unused_warning();
    return parse_json_as_int(json);
}

template<typename T>
std::vector<T> parse_json(const Json& json, dummy<std::vector<T>> d)
{
    d.silence_unused_warning();
    return {};
}

#endif // PARSE_HPP
