#include <iostream>
#include <stdio.h>
#include <string.h>

#define TEXTO_MAX 50
#define LARGO_MAX 5
#define LARGONOMBRE 19

using namespace std;
#include "Definiciones.h"
#include "Funciones.cpp"

/** TODO IC aun no funciona
*/
int main()
{
    string comando,tipo,texto,subComando,nombre_archivo;
    int espacio = 0,pos = 0;
    Directorio d = NULL;
    d = new _directorio;
    d->dirsig = NULL;
    d->contenido = NULL;
    bool flag = true;
    while(flag == true)
    {
        getline(cin,comando,'\n');
        cin.clear();

        pos = comando.find(' ');
        tipo = comando.substr(0, pos);
        subComando = comando.substr(pos + 1);

        if(tipo.compare("CREATE") == 0)
        {
            MuestroRetorno(CREATE(d,subComando));
        }
        if(tipo.compare("DIR") == 0)
            MuestroRetorno(DIR(d));
        if(tipo.compare("IF") == 0)
        {
            espacio = subComando.find(' ');
            texto = subComando.substr(espacio + 1);
            subComando = subComando.substr(0,espacio);
            MuestroRetorno(IF(d,subComando,texto));
        }
        if(tipo.compare("TYPE") == 0)
        {
            MuestroRetorno(TYPE(d,subComando));
        }
        if(tipo.compare("DELETE") == 0)
        {
            MuestroRetorno(DELETE(d,subComando));
        }

        if(tipo.compare("UNDELETE") == 0)
            cout << "IF";
        if(tipo.compare("BF") == 0)
        {
            espacio = subComando.find(' ');
            subComando = subComando.substr(0,espacio);
            MuestroRetorno(BF(d,subComando,0));
        }
        if(tipo.compare("CAT") == 0)
            cout << "IF";
        if(tipo.compare("IC") == 0)
        {
            espacio = subComando.find(' ');
            texto = subComando.substr(espacio + 1);
            subComando = subComando.substr(0,espacio);
            MuestroRetorno(IC(d,subComando,texto));
        }
        if(tipo.compare("BC") == 0)
            cout << "IF";
        if(tipo.compare("FIN") == 0)
            flag = false;
    }
    return 0;
}
