#include "Array.hpp"

template <class T>
const char *Array<T>::ExceptionOutOfBounds::what() const throw() {
    return "Error: Trying to access a position that is out of bounds!";
}

template <class T>
Array<T>::Array(): _array(new T[0]()), _size(0){}

template <class T>
Array<T>::Array(unsigned int n): _array(new T[n]()), _size(n){
}

template <class T>
Array<T>::Array(Array &other): _array(new T[other._size]()), _size(other._size){
    if (&other == this)
        return;
    for (unsigned int i = 0; i < other._size; i++)
        _array[i] = other[i];
}

template <class T>
Array<T> &Array<T>::operator=(Array &other){
    if (this->_size != other._size){
        delete[] _array;
        _array = new T[other._size];
        this->_size = other._size;
    }
    for (unsigned int i = 0; i < other._size; i++)
        _array[i] = other._array[i];
    return *this;
}

template <class T>
Array<T>::~Array(){
    delete[] _array;
}

template <class T>
T &Array<T>::operator[](unsigned int position){
    if (position >= _size)
        throw ExceptionOutOfBounds();
    return _array[position];
}

template <class T>
unsigned int Array<T>::size(){
    return _size;
}