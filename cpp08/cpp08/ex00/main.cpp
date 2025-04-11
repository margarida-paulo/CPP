#include <vector>
#include <iostream>
#include <string>

#include "easyfind.hpp"

int main(){
    //Create container
    std::vector<int> testContainer;
    testContainer.push_back(1);
    testContainer.push_back(2);
    testContainer.push_back(3);
    testContainer.push_back(4);
    testContainer.push_back(5);

    //Print container
    std::cout << "Test Container:" << std::endl;
    std::vector<int>::iterator it = testContainer.begin();
    while(it != testContainer.end()){
        std::cout << *it << std::endl;
        it++;
    }
    std::cout << std::endl;

    //Test easyfind
    if (easyfind(testContainer, 2) == testContainer.end())
        std::cout << "Number 2 was not found!" << std::endl;
    else
        std::cout << "Number 2 was found!" << std::endl;

    if (easyfind(testContainer, 5) == testContainer.end())
        std::cout << "Number 5 was not found!" << std::endl;
    else
        std::cout << "Number 5 was found!" << std::endl;

    if (easyfind(testContainer, 10) == testContainer.end())
        std::cout << "Number 10 was not found!" << std::endl;
    else
        std::cout << "Number 10 was found!" << std::endl;

    if (easyfind(testContainer, 15) == testContainer.end())
        std::cout << "Number 15 was not found!" << std::endl;
    else
        std::cout << "Number 15 was found!" << std::endl;

    if (easyfind(testContainer, 1) == testContainer.end())
        std::cout << "Number 1 was not found!" << std::endl;
    else
        std::cout << "Number 1 was found!" << std::endl;
}