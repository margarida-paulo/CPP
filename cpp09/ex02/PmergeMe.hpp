#pragma once

#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <deque>
#include <stdlib.h>
#include <cmath>
#include <ctime>
#include <iomanip>

#define DEBUG 0

//Containers FORBIDDEN: Map and Stack
//Let's use Vector and List.
//Vector because looking for a specific element is faster, so looking for the placement of the binary insertion will be faster.
//List because insertions in the middle of a list are faster, so the binary insertion will be faster.


class PmergeMe{
    private:
        PmergeMe();
        std::deque<int> numbersDeque;
        std::vector<int> numbersVector;
        double dequeTime;
        double vectorTime;

        //Vector functions
        std::vector<int> sortVector();
        std::vector<int> mergeInsert(std::vector<int> &numbers);
        
        //List functions
        std::deque<int> sortDeque();
        std::deque<int> mergeInsert(std::deque<int> &numbers);
        
        
        public:
        PmergeMe(char **numbersArray, int size);
        ~PmergeMe();
        PmergeMe(const PmergeMe &other);
        PmergeMe &operator=(const PmergeMe &other);
        class invalidInputException: public std::exception{
            public:
            virtual const char* what() const throw();
        };
        
        //Getters
        std::vector<int> getNumbersVector() const;
        std::deque<int> getNumbersDeque() const;
        double getVectorTime() const;
        double getDequeTime() const;
};

void mergeInsertBinaryInsertion(std::vector<int> &mainList, std::vector<int> &toInsert);
void mergeInsertBinaryInsertion(std::deque<int> &mainDeque, std::deque<int> &toInsert);
 
int validateInput(std::string number);