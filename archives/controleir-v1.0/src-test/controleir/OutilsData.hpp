#ifndef OUTILSDATA_HPP
#define OUTILSDATA_HPP

#include "Action.hpp"
#include "Application.hpp"
#include "Telecommande.hpp"
#include "Outils.hpp"

/* BIBLIOTHEQUES */
#include <string>
#include <fstream>

class OutilsData
{
public:
	static Telecommande initTelecommandeWithData( std::ifstream& fichier );
};

#endif // OUTILSDATA_HPP
