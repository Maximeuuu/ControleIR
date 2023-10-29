/* IMPORTATIONS */
#include "ControleMain.hpp"

/* ESPACE DE TRAVAIL */
using namespace std;

int main() //à remplacer par ControleMain
{
	/* CONSTANTES */
	string const DATA_FOLDER = "../data/";
	string const DEFAULT_LED_COLOR = "255,0,0";


	/* VARIABLES */
	string userPort;
	Arduino* ptrArduino(nullptr); //on ne peut pas utiliser autre chose qu'un pointeur

	string userDataFile;
	ifstream dataFile;
	Telecommande telecommande;

	string dataArduino="0";
	int tmpIndex;
	string strCommande;

	/* Connexion arduino */
	do
	{
		userPort = OutilsSaisie::demanderString( "Port (format : \"COMx\") > " );
		ptrArduino = Arduino::createArduino( userPort );
	}
	while( ptrArduino == nullptr );
	ptrArduino->sendData( DEFAULT_LED_COLOR );


	/* Ouverture du fichier */
	do
	{
		userDataFile = OutilsSaisie::demanderString( "Fichier (format : \"name.data\") > " + DATA_FOLDER );
		dataFile.open( (DATA_FOLDER + userDataFile).c_str() );
		if( !dataFile )
		{
			cout << "Erreur lors de l'ouverture du fichier " + DATA_FOLDER + userDataFile << endl;
		}
	}
	while( !dataFile );
	telecommande = LectureData::initTelecommandeWithData( dataFile );
	dataFile.close();

	cout << "Interraction via : " << endl;
	cout << "\t" << telecommande.toString() << endl;


	/* Boucle d'interraction */
	while( dataArduino != "" ) //permet d'arrêter le programme lorsque l'arduino est déconnecté
	{
		dataArduino = ptrArduino->readData();
		cout << "recu : " << dataArduino << endl;
		tmpIndex = telecommande.getIndexApplicationByCodeIR( dataArduino );
		bool codeEstApp = (tmpIndex != -1);
		if( codeEstApp )
		{
			telecommande.setCurrentAppIndex( tmpIndex );
			ptrArduino->sendData( telecommande.getCurrentApplication().getColor() ); //ajoute un changement de led via le port série
			cout << "couleur : " << telecommande.getCurrentApplication().getColor() << endl;
			continue;
		}

		tmpIndex = telecommande.getIndexActionByCodeIR( dataArduino );
		bool codeEstAction = (tmpIndex != -1);
		if( !codeEstAction ){ continue; }

		strCommande = telecommande.getAction(tmpIndex).getCommandeActive( telecommande.getCurrentAppIndex() );
		useKeyStrokeWithCommande( strCommande );
	}

}


void useKeyStrokeWithCommande( string commande )
{
	char const VALUE_SEPARATOR = '+';

	bool estCommandeVide = (commande == "" || commande == ".");
	if( estCommandeVide ){ return; }

	// décompose la commande pour pouvoir l'utiliser comme raccourcis clavier
	vector<string> ensCommandeStr = Outils::decomposerTexte(commande, VALUE_SEPARATOR);
	vector<int> ensCommandeInt = Outils::convertirVectorStringToVectorInt( ensCommandeStr );

	// Active les touches
	pressKeystroke( ensCommandeInt );
}


void pressKeystroke( vector<int> combinaisons )
{
	//On active chaque touches
	for( int cptTouche=0; cptTouche<combinaisons.size(); cptTouche++ )
	{
		if( combinaisons[cptTouche] != 0 )
		{
			cout << "+" << combinaisons[cptTouche] << endl;
			keybd_event( combinaisons[cptTouche], 0, 0, 0 );
		}
	}

	//On relache chaque touches
	for( int cptTouche=0; cptTouche<combinaisons.size(); cptTouche++ )
	{
		if( combinaisons[cptTouche] != 0 )
		{
			//cout << "-" << combinaisons[cptTouche] << endl;
			keybd_event( combinaisons[cptTouche], 0, KEYEVENTF_KEYUP, 0 );
		}
	}
}
