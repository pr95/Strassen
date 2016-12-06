#pragma once
#include "AktivesVO.h"
class Fahrzeug;
class Weg;

class FahrAusnahme
{
public:
	FahrAusnahme();
	FahrAusnahme(Fahrzeug*, Weg*);
	virtual void vBearbeiten() = 0;
	~FahrAusnahme();

protected:
	Fahrzeug* p_pFahrzeug;
	Weg* p_pWeg;
};

