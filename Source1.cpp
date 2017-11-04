#include <iostream>
#include <string>
#include <sstream>
#include "Cluster.h"


vector<int> solucionInicial(vector<Cluster>& clusters, vector<Punto>& puntos, int total_puntos, int total_atributos, int K) {

	vector<int> puntos_centrales;

	for (int i = 0; i < K; i++)
	{
		while (true)
		{
			int punto_inicial = rand() % total_puntos;

			if (find(puntos_centrales.begin(), puntos_centrales.end(),
				punto_inicial) == puntos_centrales.end())
			{
				puntos_centrales.push_back(punto_inicial);
				puntos[punto_inicial].setCluster(i);
				Cluster cluster(i, puntos[punto_inicial]);
				clusters.push_back(cluster);
				break;
			}
		}
	}

	return puntos_centrales;

}

int centroideMasCercano(Punto punto, vector<Punto> puntos, vector<Cluster> clusters) {

			double suma = 0.0, distancia_minima;
			int id_cluster = 0;
	
			for (int i = 0; i < punto.getTotalAtributos(); i++)
			{
				suma += pow(clusters[0].getCentroAtributo(i) -
					punto.getValorAtributo(i), 2.0);
			}
	
			distancia_minima = sqrt(suma);
	
			for (int i = 1; i < clusters.size(); i++)
			{
				double distancia;
				suma = 0.0;
	
				for (int j = 0; j < punto.getTotalAtributos(); j++)
				{
					suma += pow(clusters[i].getCentroAtributo(j) -
						punto.getValorAtributo(j), 2.0);
				}
	
				distancia = sqrt(suma);
	
				if (distancia < distancia_minima)
				{
					distancia_minima = distancia;
					id_cluster = i;
				}
			}
	
			return id_cluster;
}

void asociarClusters(vector<Punto>& puntos, vector<Cluster>& clusters) {

	for (int i = 0; i < puntos.size(); i++)
	{
		int cluster_actual = puntos[i].getCluster();
		int nuevo_cluster = centroideMasCercano(puntos[i], puntos, clusters);
		
		if (cluster_actual != nuevo_cluster)
		{
			if (cluster_actual != -1)
				clusters[cluster_actual].quitarPunto(puntos[i].getID());
		
			puntos[i].setCluster(nuevo_cluster);
			clusters[nuevo_cluster].agregarPunto(puntos[i]);
		}
	}

}

void calcularCentroide(Cluster& cluster) {

	int total_puntos = cluster.getTotalPuntos();
	int total_atributos = cluster.getTotalAtributos();


				for (int i = 0; i < total_puntos; i++)
				{
					for (int j = 0; j < total_atributos; j++)
					{
						double sum = 0.0;
						sum = cluster.getPunto(i).getValorAtributo(j);
						sum += cluster.getCentroAtributo(j);

						cout << to_string(sum/2);
						cout << "\n";

						cluster.setCentroAtributo(j, sum / 2);
					}
				}
}

void busquedaLocal() {

}

int main(int argc, char *argv[]) {

	vector<double> attr1;
	vector<double> attr2;
	vector<double> attr3;
	vector<double> attr4;
	vector<double> attr5;
	vector<double> attr6;
	vector<double> attr7;

	attr1.push_back(1.0);
	attr1.push_back(1.0);
	attr2.push_back(1.5);
	attr2.push_back(2.0);
	attr3.push_back(3.0);
	attr3.push_back(4.0);
	attr4.push_back(5.0);
	attr4.push_back(5.25);
	attr5.push_back(3.5);
	attr5.push_back(5.0);
	attr6.push_back(4.5);
	attr6.push_back(5.0);
	attr7.push_back(3.5);
	attr7.push_back(4.5);

	Punto p1 = Punto(1, attr1, "Punto 1");
	Punto p2 = Punto(2, attr2, "Punto 2");
	Punto p3 = Punto(3, attr3, "Punto 3");
	Punto p4 = Punto(4, attr4, "Punto 4");
	Punto p5 = Punto(5, attr5, "Punto 5");
	Punto p6 = Punto(6, attr6, "Punto 6");
	Punto p7 = Punto(7, attr7, "Punto 7");

	cout << p1.toString();
	cout << p2.toString();
	cout << p3.toString();
	cout << p4.toString();
	cout << p5.toString();
	cout << p6.toString();
	cout << p7.toString();

	vector<Cluster> clusters;
	vector<Punto> puntos;
	puntos.push_back(p1);
	puntos.push_back(p2);
	puntos.push_back(p3);
	puntos.push_back(p4);
	puntos.push_back(p5);
	puntos.push_back(p6);
	puntos.push_back(p7);

	vector<int> indices = solucionInicial(clusters, puntos, 7, 2, 2);
	asociarClusters(puntos, clusters);
	calcularCentroide(clusters[0]);
	calcularCentroide(clusters[1]);

	cout << "\n";

	for (int i = 0; i < puntos.size(); i++)
	{
		cout << puntos[i].toString();
	}

	cout << "\n";

	for (int i = 0; i < clusters.size(); i++)
	{
		for (int j = 0; j < clusters[i].getTotalAtributos(); j++)
		{
			cout << to_string(clusters[i].getCentroAtributo(j));
		}
		cout << "\n\n";
	}
	string aux;
	cin >> aux;

	return 0;

}