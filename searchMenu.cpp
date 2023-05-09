#include <iostream>
using namespace std;
int main()
{
    int opciones;
    do
    {
        cout << "MENU" << endl;
        cout << "1. Marca del camión." << endl;
        cout << "2. Modelo del camión." << endl;
        cout << "3. Año de fabricación." << endl;
        cout << "4. Tipo de camión (Refrigerado o sin refrigeración)." << endl;
        cout << "5. Capacidad de carga (Toneladas)." << endl;
        cout << "6. Código de camión." << endl;
        cout << "7. Placa del camión." << endl;
        cout << "8. Conductor del camión (con fecha de asignación al camión)." << endl;
        cout << "9. Salir..." << endl;

        cout << "Selecione una opción: ";
        cin >> opciones;

        switch (opciones)
        {
        case 1:
            cout << "Ingresaste a:" << endl;
            cout << "Marca del camión..." << endl;

            break;
        case 2:
            cout << "Ingresaste a:" << endl;
            cout << "Modelo del camión..." << endl;

            break;
        case 3:
            cout << "Ingresaste a:" << endl;
            cout << "Año de fabricación..." << endl;

            break;
        case 4:
            cout << "Ingresaste a:" << endl;
            cout << "Tipo de camión..." << endl;

            break;
        case 5:
            cout << "Ingresaste a:" << endl;
            cout << "Capacidad de carga..." << endl;

            break;
        case 6:
            cout << "Ingresaste a:" << endl;
            cout << "Código del camión..." << endl;

            break;
        case 7:
            cout << "Ingresaste a:" << endl;
            cout << "Placa del camión..." << endl;

            break;
        case 8:
            cout << "Ingresaste a:" << endl;
            cout << "Conductor del camión..." << endl;
            
            break;
        default:
            cout << "Opción Invalida. Seleccione una opción del 1 al 8..." << endl;
            break;
        }
    } while (opciones != 9);

    return 0;
}