#include "OutilsSaisie.hpp"

std::string OutilsSaisie::demanderString( std::string txt )
{
	std::string sRet;

	std::cout << txt + " : ";
	getline( std::cin, sRet );

	return sRet;
}
