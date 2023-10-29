#ifndef LECTUREDATA_HPP
#define LECTUREDATA_HPP

#include "../telecommande/Application.hpp"
#include "../telecommande/Action.hpp"
#include "../telecommande/Telecommande.hpp"
#include "../outils/Outils.hpp"

/* BIBLIOTHEQUES */
#include <string>
#include <fstream>

class LectureData
{
public:
	static Telecommande initTelecommandeWithData( std::ifstream& fichier );
};

#endif // LECTUREDATA_HPP
