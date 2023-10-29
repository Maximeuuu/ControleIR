#ifndef OUTILS_HPP
#define OUTILS_HPP

#include <string>
#include <vector>
#include <sstream>

class Outils
{
public:
	static std::vector<std::string> decomposerTexte( const std::string& text, char separator );
	static int convertirStringToInt( const std::string& str );
	static std::vector<int> convertirVectorStringToVectorInt( std::vector<std::string>& vectorStr );
};

#endif // OUTILS_HPP
