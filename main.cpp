#include "PKW.h"
#include "Fahrrad.h"
#include <vector>
#include "AktivesVO.h"

//Uhr initialisieren (global)
double dGlobaleZeit = 0.0;

/*
Funktion zum testen der Fahrzeug-Klasse.
Erstellt Fahrzeuge, ruft die Ausgabe-Funktion auf und löscht alle Fahrzeuge wieder
*/
void vAufgabe_1()
{
	//Statisch erzeugte Objekte
	Fahrzeug tAuto1;
	Fahrzeug tAuto2("PKW", 40.0);

	//Dynamisch erzeugte Objekte
	Fahrzeug* pAuto3;
	Fahrzeug* pAuto4;
	
	//Nutzer nach Fahrzeugnamen fragen
	string sAutoname;
	cout << "Geben sie einen Fahrzeugnamen ein:" << endl;
	cin >> sAutoname;
	pAuto3 = new Fahrzeug();
	pAuto4 = new Fahrzeug(sAutoname, 30.0);

	//Ausgabe der Fahrzeuge und Daten
	cout << endl << "ID  Name     :  MaxKmh   GesamtStrecke      " << endl;
	cout << setw(42) << setfill('+') << " " << endl;
	
	//Schleife zum Abfertigen der Fahrzeuge jede Zehntel Stunde
	for (double d = 0; d <= 2.1; d += gZeitschritt)
	{
		dGlobaleZeit = d;
		
		tAuto1.vAbfertigung();
		tAuto2.vAbfertigung();
		pAuto3->vAbfertigung();
		pAuto4->vAbfertigung();

		cout << "Nach " << dGlobaleZeit << "h:" << endl;
		tAuto1.vAusgabe();
		cout << endl;
		tAuto2.vAusgabe();
		cout << endl;
		pAuto3->vAusgabe();
		cout << endl;
		pAuto4->vAusgabe();
		cout << endl << endl;
	}


	//Löschen der dynamischen Objekte
	delete pAuto4;	
	delete pAuto3;
}


void vAufgabe_1_deb()
{
	Fahrzeug* pFeld[4] = { new Fahrzeug("Rot", 40.0), new Fahrzeug("Blau", 25.0),
							new Fahrzeug("Gruen", 30.0), new Fahrzeug("Gelb", 10.0) };

	for (int i = 0; i <= 3; i++)
	{
		pFeld[i]->vAusgabe();
		cout << endl;
	}

	pFeld[2] = 0;

	for (int i = 0; i <= 3; i++)
	{
		pFeld[i]->vAusgabe();
		cout << endl;
	}

}

/*
Funktion zum Testen von PKWs und Fahrräder. Zuerst wird die Anzahl jeweils eingelesen und danach dynamisch erzeugt und in einen Vektor gespeichert.
Danach werden alle Fahrzeuge über eine "Zeitspanne" von 8h abgefertigt, wobei PKWs nach 3h vollgetankt werden.
*/
void vAufgabe_2()
{
	int iAnzahlPKW, iAnzahlFahrrad;
	
	//Anzahl PKWs und Fahrräder einlesen
	cout << "Wie viele PKWs moechten Sie erstellen?" << endl;
	cin >> iAnzahlPKW;
	cout << "Wie viele Fahrraeder moechten sie erstellen?" << endl;
	cin >> iAnzahlFahrrad;

	//Vektor erstellen
	vector<Fahrzeug*> vecFahrzeuge;

	//PKWs erstellen und in Vektor schieben
	for (int i = 0; i < iAnzahlPKW; i++)
	{
		PKW* tempPKW = new PKW("PKW" + to_string(i+1), 50, 20);
		vecFahrzeuge.push_back(tempPKW);
	}

	//Fahrräder erstellen und in Vektor schieben
	for (int i = 0; i < iAnzahlFahrrad; i++)
	{
		Fahrrad* tempFR = new Fahrrad("Fahrrad" + to_string(i + 1), 25);
		vecFahrzeuge.push_back(tempFR);
	}

	//Tabellenkopf
	cout << endl << "ID  Name     :  MaxKmh  AktKmh   GesamtStrecke  GesamtVerbrauch  AktTankinhalt " << endl;
	cout << setw(80) << setfill('+') << " " << endl;
	
	//Fahrzeuge abfertigen und ausgeben
	while(dGlobaleZeit < 8)
	{
		cout << "Nach " << dGlobaleZeit << "h:" << endl;

		for (int i = 0; i < vecFahrzeuge.size(); i++)
		{
			cout << *vecFahrzeuge[i] << endl;
			
			vecFahrzeuge[i]->vAbfertigung();

			//Nach 3h tanken. Vergleich mit epsilon, da double nicht 100% exakt sind
			if (fabs(dGlobaleZeit-3) < epsilon)
			{
				vecFahrzeuge[i]->dTanken(666);
			}

			//vecFahrzeuge[i]->vAusgabe();

		}
		cout << endl;
		dGlobaleZeit += gZeitschritt;
	}
}

void vAufgabe_3()
{
	cout << "Testen des Copykonstruktors und Ueberladung von =" << endl;
	
	//Statisches Fahrzeug
	PKW tempPKW1("PKW 1", 50, 20);
	//Copykonstruktor
	PKW tempPKW2 = tempPKW1;

	//Tabellenkopf
	cout << endl << "ID  Name   :  MaxKmh  AktKmh   GesamtStrecke  GesamtVerbrauch  AktTankinhalt " << endl;
	cout << setw(80) << setfill('+') << " " << endl;
	
	//Ausgabe der beiden Fahrzeuge
	cout << tempPKW1 << endl << tempPKW2 << endl << endl;

	

	cout << "Testen der Ueberladung von <" << endl;

	//PKW1 einmal abfertigen, beide ausgeben
	tempPKW1.vAbfertigung();
	cout << tempPKW1 << endl << endl;

	//Vergleich der Gesamtstrecken von PKW1 und PKW2
	//if (tempPKW1 < tempPKW2)
	//{
	//	cout << "PKW2 ist weiter gefahren als PKW1" << endl;
	//}
	//else
	//{
	//	cout << "PKW1 ist weiter gefahren als PKW2" << endl;
	//}

}

int main()
{
	vAufgabe_1();
	//vAufgabe_1_deb();
	//vAufgabe_2();
	//vAufgabe_3();
	return 0;
}

