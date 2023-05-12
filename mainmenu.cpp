#include <iostream>
#include "mainmenu.h"

using namespace std;

void mainmenu()
{
    int actions;
    do 
    {
        cout << "<<-- MENU DE ACCIONES -->>"
        cout << "*** Que acción deseas realizar ***" << endl;
        cout << "1. Buscar." << endl;
        cout << "2. Añadir datos." << endl;
        cout << "3. Modificar datos." << endl;
        cout << "4. Eliminar datos." << endl; 
        cout << "5. Salir..." << endl;

        cout << "Seleccione una opción: ";
        cin >> actions;

        switch (actions)
        {
        case 1:
            cout << "Ingresaste al buscador de camiones: " << endl;
            cout << " " << endl;

            break;
        case 2:
            cout << "Ingresaste a la opción 2: " << endl;
            cout << "*** Ahora puedes añadir datos ***" << endl;

            break;
        case 3:
            cout << "Ingresaste a la opción 3: " << endl;
            cout << "*** Ahora puedes modificar datos ***" << endl;

            break;
        case 4:
            cout << "Ingresaste a la opción 4: " << endl;
            cout << "*** Ahora puedes eliminar datos ***"

        break;

        default:
            cout << "Opción Invalida. Seleccione una opción del 1 al 4..." << endl;
            break;

        }
    } while (actions !=5);
}