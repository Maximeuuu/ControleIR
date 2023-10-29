#ifndef OUTILSTELECOMMANDE_HPP
#define OUTILSTELECOMMANDE_HPP

#include "../arduino/Arduino.hpp"
#include "Application.hpp"
#include "Action.hpp"
#include "../outils/OutilsSaisie.hpp"

#include <iostream>
#include <vector>

class OutilsTelecommande
{
private:

public:
	// Méthodes
	static Application inputAppData( Arduino arduino );
	static Action inputActionData( Arduino arduino, std::vector<Application> ensApplication );
};

#endif //OUTILSTELECOMMANDE_HPP
