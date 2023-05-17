#include <iostream>
#include <string>
#include "auxiliar.h"
#include "structure.h"

using namespace std;

int lastReg = 0;
// login
void login();

// Create
void addTruck(trucks tru);
void initializeTrucks(int pos);
// Read
void searchmenu();
// Update
void updateTruck(trucks tru, int pos);
// Delete

// Menu
void mainmenu();

//Archivos
FILE *truckRegister;
void saveTrucks();
void readTrucks();
int calcLastRegister(FILE *archivo);

void addTruck(trucks tru)
{
    trucksData[lastReg] = tru;
    lastReg++;
}

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
            system("pause");
            system("cls");
        }
        else
        {
            cout << "Acceso denegado..." << endl;
            cout << "*** Presione enter para volver a introdocir las credenciales ***" << endl;
            system("pause");
            system("cls");
        }

    } while (login != 1);
}

void mainmenu()
{
    trucks tru;
    int actions;
    readTrucks();
    do
    {
        system("cls");
        cout << "<<-- MENU DE ACCIONES -->>" << endl;
        cout << "*** Que accion deseas realizar ***" << endl;
        cout << "1. Buscar." << endl;
        cout << "2. Añadir datos." << endl;
        cout << "3. Modificar datos." << endl;
        cout << "4. Eliminar datos." << endl;
        cout << "5. Salir..." << endl;

        cout << "Seleccione una opcion: ";
        cin >> actions;

        switch (actions)
        {
        case 1:
            system("cls");
            cout << "Ingresaste al buscador de camiones: " << endl;
            searchmenu();

            break;
        case 2:
            system("cls");
            cout << "Ingresaste a la opcion 2: " << endl;
            cout << "*** Ingresa los datos a añadir ***" << endl;

            gotoxy(10, 5);
            cout << "Codigo de vehiculo: ";
            gotoxy(10, 6);
            cout << "Tipo de vehiculo: ";
            gotoxy(10, 7);
            cout << "Marca: ";
            gotoxy(10, 8);
            cout << "Año de fabricacion: ";
            gotoxy(10, 9);
            cout << "Placa: ";
            gotoxy(10, 10);
            cout << "Refrigeracion: ";
            gotoxy(10, 11);
            cout << "Conductor: ";
            gotoxy(40, 5);
            cin>>tru.truckCode;
            gotoxy(40, 6);

            break;
        case 3:
            system("cls");
            cout << "Ingresaste a la opcion 3: " << endl;
            cout << "*** Ahora puedes modificar datos ***" << endl;
            system("pause");
            system("cls");

            break;
        case 4:
            system("cls");
            cout << "Ingresaste a la opcion 4: " << endl;
            cout << "*** Ahora puedes eliminar datos ***" << endl;
            system("pause");
            system("cls");

            break;
        case 5:

            break;

        default:
            cout << "Opcion Invalida. Seleccione una opcion del 1 al 5..." << endl;
            break;
        }
    } while (actions != 5);
    saveTrucks();
}

void searchmenu()
{
    int options;
    do
    {
        cout << "MENU" << endl;
        cout << "1. Marca del camion." << endl;
        cout << "2. Modelo del camion." << endl;
        cout << "3. Año de fabricacion." << endl;
        cout << "4. Tipo de camion (Refrigerado o sin refrigeracion)." << endl;
        cout << "5. Capacidad de carga (Toneladas)." << endl;
        cout << "6. Codigo de camion." << endl;
        cout << "7. Placa del camion." << endl;
        cout << "8. Conductor del camion (con fecha de asignacion al camion)." << endl;
        cout << "9. Salir..." << endl;

        cout << "Selecione una opcion: ";
        cin >> options;

        switch (options)
        {
        case 1:
            system("cls");
            cout << "Ingresaste a:" << endl;
            cout << "Marca del camion..." << endl;
            system("pause");
            system("cls");
            break;
        case 2:
            cout << "Ingresaste a:" << endl;
            cout << "Modelo del camion..." << endl;

            break;
        case 3:
            cout << "Ingresaste a:" << endl;
            cout << "Año de fabricacion..." << endl;

            break;
        case 4:
            cout << "Ingresaste a:" << endl;
            cout << "Tipo de camion..." << endl;

            break;
        case 5:
            cout << "Ingresaste a:" << endl;
            cout << "Capacidad de carga..." << endl;

            break;
        case 6:
            cout << "Ingresaste a:" << endl;
            cout << "Codigo del camion..." << endl;

            break;
        case 7:
            cout << "Ingresaste a:" << endl;
            cout << "Placa del camion..." << endl;

            break;
        case 8:
            cout << "Ingresaste a:" << endl;
            cout << "Conductor del camion..." << endl;

            break;

        case 9:
            system("cls");
            cout<<"Saliendo del menu de busqueda..."<<endl;
            system("pause");
            system("cls");
            break;
        default:
            cout << "Opcion Invalida. Seleccione una opcion del 1 al 8..." << endl;
            break;
        }
    } while (options != 9);
}

void updateTruck(trucks tru, int pos)
{
    trucksData[pos] = tru;
}

void initializeTrucks(int pos)
{

    strcpy(trucksData[pos].truckBrand, "");
    strcpy(trucksData[pos].truckPlate, "");
    strcpy(trucksData[pos].driver, "");
    trucksData[pos].truckYear = 0;
    strcpy(trucksData[pos].refr, "");
    trucksData[pos].truckCode = 0; 
    strcpy(trucksData[pos].vehicleType, "");

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

    // Calcular el número de alumnos
    num_trucks = tam_archivo / sizeof(trucks);
    return num_trucks;
}