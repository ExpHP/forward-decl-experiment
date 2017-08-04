
#include "json.hpp"

#include <iostream>

int main()
{
    // use stuff for 100% code coverage
    Json json;
    std::cout << json.elements().size() << std::endl;
    auto v = json.parse<std::vector<int>>();
    std::cout << v.size() << std::endl;
    return 0;
}