#include "FzgFahren.h"
#include "Fahrzeug.h"
#include "Weg.h"



FzgFahren::FzgFahren(Weg* Weg):FzgVerhalten(Weg)
{
}


FzgFahren::~FzgFahren()
{
}


//
double FzgFahren::dStrecke(Fahrzeug* pFzg, double dZeitraum)
{
	double dFahrbareStrecke = pFzg->dGeschwindigkeit() * dZeitraum;

	if (this->p_pWeg->dGetLaenge() == pFzg->getAbschnittStrecke())
	{
		cout << "Ein Auto hat das Ende des Weges erreicht, tschau." << endl;
		exit(1);
	}
	else if (dFahrbareStrecke > (this->p_pWeg->dGetLaenge() - pFzg->getAbschnittStrecke()))
	{
		return this->p_pWeg->dGetLaenge() - pFzg->getAbschnittStrecke();
	}
	else
	{
		return dFahrbareStrecke;
	}

	return 0.0;
}
