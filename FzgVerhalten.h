#pragma once
#include "Weg.h"

class FzgVerhalten
{
public:
	//Konstruktor und Destruktor
	FzgVerhalten(Weg* pWeg);
	~FzgVerhalten();

	virtual double dStrecke(Fahrzeug*, double)=0;
	virtual Weg* getWeg() const;

protected:
	Weg* p_pWeg;


};

