#include "EcritureFichier.hpp"

//Constructeurs
EcritureFichier::EcritureFichier( const std::string& name, const std::string& folder )
{
	m_name = name;
	m_folder = folder;
	m_file.open( folder + name );
}

//Destructeurs
EcritureFichier::~EcritureFichier()
{
	m_file.close();
}

//Usineur
EcritureFichier* EcritureFichier::creerEcritureFichier( const std::string& name, const std::string& folder )
{
	EcritureFichier* fichier = new EcritureFichier( name, folder );

	if( !fichier->isOpen() )
	{
		std::cout << "Erreur lors de l'ouverture du fichier " + folder + name << std::endl;
		delete fichier;
		return nullptr;
	}

	std::cout << "Ouverture du fichier " << folder << name << " réussie." << std::endl;
	return fichier;
}

//Accesseurs
std::string EcritureFichier::getName() const
{
	return m_name;
}

std::string EcritureFichier::getFolder() const
{
	return m_folder;
}

bool EcritureFichier::isOpen() const
{
	return m_file.is_open();
}

// Méthodes
void EcritureFichier::addLine( std::string ligne )
{
	m_file << ligne << std::endl;
}
