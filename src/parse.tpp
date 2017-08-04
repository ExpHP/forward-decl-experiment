#ifdef  PARSE_TPP
#include <diagnostic/forward-dependency-cycle>
#else
#define PARSE_TPP

// explicitly encode dependencies between tpp files;
// but beware these must form a dag
#include "json.tpp"

// include anything else you need for things that don't have TPP files.
#include "dummy.hpp"

#include <type_traits>
#include <vector>

// Templates that depend on json.hpp

template<typename T>
std::vector<T> parse_json(const Json& json, dummy<std::vector<T>> d);

#undef  PARSE_TPP
#endif
