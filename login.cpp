#include <iostream>
#include <string> 

using namespace std;

void accSys();
int credentials(string & username, string & password);

void accSys() 
{
    string enterpassword;
    string enterusername;
    int login;
    do 
    {
        cout << " Bienvenido a VehicleSift " << endl;
        cout << "Escriba su usuario: " << endl;
        cin >> enterusername;
        cout << "Escriba su contraseña: " << endl;
        cin >> enterpassword;

        login = credentials(enterusername,enterpassword);

        if (login == 1)
        {
            cout << "Acceso concedidio" << endl;
        } else {
            cout << "Acceso denegado..." << endl;
            cout << "*** Presione enter para volver a introdocir las credenciales ***" << endl;
            cin.ignore(); // Se cambia cin.get() por cin.ignore()
            
        }
    } while (login != 1);
  
}

int credentials(string & username, string & password)
{
    int confirmation;
    confirmation = 0;
    if (username == "Admin" && password == "Tmolina")
    {
        confirmation = 1;
    }
    return confirmation;
}

int main()
{
    accSys(); // Se agrega esta línea para llamar a la función accSys()
    return 0;
}
