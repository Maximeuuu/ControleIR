https://youtu.be/VLPj8ayqgY4?si=Vvs2_jtvB0IJRvRR&t=8263

ajouter un objet de type "ensKeyStroke"



# "main" (GereOutputData // ConfigurationMain)

# Outils - input (OutilsSaisie)
string demanderString( string txt )
{
	string ret;

	cout << txt << " : ";
	cin >> ret;
	cin.ignore();

	return ret;
}

# Outils port serie (Arduino)
ATTRIBUTS :
fstream serie
string port

string getSortieArduino( fstream serie& );
string getSortieIdentiqueArduino( fstream serie& )
{
	do
	{
		a = getSortieArduino( serie )
		b = getSortieArduino( serie )
	}
	while( a != b )

	return a;
}


# Fenetre 1 (GereSaisieTelecommande // OutilsTelecommande)

Application getAppData( fstream serie& )
{
	new Application();

	Application.setName( demanderString( "name" ) );
	....

	Application.setCodeIR( getSortieIdentiqueArduino( serie ) );
}

# Fenetre 2 (GereSaisieTelecommande // OutilsTelecommande)

Action getActionData( fstream serie&, vector<Application> ensApplication ) //ensApp pour avoir les noms
{

}

# Outils fichier (GestionnaireFichier)
Attributs :
fstream fichier;
string fichier
string location

nouveauFichier();
addAppToFile();
addActionToFile();
