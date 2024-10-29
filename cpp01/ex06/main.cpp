/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvalerio <mvalerio@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 17:43:39 by maggie            #+#    #+#             */
/*   Updated: 2024/10/29 09:47:54 by mvalerio         ###   ########.fr       */
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
			john.complain("DEBUG");
			// fall through
		case (INFO):
			john.complain("INFO");
			// fall through
		case (WARNING):
			john.complain("WARNING");
			// fall through
		case (ERROR):
			john.complain("ERROR");
			break;
		default :
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}

}
