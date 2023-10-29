#include "Nombre.hpp"
#include <iostream>

int main()
{
	Nombre nb1 = Nombre( 1 );
	Nombre nb2 = new Nombre( 2 );
	
	std::cout << nb1.getNombre() << std::endl;
	std::cout << nb2.getNombre() << std::endl;
	
	Nombre* ptrNombre = creerNombre( 3 );
	
	if( ptrNombre != nullptr )
	{
		Nombre nb3 = *ptrNombre;
		std::cout << nb3.getNombre() << std::endl;
		delete ptrNombre;
	}
	
	Nombre* ptrNombre = creerNombre( 4 );
	
	if( ptrNombre != nullptr )
	{
		Nombre nb4 = *ptrNombre;
		std::cout << nb4.getNombre() << std::endl;
		delete ptrNombre;
	}
}
