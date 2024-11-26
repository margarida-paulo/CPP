#include "include/Animal.hpp"
#include "include/Dog.hpp"
#include "include/Cat.hpp"
#include "include/WrongAnimal.hpp"
#include "include/WrongCat.hpp"

int main()
{
	Animal *animais[10];
	Animal test;
	for (int i = 0; i < 10; i++){
		if (i % 2 == 0)
			animais[i] = new Cat();
		else
			animais[i] = new Dog();
	}

	for (int i = 0; i < 2; i++)
		animais[i]->makeSound();

	//Test deep copies
	Dog doggo = *(dynamic_cast<Dog *>(animais[3]));
	std::cout << "Doggo is a deep copy of animais[3]" << std::endl;
	doggo.getBrain()->setIdea("I wanna be a Human...", 5);
	std::cout << "Changed doggo's idea 5, animais[3] should remain the same" << std::endl;
	std::cout << "doggo's idea 5:" << doggo.getBrain()->getIdea(5) << std::endl;
	std::cout << "animais[3]'s idea 5:" << dynamic_cast<Dog *>(animais[3])->getBrain()->getIdea(5) << std::endl;
	for (int i = 0; i < 10; i++)
		delete animais[i];
}
