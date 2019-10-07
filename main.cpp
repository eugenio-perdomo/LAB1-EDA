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
* TODO Pasaje de string a char para aquellas funciones a las que se le pasan parametros
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
    string nombre_archivo;//[LARGONOMBRE];
    bool flag = true;
    while(flag == true){

        getline(cin,comando,'\n');
        cin.clear();

        int pos = comando.find(' ');
        string tipo = comando.substr(0, pos);
        cout << "comando: " << tipo << endl;
        string subComando = comando.substr (pos + 1);
        cout << "sub: " << subComando << endl;

        if(tipo.compare("CREATE ") == 0){
            //nombre_archivo = comando.substr(subComando);
            /*cin.getline(nombre_archivo,19,'\n');
            MuestroRetorno(CREATE(d,nombre_archivo));*/
        }
        if(tipo.compare("FIN") == 0)
            flag = false;
        if(tipo.compare("UNDELETE") == 0)
            cout << "IF";
        if(tipo.compare("DIR") == 0)
            cout << "DIR";
        if(tipo.compare("IF") == 0)
            cout << "IF";
        if(tipo.compare("TYPE") == 0)
            cout << "IF";
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
