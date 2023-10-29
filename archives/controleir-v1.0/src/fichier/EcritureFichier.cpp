#include "EcritureFichier.hpp"

//Constructeurs
EcritureFichier::EcritureFichier( const std::string& name, const std::string& folder )
{
	m_name = name;
	m_folder = folder;
	m_file.open( folder + name );
}

EcritureFichier::EcritureFichier( const std::string& name, const std::string& folder, std::ofstream flux )
{
	m_name = name;
	m_folder = folder;
	m_file = flux;
}

//Destructeurs
EcritureFichier::~EcritureFichier()
{
	m_file.close();
}

//Usineur
EcritureFichier* EcritureFichier::creerEcritureFichier( const std::string& name, const std::string& folder )
{
	std::ofstream flux;

	flux.open( folder + name );

	if( !flux )
	{
		cerr << "Erreur lors de l'ouverture du fichier " + folder + name << endl;
		return nullptr;
	}

	return new EcritureFichier( name, folder, flux );
}

//Accesseurs
std::string EcritureFichier::getName()
{
	return m_name;
}

std::string EcritureFichier::getFolder()
{
	return m_folder;
}

// Méthodes
void EcritureFichier::addLine( std::string ligne )
{
	m_file << ligne << endl;
}
