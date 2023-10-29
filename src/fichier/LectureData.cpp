#include "LectureData.hpp"

Telecommande LectureData::initTelecommandeWithData( std::ifstream& fichier )
{
	/* CONSTANTES */
	std::string const TITLE_APPLICATION = "#Applications";
	std::string const TITLE_RACCOURCIS = "#Raccourcis";

	/* VARIABLES */
	Telecommande tmpTelecommande;
	std::string tmpRemoteName;
	int tmpDelaiAction;

	bool inApplicationsSection;
	bool inShortcutsSection;
	std::string tmpLigne;

	std::string tmpButtonName;
	std::string tmpName;
	std::string tmpCodeIR;
	std::string tmpCodeRGB;
	std::string tmpCommandeDefaut;
	std::string tmpCommandeApp;

	/* INITIALISATION */
	inApplicationsSection = false;
	inShortcutsSection = false;

	/* DEBUT DE LA LECTURE */
	getline( fichier, tmpLigne );
	getline( fichier, tmpRemoteName );
	getline( fichier, tmpLigne );
	tmpDelaiAction = Outils::convertirStringToInt( tmpLigne );

	tmpTelecommande = Telecommande( tmpRemoteName, tmpDelaiAction );

	while( getline( fichier, tmpLigne ) )
	{
		if( tmpLigne == TITLE_APPLICATION )
		{
			inApplicationsSection = true;
			inShortcutsSection = false;
			getline( fichier, tmpLigne );
			continue;
		}

		if( tmpLigne == TITLE_RACCOURCIS )
		{
			inApplicationsSection = false;
			inShortcutsSection = true;
			getline( fichier, tmpLigne );
			continue;
		}

		if( inApplicationsSection )
		{
			std::istringstream iss( tmpLigne );
			if (iss >> tmpButtonName >> tmpName >> tmpCodeIR >> tmpCodeRGB )
			{
				tmpTelecommande.addApplication( Application(tmpButtonName, tmpName, tmpCodeIR, tmpCodeRGB) );
			}
		}

		if( inShortcutsSection )
		{
			std::istringstream iss( tmpLigne );
			if( iss >> tmpButtonName >> tmpCodeIR >> tmpCommandeDefaut )
			{
				Action tmpAction = Action( tmpButtonName, tmpCodeIR, tmpCommandeDefaut );
				while( iss >> tmpCommandeApp )
				{
					tmpAction.addCommandeApp( tmpCommandeApp );
				}
				tmpTelecommande.addAction( tmpAction );
			}
		}
	}

	return tmpTelecommande;
}
