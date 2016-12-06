#pragma once
#include "FahrAusnahme.h"
class Losfahren :
	public FahrAusnahme
{
public:
	Losfahren(Fahrzeug*, Weg*);
	~Losfahren();
	void vBearbeiten();
};

