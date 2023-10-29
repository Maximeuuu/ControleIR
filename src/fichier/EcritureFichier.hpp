#ifndef ECRITUREFICHIER_HPP
#define ECRITUREFICHIER_HPP

#include "../telecommande/Application.hpp"
#include "../telecommande/Action.hpp"
#include <string>
#include <fstream>
#include <iostream>

class EcritureFichier
{
private:
	//Attributs
	std::string m_name;
	std::string m_folder;
	std::ofstream m_file;

	//Constructeurs
	EcritureFichier( const std::string& name, const std::string& folder="./" );

public:
	//Destructeurs
	~EcritureFichier();

	//Usineur
	EcritureFichier* creerEcritureFichier( const std::string& name, const std::string& folder );

	//Accesseurs
	std::string getName() const;
	std::string getFolder() const;
	bool isOpen() const;

	// Méthodes
	void addLine( std::string ligne );
};

#endif //ECRITUREFICHIER_HPP
