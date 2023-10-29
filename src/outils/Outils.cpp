#include "Outils.hpp"

std::vector<std::string> Outils::decomposerTexte( const std::string& text, char separator )
{
	std::vector<std::string> decomposition;
	std::istringstream iss(text);
	std::string membre;

	while( getline(iss, membre, separator) )
	{
		decomposition.push_back( membre );
	}

	return decomposition;
}

int Outils::convertirStringToInt( const std::string& str )
{
	std::istringstream iss(str);
	int entier;

	if( !str.empty() && str[0] == '0' && str.size() > 1 && str[1] == 'x' )
	{
		iss >> std::hex >> entier;
	}
	else
	{
		iss >> std::dec >> entier;
	}

	return entier;
}

std::vector<int> Outils::convertirVectorStringToVectorInt( std::vector<std::string>& vectorStr )
{
	std::vector<int> vectorInt;

    for( const std::string& str : vectorStr)
	{
        int entier = convertirStringToInt(str);
        vectorInt.push_back(entier);
    }

    return vectorInt;
}
