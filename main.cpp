#include <iostream>
#include <string.h>
#include "Definiciones.h"
#include "Funciones.cpp"
using namespace std;
 ///TODO 2 getline dependiendo de nuestra entrada.
int main()
{
    string comando,comnadosinp;
    Directorio d=NULL;
    d=new _directorio;
    //d->nombreDirectorio='/';
    d->dirsig = NULL;
    d->contenido = NULL;
    char nombre_archivo[19];
    bool flag = true;
    while(flag == true)
    {
        getline(cin,comando,'\n');
        cin.clear();
        if(comando.compare("FIN")==0)
        {
            cout << "si";
        }

        else
        {    getline(cin,comando,' ');
            if(comando.compare("CREATE")==0)
            {
                cin.getline(nombre_archivo,19,'\n');
                MuestroRetorno(CREATE(d,nombre_archivo));
            }

            /*if("IF ") == 0)
            if("TYPE ") == 0)
            if("DELETE ") == 0)
            if("BF ") == 0)
            if("CAT ") == 0)
            if("IC ") == 0)
            if("BC ") == 0)
            if("UNDELETE") == 0)*/
            //getline(cin,comnadosinp,'\n');

        }



    }
    return 0;
}
