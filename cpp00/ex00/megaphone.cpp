#include <iostream>
#include <string>

std::string charArrayToString(char *charArray)
{
	std::string finalString = "";
	for (int i = 0; charArray[i]; i++){
		finalString += charArray[i];
	}
	return finalString;
}

void toUpperCase(std::string &stringToConvert)
{
	for (size_t i = 0; i < stringToConvert.length(); i++)
	{
		stringToConvert[i] = static_cast<char>(toupper(stringToConvert[i]));
	}
}

int	main(int argc, char **argv){

	if (argc == 1){
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	} else {
		for (int i = 1; i < argc; i++) {
			std::string word = charArrayToString(argv[i]);
			toUpperCase(word);
			std::cout << word;
		}
		std::cout << std::endl;
	}
	return 0;
}
