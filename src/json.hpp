#ifndef JSON_HPP
#define JSON_HPP

#include "json.tpp"

#include "parse.hpp"
#include "dummy.hpp"

#include <vector>

class Json
{
    // ...

public:
    template<typename T>
    T parse() const
    {
        // explicitly use something from parse.hpp
        return parse_json(*this, dummy<T>());
    }

    std::vector<Json> elements() const;
};

// Just to make things interesting, let's force an instantiation.
// Now, parse.hpp is REALLY required!
template
int Json::parse<int>() const;

#endif // JSON_HPP
