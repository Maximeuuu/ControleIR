#ifndef DEF_COULEUR
#define DEF_COULEUR

class Couleur
{
private:
	//Constantes
	static int const MAX_RGB_VALUE;
	static int const MIN_RGB_VALUE;

	//Attributs
	int m_red;
	int m_green;
	int m_blue;

public:
	//Constructeurs
	Couleur();
	Couleur( int red, int green, int blue );

	//Accesseurs
	int getRed();
	int getGreen();
	int getBlue();

	//Méthodes
	void setRed( int red );
	void setGreen( int green );
	void setBlue( int blue );

	static int verifieValeurRGB( int valeur );
};

#endif
