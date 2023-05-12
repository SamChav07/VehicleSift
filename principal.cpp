#include <iostream>
#include "login.h"
#include "mainmenu.h"

using namespace std;

int main()
{
    if (accSys())
    {
        mainmenu();
    } 
    
    return 0;
}