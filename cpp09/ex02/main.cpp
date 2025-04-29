#include "PmergeMe.hpp"

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

    PmergeMe numbers = PmergeMe(argv, argc);
    numbers.sortVector();


}