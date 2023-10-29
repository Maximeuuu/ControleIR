#ifndef DEF_ACTION
#define DEF_ACTION

#include <string>

class Action
{
private:
	//attributs
	static int const c_NB_APP;
	static int s_currentApp;

	std::string m_name;
	int m_codeIR;
	std::string m_defaut;
	std::string m_app1;
	std::string m_app2;
	std::string m_app3;
	std::string m_app4;

public:
	//Constructeurs
	Action();
	Action( std::string name, int codeIR, std::string defaut, std::string app1, std::string app2, std::string app3, std::string app4 );

	//Accesseurs
	std::string getName();
	int getCodeIR();
	std::string getDefaut();
	std::string getApp( int num );

	//Méthodes
	static int getCurrentApp();
	static void setCurrentApp( int app );

	bool estEgal( int const& codeIR ) const;

	std::string getAction();
};

#endif
