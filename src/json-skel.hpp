#ifndef JSON_SKEL_HPP
#define JSON_SKEL_HPP

#include "json-skel.tpp"

#include <vector>

class Json
{
    // ...

public:
    template<typename T>
    T parse() const;

    std::vector<Json> elements() const;
};

#endif // JSON_SKEL_HPP
