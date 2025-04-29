/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maggie <maggie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 17:57:54 by maggie            #+#    #+#             */
/*   Updated: 2024/08/04 17:57:57 by maggie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void Zombie::announce(){
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie(std::string name){
	this->name = name;
	std::cout << "Zombie " << name << " was created." << std::endl;
}

Zombie::Zombie(){
	std::cout << "Zombie was created." << std::endl;
}

Zombie::~Zombie( void ){
	std::cout << "Zombie " << name << " was destroyed." << std::endl;
}

void Zombie::setName(std::string name){
	this->name = name;
}
