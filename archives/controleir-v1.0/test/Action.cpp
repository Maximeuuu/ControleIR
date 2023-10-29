#include <string>
#include "Action.hpp"

int const Action::c_NB_APP = 4;
int Action::s_currentApp = 0;

// Constructeurs
Action::Action() : m_name(""), m_codeIR(0), m_defaut(""), m_app1(""), m_app2(""), m_app3(""), m_app4("") {}

Action::Action( std::string name, int codeIR, std::string defaut, std::string app1, std::string app2, std::string app3, std::string app4 )
{
	m_name = name;
	m_codeIR = codeIR;
	m_defaut = defaut;
	m_app1 = app1;
	m_app2 = app2;
	m_app3 = app3;
	m_app4 = app4;
}

// Accesseurs
std::string Action::getName(){ return m_name; }
int Action::getCodeIR(){ return m_codeIR; }
std::string Action::getDefaut(){ return m_defaut; }
std::string Action::getApp( int num )
{ //à remplacer par un tableau plus tard
	switch( num )
	{
		case 1:
			return m_app1;
			break;
		case 2:
			return m_app2;
			break;
		case 3:
			return m_app3;
			break;
		case 4:
			return m_app4;
			break;
	}

	return " ";
}

// Méthodes
int Action::getCurrentApp(){ return s_currentApp; }
void Action::setCurrentApp( int app ){ s_currentApp = app; }

bool Action::estEgal( int const& codeIR ) const
{
	return m_codeIR == codeIR;
}

std::string Action::getAction()
{
	std::string codeAction;
	codeAction = Action::getApp( s_currentApp );

	if( codeAction != " " && codeAction != "" )
	{
		return codeAction;
	}

	codeAction = Action::getDefaut();

	if( codeAction != " " && codeAction != "" )
	{
		return codeAction;
	}

	//return NULL;
	return " ";
}
