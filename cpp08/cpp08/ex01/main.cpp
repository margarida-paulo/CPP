#include <vector>
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

#include "Span.hpp"


int main()
{
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;


    // Create a vector to hold the numbers
    std::vector<int> numbers(20000); // Vector with 10 elements

    // Seed the random number generator
    std::srand(std::time(0));

    // Fill the vector with random numbers
    for (size_t i = 0; i < numbers.size(); ++i) {
        numbers[i] = std::rand() % 1000000000; // Generate random numbers between 0 and 999999999
    }

    Span bigSpan(20000);
    bigSpan.fillSpan(numbers.begin(), numbers.end());
    std::cout << bigSpan.shortestSpan() << std::endl;
    std::cout << bigSpan.longestSpan() << std::endl;

    return 0;
}