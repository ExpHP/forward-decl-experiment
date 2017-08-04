#ifdef  PARSE_TPP
#include "diagnostic/forward-dependency-cycle"
#else
#define PARSE_TPP

// explicitly encode dependencies between tpp files;
// but beware these must form a dag
#include "json-skel.tpp"
#include "dummy.tpp"

#include <type_traits>
#include <vector>

template<typename T>
std::vector<T> parse_json(const Json& json, dummy<std::vector<T>> d);

#undef  PARSE_TPP
#endif
