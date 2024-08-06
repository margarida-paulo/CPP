/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maggie <maggie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 18:33:10 by maggie            #+#    #+#             */
/*   Updated: 2024/08/04 19:43:22 by maggie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_B
#define HUMAN_B

#include "Weapon.hpp"

class HumanB{
	public:
	HumanB();
	HumanB(std::string name);
	~HumanB();
	std::string name;
	Weapon *weapon;	
	void attack();
	void setWeapon(Weapon &weapon);
};

#endif