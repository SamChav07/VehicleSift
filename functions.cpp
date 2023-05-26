#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cstdlib>
#include <cstring>
#include "auxiliar.h"
#include "structure.h"

using namespace std;

int lastDriverReg = 0;
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
void searchTruckBrand(char brand[]);
void searchTruckYear(int year);
void searchVehicleType(char type[]);
void searchRefr(char refr[]);
void searchStatus(char status[]);
void showTruck(int pos);
void showTrucksRegister();
trucks getTruck(int pos);
// Update
void updateTruck(trucks currentTruck, int pos);
// Delete
void deleteTruck(int pos);
// Menu
void mainmenu();

// Seccion conductores
void addDriverRegister(drivers currentDriver);
void initializeDriver(int driverPos);
int searchDriverID(char id[]);
void showDriverData(int driverPos);
void showDriversRegister();
drivers getDriver(int driverPos);
void updateDrivers(drivers currentDriver, int driverPos);
void deleteDriver(int driverPos);
// Archivos para conductores
FILE *driversRegister;
void saveDrivers();
void readDrivers();
int calcLastDriversRegister(FILE *archivoConductores);

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
            mainmenu();
            system("pause || read -p 'Presiona Enter para continuar...' -n 1 -s");
            system("cls || clear");
        } 
        else if (username == "User1" && password == "12345")
        {
            cout << "Acceso concedidio" << endl;
            login = 1;
            searchmenu();
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
    strcpy(trucksData[pos].status, "");
}

