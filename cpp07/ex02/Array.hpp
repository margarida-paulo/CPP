#ifndef ARRAY_HPP

#define ARRAY_HPP

#include <iostream>
#include <string>
#include <exception>

template <class T>
class Array{
    private:
        T *_array;
        unsigned int _size;

    public:
        class ExceptionOutOfBounds: public std::exception{
            public:
                virtual const char* what() const throw();
        };
        Array();

        Array(unsigned int n);

        Array(Array &other);

        Array &operator=(Array &other);

        ~Array();

        T &operator[](unsigned int position);

        unsigned int size();
};

#include "Array.tpp"

#endif