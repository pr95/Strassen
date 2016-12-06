#include "Weg.h"
#include "Fahrzeug.h"
#include "FahrAusnahme.h"

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
		try
		{
			(*itL)->vAbfertigung();
			(*itL)->vZeichnen(this);
			
		}
		catch (FahrAusnahme *pAusnahme)
		{
			pAusnahme->vBearbeiten();
		}
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
	p_pFahrzeuge.push_front(pFzg);
	pFzg->vNeueStrecke(this, dStartzeit);
}


//Entfernt ein Fahrzeug aus der Liste
void Weg::vAbgabe(Fahrzeug* pFzg)
{
	ListFahrzeug::iterator itL;
	itL = p_pFahrzeuge.begin();
	int i = 0;
	
	while (p_pFahrzeuge.end() != itL)
	{
		if ((*itL) == pFzg)
		{
			p_pFahrzeuge.remove(*itL);
		}
	}
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
int Weg::iGetLimit()
{
	return p_eLimit;
}

