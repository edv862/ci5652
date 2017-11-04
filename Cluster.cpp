#include "Cluster.h"

Cluster::Cluster(int id, Punto punto)
{
	this->id = id;

	this->total_atributos = punto.getTotalAtributos();

	for (int i = 0; i < total_atributos; i++)
		centroide.push_back(punto.getValorAtributo(i));

	puntos.push_back(punto);
}

void Cluster::agregarPunto(Punto punto)
{
	puntos.push_back(punto);
}
bool Cluster::quitarPunto(int id)
{
	int total_puntos = puntos.size();

	for (int i = 0; i < total_puntos; i++)
	{
		if (puntos[i].getID() == id)
		{
			puntos.erase(puntos.begin() + i);
			return true;
		}
	}
	return false;
}

double Cluster::getCentroAtributo(int indice)
{
	return centroide[indice];
}

void Cluster::setCentroAtributo(int indice, double valor)
{
	centroide[indice] = valor;
}

Punto Cluster::getPunto(int indice)
{
	return puntos[indice];
}

int Cluster::getTotalPuntos()
{
	return puntos.size();
}

int Cluster::getTotalAtributos()
{
	return this->total_atributos;
}

int Cluster::getID()
{
	return id;
}
