#include <vector>
#include <stdlib.h>

using namespace std;

class Punto
{
private:
	int id;
	int cluster;
	vector<double> valores;
	string nombre;

public:
	Punto(int id, vector<double>& valores, string nombre = "");
	int getID();
	int getCluster();
	void setCluster(int cluster);
	double getValorAtributo(int index);
	void agregarValorAtributo(double valor);
	int getTotalAtributos();
	string getNombre();
	string toString();
};

