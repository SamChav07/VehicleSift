#include <iostream>
#include <vector>
#include <stdio.h>
#include <string.h>
#include "structure.h"
#define MAX 100 //los valores de max sean 100

using namespace std;

trucks trucksData[MAX];
int lastReg = 0;

void addTruck(trucks data)
{
	trucksData[lastReg] = data; //asigna el valor del objeto "data" en lastReg
	lastReg++; //incremento de lastReg de 0 - 1+

}

void showTruck(int pos)
{
	cout << "Marca del camión: " << trucksData[pos].truckBrand << endl;
	cout << "Año del camión: " << trucksData[pos].truckYear << endl;
	cout << "Refrigeración: " << trucksData[pos].refr << endl;
	cout << "Tipo de Vehiculo: " << trucksData[pos].vehicleType << endl;
	cout << "Codigo del camión: " << trucksData[pos].truckCode << endl;
	cout << "Placa del camión: " << trucksData[pos].truckPlate << endl;
	cout << "Conductor asignado: " << trucksData[pos].driver << endl;
	cout << "Estado del camión: " <<  trucksData[pos].truckStatus << endl;

}

trucks getTruck(int pos)
{
	return trucksData[pos];
}

int isTruck(int code[], size_t size)
{
	int position = -1;
	for (int i = 0; i < lastReg; i++)
	{
		/*se multiplica "size * sizeof(int)" para determinar cantidad de bytes*/
		if (memcmp(code, trucksData[i].truckCode, size * sizeof(int)) == 0) /*"memcmp" realiza una compararcion,verifica si el codigoDelCamion coincide con el codigo en la posicion "i"*/ 
		{
			position = i;
			break;
		}
	}
	return position;

}

void showTrucks()
{
	if (lastReg == 0)
	{
		cout << "No hay registro\n";
		return;
	}
	for (int i = 0; i < lastReg; i++)
	{
		showTruck(i);
	}
}

void uptadeTruck(trucks data, int pos)
{
	trucksData[pos] = data;
}

void deleteTruck (int pos)
{
	if (pos == lastReg)
	{
		cout << "No hay registro/n" << endl;
		return;
	}
	for (int i = pos; i < lastReg - 1; i++)
	{
		trucksData[i] = trucksData[i + 1];
	}
	lastReg--;
	startTruck(lastReg);

}

void startTruck(int pos)
{
	/*"memset" establece las cadnas de caracteres segun correspondan por que 
	"strcpy" da error con los datos de truckYear*/
    memset(trucksData[pos].truckBrand, 0, sizeof(trucksData[pos].truckBrand));
    memset(trucksData[pos].truckYear, 0, sizeof(trucksData[pos].truckYear));
    memset(trucksData[pos].refr, 0, sizeof(trucksData[pos].refr));
    memset(trucksData[pos].vehicleType, 0, sizeof(trucksData[pos].vehicleType));
    memset(trucksData[pos].truckCode, 0, sizeof(trucksData[pos].truckCode));
    memset(trucksData[pos].truckPlate, 0, sizeof(trucksData[pos].truckPlate));
    memset(trucksData[pos].driver, 0, sizeof(trucksData[pos].driver));
    memset(trucksData[pos].truckStatus, 0, sizeof(trucksData[pos].truckStatus));

}