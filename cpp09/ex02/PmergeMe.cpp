#include "PmergeMe.hpp"

//Containers FORBIDDEN: Map and Stack

PmergeMe::PmergeMe(char **numbersArray, int size){
    for (int i = 1; i < size; i++){
        numbersVector.push_back(atoi(numbersArray[i]));
        numbersList.push_back(atoi(numbersArray[i]));
    }
}

std::vector<int> PmergeMe::mergeInsertVector(std::vector<int> numbers){
    //Implement with Vector
    
    std::vector<int> a;
    std::vector<int> b;

    //Base case (if the list has 2 or less numbers)
    if (numbers.size() <= 2){
        if (numbers.at(0) > numbers.at(1)){
            int temp = a.at(0);
            numbers.at(0) = numbers.at(1);
            numbers.at(1) = temp;
        }
        return numbers;
    }

    //Recursive case (if the list has 3 or more numbers)
    for (size_t i = 0; i < numbers.size(); i++){
    
        if (i + 1 < numbers.size()){
            b.push_back(std::min(numbers[i], numbers[i+1])); //Put the smallest number per pair in b
            a.push_back(std::max(numbers[i], numbers[i+1])); //Put the biggest number per pair in a
            i++;
        } else {
            a.push_back(numbers[i]); //If there is an odd amount of numbers, put the leftover in a
        }
    }

    
    a = mergeInsertVector(a); //Recursive call to the algorithm
    
    //Build main and pend. Main has the first element of b and all the a's. Pend has the rest of the elements of b
    std::vector<int> main;
    std::vector<int> pend;
    main.push_back(b.at(0));
    for (size_t i = 0; i < a.size(); i++){
        main.push_back(a.at(i));
    }
    for (size_t i = 1; i < b.size(); i++){
        pend.push_back(b.at(i));
    }
    
    
    if (DEBUG){ //Print lists a, b, main and pend
        std::cout << std::endl << "-------------------" << std::endl;
        std::cout << "Vector a: " << std::endl;
        for (size_t i = 0; i < a.size(); i++)
            std::cout << a.at(i) << std::endl;
        std::cout << std::endl << "Vector b: " << std::endl;
            for (size_t i = 0; i < b.size(); i++)
                std::cout << b.at(i) << std::endl;

        std::cout << std::endl << "Main: " << std::endl;
            for (size_t i = 0; i < main.size(); i++)
                std::cout << main.at(i) << std::endl;

        std::cout << std::endl << "Pend: " << std::endl;
            for (size_t i = 0; i < pend.size(); i++)
                std::cout << pend.at(i) << std::endl;
        std::cout << "-------------------" << std::endl;
    }

    //TODO Binary insertion from b in a
    
    return numbers;

}

std::vector<int> PmergeMe::sortVector(){
    return mergeInsertVector(numbersVector);
}

PmergeMe::~PmergeMe(){}
PmergeMe::PmergeMe(const PmergeMe &other){
    (void) other;
    //TODO copy attributes if they exist
}
PmergeMe &PmergeMe::operator=(const PmergeMe &other){
    (void) other;
    //TODO copy attributes if they exist
    return *this;
}

const char* PmergeMe::invalidInputException::what() const throw(){
    return "Invalid input";
}

int validateInput(std::string numberString){
    int integer;

    std::istringstream numberStream(numberString);
    if ((numberStream >> integer) && numberStream.eof())
        return integer;
    throw PmergeMe::invalidInputException();
}