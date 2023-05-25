#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cstdlib>
#include <cstring>
#include "auxiliar.h"
#include "structure.h"

using namespace std;

int lastReg = 0;
// login
void login();

// Create
void addTruckRegister(trucks currentTruck);
void initializeTrucks(int pos);
// Read
void searchmenu();
int searchTruckCode(char code[]);
int searchTruckPlate(char plate[]);
int searchTruckBrand(char brand[]);
int searchTruckYear(int year);
int searchVehicleType(char type[]);
int searchRefr(char refr[]);
void showTruck(int pos);
void showTrucksRegister();
trucks getTruck(int pos);
// Update
void updateTruck(trucks currentTruck, int pos);
// Delete
void deleteTruck(int pos);
// Menu
void mainmenu();

// Archivos
FILE *truckRegister;
void saveTrucks();
void readTrucks();
int calcLastRegister(FILE *archivo);

void login()
{
    string password;
    string username;
    int login = 0;
    do
    {

        cout << "Bienvenido a VehicleSift " << endl;
        cout << "Escriba su usuario: " << endl;
        cin >> username;
        cout << "Escriba su contraseña: " << endl;
        cin >> password;

        if (username == "Admin" && password == "Tmolina")
        {

            cout << "Acceso concedidio" << endl;
            login = 1;
            system("pause || read -p 'Presiona Enter para continuar...' -n 1 -s");
            system("cls || clear");
        }
        else
        {
            cout << "Acceso denegado..." << endl;
            cout << "*** Presione enter para volver a introdocir las credenciales ***" << endl;
            system("pause || read -p 'Presiona Enter para continuar...' -n 1 -s");
            system("cls || clear");
        }

    } while (login != 1);
}

void addTruckRegister(trucks currentTruck)
{
    trucksData[lastReg] = currentTruck;
    lastReg++;
}

void initializeTrucks(int pos)
{

    strcpy(trucksData[pos].truckCode, "");
    strcpy(trucksData[pos].truckPlate, "");
    strcpy(trucksData[pos].truckBrand, "");
    trucksData[pos].truckYear = 0;
    strcpy(trucksData[pos].vehicleType, "");
    strcpy(trucksData[pos].refr, "");
    strcpy(trucksData[pos].driverInfo.driverName, "");
    strcpy(trucksData[pos].driverInfo.driverLastname, "");
}

