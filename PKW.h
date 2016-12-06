#pragma once
#include "Fahrzeug.h"

/*
PKW Klasse
Erbt von Fahrzeug
*/
class PKW :
	public Fahrzeug
{

public:
	//Konstruktoren
	PKW();
	PKW(string, double, double, double dTankvolumen = 55, double = 0); //Mit Namen, MaxGeschwindigkeit, Verbrauch und Tankvolumen und AbschnittStrecke
	
	//Copykonstruktor
	PKW(const PKW&); 

	//Destruktor
	~PKW();

	//Methoden
	void vAbfertigung();
	void vZeichnen(Weg*);

	//�berladung
	ostream& ostreamAusgabe(ostream&);
	PKW& operator =(PKW&);

private:
	//Attribute
	double p_dVerbrauch;	//Verbrauch/100km
	double p_dTankinhalt;	//In Liter
	double p_dTankvolumen;	//Standard 55l
	
	//Methoden
	double dVerbrauch();
	double dTanken(double dMenge = 666);
	double dGeschwindigkeit();
};

