#include "Arduino.hpp"

//Constructeurs
Arduino::Arduino( const std::string& portName, std::fstream serialPort )
{
	m_portName = portName;
	m_serialPort = serialPort;

	m_serialPort.setf(std::ios::dec);
}

//Destructeurs
Arduino::~Arduino()
{
	m_serialPort.close();
}

//Usineur
Arduino* Arduino::creerArduino( const std::string& port )
{
	std::fstream serialPort;
	serialPort.open( port, ios::out | ios::in );

	if( !serialPort.is_open() )
	{
		cout << "Erreur lors de l'ouverture du port serie " << port << endl;
		return nullptr;
	}
	cout << "Connexion au port serie " << userPort << " reussie." << endl;
	return Arduino( port, serialPort );
}

//Accesseurs
std::string Arduino::getPortName()
{
	return m_portName;
}

// Méthodes
void Arduino::sendData( std::string& data )
{
	m_serialPort << data << endl;
}

std::string Arduino::readData()
{
	string sRet;

	m_serialPort.ignore();
	getline(m_serialPort, sRet);

	return sRet;
}

std::string Arduino::getMatchingData()
{
	string s1, s2;

	m_serialPort.ignore();
	do
	{
		s1 = readData();
		s2 = readData();
	}
	while( s1 != s2 )

	return s1;
}