void searchmenu() // TRABAJAR EN ESTA FUNCION, FALTA UN GOTOXY PARA EL MENU
{
    int options, pos;
    char enteredTruckCode[10];
    char enteredTruckPlate[30];
    char enteredTruckBrand[30];
    int enteredTruckYear;
    char enteredVehicleType[30];
    char enteredrefr[4];
    char enteredStatus[15];
    do
    {
        system("cls || clear");
        gotoxy(10, 4);
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
        cout << "7. Estado." << endl;
        gotoxy(10, 13);
        cout << "8. Mostrar todos los registros..." << endl;
        gotoxy(10, 14);
        cout << "9. Salir";
        gotoxy(10, 15);
        cout << "Selecione una opcion: ";
        cin >> options;

        switch (options)
        {
        case 1:
            system("cls || clear");
            cout << "Buscar por codigo de vehiculo:" << endl;
            cout << "Escribe el codigo a buscar: ";
            scanf(" %[^\n]", enteredTruckCode);
            pos = searchTruckCode(enteredTruckCode);
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
            searchTruckBrand(enteredTruckBrand);
            system("pause || read -p 'Presiona Enter para continuar...' -n 1 -s");
            system("cls || clear");
            break;

        case 4:
            system("cls || clear");
            cout << "Busqueda por año de fabricación:" << endl;
            cout << "Escriba el año de fabricación: ";
            cin >> enteredTruckYear;
            searchTruckYear(enteredTruckYear);
            system("pause || read -p 'Presiona Enter para continuar...' -n 1 -s");
            system("cls || clear");
            break;

        case 5:
            system("cls || clear");
            cout << "Busqueda por tipo de vehiculo:" << endl;
            cout << "Escriba el tipo de vehiculo";
            cin >> enteredVehicleType;
            searchVehicleType(enteredVehicleType);
            system("pause || read -p 'Presiona Enter para continuar...' -n 1 -s");
            system("cls || clear");
            break;

        case 6:
            system("cls || clear");
            cout << "Busqueda por refrigeracion..." << endl;
            cout << "Posee refrigeracion el vehiculo? SI/NO ";
            cin >> enteredrefr;
            searchRefr(enteredrefr);
            system("pause || read -p 'Presiona Enter para continuar...' -n 1 -s");
            system("cls || clear");

            break;
        case 7:
            cout << "Busqueda por estado: " << endl;
            cout << "'En viaje' o 'Inactivo'? " << endl;
            cin >> enteredStatus;
            searchStatus(enteredStatus);
            system("pause || read -p 'Presiona Enter para continuar...' -n 1 -s");
            system("cls || clear");

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

void searchTruckBrand(char enteredTruckBrand[])
{
    int count = 0;
    for (int i = 0; i < lastReg; i++)
    {
        if (strcmp(enteredTruckBrand, trucksData[i].truckBrand) == 0)
        {
            cout << "=========================" << endl;
            showTruck(i);
            count++;
        }
        if (count == 0)
        {
            cout << "No se encontraron resultados " << endl;
        }
    }
}

void searchTruckYear(int enteredTruckYear)
{

    int count = 0;
    for (int i = 0; i < lastReg; i++)
    {
        if (enteredTruckYear == trucksData[i].truckYear)
        {
            cout << "=========================" << endl;
            showTruck(i);
            count++;
        }
        if (count == 0)
        {
            cout << "No se encontraron resultados " << endl;
        }
    }
}

void searchVehicleType(char enteredVehicleType[])
{
    int count = 0;
    for (int i = 0; i < lastReg; i++)
    {
        if (strcmp(enteredVehicleType, trucksData[i].vehicleType) == 0)
        {
            cout << "=========================" << endl;
            showTruck(i);
            count++;
        }
        if (count == 0)
        {
            cout << "No se encontraron resultados " << endl;
        }
    }
}

void searchRefr(char enteredRefr[])
{
    int count = 0;
    for (int i = 0; i < lastReg; i++)
    {
        if (strcmp(enteredRefr, trucksData[i].refr) == 0)
        {
            cout << "=========================" << endl;
            showTruck(i);
            count++;
        }
        if (count == 0)
        {
            cout << "No se encontraron resultados " << endl;
        }
    }
}

void searchStatus(char enteredStatus[])
{

    int count = 0;
    for (int i = 0; i < lastReg; i++)
    {
        if (strcmp(enteredStatus, trucksData[i].status) == 0)
        {
            cout << "=========================" << endl;
            showTruck(i);
            count++;
        }
        if (count == 0)
        {
            cout << "No se encontraron resultados " << endl;
        }
    }
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
    cout << "Estado: " << trucksData[pos].status << endl;

    if (strcmp(trucksData[pos].status, "En viaje") == 0)
    {

        cout << "Conductor asignado: " << driversData[pos].driverName << endl;
        cout << "ID del conductor: " << driversData[pos].id << endl;
        cout << "Fecha de asignacion: " << driversData[pos].assignDate.day << "/" << driversData[pos].assignDate.month << "/" << driversData[pos].assignDate.year << endl;
    }
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
        trucksData[i] = trucksData[i + 1];
    }
    lastReg--;
    initializeTrucks(lastReg);
}

void mainmenu()
{
    trucks currentTruck;
    drivers currentDriver;
    int actions, pos, resp, driverPos;
    char enteredTruckCode[10];
    char enteredDriverID[10];
    readTrucks();
    readDrivers();
    do
    {
        system("cls || clear");
        gotoxy(10, 5);
        cout << " Bienvenido a VehicleSift" << endl;
        gotoxy(11, 6);
        cout << "Cantidad de registros de vehiculos: " << lastReg;
        gotoxy(60, 6);
        cout << " Cantidad de registros de conductores: " << lastDriverReg << endl;
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
        cout << " 6. Añadir Conductor " << endl;
        gotoxy(10, 15);
        cout << " 7. Modificar Conductor " << endl;
        gotoxy(10, 16);
        cout << " 8. Eliminar Conductor " << endl;
        gotoxy(10, 17);
        cout << " 9. Mostrar todos los conductores " << endl;
        gotoxy(10, 18);
        cout << " 10. Modificar asignacion " << endl;
        gotoxy(10, 19);
        cout << " 11. Cerrar Sesion." << endl;
        gotoxy(10, 20);
        cout << " 12. Salir del programa.";
        gotoxy(10, 21);
        cout << " Digite la opcion: ";
        gotoxy(29, 21);
        cin >> actions;

        switch (actions)
        {
        case 1:
            system("cls || clear");
            cout << "* Ingresa los datos a añadir *" << endl;
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
            cout << "Estado: " << endl;
            gotoxy(10, 12);
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
            scanf(" %[^\n]", currentTruck.status);
            if (strcmp(currentTruck.status, "En viaje") == 0)
            {

                gotoxy(10, 12);
                cout << "Conductor asignado: " << endl;
                scanf(" %[^\n]", currentDriver.driverName);
                gotoxy(10, 13);
                cout << "ID del conductor a asignar ";
                scanf(" %[^\n]", currentDriver.id);
                gotoxy(10, 13);
                cout << "Fecha de asignacion: " << endl;
                scanf("%d/%d/%d", &currentDriver.assignDate.day, &currentDriver.assignDate.month, &currentDriver.assignDate.year);
                addDriverRegister(currentDriver);
            }

            addTruckRegister(currentTruck);
            system("pause || read -p 'Presiona Enter para continuar...' -n 1 -s");

            break;
        case 2:

            system("cls||clear");
            cout << "Escribe el codigo del vehiculo a modificar: ";
            scanf(" %[^\n]", enteredTruckCode);
            pos = searchTruckCode(enteredTruckCode);
            if (pos != -1)
            {
                system("cls || clear");
                showTruck(pos);
                gotoxy(50, 0);
                cout << "Datos a modificar: " << endl;
                gotoxy(50, 2);
                cout << "Codigo de vehiculo:";
                gotoxy(50, 3);
                cout << "Placa de vehiculo: ";
                gotoxy(50, 4);
                cout << "Marca de vehiculo: ";
                gotoxy(50, 5);
                cout << "Año de vehiculo: ";
                gotoxy(50, 6);
                cout << "Tipo de vehiculo: ";
                gotoxy(50, 7);
                cout << "Refrigeracion: ";
                gotoxy(50, 8);
                cout << "Estado: ";
                gotoxy(0, 0);
                cout << "Datos actuales:                               ";
                gotoxy(70, 2);
                scanf(" %[^\n]", currentTruck.truckCode);
                gotoxy(68, 3);
                scanf(" %[^\n]", currentTruck.truckPlate);
                gotoxy(65, 4);
                scanf(" %[^\n]", currentTruck.truckBrand);
                gotoxy(72, 5);
                cin >> currentTruck.truckYear;
                gotoxy(65, 6);
                scanf(" %[^\n]", currentTruck.vehicleType);
                gotoxy(65, 7);
                scanf(" %[^\n]", currentTruck.refr);
                gotoxy(65, 8);
                scanf(" %[^\n]", currentTruck.status);
                if (strcmp(currentTruck.status, "En viaje") == 0)
                {

                    gotoxy(10, 12);
                    cout << "Conductor asignado: " << endl;
                    scanf(" %[^\n]", currentDriver.driverName);
                    gotoxy(10, 13);
                    cout << "ID del conductor a asignar ";
                    scanf(" %[^\n]", currentDriver.id);
                    gotoxy(10, 13);
                    cout << "Fecha de asignacion: " << endl;
                    scanf("%d/%d/%d", &currentDriver.assignDate.day, &currentDriver.assignDate.month, &currentDriver.assignDate.year);
                    updateDrivers(currentDriver, driverPos);
                }

                cout << "Registro actualizado...\n";
                system("cls || clear");
                updateTruck(currentTruck, pos);
            }
            else
            {
                cout << "Registro inexistente" << endl;
            }

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
            if (pos != -1)
            {

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
            }
            else
            {
                cout << "Registro inexistente" << endl;
            }
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
            system("cls || clear");
            cout << "* Ingresa los datos a añadir *" << endl;
            system("cls || clear");
            gotoxy(10, 5);
            cout << "Nombre completo del conductor: " << endl;
            gotoxy(10, 6);
            cout << "ID del conductor: " << endl;
            gotoxy(45, 5);
            scanf(" %[^\n]", currentDriver.driverName);
            gotoxy(30, 6);
            scanf(" %[^\n]", currentDriver.id);
            currentDriver.assignDate.day = 0;
            currentDriver.assignDate.month = 0;
            currentDriver.assignDate.year = 0;
            addDriverRegister(currentDriver);
            system("pause || read -p 'Presiona Enter para continuar...' -n 1 -s");

            break;
        case 7:
            system("cls||clear");
            cout << "Escribe el ID del conductor a modificar: ";
            scanf(" %[^\n]", enteredDriverID);
            driverPos = searchDriverID(enteredDriverID);
            showDriverData(driverPos);
            gotoxy(50, 0);
            cout << "Datos a modificar: " << endl;
            gotoxy(50, 2);
            cout << "Nombre del conductor:";
            gotoxy(50, 3);
            cout << "ID del conductor: ";
            gotoxy(0, 0);
            cout << "Datos actuales:                               ";
            gotoxy(71, 2);
            scanf(" %[^\n]", currentDriver.driverName);
            gotoxy(68, 3);
            scanf(" %[^\n]", currentDriver.id);
            gotoxy(57, 4);
            cout << "Registro actualizado...\n";
            system("cls || clear");
            updateDrivers(currentDriver, driverPos);
            system("pause || read -p 'Presiona Enter para continuar...' -n 1 -s");

            break;

        case 8:

            system("cls||clear");
            if (lastDriverReg == 0)
            {
                cout << "No hay nada que eliminar\n";
                break;
            }
            cout << "Escribe el ID del conductor: ";
            cin >> enteredDriverID;
            pos = searchDriverID(enteredDriverID);
            currentDriver = getDriver(driverPos);
            cout << "¿Realmente deseas eliminar el conductor: " << currentDriver.driverName << "?\n";
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

        case 9:
            system("cls||clear");
            showDriversRegister();
            system("pause || read -p 'Presiona Enter para continuar...' -n 1 -s");

            break;

        case 10:
            system("cls||clear");
            cout << "Escribe el codigo del vehiculo a modificar asignacion: ";
            scanf(" %[^\n]", enteredTruckCode);
            pos = searchTruckCode(enteredTruckCode);
            if (pos != -1)
            {
                showTruck(pos);
                gotoxy(0, 0);
                cout << "Datos actuales:                             ";
                gotoxy(50, 0);
                cout << "Datos a modificar: " << endl;
                gotoxy(50, 2);
                cout << "Estado: ";
                scanf(" %[^\n]", currentTruck.status);
                if (strcmp(currentTruck.status, "En viaje") == 0)
                {

                    gotoxy(10, 12);
                    cout << "Conductor asignado: " << endl;
                    scanf(" %[^\n]", currentDriver.driverName);
                    gotoxy(10, 13);
                    cout << "ID del conductor a asignar ";
                    scanf(" %[^\n]", currentDriver.id);
                    gotoxy(10, 13);
                    cout << "Fecha de asignacion: " << endl;
                    scanf("%d/%d/%d", &currentDriver.assignDate.day, &currentDriver.assignDate.month, &currentDriver.assignDate.year);
                    updateDrivers(currentDriver, driverPos);
                }
                else
                {
                    break;
                }
                updateTruck(currentTruck, pos);
                cout << "Registro actualizado...\n";
                system("cls || clear");
            }
            else
            {
                cout << "Registro inexistente" << endl;
            }
            updateTruck(currentTruck, pos);
            system("pause || read -p 'Presiona Enter para continuar...' -n 1 -s");
            system("cls || clear");

            break;
        case 11:
            system("cls || clear");
            login();
            system("pause || read -p 'Presiona Enter para continuar...' -n 1 -s");
            system("cls || clear");
            break;

        case 12:

            break;

        default:
            cout << "Opcion Invalida. Seleccione una opcion del 1 al 5..." << endl;
            break;

        }
    } while (actions != 12);
    saveDrivers();
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

// Seccion de conductores

void addDriverRegister(drivers currentDriver)
{
    driversData[lastDriverReg] = currentDriver;
    lastDriverReg++;
}

void initializeDriver(int driverPos)
{

    strcpy(driversData[driverPos].driverName, " ");
    strcpy(driversData[driverPos].id, " ");
    driversData[driverPos].assignDate.day = 0;
    driversData[driverPos].assignDate.month = 0;
    driversData[driverPos].assignDate.year = 0;
}

int searchDriverID(char enteredDriverID[])
{

    int position = -1;
    for (int i = 0; i < lastDriverReg; i++)
    {
        if (strcmp(enteredDriverID, driversData[i].id) == 0)
        {
            position = i;
            break;
        }
    }
    return position;
}

void showDriverData(int driverPos)
{
    gotoxy(0, 2);
    cout << "Nombre del conductor: " << driversData[driverPos].driverName << endl;
    gotoxy(0, 3);
    cout << "ID del conductor: " << driversData[driverPos].id << endl;
    gotoxy(0, 4);
    cout << "Fecha de asignacion: " << driversData[driverPos].assignDate.day << "/" << driversData[driverPos].assignDate.month << "/" << driversData[driverPos].assignDate.year << endl;
}

void showDriversRegister()
{
    system("cls||clear");
    if (lastDriverReg == 0)
    {
        cout << "No hay registros" << endl;
        return;
    }
    for (int i = 0; i < lastDriverReg; i++)
    {
        cout << "=========================" << endl;
        showDriverData(i);
    }
    cout << "Ultimo registro..." << endl;
}

drivers getDriver(int driverPos)
{
    return driversData[driverPos];
}

void updateDrivers(drivers currentDriver, int driverPos)
{

    driversData[driverPos] = currentDriver;
}

void deleteDriver(int driverPos)
{

    if (driverPos == lastDriverReg)
    {
        cout << "No hay registros " << endl;
        return;
    }
    for (int i = driverPos; i < lastDriverReg - 1; i++)
    {
        trucksData[i] = trucksData[i + 1];
    }
    lastDriverReg--;
    initializeDriver(lastDriverReg);
}

void saveDrivers()
{

    driversRegister = fopen("datosConductores.bin", "wb");
    fwrite(driversData, sizeof(drivers), lastDriverReg, driversRegister);
    fclose(driversRegister);
}

void readDrivers()
{

    driversRegister = fopen("datosConductores.bin", "rb");
    if (driversRegister == NULL)
    {
        return;
    }
    lastDriverReg = calcLastDriversRegister(driversRegister);
    fread(driversData, sizeof(drivers), MAX, driversRegister);

    fclose(driversRegister);
}

int calcLastDriversRegister(FILE *archivoConductores)
{

    int tam_archivoConductores, num_drivers;
    // Obtener el tamaño del archivo
    fseek(archivoConductores, 0, SEEK_END);
    tam_archivoConductores = ftell(archivoConductores);
    rewind(archivoConductores);

    // Calcular el número de conductores
    num_drivers = tam_archivoConductores / sizeof(drivers);
    return num_drivers;
}