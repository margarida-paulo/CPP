/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvalerio <mvalerio@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 19:52:46 by maggie            #+#    #+#             */
/*   Updated: 2024/10/10 13:54:50 by mvalerio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"

int main(int argc, char **argv){
	if (argc != 4){
		std::cout << "Incorrect number of arguments" << std::endl;
		return (EXIT_FAILURE);
	}

	std::string filename(argv[1]);
	std::string s1(argv[2]);
	std::string s2(argv[3]);

	std::ifstream inputFile(filename.c_str());
	if (!inputFile.is_open()){
		std::cerr << "Failed to open the input file " << filename << std::endl;
		return (EXIT_FAILURE);
	}

	std::string finalFileName(filename + ".replace");
	std::ofstream outputFile(finalFileName.c_str());
	if (!outputFile.is_open()){
		std::cerr << "Failed to create the output file " << finalFileName << std::endl;
		return (EXIT_FAILURE);
	}

	std::string buffer;
	while (getline(inputFile, buffer)){
		if (!buffer.empty()){
			findAndReplace(buffer, s1, s2);
			outputFile << buffer;
		}
		if (!inputFile.eof()) {
			outputFile << '\n';
		}
	}

	std::cout << std::endl << "Replacements made successfully. Check your file in " << finalFileName << std::endl;

	inputFile.close();
	outputFile.close();
}
