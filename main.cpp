#include <iostream>
#include <stdio.h>
#include <string.h>

#define TEXTO_MAX 50
#define LARGO_MAX 5
#define LARGONOMBRE 19

#include "Definiciones.h"
#include "Funciones.cpp"

using namespace std;

/*
* TODO 2 getline dependiendo de nuestra entrada;
* ver funciones que a cada uno nos funcione diferente/mal;
* definir todos los tipos de variables y nombres de variables para cada estructura
*/
int main(){

    string comando;
    Directorio d=NULL;
    d = new _directorio;
    //d->nombreDirectorio='/';
    d->dirsig = NULL;
    d->contenido = NULL;
    char nombre_archivo[LARGONOMBRE];
    bool flag = true;
    while(flag == true){

        getline(cin,comando,'\n');
        cin.clear();

        if(comando.compare("FIN") == 0){
            flag = false;
        }else{
            getline(cin,comando,' ');
            if(comando.compare("CREATE")==0){
                cin.getline(nombre_archivo,19,'\n');
                MuestroRetorno(CREATE(d,nombre_archivo));
            }

            if(comando.compare("IF") == 0)
            if(comando.compare("TYPE") == 0)
            if(comando.compare("DELETE") == 0)
            if(comando.compare("BF") == 0)
            if(comando.compare("CAT") == 0)
            if(comando.compare("IC") == 0)
            if(comando.compare("BC") == 0)
            if(comando.compare("UNDELETE") == 0)
        }
    }
    return 0;
}
