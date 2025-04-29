/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvalerio <mvalerio@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 18:33:10 by maggie            #+#    #+#             */
/*   Updated: 2024/10/10 13:00:35 by mvalerio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_B
#define HUMAN_B

#include "Weapon.hpp"

class HumanB{

	private:
	std::string name;
	Weapon *weapon;

	public:
	HumanB(std::string name);
	~HumanB();
	void attack();
	void setWeapon(Weapon *weapon);
};

#endif
