#ifndef ARDUINO_HPP
#define ARDUINO_HPP

#include <string>
#include <fstream>

class Arduino
{
private:
	//Attributs
	std::string m_portName;
	std::fstream m_serialPort;

public:
	//Constructeurs
	Arduino( const std::string& portName, std::fstream serialPort );

	//Destructeurs
	~Arduino();

	//Usineur
	Arduino* creerArduino( const std::string& port ) static;

	//Accesseurs
	std::string getPortName();

	// Méthodes
	void sendData( std::string& data );
	std::string readData();
	std::string getMatchingData();
};

#endif //ARDUINO_HPP
