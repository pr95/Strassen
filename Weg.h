#pragma once
#include "AktivesVO.h"

class Fahrzeug;
typedef list<Fahrzeug*> ListFahrzeug;
enum Begrenzung { Innerorts = 50, Landstraﬂe = 100, Autobahn = -1 }; //Innerorts, Landstraﬂe, Autobahn

class Weg :
	public AktivesVO	

{
//Anlegung von Aufz‰hlung Begrenzung zur Nutzung im Konstruktor
public:
	Weg();
	Weg(string sName, double dLaenge, Begrenzung eLimit = Innerorts);
	~Weg();


	void vAbfertigung();
	void vAnnahme(Fahrzeug*);
	void vAnnahme(Fahrzeug*, double);
	void vAbgabe(Fahrzeug*);

	double dGetLaenge() const;
	int iGetLimit();

	ostream& ostreamAusgabe(ostream&);

private:
	double p_dLaenge;
	ListFahrzeug p_pFahrzeuge;
	Begrenzung p_eLimit;

};

