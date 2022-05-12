#include "Funkcijos.h"
#include "Baldas.h";
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

//Nuskaitomi apartamentai iš duomenų failo į klasę. ApartamDuomFailas - tekstinis dokumentas,
//Apartamentai[] - apartamentų klasės masyvas, n - miestų kiekis, k[] - apartamentų kiekio masyvas.
void ApartamentuNuskaitymas(string ApartamDuomFailas, Apartamentas Apartamentai[], int &n, int k[])
{
	ifstream fd(ApartamDuomFailas);

	while (!fd.eof())
	{
		int LaikKv[100];
		int LaikKaina[100];
		string Laikinas = " ";
		getline(fd, Laikinas, '\n');
		Apartamentai[n].DetiMiesta(Laikinas); // Į apartamentų klasės masyvą n įrašomas Miestas.
		k[n] = 0;
		while (fd.peek() != ';')
		{
			fd >> LaikKv[n];
			fd >> LaikKaina[n];
			Apartamentai[n].DetiKv(LaikKv[n], k[n]); // // Į apartamentų klasės masyvą n įrašomas kvadratų skaičius.
			Apartamentai[n].DetiKaina(LaikKaina[n], k[n]); // Į apartamentų klasės masyvą n įrašoma apartamentų kaina.
			k[n]++;
		}
		fd.ignore(50, ';');
		fd.ignore(50, '\n');
		n++;
	}
	fd.close();
}

//Atrenkami apartamentai pagal biudžetą Apartamentai[] - apartamentų klasės masyvas, n - miestų kiekis, k[] - apartamentų kiekio masyvas, Kaina - biudžetas.
void ApartamentuAtrinkimas(Apartamentas Apartamentai[], int &n, int k[], int Kaina)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < k[i]; j++)
			if (Apartamentai[i].ImtiKaina(j) > Kaina) //Paimama apartamentų kaina ir tikrinama ar ji mažesnė už galimą biudžetą.
			{
				Apartamentai[i].PasalintiApartamenta(j, k[i]); // Pašalinamas apartamentas, kuris neatitiko biudžeto.
				j--; // sumažėja tam tikrų apartamentų kiekis
			}
	if (k[i] == 0) // jei apartamentų kiekis mieste tampa lygus 0 pašalinamas miestas.
		{
			for (int j = i; j < n -1; j++)
			{
				Apartamentai[j] = Apartamentai[j + 1]; // Apartamentų klasės masyvas pašalinamas, sekantis po jo nukeliamas į jo vietą.
				k[j] = k[j + 1];
			}
			n--; //sumažėja miestų kiekis.
			i--;
		}
	}
}

//Išrinktų apartamentų spausdinimas ApartamSpausdinimas - tekstinis dokumentas, Miestas - miestas, Kvadratūra - kvadratūra, Kaina - kaina.
void IssirinktuApartamentuSpausdinimas(string ApartamSpausdinimas, string Miestas, int Kvadratura, double Kaina)
{
	ofstream fr(ApartamSpausdinimas);

	fr << "Miestas - " << Miestas << endl;
	fr << "Kvadratu skaicius - " << Kvadratura << endl;
	fr << "Kaina - " << Kaina << endl;

	fr.close();
}

// Nuskaitomi baldai iš duomenų failo į klasę.
// BalduDuomFailas - tekstinis dokumentas, BaldaiVisi[] - baldų klasės masyvas, m - kiekis.
void BalduNuskaitymasIKlase(string BalduDuomFailas, Baldas BaldaiVisi[], int &m)
{
	if (m == 0)
	{
		ifstream duom(BalduDuomFailas);
		while (!duom.eof())
		{
			int LaikKv;
			int LaikKaina;
			char Laikinas[20];
			duom.get(Laikinas, sizeof(Laikinas));
			BaldaiVisi[m].DetiPav(Laikinas); // Į baldų klasės masyvą m įrašomas pavadinimas.

			duom >> LaikKv >> LaikKaina;
			BaldaiVisi[m].DetiKv(LaikKv); // Į baldų klasės masyvą m įrašomas užimamas kvadratų skaičius.
			BaldaiVisi[m].DetiKaina(LaikKaina); // Į baldų klasės masyvą m įrašoma baldo kaina.
			duom.ignore(40, '\n');
			m++;
		}
		duom.close();
	}
}

// Baldai spausdinami į failą. Naudojama rikiuotų baldų spausdinimui į failą.
// BalduSpausdiniams - tekstinis dokumentas, BaldaiVisi[] - baldų klasės masyvas, m - kiekis.
void BalduSpausdinimasIFaila(string BalduSpausdinimas, Baldas BaldaiVisi[], int m) 
{
	ofstream fr(BalduSpausdinimas);
	for (int i = 0; i < m; i++)
		{
		if (i == m - 1) //Tikrinama ar paskutinis baldas
			fr << BaldaiVisi[i].imtiPav() << BaldaiVisi[i].ImtiKv() << " " << BaldaiVisi[i].ImtiKaina(); //Iš baldų klasės masyvo paimamas ir spausdinamas pavadinimas, kvadratų užimamas kiekis ir kaina.
		else
			fr << BaldaiVisi[i].imtiPav() << BaldaiVisi[i].ImtiKv() << " " << BaldaiVisi[i].ImtiKaina() << endl; //Iš baldų klasės masyvo paimamas ir spausdinamas pavadinimas, kvadratų užimamas kiekis ir kaina.
		}
	fr.close();
}

