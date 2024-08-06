/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maggie <maggie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 18:23:34 by maggie            #+#    #+#             */
/*   Updated: 2024/08/04 19:10:20 by maggie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

std::string &Weapon::getType(){
	return this->type;
}

void Weapon::setType(std::string newType){
	this->type = newType;
}

Weapon::Weapon(){
	std::cout << "Unknown weapon was created" << std::endl;
}

Weapon::Weapon(std::string weaponType){
	this->setType(weaponType);
	std::cout << "Weapon " << this->type << " was created" << std::endl;
}

Weapon::~Weapon(){
	std::cout << "Weapon " << this->type << " was destroyed" << std::endl;
}