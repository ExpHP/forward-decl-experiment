#ifndef JSON_HPP
#define JSON_HPP

// look ma, no dependence on #include order!
// TODO: uh, should verify that...
#include "dummy.hpp"
#include "parse.hpp"
#include "json-skel.hpp"

template<typename T>
T Json::parse() const
{
    // explicitly use something from parse.hpp
    return parse_json(*this, dummy<T>());
}

// Just to make things interesting, let's force an instantiation.
// Now, parse.hpp is REALLY required!
template
int Json::parse<int>() const;

#endif // JSON_HPP
