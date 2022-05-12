#include "Baldas.h"
using namespace std;

Baldas::Baldas()
{
}
Baldas::~Baldas()
{

}
void Baldas::Deti(string PavadinimasB, int kvadrataiB, int kainaB) //PavadinimasB - baldo pavadinimas, kvadrataiB - baldo užimamas kvadratų skaičius, kainaB - baldo kaina.
{
	this->PavadinimasB = PavadinimasB;
	this->kvadrataiB = kvadrataiB;
	this->kainaB = kainaB;
}
void Baldas::DetiPav(string PavadinimasB) // PavadinimasB - baldo pavadinimas.
{
	this->PavadinimasB = PavadinimasB;
}
void Baldas::DetiKv(int kvadrataiB) // kvadrataiB - baldo užimamas kvadratų skaičius.
{
	this->kvadrataiB = kvadrataiB;
}
void Baldas::DetiKaina(int kainaB) // kainaB - baldo kaina.
{
	this->kainaB = kainaB;
}
string Baldas::imtiPav() //Paimamas baldo pavadinimas iš klasės.
{
	return PavadinimasB;
}
int Baldas::ImtiKv() // Paimamas baldo užimamas kvadratų skaičius iš klasės.
{
	return kvadrataiB;
}
int Baldas::ImtiKaina() // Paimama baldo kaina iš klasės.
{
	return kainaB;
}