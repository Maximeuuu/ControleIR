#include "OutilsTelecommande.hpp"

// Méthodes
Application OutilsTelecommande::inputAppData( Arduino arduino )
{
	std::string btnName;
	std::string name;
	std::string codeIR;
	std::string color;

	btnName = demanderString( "Nom bouton" );
	name = demanderString( "Nom application" );

	cout << "CodeIR (x2) : ";
	codeIR = arduino.getMatchingData();
	cout << endl;

	color = demanderString( "Couleur LED (format : 'R,G,B')" );

	return Application( btnName, name, codeIR, color );
}

Action OutilsTelecommande::inputActionData( Arduino arduino, std::vector<Application> ensApplication )
{
	std::string btnName;
	std::string codeIR;
	std::string keyDefaut;
	std::string keyApp;
	Action actionTmp;

	btnName = demanderString( "Nom bouton" );

	cout << "CodeIR (x2) : ";
	codeIR = arduino.getMatchingData();
	cout << endl;

	keyDefaut = demanderString( "Touche par defaut (si rien : \".\")" )

	actionTmp = Action( btnName, codeIR, keyDefaut );

	for( int cptApp=0; cptApp<ensApplication.size(); cptApp++ )
	{
		keyApp = demanderString( "Touche "+ensApplication[cptApp]) );
		actionTmp.addCommandeApp( keyApp );
	}

	return actionTmp;
}
