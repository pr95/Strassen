#include "Weg.h"
#include "Fahrzeug.h"

//Standardkonstruktor
Weg::Weg()
{
}

//Konstruktor mi Name, Länge und Begrenzung
Weg::Weg(string sName, double dLaenge, Begrenzung eLimit) :AktivesVO(sName)
{
	p_dLaenge = dLaenge;
	p_eLimit = eLimit;
}

//Destruktor
Weg::~Weg()
{
}

//Gitb die Länge des Weges aus
double Weg::dGetLaenge() const
{
	return p_dLaenge;
}

//Fertigt die Fahrzeuge auf dem Weg ab
void Weg::vAbfertigung()
{
	ListFahrzeug::iterator itL;
	itL = p_pFahrzeuge.begin();

	while (p_pFahrzeuge.end() != itL)
	{
		(*itL)->vAbfertigung();
		itL++;
	}
}

//Nimmt neue FAHRENDE Fahrzeuge auf den Weg auf
void Weg::vAnnahme(Fahrzeug* pFzg)
{
	p_pFahrzeuge.push_back(pFzg);
	pFzg->vNeueStrecke(this);
}

//Nimmt neue PARKENDE Fahrzeuge auf den Weg auf
void Weg::vAnnahme(Fahrzeug* pFzg, double dStartzeit)
{
	p_pFahrzeuge.push_back(pFzg);
	pFzg->vNeueStrecke(this, dStartzeit);
}


//Ausgabe des Weges und der darauf befindlichen Fahrzeuge
ostream& Weg::ostreamAusgabe(ostream& daten)
{
	AktivesVO::ostreamAusgabe(daten) << p_dLaenge << "     ( ";

	ListFahrzeug::iterator itL;
	itL = p_pFahrzeuge.begin();

	while (p_pFahrzeuge.end() != itL)
	{
		daten << (*itL)->getName() << " ";
		itL++;
	}

	daten << ")";

	return daten;
}

//Gibt das Limit des Weges aus
int Weg::iGetLimit() const
{
	return p_eLimit;
}