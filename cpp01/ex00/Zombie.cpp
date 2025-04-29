/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maggie <maggie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 17:58:23 by maggie            #+#    #+#             */
/*   Updated: 2024/08/04 17:58:24 by maggie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void Zombie::announce( void ){
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie( std::string name ){
	this->name = name;
	std::cout << "Zombie " << name << " was created!" << std::endl;
}

Zombie::~Zombie( void ){
	std::cout << "Zombie " << this->name << " was destroyed!" << std::endl;
}