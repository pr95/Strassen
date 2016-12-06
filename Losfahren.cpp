#include "Losfahren.h"
#include "Weg.h"
#include "Fahrzeug.h"



Losfahren::Losfahren(Fahrzeug* fFahrzeug, Weg* wWeg):FahrAusnahme(fFahrzeug, wWeg)
{
	
}


Losfahren::~Losfahren()
{
}

void Losfahren::vBearbeiten()
{
	cout << "Fahrzeug f�hrt los!" << endl;
	p_pWeg->vAbgabe(p_pFahrzeug);
}