#include "../include/Brain.hpp"

Brain::Brain(){
	std::cout << "Brain was created with the default constructor." << std::endl;
	ideas = new std::string[100];
}

Brain::Brain(Brain &other){
	std::cout << "Brain was created with the copy constructor." << std::endl;
	ideas = other.ideas;
}

Brain &Brain::operator=(const Brain &other){
	std::cout << "Brain was initialized with attributes of another brain." << std::endl;
	ideas = other.ideas;
	return *this;
}

Brain::~Brain(){
	delete[] ideas;
	std::cout << "Brain was destroyed!" << std::endl;
}

void Brain::setIdea(std::string idea, int index){
	ideas[index] = idea;
}

std::string Brain::getIdea(int index){
	return ideas[index];
}
