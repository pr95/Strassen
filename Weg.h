#pragma once
#include "AktivesVO.h"

class Fahrzeug;
typedef list<Fahrzeug*> ListFahrzeug;

class Weg :
	public AktivesVO
{
//Anlegung von Aufz‰hlung Begrenzung zur Nutzung im Konstruktor
private:
	enum Begrenzung { Innerorts = 50, Landstraﬂe = 100, Autobahn = 0 }; //Innerorts, Landstraﬂe, Autobahn

public:
	Weg();
	Weg(string sName, double dLaenge, Begrenzung eLimit = Innerorts);
	~Weg();

	double dGetLaenge() const;
	void vAbfertigung();
	void vAnnahme(Fahrzeug*);
	void vAnnahme(Fahrzeug*, double);

	int iGetLimit() const;

	ostream& ostreamAusgabe(ostream&);

private:
	double p_dLaenge;
	ListFahrzeug p_pFahrzeuge;
	Begrenzung p_eLimit;

};

