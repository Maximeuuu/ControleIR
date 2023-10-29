#ifndef DEF_NOMBRE
#define DEF_NOMBRE

#include <iostream>

class Nombre
{
private:
	int m_val;
	
public:
	//Constructeurs
	Nombre( int val );

	//Destructeurs
	~Nombre();

	//Usineur
	static Nombre* creerNombre( int val );

	//Accesseurs
	int getNombre() const;
};

#endif

