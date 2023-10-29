#include "Nombre.hpp"
#include <iostream>

int main()
{
    // Créez un pointeur vers un objet Nombre en utilisant la fonction creerNombre
    Nombre* ptrNombre2 = Nombre::creerNombre(2);

    if (ptrNombre2 != nullptr)
    {
        // Créez un nouvel objet Nombre en copiant les données du pointeur
        Nombre nb2 = *ptrNombre2;

        // Accédez aux membres de l'objet créé en utilisant .
        std::cout << nb2.getNombre() << std::endl;

        // N'oubliez pas de libérer la mémoire du pointeur
        delete ptrNombre2;
    }

    // Créez un autre pointeur vers un objet Nombre en utilisant la fonction creerNombre
    Nombre* ptrNombre3 = Nombre::creerNombre(3);

    if (ptrNombre3 != nullptr)
    {
        // Créez un nouvel objet Nombre en copiant les données du pointeur
        Nombre nb3 = *ptrNombre3;

        // Accédez aux membres de l'objet créé en utilisant .
        std::cout << nb3.getNombre() << std::endl;

        // N'oubliez pas de libérer la mémoire du pointeur
        delete ptrNombre3;
    }

    return 0;
}
