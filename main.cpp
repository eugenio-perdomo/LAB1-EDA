#include <iostream>
#include <string.h>
#include "Definiciones.h"
#include "Funciones.cpp"

using namespace std;

int main()
{
    bool flag = true;
    string palabra;
    while(flag == true){
        getline(cin,palabra,'\n');

        if(palabra.compare("DIR") == 0)
        if(palabra.compare("CREATE") == 0)
        if(palabra.compare("IF") == 0)
        if(palabra.compare("TYPE") == 0)
        if(palabra.compare("DELETE") == 0)
        if(palabra.compare("BF") == 0)
        if(palabra.compare("CAT") == 0)
        if(palabra.compare("IC") == 0)
        if(palabra.compare("BC") == 0)
        if(palabra.compare("UNDELETE") == 0)
        if(palabra.compare("FIN") == 0)
        flag = false;
    }
    return 0;
}
