#include "PmergeMe.hpp"

bool isSorted(std::vector<int> numbers){
    for (size_t i = 0; i < numbers.size() - 1; i++){
        if (numbers[i] > numbers[i+1]){
            std::cout << "Problem numbers: " << numbers[i] << " and " << numbers[i+1] << std::endl;
            return false;
        }
    }
    return true;
}

bool isSorted(std::deque<int> numbers){
    for (size_t i = 0; i < numbers.size() - 1; i++){
        if (numbers[i] > numbers[i+1]){
            std::cout << "Problem numbers: " << numbers[i] << " and " << numbers[i+1] << std::endl;
            return false;
        }
    }
    return true;
}

//Before: 3 5 9 7 4
//After: 3 4 5 7 9
//Time to process a range of 5 elements with std::[..] : 0.00031 us
//Time to process a range of 5 elements with std::[..] : 0.00014 us

int main(int argc, char **argv){
    if (argc <= 2){
        std::cerr << "Usage: ./PmergeMe <list> <of> <integers> <...> (minimum 2 integers)" << std::endl;
        return 1;
    }

    for (int i = 1; i < argc; i++){
        try{
            validateInput(std::string(argv[i]));
        } catch (PmergeMe::invalidInputException &e){
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }


    //Print the list before sorting
    std::cout << "Before: ";
    for (int i = 0; i < argc; i++)
        std::cout << argv[i] << " "; 

    PmergeMe numbers = PmergeMe(argv, argc);
    std::vector<int> sortedVector = numbers.getNumbersVector();
    
/*     //Print the list after sorting
    std::cout << std::endl << "After: ";
    for (size_t i = 0; i < sortedDeque.size(); i++){
        std::cout << sortedDeque[i] << " ";
    }
    std::cout << std::endl;
    if (isSorted(sortedDeque))
        std::cout << "YEYYYY!" << std::endl;
    else
        std::cout << "OH NOOOOOO!!!" << std::endl; */

    //Print the list after sorting
    std::cout << std::endl << "After: ";
    for (size_t i = 0; i < sortedVector.size(); i++){
        std::cout << sortedVector[i] << " ";
    }
    std::cout << std::endl;
/*     if (isSorted(sortedVector))
        std::cout << "YEYYYY!" << std::endl;
    else
        std::cout << "OH NOOOOOO!!!" << std::endl; */

    //Print the times
    std::cout << "Time to process a range of " << sortedVector.size() << " elements with std::vector: " << numbers.getVectorTime() << " us" << std::endl;
    std::cout << "Time to process a range of " << sortedVector.size() << " elements with std::deque: " << numbers.getDequeTime() << " us" << std::endl;

}