#pragma once

#include <stack>
#include <iterator>
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

template<typename T, typename Container = std::deque<T> >
class MutantStack: public std::stack<T,Container> {
    public:
        MutantStack(): std::stack<T, Container>(){}
        ~MutantStack(){}
        MutantStack(const MutantStack &other): std::stack<T, Container>(other){}
        MutantStack &operator=(const MutantStack &other){
            if (this != &other){
                std::stack<T, Container>::operator=(other);
            }
            return this;
        }

    typedef typename Container::iterator iterator;
    typedef typename Container::const_iterator const_iterator;
    typedef typename Container::reverse_iterator reverse_iterator;
    typedef typename Container::const_reverse_iterator const_reverse_iterator;

    iterator begin(){return this->c.begin();}
    const_iterator begin() const {return this->c.begin();}
    iterator end(){return this->c.end();}
    const_iterator end() const {return this->c.end();}

    reverse_iterator rbegin(){return this->c.rbegin();}
    const_reverse_iterator rbegin() const {return this->c.rbegin();}
    reverse_iterator rend(){return this->c.rend();}
    const_reverse_iterator rend() const {return this->c.rend();}
};