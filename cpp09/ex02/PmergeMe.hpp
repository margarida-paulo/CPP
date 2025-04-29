#pragma once

#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <list>
#include <stdlib.h>

#define DEBUG 1

//Containers FORBIDDEN: Map and Stack
//Let's use Vector and List.
//Vector because looking for a specific element is faster, so looking for the placement of the binary insertion will be faster.
//List because insertions in the middle of a list are faster, so the binary insertion will be faster.


class PmergeMe{
    private:
        PmergeMe();
        std::list<int> numbersList;
        std::vector<int> numbersVector;
        std::vector<int> mergeInsertVector(std::vector<int> numbers);
        
    
    public:
        PmergeMe(char **numbersArray, int size);
        ~PmergeMe();
        PmergeMe(const PmergeMe &other);
        PmergeMe &operator=(const PmergeMe &other);
        class invalidInputException: public std::exception{
            public:
                virtual const char* what() const throw();
        };

        std::vector<int> sortVector();
};

int validateInput(std::string number);