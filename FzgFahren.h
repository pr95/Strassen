#pragma once
#include "FzgVerhalten.h"


class FzgFahren :
	public FzgVerhalten
{
public:
	FzgFahren(Weg* Weg);
	~FzgFahren();

	double dStrecke(Fahrzeug*, double Zeitraum);
	int getSpeed() const;
};

