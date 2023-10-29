#include "Action.hpp"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream> //converstion de string en int
#include <windows.h>
#include <fstream>

using namespace std;

string appToRGB( int indice );
vector<int> decomposeText(const string& text, char separator);
bool ligneEstUnCommentaire( const string& ligne );
void fichierInvalide();


int main()
{
	/*Variables*/
	char const SEPARATEUR = '+';

	string const DATA_FOLDER = "./data/";
	string const DATA_FILE = "controlestest.data"; // à modifier pour laisser l'utilisateur saisir / chosir parmis les fichiers disponibles
	int const NB_APP(5);
	string const ensApp[] = { "DEFAUT", "APP1", "APP2", "APP3", "APP4" };

	vector<Action> ensAction;

	string receivedHexa;
	string strCommande;


	/*Serial Port*/
	fstream serialPort;
    serialPort.open("COM5", ios::out | ios::in);  // Modifier le chemin du port série si nécessaire

	if (!serialPort.is_open())
	{
		std::cerr << "Erreur lors de l'ouverture du port serie" << std::endl;
		return 1;
	}

	serialPort.setf(std::ios::dec);
	std::cout << "Port serie ouvert" << std::endl;
	serialPort << appToRGB(0) << endl; //reinitialisation de la couleur de la led

	/*Ajout des datas*/
	ifstream dataFile( (DATA_FOLDER + DATA_FILE).c_str() );

	if( dataFile )
	{
		string ligneFichier;
		string sIgnore;
		string remoteName;
		int delaiAction;

		getline( dataFile, remoteName );
		getline( dataFile, ligneFichier ); istringstream( ligneFichier ) >> delaiAction; //conversion en entier
		getline( dataFile, sIgnore );

		getline( dataFile, ligneFichier ); if( !ligneEstUnCommentaire( ligneFichier ) ){ fichierInvalide(); }
		getline( dataFile, sIgnore );
		while( getline( dataFile, ligneFichier ) & !ligneFichier.empty() )
		{
			istringstream iss(line);
			Application app;
		}



		dataFile.close();
	}

	/*
	//a remplacer par une lecture d'un document.data
	ensAction.push_back( Action( "OnOff", "A90", "0x12+0x73", "", "", "", "") );
	ensAction.push_back( Action( "Rouge", "338", "APP1", "", "", "", "") );
	ensAction.push_back( Action( "Vert", "B38", "APP2", "", "", "", "") );
	ensAction.push_back( Action( "Jaune", "738", "APP3", "", "", "", "") );
	ensAction.push_back( Action( "Bleu", "F38", "APP4", "", "", "", "") );
	ensAction.push_back( Action( "Coeur", "37EE", "", "", "0x12+0x10+0x42", "", "") );*/


	/*Boucle d'intéraction*/
	while( true )
	{
		//récupère la sortie IR de l'arduino
		getline(serialPort, receivedHexa);

		//Test toutes les touches enregistrées
		for( int cpt=0; cpt<ensAction.size(); cpt++ )
		{
			// Si le code IR recu correspond à celui d'une des touches enregistrées
			if( ensAction[cpt].estEgal(receivedHexa) )
			{
				strCommande = ensAction[cpt].getAction();

				/*cout << strCommande << endl;*/

				// On regarde si la commande correspond à un changement d' "application"
				bool appAChange = false;
				for( int cptApp=0; cptApp<NB_APP; cptApp++ )
				{
					if( strCommande == ensApp[cptApp] )
					{
						appAChange = true;
						Action::setCurrentApp( cptApp );
						serialPort << appToRGB(cptApp) << endl; //ajoute un changement de led via le port série
						break;
					}
				}

				// S'il n'y a pas de commande valide, on arrête
				if( appAChange || strCommande=="" ){ break; }

				// décompose la commande pour pouvoir l'utiliser comme raccourcis clavier
				vector<int> combinaisons = decomposeText(strCommande, SEPARATEUR);

				/*if( combinaisons.size() == 0 || combinaisons[0] == 0 ){ break; }*/ //Je pense qu'il n'y a plus besoin de ce test

/* A METTRE DANS UNE METHODE "useKeystroke( vector<int> v );" */

				//On active chaque touches
				for( int cptTouche=0; cptTouche<combinaisons.size(); cptTouche++ )
				{
					/*cout << "appuie " << combinaisons[cptTouche] << endl;*/
					keybd_event( combinaisons[cptTouche], 0, 0, 0 );
				}

				//On relache chaque touches
				for( int cptTouche=0; cptTouche<combinaisons.size(); cptTouche++ )
				{
					/*cout << "relachement " << combinaisons.size()-cptTouche << " - " << combinaisons[cptTouche] << endl;*/
					keybd_event( combinaisons[cptTouche], 0, KEYEVENTF_KEYUP, 0 ); // Relâchement des touches
				}

/* FIN DE LA METHODE */

				break;
			}
		}
	}

	serialPort.close();
	return 0;
}

bool ligneEstUnCommentaire( const string& ligne )
{
	return ligneFichier.find("#") != string::npos
}

void fichierInvalide()
{
	cout << "Format de fichier non valide" << endl;
	return 1;
}

string appToRGB( int indice ) //à remplacer par un tableau { {"APP1", "255,0,0"}, ... } qui permettrait d'enlever cette méthode + rendre plus adaptatif
{
	switch( indice )
	{
		case 1:
			return "255,0,0";
		case 2:
			return "0,255,0";
		case 3:
			return "255,255,0";
		case 4:
			return "0,0,255";
		default:
			return "0,0,0";
	}
}

vector<int> decomposeText(const string& text, char separator)
{
    vector<int> result; // Vecteur pour stocker les valeurs séparées
    string currentValue; // Chaîne temporaire pour stocker la valeur en cours de construction

    for (char c : text) {
        if (c == separator) {
			// Utilisation de std::istringstream pour convertir la chaîne en entier
			istringstream iss(currentValue);
			int valeurHexa;
			iss >> hex >> valeurHexa;

            result.push_back(valeurHexa); // Ajouter la valeur actuelle au vecteur
            currentValue.clear(); // Réinitialiser la valeur en cours
        } else {
            currentValue += c; // Ajouter le caractère à la valeur en cours
        }
    }

	// Utilisation de std::istringstream pour convertir la chaîne en entier
	istringstream iss(currentValue);
	int valeurHexa;
	iss >> hex >> valeurHexa;

    result.push_back(valeurHexa); // Ajouter la dernière valeur au vecteur

    return result;
}
