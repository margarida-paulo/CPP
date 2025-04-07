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

        Array(const unsigned int n);

        Array(const Array &other);

        Array &operator=(const Array &other);

        ~Array();

        T &operator[](const unsigned int position);

        const T &operator[](const unsigned int position) const;

        unsigned int size() const;
};

#include "Array.tpp"

#endif