#include <iostream>
#include <string>

int main() {
    std::string hexString = "0x5B6C";

    // Utilisation de std::stoi avec base 16 (hexadécimal)
    int valeur = std::stoi(hexString, nullptr, 16);

    std::cout << "Valeur décimale : " << valeur << std::endl;

    return 0;
}
