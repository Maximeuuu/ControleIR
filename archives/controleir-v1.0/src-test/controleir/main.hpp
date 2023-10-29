#ifndef MAIN_HPP
#define MAIN_HPP

/* IMPORTATIONS */
#include "Action.hpp"
#include "Application.hpp"
#include "Telecommande.hpp"
#include "Outils.hpp"
#include "OutilsData.hpp"

/* BIBLIOTHEQUES */
#include <string>
#include <iostream>
#include <limits> // Inclure la bibliothèque limits pour utiliser std::numeric_limits
#include <fstream>
#include <vector>
#include <windows.h>

/* PROTOTYPES */
void useKeystroke( std::vector<int> combinaisons );

#endif // MAIN_HPP
