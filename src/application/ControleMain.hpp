#ifndef CONTROLEMAIN_HPP
#define CONTROLEMAIN_HPP

/* IMPORTATIONS */
#include "../telecommande/Action.hpp"
#include "../telecommande/Application.hpp"
#include "../telecommande/Telecommande.hpp"
#include "../outils/Outils.hpp"
#include "../outils/OutilsSaisie.hpp"
#include "../arduino/Arduino.hpp"
#include "../fichier/LectureData.hpp"

/* BIBLIOTHEQUES */
#include <string>
#include <iostream>
//#include <limits> // Inclure la bibliothèque limits pour utiliser std::numeric_limits
#include <fstream>
#include <vector>
#include <windows.h>

/* PROTOTYPES */
int ControleMain();
void useKeyStrokeWithCommande( std::string commande );
void pressKeystroke( std::vector<int> combinaisons );

#endif // CONTROLEMAIN_HPP
