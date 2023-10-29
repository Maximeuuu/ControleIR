#include "Application.hpp"

// Constructeurs
Application::Application() : m_buttonName(""), m_name(""), m_codeIR(""), m_color(""){}
Application::Application( std::string buttonName, std::string name, std::string codeIR, std::string color )
{
	m_buttonName = buttonName;
	m_name = name;
	m_codeIR = codeIR;
	m_color = color;
}

// Accesseurs
std::string Application::getButtonName(){ return m_buttonName; }
std::string Application::getName(){ return m_name; }
std::string Application::getCodeIR() const { return m_codeIR; }
std::string Application::getColor(){ return m_color; }

// Setteurs
void Application::setButtonName( std::string buttonName )	{ m_buttonName = buttonName; }
void Application::setName( std::string name )				{ m_name = name; }
void Application::setCodeIR( std::string codeIR )			{ m_codeIR = codeIR; }
void Application::setColor( std::string color )				{ m_color = color; }

// Méthodes
std::string Application::toString()
{
	std::string sep = "/t";
	std::string buttonName, name, codeIR, color;

	buttonName = m_buttonName;
	if( buttonName == "" ){ buttonName = "."; }

	name = m_name;
	if( name == "" ){ name = "."; }

	codeIR = m_codeIR;
	if( codeIR == "" ){ codeIR = "."; }

	color = m_color;
	if( color == "" ){ color = "."; }

	return buttonName + sep + name + sep + codeIR + sep + color;
}

// Opérateurs
bool operator==(Application const& app1, Application const& app2)
{
	return app1.getCodeIR() == app2.getCodeIR();
}

/*std::ostream& operator<<(std::ostream& os, const Application& app)
{
	os << "ButtonName: " << app.getButtonName() << "Name: " << app.getName() << ", Code IR: " << app.getCodeIR() << ", RGB: " << app.getColor();
    return os;
}*/
