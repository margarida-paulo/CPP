#include "iter.hpp"

void sumOne(int &number){
    number++;
}

int main(){
    int array[] = {1,2,3,4};
    std::cout << "Original array:" << std::endl;
    iter(array, 4, print);
    std::cout << std::endl << "Array after summing one to each element:" << std::endl;
    iter(array, 4, sumOne);
    iter(array, 4, print);
}