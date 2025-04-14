#pragma once

#include <vector>
#include <exception>
#include <algorithm>
#include <iostream>

class Span{
    private:
        unsigned int size;
        std::vector<int> data;
        Span();

    public:
        ~Span();
        Span(const Span &other);
        Span &operator=(const Span &other);

        Span(unsigned int n);

        void addNumber(int n);

        class SpanOverflowException : public std::exception{
            virtual const char* what() const throw();
        };

        class NotEnoughElements : public std::exception{
            virtual const char* what() const throw();
        };

        int shortestSpan() const;

        int longestSpan() const;

        void fillSpan(std::vector<int>::iterator beginning, std::vector<int>::iterator end);
};