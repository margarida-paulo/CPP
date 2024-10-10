/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvalerio <mvalerio@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 17:59:00 by maggie            #+#    #+#             */
/*   Updated: 2024/10/10 12:00:50 by mvalerio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie{
	private:
	std::string name;

	public:
	void announce(void);
	Zombie(void);
	Zombie(std::string name);
	~Zombie(void);

};

void randomChump(std::string name);
Zombie* newZombie(std::string name);

#endif
