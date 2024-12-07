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

	std::cout << std::endl << "---------------------------------" << std::endl;
	std::cout << "TESTING ANIMAL CLASS: DEEP COPY" << std::endl;
	std::cout << "---------------------------------" << std::endl << std::endl;
	//Test deep copies
	Dog doggo = *(dynamic_cast<Dog *>(animais[3]));
	std::cout << "Doggo is a deep copy of animais[3]" << std::endl;
	doggo.getBrain()->setIdea("I wanna be a Human...", 5);
	std::cout << "Changed doggo's idea 5, animais[3] should remain the same" << std::endl;
	std::cout << "doggo's idea 5:" << doggo.getBrain()->getIdea(5) << std::endl;
	std::cout << "animais[3]'s idea 5:" << dynamic_cast<Dog *>(animais[3])->getBrain()->getIdea(5) << std::endl;
	std::cout << std::endl << "------------------------------------------" << std::endl;
	std::cout << "TESTING ANIMAL CLASS: " << ARRAY_SIZE + 1 << " DELETES EXPECTED" << std::endl;
	std::cout << "------------------------------------------" << std::endl << std::endl;
	for (int i = 0; i < ARRAY_SIZE; i++)
		delete animais[i];

}
