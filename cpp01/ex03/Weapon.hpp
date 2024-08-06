/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maggie <maggie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 18:23:49 by maggie            #+#    #+#             */
/*   Updated: 2024/08/04 19:07:50 by maggie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon{
	private:
	std::string type;

	public:
	std::string &getType();
	void setType(std::string newType);
	Weapon();
	Weapon(std::string weaponType);
	~Weapon();
};

#endif