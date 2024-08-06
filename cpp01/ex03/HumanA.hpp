/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maggie <maggie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 18:33:10 by maggie            #+#    #+#             */
/*   Updated: 2024/08/04 19:35:38 by maggie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_A
#define HUMAN_A

#include "Weapon.hpp"

class HumanA{

	public:
	HumanA(std::string name, Weapon &weapon);
	~HumanA();
	std::string name;
	Weapon &weapon;
	void attack();
	void setWeapon(Weapon &weapon);
};

#endif