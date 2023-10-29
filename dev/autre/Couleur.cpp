#include "Couleur.hpp"

// Constantes
static int const MAX_RGB_VALUE = 255;
static int const MIN_RGB_VALUE = 0;

// Constructeurs
Couleur::Couleur() : m_red(MIN_RGB_VALUE), m_green(MIN_RGB_VALUE), m_blue(MIN_RGB_VALUE) {}

Couleur::Couleur( int red, int green, int blue )
{
	m_red = Couleur::verifieValeurRGB( red );
	m_green = Couleur::verifieValeurRGB( green );
	m_blue = Couleur::verifieValeurRGB( blue );
}

// Accesseurs
int Couleur::getRed(){ return m_red; }
int Couleur::getGreen(){ return m_green; }
int Couleur::getBlue(){ return m_blue; }

// Setteurs
void Couleur::setRed( int red ){ m_red = Couleur::verifieValeurRGB( red ); }
void Couleur::setGreen( int green ){ m_green = Couleur::verifieValeurRGB( green ); }
void Couleur::setBlue( int blue ){ m_blue = Couleur::verifieValeurRGB( blue ); }

// Méthodes
int Couleur::verifieValeurRGB( int valeur )
{
	if( valeur > MAX_RGB_VALUE ){ return MAX_RGB_VALUE; }
	if( valeur < MIN_RGB_VALUE ){ return MIN_RGB_VALUE; }
	return valeur;
}
