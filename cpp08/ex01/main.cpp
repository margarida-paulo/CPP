#include <vector>
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

#include "Span.hpp"


int main()
{
    std::cout << std::endl << BMAGENTA << "TESTING A SMALL SPAN (5 elements)" << RESET << std::endl;
    try{
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        sp.printList();
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    } catch (std::exception &e){
        std::cout << std::endl << RED << "EXCEPTION: " << e.what() << RESET << std::endl;
    }

    std::cout << BMAGENTA << std::endl << "TESTING A BIG SPAN (20000 elements)" << RESET << std::endl;

    // Create a vector to hold the numbers
    std::vector<int> numbers(20000); // Vector with 10 elements

    // Seed the random number generator
    std::srand(std::time(0));

    // Fill the vector with random numbers
    for (size_t i = 0; i < numbers.size(); ++i) {
        numbers[i] = std::rand() % 1000000000; // Generate random numbers between 0 and 999999999
    }

    try{
        Span bigSpan(20000);
        bigSpan.fillSpan(numbers.begin(), numbers.end());
    
        bigSpan.printList();
        std::cout << "Shortest span: " << bigSpan.shortestSpan() << std::endl;
        std::cout << "Longest span: " << bigSpan.longestSpan() << std::endl;
    } catch (std::exception &e){
        std::cout << std::endl << RED << "EXCEPTION: " << e.what() << RESET << std::endl;
    }


    std::cout << std::endl << BMAGENTA << "TESTING A ONE NUMBER SPAN" << RESET << std::endl;
    try{
        Span oneNumberSp = Span(1);
        oneNumberSp.addNumber(6);
        oneNumberSp.printList();
        std::cout << "Shortest span: " << oneNumberSp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << oneNumberSp.longestSpan() << std::endl;
    } catch (std::exception &e){
        std::cout << std::endl << RED << "EXCEPTION: " << e.what() << RESET << std::endl;
    }

    std::cout << std::endl << BMAGENTA << "TESTING A SPAN OVERFLOW" << RESET << std::endl;
    try{
        Span overflowSpan = Span(3);
        overflowSpan.addNumber(6);
        overflowSpan.addNumber(9);
        overflowSpan.addNumber(50);
        overflowSpan.addNumber(473);
        overflowSpan.printList();
        std::cout << "Shortest span: " << overflowSpan.shortestSpan() << std::endl;
        std::cout << "Longest span: " << overflowSpan.longestSpan() << std::endl;
    } catch (std::exception &e){
        std::cout << std::endl << RED << "EXCEPTION: " << e.what() << RESET << std::endl;
    }

    return 0;
}