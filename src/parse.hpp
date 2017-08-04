#ifndef PARSE_HPP
#define PARSE_HPP

#include "parse.tpp"

#include "dummy.hpp"
#include "json-skel.hpp"

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

// Do something that requires the complete type.
// (chances are that any implementation of the vector version above would
//  require it, but I could only manage to get warnings that way, not errors)
static void f(Json json) {} // error: ‘json’ has incomplete type

#endif // PARSE_HPP