// Išrinktų baldų spausdinimas į failą.
// IssirinktuBalduSpausdinimas - tekstinis dokumentas,  BaldaiVisi[] - baldų klasės masyvas, indeksas - išsirinkto baldo indeksas.
void IssirinktuBalduSpausdinimasIFaila(string IssirinktuBalduSpausdinimas, Baldas BaldaiVisi[], int indeksas) 
{
	ofstream fr(IssirinktuBalduSpausdinimas,ios::app);
	fr << BaldaiVisi[indeksas].imtiPav() << setw(15) << fixed << BaldaiVisi[indeksas].ImtiKv() << setw(18) << fixed << BaldaiVisi[indeksas].ImtiKaina() << endl; //Iš tam tikro baldų klasės masyvo 
																																		//spausdinams pavadinimas, kvadratų užimamas kiekis ir kaina.
	fr.close();
}

// Baldai nuskaitomi į stringą.
// BalduDuomFailas - tekstinis dokumentas, tekstas - stringas, kuriame laikomi nuskaityti baldai.
void BalduNuskaitymasIStringa(string BalduDuomFailas, string &tekstas)
{
	ifstream fd1(BalduDuomFailas);
	int b = -1;
	while (!fd1.eof())
	{
		b++; //baldo indeksas.
		tekstas += to_string(b);
		tekstas += " ";
		string a = "";
		getline(fd1, a);
		tekstas += a + '\n';
	}
	fd1.close();
}

// Reikalinga norint nuskaityti baldus ir įrašyti į textboxą be indeksų.
// BalduDuomFailas - tekstinis dokumentas, tekstas - stringas, kuriame laikomi nuskaityti baldai.
void BalduNuskaitymasIRichBoxa(string BalduDuomFailas, string &tekstas)
{
	ifstream fd1(BalduDuomFailas);
	while (!fd1.eof())
	{
		string a = "";
		getline(fd1, a);
		tekstas += a + '\n';
	}
	fd1.close();
}

// Rikiavimo funkciją pagal kainą didėjančiai.
// BaldaiVisi[] - baldų klasės masyvas, int m - kiekis.
void BalduRikiavimasPagalKainaDidejanciai(Baldas BaldaiVisi[], int m)
{
	int mini = 0;
	Baldas Sukeitimas;
	for (int i = 0; i < m - 1; i++)
	{
		mini = i;
		for (int j = i + 1; j < m; j++)
			if (BaldaiVisi[j].ImtiKaina() < BaldaiVisi[mini].ImtiKaina()) //Rikiuojama baldų klasę.
				mini = j;
				Sukeitimas = BaldaiVisi[i];
				BaldaiVisi[i] = BaldaiVisi[mini];
				BaldaiVisi[mini] = Sukeitimas;
	}
}

// Rikiavimo funkciją pagal kainą mažėjančiai.
// BaldaiVisi[] - baldų klasės masyvas, int m - kiekis.
void BalduRikiavimasPagalKainaMazejanciai(Baldas BaldaiVisi[], int m)
{
	int max = 0;
	Baldas Sukeitimas;
	for (int i = 0; i < m - 1; i++)
	{
		max = i;
		for (int j = i + 1; j < m; j++)
			if (BaldaiVisi[j].ImtiKaina() > BaldaiVisi[max].ImtiKaina()) //Rikiuojama baldų klasę.
				max = j;
		Sukeitimas = BaldaiVisi[i];
		BaldaiVisi[i] = BaldaiVisi[max];
		BaldaiVisi[max] = Sukeitimas;
	}
}

// Rikiavimo funkciją pagal kvadratų skaičių didėjančiai.
// BaldaiVisi[] - baldų klasės masyvas, int m - kiekis.
void BalduRikiavimasPagalKvadratusMazejanciai(Baldas BaldaiVisi[], int m)
{
	int mini = 0;
	Baldas Sukeitimas;
	for (int i = 0; i < m - 1; i++)
	{
		mini = i;
		for (int j = i + 1; j < m; j++)
			if (BaldaiVisi[j].ImtiKv() > BaldaiVisi[mini].ImtiKv()) //Rikiuojama baldų klasę.
				mini = j;
		Sukeitimas = BaldaiVisi[i];
		BaldaiVisi[i] = BaldaiVisi[mini];
		BaldaiVisi[mini] = Sukeitimas;
	}
}

// Rikiavimo funkciją pagal kvadratų skaičių didėjančiai.
// BaldaiVisi[] - baldų klasės masyvas, int m - kiekis.
void BalduRikiavimasPagalKvadratusDidejanciai(Baldas BaldaiVisi[], int m)
{
	int mini = 0;
	Baldas Sukeitimas;
	for (int i = 0; i < m - 1; i++)
	{
		mini = i;
		for (int j = i + 1; j < m; j++)
			if (BaldaiVisi[j].ImtiKv() < BaldaiVisi[mini].ImtiKv()) //Rikiuojama baldų klasę.
				mini = j;
		Sukeitimas = BaldaiVisi[i];
		BaldaiVisi[i] = BaldaiVisi[mini];
		BaldaiVisi[mini] = Sukeitimas;
	}
}