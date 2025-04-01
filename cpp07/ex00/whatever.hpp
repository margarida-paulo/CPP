#include <iostream>

// Swaps the values of two given parameters. Does not return anything.
template<typename t> void swap(t &arg1, t &arg2){
    t temp = arg1;
    arg1 = arg2;
    arg2 = temp;
}

// Compares the two values passed as parameters and returns the smallest one.
// If they are equal, it returns the second one.
template<typename t> t min(t &arg1, t &arg2){
    if (arg1 < arg2)
        return arg1;
    return arg2;
}

// Compares the two values passed as parameters and returns the greatest one.
// If they are equal, it returns the second one.
template<typename t> t max(t &arg1, t &arg2){
    if (arg1 > arg2)
        return arg1;
    return arg2;
}