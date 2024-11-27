/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvalerio <mvalerio@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 19:52:46 by maggie            #+#    #+#             */
/*   Updated: 2024/11/27 15:50:14 by mvalerio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"

int main(int argc, char **argv){
	if (argc != 4){
		std::cout << "Incorrect number of arguments." << std::endl;
		std::cout << "Correct usage:" << std::endl;
		std::cout << "./Replace [FILE_NAME] [STRING_TO_REPLACE] [REPLACEMENT_STRING]" << std::endl;
		return (EXIT_FAILURE);
	}

	std::string filename(argv[1]);
	std::string s1(argv[2]);
	std::string s2(argv[3]);

	std::ifstream inputFile(filename.c_str());
	if (!inputFile.is_open()){
		std::cerr << "Failed to open the input file " << filename << "." << std::endl;
		return (EXIT_FAILURE);
	}
	if (inputFile.peek() == EOF){
		std::cerr << "The input file " << filename << " is empty, so there is nothing to replace." << std::endl;
		return (EXIT_FAILURE);
	}

	std::string finalFileName(filename + ".replace");
	std::ofstream outputFile(finalFileName.c_str());
	if (!outputFile.is_open()){
		std::cerr << "Failed to create the output file " << finalFileName << "." << std::endl;
		return (EXIT_FAILURE);
	}

	std::string buffer;
	bool	hasChanged = false;
	while (getline(inputFile, buffer)){
		if (!buffer.empty()){
			if (findAndReplace(buffer, s1, s2))
				hasChanged = true;
			outputFile << buffer;
		}
		if (!inputFile.eof()) {
			outputFile << '\n';
		}
	}

	if (hasChanged == true)
		std::cout << "Replacements made successfully. Check your file in " << finalFileName << "." << std::endl;
	else
		std::cout << "No replacements to make. The file " << finalFileName << " is just a copy of the original file." << std::endl;

	inputFile.close();
	outputFile.close();
}