void searchmenu() //TRABAJAR EN ESTA FUNCION, FALTA UN GOTOXY PARA EL MENU
{
    int options, pos;
    char enteredTruckCode[10];
    char enteredTruckPlate[30];
    char enteredTruckBrand[30];
    int enteredTruckYear;
    char enteredVehicleType[30];
    char enteredrefr[4];
    do
    {
        system("cls || clear");
        gotoxy (10, 4);
        cout << "** Menu de busqueda **" << endl;
        gotoxy(10, 6);
        cout << "1. Codigo de vehiculo." << endl;
        gotoxy(10, 7);
        cout << "2. Placa de vehiculo." << endl;
        gotoxy(10, 8);
        cout << "3. Marca de vehiculo." << endl;
        gotoxy(10, 9);
        cout << "4. Año de vehiculo." << endl;
        gotoxy(10, 10);
        cout << "5. Tipo de vehiculo." << endl;
        gotoxy(10, 11);
        cout << "6. Refrigeracion." << endl;
        gotoxy(10, 12);
        cout << "7. Conductor" << endl;
        gotoxy(10, 13);
        cout << "8. Mostrar todos los registros..." << endl;
        gotoxy(10, 14);
        cout << "9. Salir"
        gotoxy(10, 15);
        cout << "Selecione una opcion: ";
        cin >> options;

        switch (options)
        {
        case 1:
            system("cls || clear");
            cout << "Buscar por codigo de vehiculo:" << endl;
            cout << "Escribe el codigo a buscar: ";
            scanf(" %[^\n]", enteredTruckCode); //asi se deberian ver todas las funciones cuando sean implementadas
            pos = searchTruckCode(enteredTruckCode);
            if (pos!=-1)
            {
                showTruck(pos);
            }
            else
            {
                cout<<"Registro inexistente" << endl;
            }
            

            system("pause || read -p 'Presiona Enter para continuar...' -n 1 -s");
            system("cls || clear");
            break;
        case 2:
             system("cls || clear");
            cout << "Busqueda por placa de vehiculo:" << endl;
            cout << "Escribe la placa a buscar: ";
            scanf(" %[^\n]", enteredTruckPlate);
            pos = searchTruckPlate(enteredTruckPlate);
            if (pos != -1)
            {
                showTruck(pos);
            }
            else
            {
                cout << "Registro inexistente" << endl;
            }
            system("pause || read -p 'Presiona Enter para continuar...' -n 1 -s");
            system("cls || clear");
            break;

        case 3:
            system("cls || clear");
            cout << "Busqueda por marca de vehiculo:" << endl;
            cout << "Escribe la marca del vehiculo: ";
            scanf(" %[^\n]", enteredTruckBrand);
            pos = searchTruckBrand(enteredTruckBrand);
            if (pos != -1)
            {
                showTruck(pos);
            }
            else
            {
                cout << "Registro inexistente" << endl;
            }
            system("pause || read -p 'Presiona Enter para continuar...' -n 1 -s");
            system("cls || clear");
            break;

        case 4:
           system("cls || clear");
            cout << "Busqueda por año de fabricación:" << endl;
            cout << "Escriba el año de fabricación: ";
            cin >> enteredTruckYear;
            pos = searchTruckYear(enteredTruckYear);
            if (pos != -1)
            {
                showTruck(pos);
            }
            else
            {
                cout << "Registro inexistente" << endl;
            }
            system("pause || read -p 'Presiona Enter para continuar...' -n 1 -s");
            system("cls || clear");
            break;

        case 5:
            system("cls || clear");
            cout << "Busqueda por tipo de vehiculo:" << endl;
            cout << "Escriba el tipo de vehiculo";
            system("cls || clear");
            cout << "Busqueda de cabezales..." << endl;
            cin >> enteredVehicleType;
            pos = searchVehicleType(enteredVehicleType);
            if (pos != -1)
            {
                showTruck(pos);
            }
            else
            {
                cout << "Registro inexistente" << endl;
            }
            system("pause || read -p 'Presiona Enter para continuar...' -n 1 -s");
            system("cls || clear");
            break;

        case 6:
            system("cls || clear");
            cout << "Busqueda por refrigeracion..." << endl;
            cout << "Posee refrigeracion el vehiculo? SI/NO "
            cin >> enteredrefr;
            pos = searchRefr(enteredrefr);
            if (pos != -1)
            {
                showTruck(pos);
            }
            else
            {
                cout << "Registro inexistente" << endl;
            }
            system("pause || read -p 'Presiona Enter para continuar...' -n 1 -s");
            system("cls || clear");

            break;
        case 7:
            cout << "Ingresaste a:" << endl;
            cout << "Conductor del camion..." << endl;

            break;
        case 8:
            cout << "Visualizando todos los datos..." << endl;
            showTrucksRegister();
            system("pause");

            break;

        case 9:
            system("cls || clear");
            cout << "Saliendo del menu de busqueda..." << endl;
            system("pause || read -p 'Presiona Enter para continuar...' -n 1 -s");
            system("cls || clear");
            break;
        default:
            cout << "Opcion Invalida. Seleccione una opcion del 1 al 8..." << endl;
            break;
        }
    } while (options != 9);
}

int searchTruckCode(char enteredTruckCode[])
{
    int position = -1;
    for (int i = 0; i < lastReg; i++)
    {
        if (strcmp(enteredTruckCode, trucksData[i].truckCode) == 0)
        {
            position = i;
            break;
        }
    }
    return position;
}

int searchTruckPlate(char enteredTruckPlate[])
{
    int position = -1;
    for (int i = 0; i < lastReg; i++)
    {
        if (strcmp(enteredTruckPlate, trucksData[i].truckPlate) == 0)
        {
            position = i;
            break;
        }
    }
    return position;
}

int searchTruckBrand(char enteredTruckBrand[])
{
    int position = -1;
    for (int i = 0; i < lastReg; i++)
    {
        if (strcmp(enteredTruckBrand, trucksData[i].truckBrand) == 0)
        {
            position = i;
            break;
        }
    }
    return position;
}

int searchTruckYear(int enteredTruckYear)
{
    int position = -1;
    for (int i = 0; i < lastReg; i++)
    {
        if (enteredTruckYear == trucksData[i].truckYear)
        {
            position = i;
            break;
        }
    }
    return position;
}

