#include <iostream>
#include <windows.h>

int main() {
    // Définir le nom du port série que vous utilisez (par exemple, "COM1" ou "COM2")
    const char* portName = "COM5";

    // Ouvrir le port série
    HANDLE serialPort = CreateFile(portName, GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

    if (serialPort != INVALID_HANDLE_VALUE) {
        DCB dcbSerialParams = { 0 };
        dcbSerialParams.DCBlength = sizeof(dcbSerialParams);

        // Obtenir les paramètres actuels du port série
        if (GetCommState(serialPort, &dcbSerialParams)) {
            dcbSerialParams.BaudRate = CBR_9600; // Définir la vitesse de transmission (par exemple, 9600 bauds)
            dcbSerialParams.ByteSize = 8;         // Taille des octets (8 bits)
            dcbSerialParams.StopBits = ONESTOPBIT; // 1 bit d'arrêt
            dcbSerialParams.Parity = NOPARITY;     // Pas de parité

            // Appliquer les nouveaux paramètres au port série
            if (SetCommState(serialPort, &dcbSerialParams)) {
                // Envoyer des données
                const char* dataToSend = "Hello, Serial!";
                DWORD bytesWritten;
                WriteFile(serialPort, dataToSend, strlen(dataToSend), &bytesWritten, NULL);

                // Lire des données
                char buffer[256];
                DWORD bytesRead;
                ReadFile(serialPort, buffer, sizeof(buffer), &bytesRead, NULL);
                buffer[bytesRead] = '\0';

                // Convertir la chaîne de caractères en entier
                int receivedNumber = atoi(buffer);

                std::cout << "Données reçues : " << receivedNumber << std::endl;
            }
        }

        // Fermer le port série
        CloseHandle(serialPort);
    } else {
        std::cerr << "Erreur lors de l'ouverture du port série." << std::endl;
    }

    return 0;
}
