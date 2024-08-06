/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maggie <maggie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 17:58:01 by maggie            #+#    #+#             */
/*   Updated: 2024/08/04 17:58:03 by maggie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie {
	private:
	std::string name;
	
	public:
	void announce();
	Zombie(std::string name);
	Zombie();
	~Zombie( void );
	void setName(std::string name);
};

Zombie* zombieHorde( int N, std::string name );

#endif