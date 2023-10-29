#ifndef ECRITUREFICHIER_HPP
#define ECRITUREFICHIER_HPP

#include "../objets/Application.hpp"
#include "../objets/Action.hpp"
#include <string>
#include <fstream>

class EcritureFichier
{
private:
	//Attributs
	std::string m_name;
	std::string m_folder;
	std::ofstream m_file;

public:
	//Constructeurs
	EcritureFichier( const std::string& name, const std::string& folder="./" );
	EcritureFichier( const std::string& name, const std::string& folder="./", std::ofstream flux );

	//Destructeurs
	~EcritureFichier();

	//Usineur
	EcritureFichier* creerEcritureFichier( const std::string& name, const std::string& folder );

	//Accesseurs
	std::string getName();
	std::string getFolder();

	// Méthodes
	void addLine( std::string ligne );
};

#endif //ECRITUREFICHIER_HPP
