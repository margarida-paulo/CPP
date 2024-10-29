/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvalerio <mvalerio@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 17:07:02 by maggie            #+#    #+#             */
/*   Updated: 2024/10/29 09:41:46 by mvalerio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

// These are the statics with the functions of Harl. This makes it so that if
// we want to add more functions to Harl, we can just add them here.

std::string Harl::complaintType[NUMFUNCTIONS] = {"DEBUG", "INFO", "WARNING", "ERROR"};
HarlFunctions Harl::complaint[NUMFUNCTIONS] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

Harl::Harl(){
	std::cout << "Harl was created" << std::endl;
}

Harl::~Harl(){
	std::cout << "Harl was destroyed" << std::endl;
}

void Harl::debug( void ){
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info( void ){
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning( void ){
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error( void ){
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}


void Harl::complain( std::string level ){
	for (size_t i = 0; i < sizeof(complaintType) / sizeof(complaintType[0]); i++){
		if (complaintType[i] == level)
			(this->*complaint[i])();
	}
}
