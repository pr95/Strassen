#pragma once
#include <string>
#include <iostream>
#include <iomanip>
#include <math.h>
#include "AktivesVO.h"
#define gZeitschritt 0.5
#define epsilon 0.0001

using namespace std;

extern double dGlobaleZeit;

class Fahrzeug : 
	public AktivesVO
{
public:
	//Konstruktoren
	Fahrzeug();
	Fahrzeug(string);			//Mit Name
	Fahrzeug(string, double);	//Mit Name und MaxGeschwindigkeit
	
	//Copyconstruktor
	Fahrzeug(const Fahrzeug&);

	//Destructor
	virtual ~Fahrzeug();
	
	//Methoden
	void vAusgabe();
	virtual void vAbfertigung();
	virtual double dTanken(double dMenge = 666);
	
	//Überladung von Operatoren
	virtual ostream& ostreamAusgabe(ostream&);
	bool operator <(Fahrzeug&);
	virtual Fahrzeug& operator =(Fahrzeug&);

private:
	void vInitialisierung();

//Attribute zum Vererben	
protected:
	string p_sName;
	int p_iID;
	double p_dMaxGeschwindigkeit;
	double p_dGesamtStrecke;
	double p_dGesamtZeit;
	double p_dZeit;

	virtual double dGeschwindigkeit();
};

ostream& operator << (ostream& daten, Fahrzeug& fahrzeug); 
