/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvalerio <mvalerio@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 17:02:55 by maggie            #+#    #+#             */
/*   Updated: 2024/10/29 09:43:44 by mvalerio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>

#define NUMFUNCTIONS 4

class Harl;
typedef void (Harl::*HarlFunctions)();

class Harl {
	private:
	void debug( void );
	void info( void );
	void warning( void );
	void error( void );
	static HarlFunctions complaint[NUMFUNCTIONS];
	static std::string complaintType[NUMFUNCTIONS];

	public:
	Harl();
	~Harl();
	void complain( std::string level );

};


#endif
