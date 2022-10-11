#include "compound_key.h"

#include <iostream>
#include <map>

int main()
{
    std::cout << "hello" << std::endl;

    cpp_utils::compound_key<int, std::string> key;

    using KeyT = cpp_utils::compound_key<std::string, std::string>;

    std::map<KeyT, std::string, cpp_utils::prefix_compare> mp;
    mp[KeyT("hi", "hello")] = "value";

    std::cout << mp[KeyT("hi", "hello")] << std::endl;
    // std::cout << mp[cpp_utils::compound_key<std::string>{"hi"}] << std::endl;

    auto range = mp.equal_range(cpp_utils::compound_key<std::string>("hi"));
    for (auto it = range.first; it != range.second; ++it) {
        std::cout << it->second << std::endl;
    }

    return 0;
}