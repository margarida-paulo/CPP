/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maggie <maggie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 17:58:12 by maggie            #+#    #+#             */
/*   Updated: 2024/08/04 17:58:13 by maggie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main ( void ){
	randomChump("Pouya");
	Zombie *maggie = newZombie("Maggie");
	maggie->announce();
	delete maggie;
}