#include "FzgVerhalten.h"
#include "Fahrzeug.h"
#include "Weg.h"

//Konstruktor mit Zeiger auf Weg, speichert diesen
FzgVerhalten::FzgVerhalten(Weg* pWeg)
{
	p_pWeg = pWeg;
}

//Destruktor
FzgVerhalten::~FzgVerhalten()
{
}

Weg* FzgVerhalten::getWeg() const
{
	return p_pWeg;
}