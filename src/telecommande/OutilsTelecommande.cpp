#include "OutilsTelecommande.hpp"

// Méthodes
Application OutilsTelecommande::inputAppData( Arduino arduino )
{
	std::string btnName;
	std::string name;
	std::string codeIR;
	std::string color;

	btnName = OutilsSaisie::demanderString( "Nom bouton" );
	name = OutilsSaisie::demanderString( "Nom application" );

	std::cout << "CodeIR (x2) : ";
	codeIR = arduino.getMatchingData();
	std::cout << std::endl;

	color = OutilsSaisie::demanderString( "Couleur LED (format : 'R,G,B')" );

	return Application( btnName, name, codeIR, color );
}

Action OutilsTelecommande::inputActionData( Arduino arduino, std::vector<Application> ensApplication )
{
	std::string btnName;
	std::string codeIR;
	std::string keyDefaut;
	std::string keyApp;

	btnName = OutilsSaisie::demanderString( "Nom bouton" );

	std::cout << "CodeIR (x2) : ";
	codeIR = arduino.getMatchingData();
	std::cout << std::endl;

	keyDefaut = OutilsSaisie::demanderString( "Touche par defaut (si rien : \".\")" );

	Action actionTmp = Action( btnName, codeIR, keyDefaut );

	for( int cptApp=0; cptApp<ensApplication.size(); cptApp++ )
	{
		keyApp = OutilsSaisie::demanderString( "Touche "+ensApplication[cptApp].getName() );
		actionTmp.addCommandeApp( keyApp );
	}

	return actionTmp;
}
