#include "Punto.h"
#include <iostream>
#include <string>
#include <sstream>

	Punto::Punto(int id, vector<double>& valores, string nombre) {
		this->id = id;

		for (int i = 0; i < valores.size(); i++) {
			this->valores.push_back(valores[i]);
		}

		this->nombre = nombre;

		cluster = -1;
	}

	int Punto::getID() {
		return this->id;
	}

	void Punto::setCluster(int cluster) {
		this->cluster = cluster;
	}

	int Punto::getCluster()
	{
		return cluster;
	}

	double Punto::getValorAtributo(int index)
	{
		return valores[index];
	}

	int Punto::getTotalAtributos()
	{
		return valores.size();
	}

	void Punto::agregarValorAtributo(double valor)
	{
		this->valores.push_back(valor);
	}

	string Punto::getNombre()
	{
		return this->nombre;
	}

	string Punto::toString()
	{
		string output;
		string valores = "(" + std::to_string(this->getValorAtributo(0));
		string cluster = std::to_string(this->getCluster());

		for (int i = 1; i < this->getTotalAtributos(); i++)
		{
			valores = valores + ", ";
			valores = valores + std::to_string(this->getValorAtributo(i));
		}

		valores = valores + ")";

		output = getNombre() + " - pertenece al cluster ";
		output = output + cluster;
		output = output + " y contiene los valores ";
		output = output + valores;
		output = output + "\n";

		return output;
	}