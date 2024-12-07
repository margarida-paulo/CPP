#include "include/Animal.hpp"
#include "include/Dog.hpp"
#include "include/Cat.hpp"
#include "include/WrongAnimal.hpp"
#include "include/WrongCat.hpp"

#define ARRAY_SIZE 4

int main()
{
	std::cout << "---------------------------------------------------------------------------------------" << std::endl;
	std::cout << "TESTING ANIMAL CLASS: CREATE " << ARRAY_SIZE << " ANIMALS, HALF DOGS AND HALF CATS, AND A BRAIN FOR EACH." << std::endl;
	std::cout << "---------------------------------------------------------------------------------------" << std::endl << std::endl;
	Animal *animais[ARRAY_SIZE];
	for (int i = 0; i < ARRAY_SIZE; i++){
		if (i % 2 == 0)
			animais[i] = new Cat();
		else
			animais[i] = new Dog();
	}

	for (int i = 0; i < ARRAY_SIZE; i++)
		animais[i]->makeSound();

	std::cout << std::endl << "------------------------------------------" << std::endl;
	std::cout << "TESTING ANIMAL CLASS: " << ARRAY_SIZE << " DELETES EXPECTED" << std::endl;
	std::cout << "------------------------------------------" << std::endl << std::endl;
	for (int i = 0; i < ARRAY_SIZE; i++)
		delete animais[i];

	// Type is an abstract class, so it can't be instantiated. This will not compile.
	// Animal littleBaby;
}
