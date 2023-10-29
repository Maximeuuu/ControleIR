#include "Telecommande.hpp"

// Constructeurs
Telecommande::Telecommande()
{
	m_name 				= "NAME";
	m_delais 			= 0;
	m_ensApplication 	= std::vector<Application>();
	m_ensAction 		= std::vector<Action>();
	m_currentAppIndex	= -1;
}

Telecommande::Telecommande( std::string name, int delais, std::vector<Application> ensApplication, std::vector<Action> ensAction )
{
	m_name 				= name;
	m_delais 			= delais;
	m_ensApplication 	= ensApplication;
	m_ensAction 		= ensAction;
	m_currentAppIndex	= -1;
}

Telecommande::Telecommande( std::string name, int delais )
{
	m_name 				= name;
	m_delais 			= delais;
	m_ensApplication 	= std::vector<Application>();
	m_ensAction 		= std::vector<Action>();
	m_currentAppIndex	= -1;
}

// Accesseurs
std::string Telecommande::getName()						{ return m_name; }
int 		Telecommande::getDelais()					{ return m_delais; }
Application Telecommande::getApplication( int index )	{ return m_ensApplication[index]; }
Action 		Telecommande::getAction( int index )		{ return m_ensAction[index]; }
int 		Telecommande::getCurrentAppIndex()			{ return m_currentAppIndex; }
Application	Telecommande::getCurrentApplication()		{ return m_ensApplication[m_currentAppIndex]; }
int 		Telecommande::getNbApplication()			{ return m_ensApplication.size(); }
int 		Telecommande::getNbAction()					{ return m_ensAction.size(); }

// Setteurs
void Telecommande::setCurrentAppIndex( int index ){ m_currentAppIndex = index; }
void Telecommande::setCurrentApp( Application app )
{
	for( int cptApp=0; cptApp<m_ensApplication.size(); cptApp++ )
	{
		if( m_ensApplication[cptApp] == app )
		{
			m_currentAppIndex = cptApp;
			return;
		}
	}
	m_currentAppIndex = -1;
	return;
}

// Modifieurs
void Telecommande::addApplication( Application app ){ m_ensApplication.push_back(app); }
void Telecommande::addAction( Action action )		{ m_ensAction.push_back(action); }

// Méthodes
int Telecommande::getIndexApplicationByCodeIR( std::string strCodeIR )
{
	//std::cout << "testApp" << m_ensApplication.size() << std::endl;
	for( int cptApp=0; cptApp<m_ensApplication.size(); cptApp++ )
	{
		//std::cout << m_ensApplication[cptApp].getCodeIR() << "==" << strCodeIR << std::endl;
		if( m_ensApplication[cptApp].getCodeIR() == strCodeIR )
		{
			return cptApp;
		}
	}

	return -1;
}

int Telecommande::getIndexActionByCodeIR( std::string strCodeIR )
{
	//std::cout << "testAction" << m_ensAction.size() << std::endl;
	for( int cptAction=0; cptAction<m_ensAction.size(); cptAction++ )
	{
		//std::cout << m_ensAction[cptAction].getCodeIR() << "==" << strCodeIR << std::endl;
		if( m_ensAction[cptAction].getCodeIR() == strCodeIR )
		{
			return cptAction;
		}
	}

	return -1;
}

std::string Telecommande::toString()
{
	std::string sRet = "Name : "+m_name+" | NB_APP:"+ std::to_string(m_ensApplication.size()) +" | NB_ACTION:"+ std::to_string(m_ensAction.size());
	return sRet;
}

// Opérateurs
/*
std::ostream& operator<<(std::ostream& os, const Telecommande& t)
{
	os << "Name: " << t.getName() << ", Delais: " << "ms, ";
	os << "Applications : {";
	for( int cpt=0; cpt<t.getNbApplication(); cpt++ )
	{
		os << t.getApplication(cpt);
	}
	os << "}, Actions : {";
	for( int cpt=0; cpt<t.getNbAction(); cpt++ )
	{
		os << t.getAction(cpt);
	}
	os << "}."

    return os;
}*/
