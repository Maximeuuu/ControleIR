#include "Action.hpp"
#include <string>
#include <iostream>

using namespace std;

int main()
{
	Action ensAction[3];
	int hexa(0);

	ensAction[0] = Action( "OnOff", 755, "alt+f4", "", "", "", "");
	ensAction[1] = Action( "Jaune", 733, "APP3", "", "", "", "");
	ensAction[2] = Action( "Coeur", 769, "", "", "alt+shift+b", "", "");

	while( true )
	{
		cin >> hexa;
		for( int cpt=0; cpt<3; cpt++ )
		{
			if( ensAction[cpt].estEgal(hexa) )
			{
				cout << ensAction[cpt].getAction() << endl;

				if( ensAction[cpt].getAction() == "APP3" )
				{
					Action::setCurrentApp(2);
				}

				break;
			}
		}
	}

/*
	if( action1.estEgal(755) )
	{
		cout << action1.getAction() << endl;
	}
	if( action2.estEgal(744) )
	{
		cout << action2.getAction() << endl;
	}
	if( action3.estEgal(769) )
	{
		cout << action3.getAction() << endl;
	}

	cout << Action::getCurrentApp() << endl;

	Action::setCurrentApp( 2 );

	cout << Action::getCurrentApp() << endl;

	if( action1.estEgal(755) )
	{
		cout << action1.getAction() << endl;
	}
	if( action2.estEgal(744) )
	{
		cout << action2.getAction() << endl;
	}
	if( action3.estEgal(769) )
	{
		cout << action3.getAction() << endl;
	}
*/
	return 0;
}
