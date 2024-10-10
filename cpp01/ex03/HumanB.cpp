/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvalerio <mvalerio@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 18:42:10 by maggie            #+#    #+#             */
/*   Updated: 2024/10/10 13:00:27 by mvalerio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

void HumanB::attack(){
this->weapon != NULL ?
	std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl :
	std::cout << this->name << " doesn't have a weapon, attack failed :(" << std::endl;
}

HumanB::HumanB(std::string name) : name(name){
	std::cout << "HumanB " << name << " was created." << std::endl;
}

HumanB::~HumanB(){
	std::cout << "A HumanB was destroyed." << std::endl;
}

void HumanB::setWeapon(Weapon *weapon){
	this->weapon = weapon;
}