int searchVehicleType(char enteredVehicleType[])
{
    int position = -1;
    for (int i = 0; i < lastReg; i++)
    {
        if (strcmp(enteredVehicleType, trucksData[i].vehicleType) == 0)
        {
            position = i;
            break;
        }
    }
    return position;
}

int searchRefr(char enteredRefr[])
{
    int position = -1;
    for (int i = 0; i < lastReg; i++)
    {
        if (strcmp(enteredRefr, trucksData[i].refr) == 0)
        {
            position = i;
            break;
        }
    }
    return position;
}

void showTruck(int pos)
{
    cout << endl;
    cout << "Codigo de vehiculo: " << trucksData[pos].truckCode << endl;
    cout << "Placa de vehiculo: " << trucksData[pos].truckPlate << endl;
    cout << "Marca de vehiculo: " << trucksData[pos].truckBrand << endl;
    cout << "Año de vehiculo: " << trucksData[pos].truckYear << endl;
    cout << "Tipo de vehiculo: " << trucksData[pos].vehicleType << endl;
    cout << "Refrigeracion: " << trucksData[pos].refr << endl;
    cout << "Conductor: " << trucksData[pos].driverInfo.driverName << " " << trucksData[pos].driverInfo.driverLastname << endl;
}

void showTrucksRegister()
{
    system("cls||clear");
    if (lastReg == 0)
    {
        cout << "No hay registros" << endl;
        return;
    }
    for (int i = 0; i < lastReg; i++)
    {
        cout << "=========================" << endl;
        showTruck(i);
    }
    cout << "Ultimo registro..." << endl;
}

trucks getTruck(int pos)
{
    return trucksData[pos];
}

void updateTruck(trucks currentTruck, int pos)
{
    trucksData[pos] = currentTruck;
}

void deleteTruck(int pos)
{
    if (pos == lastReg)
    {
        cout << "No hay registros " << endl;
        return;
    }
    for (int i = pos; i < lastReg - 1; i++)
    {
        truckRegister[i] = truckRegister[i + 1];
    }
    lastReg--;
    initializeTrucks(lastReg);
}

