#include <stdio.h>
#include <string>
#include <iostream>

template<typename t> void print(t& toPrint){
    std::cout << toPrint << std::endl;
}

template <typename t> void iter(t *array, size_t array_length, void (*func)(t&)){
    if (array == NULL)
        return;
    for (size_t i = 0; i < array_length; i++)
        func((array)[i]);
}