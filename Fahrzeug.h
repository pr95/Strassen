#pragma once
#include <string>
#include <iostream>
#include <iomanip>
#include <math.h>
#include "AktivesVO.h"

class FzgVerhalten;
using namespace std;


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
	virtual void vAbfertigung();
	virtual double dTanken(double dMenge = 666);
	virtual double dGeschwindigkeit();
	virtual void vNeueStrecke(Weg*);				//Fahrendes Fahrzeug
	virtual void vNeueStrecke(Weg*, double);		//Parkendes Fahrzeug
	
	//�berladung von Operatoren
	virtual ostream& ostreamAusgabe(ostream&);
	bool operator <(Fahrzeug&);
	virtual Fahrzeug& operator =(Fahrzeug&);

	//Getter
	virtual FzgVerhalten* getVerhalten() const;
	virtual double getAbschnittStrecke() const;


private:
	void vInitialisierung();

//Attribute zum Vererben	
protected:
	int p_iID;
	double p_dMaxGeschwindigkeit;
	double p_dGesamtStrecke;
	double p_dGesamtZeit;
	double p_dZeit;
	double p_dAbschnittStrecke;
	FzgVerhalten* p_pVerhalten;

};

ostream& operator << (ostream& daten, Fahrzeug& fahrzeug); 