void mainmenu()
{
    trucks currentTruck;
    int actions, pos, resp;
    char enteredTruckCode[10];
    readTrucks();
    do
    {
        system("cls || clear");
        gotoxy(10, 5);
        cout << " Bienvenido a VehicleSift" << endl;
        gotoxy(15, 6);
        cout << "Cantidad de registros: " << lastReg << endl;
        gotoxy(10, 9);
        cout << " 1. Agregar Vehiculo " << endl;
        gotoxy(10, 10);
        cout << " 2. Modificar Vehiculo " << endl;
        gotoxy(10, 11);
        cout << " 3. Eliminar Vehiculo " << endl;
        gotoxy(10, 12);
        cout << " 4. Buscar Vehiculo " << endl;
        gotoxy(10, 13);
        cout << " 5. Mostrar todos los Vehiculos " << endl;
        gotoxy(10, 14);
        cout << " 6. Salir " << endl;
        gotoxy(10, 15);
        cout << " Digite la opcion: ";
        gotoxy(29, 15);
        cin >> actions;

        switch (actions)
        {
        case 1:
            system("cls || clear");
            cout << "Ingresaste a la opcion 2: " << endl;
            cout << "*** Ingresa los datos a añadir ***" << endl;
            system("cls || clear");
            gotoxy(10, 5);
            cout << "Codigo de vehiculo:" << endl;
            gotoxy(10, 6);
            cout << "Placa de vehiculo: " << endl;
            gotoxy(10, 7);
            cout << "Marca de vehiculo: " << endl;
            gotoxy(10, 8);
            cout << "Año de vehiculo: " << endl;
            gotoxy(10, 9);
            cout << "Tipo de vehiculo: " << endl;
            gotoxy(10, 10);
            cout << "Refrigeracion: " << endl;
            gotoxy(10, 11);
            cout << "Conductor asignado: " << endl;
            gotoxy(35, 5);
            scanf(" %[^\n]", currentTruck.truckCode);
            gotoxy(35, 6);
            scanf(" %[^\n]", currentTruck.truckPlate);
            gotoxy(35, 7);
            scanf(" %[^\n]", currentTruck.truckBrand);
            gotoxy(35, 8);
            cin >> currentTruck.truckYear;
            gotoxy(35, 9);
            scanf(" %[^\n]", currentTruck.vehicleType);
            gotoxy(35, 10);
            scanf(" %[^\n]", currentTruck.refr);
            gotoxy(35, 11);
            scanf(" %[^\n]", currentTruck.driverInfo.driverName); // currentTruck.driverInfo.driverLastname);
            addTruckRegister(currentTruck);
            system("pause || read -p 'Presiona Enter para continuar...' -n 1 -s");

            break;
        case 2:

            system("cls||clear");
            cout << "Escribe el codigo a buscar: ";
            scanf(" %[^\n]", enteredTruckCode);
            pos = searchTruckCode(enteredTruckCode);
            showTruck(pos);
            gotoxy(50, 0);
            cout << "Datos a modificar " << endl;
            gotoxy(50, 1);
            cout << "Codigo de vehiculo:";
            gotoxy(50, 2);
            cout << "Placa de vehiculo: ";
            gotoxy(50, 3);
            cout << "Marca de vehiculo: ";
            gotoxy(50, 4);
            cout << "Año de vehiculo: ";
            gotoxy(50, 5);
            cout << "Tipo de vehiculo: ";
            gotoxy(50, 6);
            cout << "Refrigeracion: ";
            gotoxy(50, 7);
            cout << "Conductor asignado: ";
            gotoxy(0, 0);
            cout << "Datos actuales:                               ";
            gotoxy(70, 1);
            scanf(" %[^\n]", currentTruck.truckCode);
            gotoxy(68, 2);
            scanf(" %[^\n]", currentTruck.truckPlate);
            gotoxy(57, 3);
            scanf(" %[^\n]", currentTruck.truckBrand);
            gotoxy(72, 4);
            cin >> currentTruck.truckYear;
            gotoxy(57, 5);
            scanf(" %[^\n]", currentTruck.vehicleType);
            gotoxy(64, 6);
            scanf(" %[^\n]", currentTruck.refr);
            gotoxy(61, 7);
            scanf(" %[^\n]", currentTruck.driverInfo.driverName); // currentTruck.driverInfo.driverLastname);
            cout << "Registro actualizado...\n";
            system("cls || clear");
            updateTruck(currentTruck, pos);
            system("pause || read -p 'Presiona Enter para continuar...' -n 1 -s");

            break;
        case 3:

            system("cls||clear");
            if (lastReg == 0)
            {
                cout << "No hay nada que eliminar\n";
                break;
            }
            cout << "Escribe el ID del estudiante: ";
            cin >> enteredTruckCode;
            pos = searchTruckCode(enteredTruckCode);
            currentTruck = getTruck(pos);
            cout << "¿Realmente deseas eliminar el vehiculo: " << currentTruck.truckCode << "?\n";
            cout << "Escribe 1 para SI o 2 para NO: ";
            cin >> resp;
            if (resp == 1)
            {
                deleteTruck(pos);
                cout << "Registro Eliminado... \n";
            }
            else
            {
                cout << "Operacion cancelada.... \n";
            }
            system("pause || read -p 'Presiona Enter para continuar...' -n 1 -s");
            break;

        case 4:

            system("cls || clear");
            cout << "Ingresaste al buscador de camiones: " << endl;
            searchmenu();

            break;
        case 5:
            system("cls||clear");
            showTrucksRegister();
            system("pause || read -p 'Presiona Enter para continuar...' -n 1 -s");

            break;

        case 6:

            break;
        default:
            cout << "Opcion Invalida. Seleccione una opcion del 1 al 5..." << endl;
            break;
        }
    } while (actions != 6);
    saveTrucks();
}

void saveTrucks()
{
    truckRegister = fopen("datos.bin", "wb");
    fwrite(trucksData, sizeof(trucks), lastReg, truckRegister);
    fclose(truckRegister);
}

void readTrucks()
{
    truckRegister = fopen("datos.bin", "rb");
    if (truckRegister == NULL)
    {
        return;
    }
    lastReg = calcLastRegister(truckRegister);
    fread(trucksData, sizeof(trucks), MAX, truckRegister);

    fclose(truckRegister);
}

int calcLastRegister(FILE *archivo)
{
    int tam_archivo, num_trucks;
    // Obtener el tamaño del archivo
    fseek(archivo, 0, SEEK_END);
    tam_archivo = ftell(archivo);
    rewind(archivo);

    // Calcular el número de vehiculos
    num_trucks = tam_archivo / sizeof(trucks);
    return num_trucks;
}