#include "Span.hpp"

Span::~Span(){}

Span::Span(const Span &other):size(other.size), data(other.data){}

Span &Span::operator=(const Span &other){
    if (this != &other){
        data = other.data;
        size = other.size;
    }
    return *this;
}

Span::Span(unsigned int n): size(n){}

void Span::addNumber(int n){
    data.push_back(n);
}

const char* Span::SpanOverflowException::what() const throw(){
    return "Span size exceeded";
}

int Span::shortestSpan() const{
    std::vector<int> sortedData = data;
    std::sort(sortedData.begin(), sortedData.end());
    if (size == 1 || size == 0)
        return 0;
    unsigned int shortestSpan = sortedData[1] - sortedData[0];
    for (unsigned int i = 2; i < size; i++){
        shortestSpan = std::min(shortestSpan, (unsigned int)(sortedData[i] - sortedData[i-1]));
    }
    return shortestSpan;
}
        
int Span::longestSpan() const{
    if (size == 1 || size == 0)
        return 0;
    return *std::max_element(data.begin(), data.end()) - *std::min_element(data.begin(), data.end());    
}

void Span::fillSpan(std::vector<int>::iterator beginning, std::vector<int>::iterator end){
    unsigned int rangeSize = std::distance(beginning, end);
    if (rangeSize + data.size() > size){
        throw SpanOverflowException();
    }
    data.insert(data.end(), beginning, end);
}