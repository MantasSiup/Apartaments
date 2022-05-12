#include "Apartamentas.h"
using namespace std;


Apartamentas::Apartamentas() : Miestas("") //Konstruktorius be parametrų.
{
}

Apartamentas::Apartamentas(string Miestas, int kv[], int kaina[]) // Konstuktorius su parametrais. Miestas - miestas, kv - Kvadratūros masyvas, kaina - kainos masyvas.
{
	this->Miestas = Miestas;
	for (int i = 0; i < sizeof(kaina); i++)
		this->kaina[i] = kaina[i];
	for (int i = 0; i < sizeof(kv); i++)
		this->kv[i] = kv[i];

}

Apartamentas::~Apartamentas()
{

}

////Miestas - miestas, kv - Kvadratūros masyvas, kaina - kainos masyvas.
void Apartamentas::Deti(string Miestas, int kv[], int kaina[]) //Funkcija sudedanti apartamento parametrus į Apartamentas klasės kintamuosius.
{
	this->Miestas = Miestas;
	for (int i = 0; i < sizeof(kaina); i++)
		this->kaina[i] = kaina[i];
	for (int i = 0; i < sizeof(kv); i++)
		this->kv[i] = kv[i];
}

//Funkcija sudedanti apartamento miestą į Apartamentas klasės kintamajį Miestas.
void Apartamentas::DetiMiesta(string Miestas)
{
	this->Miestas = Miestas;
}

// Funkcija sudedanti apartamento kvadratų skaičių į Apartamentas klasės kintamajį kv[] ir jo vietą masyve - Laik.
void Apartamentas::DetiKv(int kvadr, int Laik)
{
	this->kv[Laik] = kvadr;
}

//Funkcija sudedanti kvadratų skaičių į Apartamentas klasės kintamajį kvadratura.
void Apartamentas::DetiKvadratura(int kv)
{
	this->kvadratura = kv;
}

// Funkcija sudedanti apartamento kainą į Apartamentas klasės kintamajį kaina[] ir jo vietą masyve - Laik.	
void Apartamentas::DetiKaina(int kaina1, int Laik)
{
	this->kaina[Laik] = kaina1;
}

////Paimamas miestas iš klasės kintamojo.
string Apartamentas::ImtiMiesta()
{
	return this->Miestas;
}

// Paimamas kvadratų skaičius iš klasės kintamojo kv[] pagal indeksą - Laik.
int Apartamentas::ImtiKv(int Laik)
{
	return this->kv[Laik];
}

////Paimama kaina iš klasės kintamojo kaina[] pagal indeksą - Laik.
int Apartamentas::ImtiKaina(int Laik)
{
	return this->kaina[Laik];
}

//Paimamas kvadratų skaičius iš klasės kintamojo kvadratura.
int Apartamentas::ImtiKvadratura()
{
	return this->kvadratura;
}

//Pasalinamas apartamentas pagal indeksa, ir gražinamas kiekis - Kiek.
void Apartamentas::PasalintiApartamenta(int Indeksas, int &Kiek)
{
	for (int i = Indeksas; i < Kiek - 1; i++)
	{
		this->kaina[i] = kaina[i + 1];
		this->kv[i] = kv[i + 1];

	}
	Kiek--;
}