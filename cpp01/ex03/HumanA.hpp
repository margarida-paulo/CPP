/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvalerio <mvalerio@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 18:33:10 by maggie            #+#    #+#             */
/*   Updated: 2024/10/10 12:50:30 by mvalerio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_A
#define HUMAN_A

#include "Weapon.hpp"

class HumanA{

	private:
	std::string name;
	Weapon &weapon;

	public:
	HumanA(std::string name, Weapon &weapon);
	~HumanA();
	void attack();
	void setWeapon(Weapon &weapon);
};

#endif
