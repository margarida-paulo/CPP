#pragma once

#include <vector>
#include <exception>
#include <algorithm>
#include <iostream>

// Cores padrão (ANSI Escape Codes)
#define RESET       "\033[0m"
#define BLACK       "\033[30m"
#define RED         "\033[31m"
#define GREEN       "\033[32m"
#define YELLOW      "\033[33m"
#define BLUE        "\033[34m"
#define MAGENTA     "\033[35m"
#define CYAN        "\033[36m"
#define WHITE       "\033[37m"

// Cores em negrito
#define BBLACK      "\033[1;30m"
#define BRED        "\033[1;31m"
#define BGREEN      "\033[1;32m"
#define BYELLOW     "\033[1;33m"
#define BBLUE       "\033[1;34m"
#define BMAGENTA    "\033[1;35m"
#define BCYAN       "\033[1;36m"
#define BWHITE      "\033[1;37m"

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

        unsigned int getSize() const;
        void printList() const;
};