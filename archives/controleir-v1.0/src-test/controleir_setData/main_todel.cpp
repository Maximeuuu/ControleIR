/*
* créer des méthodes pour les doublons
* creer une classe expès pour ce code ?
* tester
* compiler mdr
* mettre "." par défaut si vide
* mettre les constantes avec equivalence ("VK_ALT = 0x55555" )...
*/


/* IMPORTATIONS */
#include <string>
#include <iostream>
#include <fstream>
#include <vector>

/* ESPACE DE TRAVAIL */
using namespace std;

void completerFile( ofstream& file, string texte, bool aRetour );

/* MAIN */
int main()
{
	string const DATA_FOLDER = "./data/";
	fstream serialPort;
	string port;
	int nbApp, nbAction;
	string newDataFileName, codeIR1, codeIR2;
	ofstream newDataFile;

	string saisie;
	vector<string> ensNomApp;
	bool ajouterRaccourcis;


	cout << "Enregistrer les controles" << endl;


	/* Création du fichier */
	cout << "Fichier : " << DATA_FOLDER;
	cin >> newDataFileName;

	newDataFile.open( (DATA_FOLDER + newDataFileName) );

	if( !newDataFile )
	{
		cerr << "Erreur lors de l'ouverture du fichier " + DATA_FOLDER + newDataFileName << endl;
		return 1;
	}


	/* Connexion au port série */
	cout << "Port serie : ";
	cin >> port;

	serialPort.open( port, ios::out | ios::in );
	if( !serialPort.is_open() )
	{
		cerr << "Erreur lors de l'ouverture du port serie " << port << endl;
		return 1;
	}
	cout << "Connexion au port serie " << port << " reussie." << endl;

	serialPort.setf(std::ios::dec);
	cin.ignore();

	/* Ecriture dans le fichier */
	newDataFile << "https://learn.microsoft.com/en-us/windows/win32/inputdev/virtual-key-codes" << endl;
	completerFile( newDataFile, "Nom de la telecommande", true );
	completerFile( newDataFile, "Delay", true );


	newDataFile << endl;


	cout << "#Applications" << endl;
	newDataFile << "#Applications" << endl;
	newDataFile << "BUTTON\tNAME\tIR\tRGB" << endl;

	cout << "Nombre d'applications : ";
	cin >> nbApp;
	cin.ignore();

	for( int cpt=0; cpt<nbApp; cpt++ )
	{
		completerFile( newDataFile, "Nom bouton", false );

		cout << "Nom : ";
		cin >> saisie;
		cin.ignore();
		file << saisie;
		ensNomApp.push_back(saisie);

		completerFile( newDataFile, "Nom application", false );

		do
		{
			cout << "CodeIR (x2) : ";
			serialPort.ignore();
			serialPort >> codeIR1 >> codeIR2;
		}
		while( codeIR1 != codeIR2);
		cout << endl;
		newDataFile << codeIR1;

		completerFile( newDataFile, "Couleur LED", true );
	}


	newDataFile << endl;


	cout << "#Raccourcis" << endl;
	newDataFile << "#Raccourcis" << endl;

	newDataFile << "BUTTON\tIR\tKEY_DEFAUT"
	for( int cpt=0; cpt<ensNomApp.size(); cpt++ )
	{
		newDataFile << "\t" << ensNomApp[cpt];
	}
	newDataFile << endl;

	cout << "Nombre d'action : ";
	cin >> nbAction;
	cin.ignore();

	for( int cpt=0; cpt<nbAction; cpt++ )
	{
		completerFile( newDataFile, "BUTTON", false );

		do
		{
			cout << "CodeIR (x2) : ";
			serialPort.ignore();
			serialPort >> codeIR1 >> codeIR2;
		}
		while( codeIR1 != codeIR2);
		cout << endl;
		newDataFile << codeIR1;

		cout << "Ajouter les raccourcis (yes/no) : ";
		cin >> saisie;
		cin.ignore();
		ajouterRaccourcis = (saisie == "yes");

		if( ajouterRaccourcis )
		{
			completerFile( newDataFile, "KEY_DEFAUT (rien : \".\")", false );
			for( int cptApp=0; cptApp<ensNomApp.size(); cptApp++ )
			{
				completerFile( newDataFile, ensNomApp[cpt], false );
			}
		}
	}

	newDataFile.close();
}

void completerFile( ofstream& file, string texte, bool aRetour )
{
	string saisie;

	cout << texte << " : ";
	getline(cin, saisie);
	file << saisie;

	if( aRetour ){ file << endl; }
	else{ file << "\t"; }
}
