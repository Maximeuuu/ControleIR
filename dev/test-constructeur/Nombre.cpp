#include "Nombre.hpp"

//Constructeurs
Nombre::Nombre( int val )
{
	m_val = val;
}

//Destructeurs
Nombre::~Nombre()
{
	std::cout << "supprimé" << std::endl;
}

//Usineur
Nombre* Nombre::creerNombre( int val )
{
	if( val == 0 )
	{
		return nullptr;
	}
	return new Nombre( val );
}

//Accesseurs
int Nombre::getNombre() const
{
	return m_val;
}
