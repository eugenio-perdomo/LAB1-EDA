#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>

#define TEXTO_MAX 50    // Cantidad maxima de caracteres por linea
#define LARGO_MAX 5     // Cantidad maxima de lineas por archivo
#define LARGONOMBRE 19  // Texto mas extension

using namespace std;
#include "Definiciones.h"
#include "Funciones.cpp"

/** TODO
    CAT, UNDELETE, DELETE, CD, RMDIR, DIR_S, COPY
    MKDIR y PWD en proceso.
*/
int main()
{
    string comando,tipo,texto,subComando,nombre_archivo;
    int espacio = 0,pos = 0;
    Directorio d;
    d=CreoDirectorio(d);
    //getchar();
    //d = cargarDirectoriosDePrueba(d);
    //muestroDirectorios(d->hijo);


    //cout<<"hola" << endl;
    //d = recorrida(d->hijo, "/asd/asd");

    //cargarDatosDePrueba(d);
    bool flag = true;
    while(flag == true)
    {
        getline(cin,comando,'\n');
        cin.clear();
        pos = comando.find(' ');
        tipo = comando.substr(0, pos);
        subComando = comando.substr(pos + 1);

        if(tipo.compare("CREATE") == 0)
            MuestroRetorno(CREATE(d,subComando));

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
            MuestroRetorno(TYPE(d,subComando));

        if(tipo.compare("DELETE") == 0)
            MuestroRetorno(DELETE(d,subComando));

        if(tipo.compare("UNDELETE") == 0)
            MuestroRetorno(UNDELETE());

        if(tipo.compare("BF") == 0)
        {
            espacio = subComando.find(' ');
            subComando = subComando.substr(0,espacio);
            MuestroRetorno(BF(d,subComando,0));
        }

        if(tipo.compare("CAT") == 0) {}
        //MuestroRetorno(CAT());
        if(tipo.compare("IC") == 0)
        {
            espacio = subComando.find(' ');
            texto = subComando.substr(espacio + 1);
            subComando = subComando.substr(0,espacio);
            MuestroRetorno(IC(d,subComando,texto));
        }
        if(tipo.compare("MKDIR") == 0)
        {
            espacio = subComando.find(' ');
            texto = subComando.substr(espacio + 1);
            subComando = subComando.substr(0,espacio);
            MuestroRetorno(MKDIR(d,subComando));
        }


        if(tipo.compare("PWD") == 0)
            MuestroRetorno(PWD(d));

        if(tipo.compare("BC") == 0)
            cout << "BC";

        if(tipo.compare("FIN") == 0)
            flag = false;

        if(tipo.compare("CD") == 0)
        {
            espacio = subComando.find(' ');
            texto = subComando.substr(espacio + 1);
            subComando = subComando.substr(0,espacio);
            MuestroRetorno(CD(d,subComando));
        }

    }
    return 0;
}
