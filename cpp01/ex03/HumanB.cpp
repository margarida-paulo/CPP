/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maggie <maggie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 18:42:10 by maggie            #+#    #+#             */
/*   Updated: 2024/08/04 19:44:53 by maggie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

void HumanB::attack(){
	std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
}

HumanB::HumanB(std::string name) : name(name){
	std::cout << "HumanB " << name << " was created." << std::endl;
}

HumanB::~HumanB(){
	std::cout << "A HumanB was destroyed." << std::endl;
}

void HumanB::setWeapon(Weapon &weapon){
	*(this->weapon) = weapon;
}