#pragma once

#include <algorithm>

//Returns an iterator to the integer found in the T container, or the iterator to the
//end of the container, in case the element was not found.
template <typename T>
typename T::iterator easyfind(T &container, int toFind){
    return std::find(container.begin(), container.end(), toFind);
}