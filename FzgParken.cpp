#include "FzgParken.h"
#include "Weg.h"



FzgParken::FzgParken(Weg* Weg):FzgVerhalten(Weg)
{
}

FzgParken::FzgParken(Weg* Weg, double dStartzeit) : FzgVerhalten(Weg)
{
	p_dStartzeit = dStartzeit;
}

FzgParken::~FzgParken()
{
}

double FzgParken::dStrecke(Fahrzeug*, double Zeitraum)
{
	if (p_dStartzeit > dGlobaleZeit)
	{
		return 0.0;
	}
	else
	{
		cout << "Die Startzeit wurde erreicht, das Programm wird beendet." << endl;
		exit(2);
	}
}
