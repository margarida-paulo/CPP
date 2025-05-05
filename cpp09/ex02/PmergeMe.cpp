#include "PmergeMe.hpp"

//Containers FORBIDDEN: Map and Stack

PmergeMe::PmergeMe(char **numbersArray, int size){

    clock_t startVector = clock();
    //Handle the vector
    for (int i = 1; i < size; i++){
        numbersVector.push_back(atoi(numbersArray[i]));
    }
    numbersVector = this->sortVector();
    clock_t endVector = clock();
    vectorTime = static_cast<double>(endVector - startVector) / CLOCKS_PER_SEC * 1e6; // Convert to microseconds
    
    clock_t startDeque = clock();  
    //Handle the deque
    for (int i = 1; i < size; i++){
        numbersDeque.push_back(atoi(numbersArray[i]));
    }
    numbersDeque = this->sortDeque();
    clock_t endDeque = clock();
    dequeTime = static_cast<double>(endDeque - startDeque) / CLOCKS_PER_SEC * 1e6; // Convert to microseconds
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

/****************************
 Getter functions
 ****************************/

std::vector<int> PmergeMe::getNumbersVector() const{
    return numbersVector;
}

std::deque<int> PmergeMe::getNumbersDeque() const{
    return numbersDeque;
}

double PmergeMe::getVectorTime() const{
    return vectorTime;
}

double PmergeMe::getDequeTime() const{
    return dequeTime;
}

/****************************
 Vector handling functions
 ****************************/


std::vector<int> PmergeMe::sortVector(){
    return mergeInsert(numbersVector);
}

std::vector<int> PmergeMe::mergeInsert(std::vector<int> &numbers){
    //Implement with Vector
    
    std::vector<int> a;
    std::vector<int> b;
    
    //Base case (if the list has 2 or less numbers)
    if (numbers.size() <= 2){
        if (numbers.size() == 2 && numbers.at(0) > numbers.at(1)){
            int temp = numbers.at(0);
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
            b.push_back(numbers[i]); //If there is an odd amount of numbers, put the leftover in a
        }
    }

   
    
    //Build main and pend. Main has the first element of b and all the a's. Pend has the rest of the elements of b
    std::vector<int> main;
    std::vector<int> pend;
    if (!b.empty())
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

    main = mergeInsert(main); // Recursive call to the algorithm with the main
    

    //TODO Binary insertion from b in a
    mergeInsertBinaryInsertion(main, pend);

    if (DEBUG){ //Print lists a, b, main and pend
        std::cout << std::endl << "-------------------" << std::endl;
        std::cout << "AFTER BINARY INSERTION: " << std::endl;
        std::cout << std::endl << "Main: " << std::endl;
            for (size_t i = 0; i < main.size(); i++)
                std::cout << main.at(i) << std::endl;
    }
    
    return main;

}

void mergeInsertBinaryInsertion(std::vector<int> &mainList, std::vector<int> &toInsert){
    int k = 1;
    size_t previous_t = 1;
    std::vector<size_t> jacobsthal_numbers; //Stores the jacobstal sequence
    jacobsthal_numbers.push_back(1);
    std::vector<bool> inserted(toInsert.size()); //Stores which numbers were inserted already
    
    //Calculate the order of insertion of the elements to insert (based on jacobsthal numbers)
    while(jacobsthal_numbers.size() <= toInsert.size() + 1){
        size_t current_t = (1 << k) - previous_t; // Bit-shifting is precise for powers of 2
        for (size_t i = 0; current_t - i > 0 && current_t - i > previous_t && jacobsthal_numbers.size() <= toInsert.size() + 1 ;i++){
            jacobsthal_numbers.push_back(current_t - i);
        }
        previous_t = current_t;
        k++;
    }
    if (DEBUG){
        for (size_t i = 0; i < jacobsthal_numbers.size(); i++)
            std::cout << "t[" << i << "]: " << jacobsthal_numbers[i] << std::endl;
    }
    // Binary insert until the jacobsthal_number is bigger than the size of toInsert, and insert the leftover by the order they came in.
    size_t numbersInserted;
    for (numbersInserted = 0; numbersInserted < toInsert.size(); numbersInserted++){
        if (jacobsthal_numbers[numbersInserted] < toInsert.size()){
            std::vector<int>::iterator it = std::lower_bound(mainList.begin(), mainList.end(), toInsert[jacobsthal_numbers[numbersInserted] - 1]);
            mainList.insert(it, toInsert[jacobsthal_numbers[numbersInserted] - 1]);
            if (DEBUG)
            std::cout << "Inserting number " << toInsert[jacobsthal_numbers[numbersInserted] - 1] << " with index " << jacobsthal_numbers[numbersInserted] << std::endl;
            inserted[numbersInserted] = true; 
        } else
        break;
    }
    for (size_t i = 0; numbersInserted < toInsert.size(); i++){
        if (!inserted[i]){
            std::vector<int>::iterator it = std::lower_bound(mainList.begin(), mainList.end(), toInsert[i]);
            mainList.insert(it, toInsert[i]);
            inserted[i] = true;
            numbersInserted++;
        }
    }  
}


/****************************
 Deque handling functions
 ****************************/


 std::deque<int> PmergeMe::sortDeque(){
    return mergeInsert(numbersDeque);
}

std::deque<int> PmergeMe::mergeInsert(std::deque<int> &numbers){
    //Implement with Deque
    
    std::deque<int> a;
    std::deque<int> b;
    
    //Base case (if the list has 2 or less numbers)
    if (numbers.size() <= 2){
        if (numbers.size() == 2 && numbers.at(0) > numbers.at(1)){
            int temp = numbers.at(0);
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
            b.push_back(numbers[i]); //If there is an odd amount of numbers, put the leftover in a
        }
    }

   
    
    //Build main and pend. Main has the first element of b and all the a's. Pend has the rest of the elements of b
    std::deque<int> main;
    std::deque<int> pend;
    if (!b.empty())
        main.push_back(b.at(0));
    for (size_t i = 0; i < a.size(); i++){
        main.push_back(a.at(i));
    }
    for (size_t i = 1; i < b.size(); i++){
        pend.push_back(b.at(i));
    }

    if (DEBUG){ //Print lists a, b, main and pend
        std::cout << std::endl << "-------------------" << std::endl;
        std::cout << "Deque a: " << std::endl;
        for (size_t i = 0; i < a.size(); i++)
            std::cout << a.at(i) << std::endl;
        std::cout << std::endl << "Deque b: " << std::endl;
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

    main = mergeInsert(main); // Recursive call to the algorithm with the main
    

    //TODO Binary insertion from b in a
    mergeInsertBinaryInsertion(main, pend);

    if (DEBUG){ //Print lists a, b, main and pend
        std::cout << std::endl << "-------------------" << std::endl;
        std::cout << "AFTER BINARY INSERTION: " << std::endl;
        std::cout << std::endl << "Main: " << std::endl;
            for (size_t i = 0; i < main.size(); i++)
                std::cout << main.at(i) << std::endl;
    }
    
    return main;

}

void mergeInsertBinaryInsertion(std::deque<int> &mainList, std::deque<int> &toInsert){
    int k = 1;
    size_t previous_t = 1;
    std::deque<size_t> jacobsthal_numbers; //Stores the jacobstal sequence
    jacobsthal_numbers.push_back(1);
    std::deque<bool> inserted(toInsert.size()); //Stores which numbers were inserted already
    
    //Calculate the order of insertion of the elements to insert (based on jacobsthal numbers)
    while(jacobsthal_numbers.size() <= toInsert.size() + 1){
        size_t current_t = (1 << k) - previous_t; // Bit-shifting is precise for powers of 2
        for (size_t i = 0; current_t - i > 0 && current_t - i > previous_t && jacobsthal_numbers.size() <= toInsert.size() + 1 ;i++){
            jacobsthal_numbers.push_back(current_t - i);
        }
        previous_t = current_t;
        k++;
    }
    if (DEBUG){
        for (size_t i = 0; i < jacobsthal_numbers.size(); i++)
            std::cout << "t[" << i << "]: " << jacobsthal_numbers[i] << std::endl;
    }
    // Binary insert until the jacobsthal_number is bigger than the size of toInsert, and insert the leftover by the order they came in.
    size_t numbersInserted;
    for (numbersInserted = 0; numbersInserted < toInsert.size(); numbersInserted++){
        if (jacobsthal_numbers[numbersInserted] < toInsert.size()){
            std::deque<int>::iterator it = std::lower_bound(mainList.begin(), mainList.end(), toInsert[jacobsthal_numbers[numbersInserted] - 1]);
            mainList.insert(it, toInsert[jacobsthal_numbers[numbersInserted] - 1]);
            if (DEBUG)
            std::cout << "Inserting number " << toInsert[jacobsthal_numbers[numbersInserted] - 1] << " with index " << jacobsthal_numbers[numbersInserted] << std::endl;
            inserted[numbersInserted] = true; 
        } else
        break;
    }
    for (size_t i = 0; numbersInserted < toInsert.size(); i++){
        if (!inserted[i]){
            std::deque<int>::iterator it = std::lower_bound(mainList.begin(), mainList.end(), toInsert[i]);
            mainList.insert(it, toInsert[i]);
            inserted[i] = true;
            numbersInserted++;
        }
    }  
}



/****************************
 Helper functions
 ****************************/


int validateInput(std::string numberString){
    int integer;

    std::istringstream numberStream(numberString);
    if ((numberStream >> integer) && numberStream.eof())
    return integer;
    throw PmergeMe::invalidInputException();
}