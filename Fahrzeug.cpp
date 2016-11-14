#include "Fahrzeug.h"


//Standardkonstruktor, Name und ID von AktivesVo, rest durch eigene Initialisierung
Fahrzeug::Fahrzeug() : AktivesVO()
{
	vInitialisierung();
}

//Konstruktor mit Name
Fahrzeug::Fahrzeug(string sName): AktivesVO(sName)
{
	vInitialisierung();
}

//Konstruktor mit Name und MaxGeschwindigkeit
Fahrzeug::Fahrzeug(string sName, double dMaxGeschwindigkeit) :AktivesVO(sName)
{
	vInitialisierung();
	p_dMaxGeschwindigkeit = dMaxGeschwindigkeit;

}

//Selbstdefinierter Copyconstructor
Fahrzeug::Fahrzeug(const Fahrzeug& fahrzeug)
{
	p_sName = fahrzeug.p_sName;
	p_dGesamtStrecke = fahrzeug.p_dGesamtStrecke;
	p_dGesamtZeit = fahrzeug.p_dGesamtZeit;
	p_dMaxGeschwindigkeit = fahrzeug.p_dMaxGeschwindigkeit;
	p_dZeit = fahrzeug.p_dZeit;
	
}

//Virtueller Destruktor
Fahrzeug::~Fahrzeug()
{
}

/*
Funktion zur Initialisierung von allen Attributen und Vergabe der ID.
*/
void Fahrzeug::vInitialisierung()
{
	p_dGesamtStrecke = 0;
	p_dMaxGeschwindigkeit = 0.00;

}

/*
Ausgabe der Objektdaten in formatierter Form
*/
void Fahrzeug::vAusgabe()
{
	AktivesVO::vAusgabe();
	cout << p_dMaxGeschwindigkeit << setw(8) << setfill(' ') << this->dGeschwindigkeit() << setw(11) << setfill(' ') << p_dGesamtStrecke;
}

/*
Aktualisiert die Gesamtstrecke nach um die im vergangenen Zeitraum abgefahrene Strecke.
Prüft zuerst, ob Fahrzeug bereits in dem selben Zeitraum abgefertigt wurde über p_dZeit.
*/
void Fahrzeug::vAbfertigung()
{
	if (dGlobaleZeit == p_dZeit && dGlobaleZeit != 0.0)
	{
		cout << "Dieses Fahrzeug wurde bereits abgefertigt in diesem Zeitschritt" << endl;
		return;
	}
	else
	{
		p_dGesamtStrecke += gZeitschritt * this->dGeschwindigkeit();
	}
	
	p_dZeit = dGlobaleZeit;
}

//Default Funktion für alle Tochterklassen
double Fahrzeug::dTanken(double dMenge)
{
	return 0;
}

//Gibt die maximale Geschwindigkeit als aktuelle Geschwindigkeit zurück
double Fahrzeug::dGeschwindigkeit()
{
	return p_dMaxGeschwindigkeit;
}

//Überladung von <<
ostream& operator << (ostream& daten, Fahrzeug& fahrzeug)
{
	return fahrzeug.ostreamAusgabe(daten);
}

//Aufbau der Fahrzeugausgabe mit ostream
ostream& Fahrzeug::ostreamAusgabe(ostream& daten)
{
	AktivesVO::ostreamAusgabe(daten) <<p_dMaxGeschwindigkeit << setw(8) << setfill(' ') << dGeschwindigkeit() << setw(11) << setfill(' ') << p_dGesamtStrecke;

	return daten;
}


//Überladen des < Operators für Fahrzeuge
bool Fahrzeug::operator <(Fahrzeug& fahrzeug)
{
	if (p_dGesamtStrecke < fahrzeug.p_dGesamtStrecke)
	{
		return true;
	}

	return false;
}

//Überladen des = Operators, aufruf des Copykonstruktors
Fahrzeug& Fahrzeug::operator =(Fahrzeug& fahrzeug)
{
	Fahrzeug::Fahrzeug(fahrzeug);

	return *this;
}