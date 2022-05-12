#pragma once

#include <string>
using namespace std;

class Apartamentas
{
public:
	static const int CKvMax = 100; //Maksimalus kvadratų kiekis masyve.
	static const int CKainaMax = 100; //Maksimalus kainos kiekis masyve.

private:
	string Miestas; // Apartamento miestas.
	int kv[CKvMax]; // Apartamentų kvadratų masyvas.
	int kaina[CKainaMax]; // Apartamentų kainų masyvas.
	int kaina1; // Apartamento kaina.
	int kvadratura; // Apartamento kvadratūra.
public:
	Apartamentas();
	Apartamentas(string Miestas, int kv[], int kaina[]); // Konstuktorius su parametrais. Miestas - miestas, kv - Kvadratūros masyvas, kaina - kainos masyvas.
	~Apartamentas();
	//Miestas - miestas, kv - Kvadratūros masyvas, kaina - kainos masyvas.
	void Deti(string Miestas, int kv[], int kaina[]);  //Funkcija sudedanti apartamento parametrus į Apartamentas klasės kintamuosius.
	void DetiMiesta(string Miestas); //Funkcija sudedanti apartamento miestą į Apartamentas klasės kintamajį Miestas.
	void DetiKv(int kvadr, int Laik); // Funkcija sudedanti apartamento kvadratų skaičių į Apartamentas klasės kintamajį kv[] ir jo vietą masyve - Laik.
	void DetiKvadratura(int kv); //Funkcija sudedanti kvadratų skaičių į Apartamentas klasės kintamajį kvadratura.
	void DetiKaina(int kaina1, int Laik); // Funkcija sudedanti apartamento kainą į Apartamentas klasės kintamajį kaina[] ir jo vietą masyve - Laik.	
	string ImtiMiesta(); //Paimamas miestas iš klasės kintamojo.
	int ImtiKv(int Laik); //Paimamas kvadratų skaičius iš klasės kintamojo kv[] pagal indeksą - Laik.
	int ImtiKaina(int Laik); //Paimama kaina iš klasės kintamojo kaina[] pagal indeksą - Laik.
	int ImtiKvadratura(); //Paimamas kvadratų skaičius iš klasės kintamojo kvadratura.
	void PasalintiApartamenta(int Indeksas, int &Kiek); //Pasalinamas apartamentas pagal indeksa, ir gražinamas kiekis - Kiek.
};
