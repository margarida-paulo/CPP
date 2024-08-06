/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maggie <maggie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 17:43:39 by maggie            #+#    #+#             */
/*   Updated: 2024/08/07 13:51:12 by maggie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv){
	if (argc != 2){
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		return (0);
	}	
	std::string complaint(argv[1]);
	Harl john;
	int currentSaying = NUMFUNCTIONS;
	for (size_t i = 0; i < NUMFUNCTIONS; i++){
		if (complaint == Harl::complaintType[i])
			currentSaying = i;
	}
	switch (currentSaying){
		case (DEBUG):
			john.complain("Debug");
			// fall through
		case (INFO):
			john.complain("Info");
			// fall through
		case (WARNING):
			john.complain("Warning");
			// fall through
		case (ERROR):
			john.complain("Error");
			break;
		default :
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
	
}