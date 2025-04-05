#include "Array.hpp"

int main(){
    std::cout << "Create empty array: emptyArray" << std::endl;
    Array<std::string> emptyArray;

    std::cout << "emptyArray size = " << emptyArray.size() << std::endl << std::endl;

    std::cout << "Create array with 2 positions: filledArray" << std::endl;
    Array<std::string> filledArray(2);

    std::cout << "filledArray size = " << filledArray.size() << std::endl << std::endl;

    try{
        std::cout << "filledArray[0] = \"Hello\"" << std::endl;
        filledArray[0] = "Hello";
        std::cout << "filledArray position 0: " << filledArray[0] << std::endl << std::endl;
        std::cout << "filledArray[1] = \"World\"" << std::endl;
        filledArray[1] = "World";
        std::cout << "filledArray position 1: " << filledArray[1] << std::endl << std::endl;
        std::cout << "filledArray[2] = \"I am Bob\"" << std::endl;
        filledArray[2] = "I am Bob";
    } catch (Array<std::string>::ExceptionOutOfBounds &e){
        std::cout << e.what() << std::endl << std::endl;
    }


    std::cout << "Copy filled array to empty array" << std::endl;

    emptyArray = filledArray;

    std::cout << "emptyArray size = " << emptyArray.size() << std::endl;
    std::cout << "emptyArray position 0: " << emptyArray[0] << std::endl;
    std::cout << "emptyArray position 1: " << emptyArray[1] << std::endl << std::endl;   

    std::cout << "Using copy construtor to make array: copyArray" << std::endl;

    Array <std::string> copyArray(emptyArray);
    std::cout << "copyArray size = " << copyArray.size() << std::endl;
    std::cout << "copyArray position 0: " << copyArray[0] << std::endl;
    std::cout << "copyArray position 1: " << copyArray[1] << std::endl << std::endl;  

}