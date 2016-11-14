#include "AktivesVO.h"

int AktivesVO::p_iMaxID = 1;

AktivesVO::AktivesVO()
{
	vInitialisierung();
}


AktivesVO::AktivesVO(string sName)
{
	vInitialisierung();

	p_sName = sName;
}

//Konstruktor mit lokaler Zeit fehlt noch

AktivesVO::~AktivesVO()
{
}

//Initialisierungsfunktion von AkitvesVo
void AktivesVO::vInitialisierung()
{
	p_sName = "";
	p_dZeit = 0;
	p_iID = p_iMaxID;
	p_iMaxID++;
}


//Ausgabe von allen in AktivesVO gespeicherten Attributen
void AktivesVO::vAusgabe()
{
	cout << setw(4) << resetiosflags(ios::right) << setiosflags(ios::left) << setfill(' ')
		<< p_iID << setw(9) << setfill(' ') << p_sName << ":" << resetiosflags(ios::left) << setiosflags(ios::right)
		<< setw(8) << setfill(' ');
}

//nicht definiert, weil rein virtuelle Funktion. Definition in Unterklassen
/*void AktivesVO::vAbfertigung()
{
}*/

//�berladung von <<
ostream& operator << (ostream& daten, AktivesVO& VO)
{
	return VO.ostreamAusgabe(daten);
}

//Aufbau der AktivesVO Ausgabe mit ostream
ostream& AktivesVO::ostreamAusgabe(ostream& daten)
{
	daten << setw(4) << resetiosflags(ios::right) << setiosflags(ios::left) << setfill(' ')
		<< p_iID << setw(9) << setfill(' ') << p_sName << ":" << resetiosflags(ios::left) << setiosflags(ios::right)
		<< setw(8) << setfill(' ');

	return daten;
}
