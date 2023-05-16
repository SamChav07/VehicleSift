#ifndef TRUCKSTRUCTURE_H
#define TRUCKSTRUCTURE_H
#define MAX 100

typedef struct 
{
    char truckBrand[50];
    int truckYear[4];
    char refr[2];
    char vehicleType[8];
    int truckCode[8];
    char truckPlate[7];
    char driver[20];
    char truckStatus[10];

}trucks;

typedef struct 
{
    char name[30];
    char lastName[30];
    char iDriver[8];
    char status[8];
    char assignedVehicle[50];
    int truckCode[8];
    char truckStatus[10];
}driver;

extern trucks trucksData[MAX]; //extern es para una variabe que esta en otro archivo.
extern int lastReg;//aqui es lo mismo con el extern

void addTruck(trucks data);
void showTruck(int pos);
trucks getTruck(int pos);
int isTruck(int code[]);
void showTrucks();
void uptadeTruck(trucks data, int pos);
void deleteTruck(int pos);
void startTruck(int pos);
int menu();
void start();

#endif