#include "Punto.h"
#include <vector>
#include <stdlib.h>

using namespace std;

class Cluster
{
private:
	int id;
	vector<double> centroide;
	vector<Punto> puntos;
	int total_atributos;

public:
	Cluster(int id, Punto centro);
	int getID();
	Punto getPunto(int indice);
	void agregarPunto(Punto punto);
	bool quitarPunto(int id);
	double getCentroAtributo(int indice);
	void setCentroAtributo(int indice, double valor);
	int getTotalPuntos();
	int getTotalAtributos();
};

