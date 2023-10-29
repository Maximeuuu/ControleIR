#include "Action.hpp"

// Constructeurs
Action::Action( std::string buttonName, std::string codeIR, std::string commandeDefaut )
{
	m_buttonName = buttonName;
	m_codeIR = codeIR;
	m_commandeDefaut = commandeDefaut;
	m_ensCommandeApp = std::vector<std::string>();
}

Action::Action( std::string buttonName, std::string codeIR, std::string commandeDefaut, std::vector<std::string> m_ensCommandeApp )
{
	m_buttonName = buttonName;
	m_codeIR = codeIR;
	m_commandeDefaut = commandeDefaut;
	m_ensCommandeApp = m_ensCommandeApp;
}

// Accesseurs
std::string Action::getButtonName()				{ return m_buttonName; }
std::string Action::getCodeIR()					{ return m_codeIR; }
std::string Action::getCommandeDefaut()			{ return m_commandeDefaut; }
std::string Action::getCommandeApp( int index )	{ return m_ensCommandeApp[index]; }

// Modifieurs
void Action::addCommandeApp( std::string commandeApp ){ m_ensCommandeApp.push_back(commandeApp); }

// Méthodes
std::string Action::getCommandeActive( int indexApp )
{
	if( indexApp < 0 ){ return m_commandeDefaut; }

	std::string commande;

	commande = m_ensCommandeApp[indexApp];
	if( commande != "" && commande != "." ){ return commande; } //faudra trouver un moyen de n'avoir que "" ou jsp après

	return m_commandeDefaut;
}

std::string Action::toString()
{ //à remplacer par une géante liste où on ajoute tous les attributs et après on parcours un for, au lieu de répéter le code 4 fois
	std::string sep = "/t";
	std::string sRet;
	std::string buttonName, codeIR, commandeDefaut, commandeApp;

	buttonName = m_buttonName;
	if( buttonName == "" ){ buttonName = "."; }

	codeIR = m_codeIR;
	if( codeIR == "" ){ codeIR = "."; }

	commandeDefaut = m_commandeDefaut;
	if( commandeDefaut == "" ){ commandeDefaut = "."; }

	sRet = buttonName + sep + codeIR + sep + commandeDefaut;

	for( int cpt=0; cpt<m_ensCommandeApp.size(); cpt++ )
	{
		commandeApp = m_ensCommandeApp[cpt];
		if( commandeApp == "" ){ commandeApp = "."; }
		sRet += sep + commandeApp;
	}

	return sRet;
}
