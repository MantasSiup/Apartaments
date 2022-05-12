#pragma once

#include <string> 
using namespace std;

class Baldas
{
private:
	string PavadinimasB; //Baldo pavadinimas
	int kvadrataiB; // Baldo užimamas kvadratų skaičius
	int kainaB; // Baldo kaina

public:
	Baldas(); //Konstruktorius be Parametrų.
	Baldas(string PavadinimasB, int kvadrataiB, int kainaB); //Konstruktorius su parametrais, PavadinimasB - baldo pavadinimas, kvadrataiB - baldo užimamas kvadratų skaičius, kainaB - baldo kaina.
	~Baldas();
	//PavadinimasB - baldo pavadinimas, kvadrataiB - baldo užimamas kvadratų skaičius, kainaB - baldo kaina.
	void Deti(string PavadinimasB, int kvadrataiB, int kainaB); //Funkcija sudedanti visus parametrus į klasės kintamuosius. 
	void DetiPav(string PavadinimasB); //Funkcija sudedanti baldo pavadinimą į baldas klasės kintamajį PavadinimasB.
	void DetiKv(int kvadrataiB); //Funkcija sudedanti baldo užimamą kvadratų skaičių į baldas klasės kintamajį kvadrataiB.
	void DetiKaina(int kainaB); //Funkcija sudedanti baldo kainą į baldas klasės kintamajį kainaB.
	string imtiPav(); // Paimamas baldo pavadinimas iš klasės.
	int ImtiKv(); // Paimamas baldo kvadratų skaičius iš klasės.
	int ImtiKaina(); // Paimama baldo kaina iš klasės.
};

