#include "Arduino.hpp"

#include <iostream>
#include <string>
#include <fstream>

//Constructeur
Arduino::Arduino( const std::string& port )
{
	m_portName = port;
	m_serialPort.open(port, std::ios::out | std::ios::in | std::ios::binary);
	m_serialPort.setf(std::ios::dec);
}

//Destructeurs
Arduino::~Arduino()
{
	std::cout << "Je suis détruit" << std::endl;
	m_serialPort.close();
}

//Usineur
Arduino* Arduino::createArduino( const std::string& port )
{
    Arduino* arduino = new Arduino(port);
    if( !arduino->isConnected() )
	{
		std::cout << "Erreur lors de l'ouverture du port serie " << port << std::endl;
		delete arduino;
        return nullptr;
    }

	std::cout << "Connexion au port serie " << port << " reussie." << std::endl;
    return arduino;
}

//Accesseurs
std::string Arduino::getPortName() const
{
    return m_portName;
}

bool Arduino::isConnected() const
{
	if( !m_serialPort.is_open() )
	{
		std::cout << "je suis déco" << std::endl;
	}
	else
	{
		std::cout << "je suis tjrs co" << std::endl;
	}

    return m_serialPort.is_open();
}

void Arduino::sendData( const std::string& data )
{
    if( isConnected() )
	{
        //serialPort.write(data.c_str(), data.size()); //chatgpt
		m_serialPort << data << std::endl;
    }
}

std::string Arduino::readData()
{
    std::string data;

	std::cout << "je read" << std::endl;

    if( isConnected() )
	{
		/*
        char buffer[256];
        m_serialPort.read(buffer, sizeof(buffer));
        data.assign(buffer, m_serialPort.gcount()); //chatgpt*/

		/*//m_serialPort.ignore();

		m_serialPort >> data;*/
		getline(m_serialPort, data);

		std::cout << data << std::endl;

		std::cout << "j'ai bien read" << std::endl;
    }

	std::cout << "j'ai fini de read" << std::endl;

    return data;
}

std::string Arduino::getMatchingData()
{
	std::string s1, s2;

	if( isConnected() )
	{
		m_serialPort.ignore();
		do
		{
			s1 = readData();
			s2 = readData();
		}
		while( s1 != s2 );
	}

	return s1;
}
