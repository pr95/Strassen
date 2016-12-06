#include "Streckenende.h"



Streckenende::Streckenende(Fahrzeug* fFahrzeug, Weg* wWeg):FahrAusnahme(fFahrzeug, wWeg)
{
}


Streckenende::~Streckenende()
{
}

void Streckenende::vBearbeiten()
{
	cout << "Fahrzeug hat das Streckenende erreicht!" << endl;
}