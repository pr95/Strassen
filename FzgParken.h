#pragma once
#include "FzgVerhalten.h"


class FzgParken :
	public FzgVerhalten
{
public:
	FzgParken(Weg* Weg);
	FzgParken(Weg* Weg, double dStartzeit);
	~FzgParken();

	double dStrecke(Fahrzeug*, double Zeitraum);

private:
	double p_dStartzeit;
};

