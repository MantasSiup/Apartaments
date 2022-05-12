#pragma once

#include "Apartamentas.h" // Reikalinga veiksmams su apartamentų klasėm.
#include "Baldas.h"; // Reikalinga veiksmams su baldų klasėm.

using namespace std;

void ApartamentuNuskaitymas(string ApartamDuomFailas, Apartamentas Apartamentai[], int &n, int k[]); 
void ApartamentuAtrinkimas(Apartamentas Apartamentai[], int &n, int k[], int Kaina); 
void IssirinktuApartamentuSpausdinimas(string ApartamSpausdinimas, string Miestas, int Kvadratura, double Kaina);
void BalduNuskaitymasIKlase(string BalduDuomFailas, Baldas BaldaiVisi[], int &m);
void BalduSpausdinimasIFaila(string BalduSpausdinimas, Baldas BaldaiVisi[], int m);
void IssirinktuBalduSpausdinimasIFaila(string IssirinktuBalduSpausdinimas, Baldas BaldaiVisi[], int indeksas);
void BalduNuskaitymasIStringa(string BalduDuomFailas, string &tekstas);
void BalduNuskaitymasIRichBoxa(string BalduDuomFailas, string &tekstas);
void BalduRikiavimasPagalKainaDidejanciai(Baldas BaldaiVisi[], int m);
void BalduRikiavimasPagalKainaMazejanciai(Baldas BaldaiVisi[], int m);
void BalduRikiavimasPagalKvadratusMazejanciai(Baldas BaldaiVisi[], int m);
void BalduRikiavimasPagalKvadratusDidejanciai(Baldas BaldaiVisi[], int m);