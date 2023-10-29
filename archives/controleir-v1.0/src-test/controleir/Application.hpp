#ifndef DEF_APPLICATION
#define DEF_APPLICATION

#include <string>

class Application
{
private:
	// Attributs
	std::string m_buttonName;
	std::string m_name;
	std::string m_codeIR;
	std::string m_color;

public:
	// Constructeurs
	Application();
	Application( std::string buttonName, std::string name, std::string codeIR, std::string color );

	// Accesseurs
	std::string getButtonName();
	std::string getName();
	std::string getCodeIR() const;
	std::string getColor();

	// Setteurs
	void setButtonName( std::string buttonName );
	void setName( std::string name );
	void setCodeIR( std::string codeIR );
	void setColor( std::string color );

	// Méthodes
	std::string toString();
};

// Opérateurs
bool operator==(Application const& app1, Application const& app2);
/*std::ostream& operator<<(std::ostream& os, const Application& app);*/

#endif //DEF_APPLICATION
