#pragma once
#include "FahrAusnahme.h"
#include "Weg.h"

class Streckenende :
	public FahrAusnahme
{
public:
	Streckenende(Fahrzeug*, Weg*);
	~Streckenende();
	void vBearbeiten();
};

