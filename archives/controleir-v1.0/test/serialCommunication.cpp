#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::fstream serialPort;
    serialPort.open("COM5", std::ios::in);  // Modifier le chemin du port série si nécessaire
	//std::ios::out | std::ios::in

    if (!serialPort.is_open()) {
        std::cerr << "Erreur lors de l'ouverture du port serie" << std::endl;
        return 1;
    }

	serialPort.setf(std::ios::dec);

	std::cout << "Port serie ouvert" << std::endl;

    // Écriture et lecture de données sur le port série
    /*std::string data = "Hello, Serial Port!";
    serialPort << data << std::endl;*/

    std::string receivedData;

	/*std::cout << "ecoute" << std::endl;
	char character;
	if (serialPort.read(&character, 1)) {
    	std::cout << "reçue : " << character << std::endl;
	} else {
    	std::cout << "pas reçue" << std::endl;
	}*/

	while( true )
	{
		std::getline(serialPort, receivedData);

		std::cout << "Données reçues : " << receivedData << std::endl;
	}
	
    serialPort.close();

    return 0;
}
