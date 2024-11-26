#include "include/Animal.hpp"
#include "include/Dog.hpp"
#include "include/Cat.hpp"
#include "include/WrongAnimal.hpp"
#include "include/WrongCat.hpp"

int main()
{
	Animal *animais[2];
	for (int i = 0; i < 2; i++){
		if (i % 2 == 0)
			animais[i] = new Cat();
		else
			animais[i] = new Dog();
	}

	for (int i = 0; i < 2; i++)
		animais[i]->makeSound();

	for (int i = 0; i < 2; i++)
		delete animais[i];
}
