/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maggie <maggie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 17:57:38 by maggie            #+#    #+#             */
/*   Updated: 2024/08/04 18:17:34 by maggie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(){
	std::string hello = "HI THIS IS BRAIN";
	std::string *stringPTR = &hello;
	std::string &stringREF = hello;
	
	std::cout << &hello << std::endl;
	std::cout << stringPTR << std::endl;
	std::cout << &stringREF << std::endl;

	std::cout << hello << std::endl;
	std::cout << *stringPTR << std::endl;
	std::cout << stringREF << std::endl;
}