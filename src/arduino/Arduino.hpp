#ifndef ARDUINO_HPP
#define ARDUINO_HPP

#include <string>
#include <fstream>
#include <iostream>

class Arduino {
private:
	//Attributs
    std::string m_portName;
    std::fstream m_serialPort;

	//Constructeur
    Arduino( const std::string& port );

public:
	//Destructeurs
	~Arduino();

	//Usineur
    static Arduino* createArduino( const std::string& port );

	//Accesseurs
	std::string getPortName() const;
    bool isConnected() const;

	// Méthodes
    void sendData( const std::string& data );
    std::string readData();
	std::string getMatchingData();
};

#endif //ARDUINO_HPP
