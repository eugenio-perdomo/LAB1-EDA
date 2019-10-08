#include <iostream>
#include <stdio.h>
#include <string.h>

#define TEXTO_MAX 50
#define LARGO_MAX 5
#define LARGONOMBRE 19

using namespace std;

#include "Definiciones.h"
#include "Funciones.cpp"



/**
* TODO
* ver funciones que a cada uno nos funcione diferente/mal;
* definir todos los tipos de variables y nombres de variables para cada estructura
*/
int main(){

    string comando,texto;
    Directorio d=NULL;
    d = new _directorio;
    //d->nombreDirectorio='/';
    d->dirsig = NULL;
    d->contenido = NULL;
    char nombre_archivo[LARGONOMBRE];//[LARGONOMBRE];
    bool flag = true;
    while(flag == true){

        getline(cin,comando,'\n');
        cin.clear();

        int pos = comando.find(' ');
        string tipo = comando.substr(0, pos);
        string subComando = comando.substr (pos + 1);

        if(tipo.compare("CREATE") == 0){
            subComando.copy(nombre_archivo,subComando.length(),0);
            MuestroRetorno(CREATE(d,nombre_archivo));
        }
        if(tipo.compare("FIN") == 0)
            flag = false;
        if(tipo.compare("UNDELETE") == 0)
            cout << "IF";
        if(tipo.compare("DIR") == 0)
            MuestroRetorno(DIR(d));
        if(tipo.compare("IF") == 0){
            subComando.copy(nombre_archivo,subComando.length(),0);
            getline(cin,texto)
            MuestroRetorno(IF(d,nombre_archivo))
        if(tipo.compare("TYPE") == 0){
            subComando.copy(nombre_archivo,subComando.length(),0);
            MuestroRetorno(TYPE(d,nombre_archivo));
        }
        if(tipo.compare("DELETE") == 0)
            cout << "IF";
        if(tipo.compare("BF") == 0)
            cout << "IF";
        if(tipo.compare("CAT") == 0)
            cout << "IF";
        if(tipo.compare("IC") == 0)
            cout << "IF";
        if(tipo.compare("BC") == 0)
            cout << "IF";
    }
    return 0;
}
