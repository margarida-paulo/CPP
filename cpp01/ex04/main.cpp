/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maggie <maggie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 19:52:46 by maggie            #+#    #+#             */
/*   Updated: 2024/08/06 16:17:45 by maggie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"

void	findAndReplace(std::string& buffer, std::string s1, std::string s2)
{
	size_t	pos = 0;
	while ((pos = buffer.find(s1, pos)) != std::string::npos){
		buffer.erase(pos, s1.length());
		buffer.insert(pos, s2);
		pos += s2.length();
	}
}

std::string fileIntoString(std::fstream &inFile){
	std::string fileContents((std::istreambuf_iterator<char>(inFile)),
                             std::istreambuf_iterator<char>());
    return fileContents;
}

int main(int argc, char **argv){
	if (argc != 4){
		std::cout << "Incorrect number of arguments" << std::endl;
		return (1);
	}

	std::string filename(argv[1]);
	std::string s1(argv[2]);
	std::string s2(argv[3]);

	std::fstream inputFile;
	inputFile.open(filename.c_str(), std::ios::in);
	if (!inputFile){
		std::cout << "Failed to open the input file " << filename << std::endl;
		return (2);
	}

	std::string buffer = fileIntoString(inputFile);

	if (!buffer.empty()){
		findAndReplace(buffer, s1, s2);
	} else {
		std::cout << "File " << filename << " is empty. Replace file not created." << std::endl;
		inputFile.close();
		return (3);
	}
	
	std::string finalFileName(filename + ".replace");
	std::fstream outputFile;
	outputFile.open(finalFileName.c_str(), std::ios::out);
	if (!outputFile){
		std::cout << "Failed to create the output file " << finalFileName << std::endl;
		return (2);
	}
	
	outputFile << buffer;
	
	std::cout << std::endl << "Replacements made successfully. Check your file in " << finalFileName << std::endl;
	
	inputFile.close();
	outputFile.close();
}