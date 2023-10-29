#ifndef DEF_TELECOMMANDE
#define DEF_TELECOMMANDE

#include "Application.hpp"
#include "Action.hpp"
#include <string>
#include <vector>

class Telecommande
{
private:
	// Attributs
	std::string m_name;
	int m_delais;
	std::vector<Application> m_ensApplication;
	std::vector<Action> m_ensAction;
	int m_currentAppIndex;

public:
	// Constructeurs
	Telecommande();
	Telecommande( std::string name, int delais, std::vector<Application> ensApplication, std::vector<Action> ensAction );
	Telecommande( std::string name, int delais );

	// Accesseurs
	std::string getName();
	int getDelais();
	Application getApplication( int index );
	Action getAction( int index );
	int getCurrentAppIndex();
	Application getCurrentApplication();
	int getNbApplication();
	int getNbAction();

	// Setteurs
	void setCurrentAppIndex( int app );
	void setCurrentApp( Application app );

	// Modifieurs
	void addApplication( Application app );
	void addAction( Action action );

	// Méthodes
	int getIndexApplicationByCodeIR( std::string strCodeIR );
	int getIndexActionByCodeIR( std::string strCodeIR );

	Application getApplicationByCodeIR( std::string strCodeIR ); //possiblement inutile et remplacé par une autre méthode
	Action getActionByCodeIR( std::string strCodeIR ); //possiblement inutile et remplacé par une autre méthode

	std::string toString();
};

// Opérateurs
/*std::ostream& operator<<(std::ostream& os, const Telecommande& t);*/

#endif //DEF_TELECOMMANDE
