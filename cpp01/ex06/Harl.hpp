/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maggie <maggie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 17:02:55 by maggie            #+#    #+#             */
/*   Updated: 2024/08/07 13:38:38 by maggie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>

#define NUMFUNCTIONS 4

class Harl;
typedef void (Harl::*HarlFunctions)();

enum {
	DEBUG,
	INFO,
	WARNING,
	ERROR,
};

class Harl {
	private:
	void debug( void );
	void info( void );
	void warning( void );
	void error( void );


	public:
	Harl();
	~Harl();
	void complain( std::string level );
	static HarlFunctions complaint[NUMFUNCTIONS];
	static std::string complaintType[NUMFUNCTIONS];
};


#endif