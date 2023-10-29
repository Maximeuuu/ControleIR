#ifndef DEF_ACTION
#define DEF_ACTION

#include <string>
#include <vector>

class Action
{
private:
	//Attributs
	std::string m_buttonName;
	std::string m_codeIR;
	std::string m_commandeDefaut;
	std::vector<std::string> m_ensCommandeApp;

public:
	//Constructeurs
	Action( std::string buttonName, std::string codeIR, std::string commandeDefaut );
	Action( std::string buttonName, std::string codeIR, std::string commandeDefaut, std::vector<std::string> m_ensCommandeApp );

	//Accesseurs
	std::string getButtonName();
	std::string getCodeIR();
	std::string getCommandeDefaut();
	std::string getCommandeApp( int index );

	// Modifieurs
	void addCommandeApp( std::string commandeApp );

	// Méthodes
	std::string getCommandeActive( int indexApp = -1 );
	std::string toString();
};

#endif //DEF_ACTION
