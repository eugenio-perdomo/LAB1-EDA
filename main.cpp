#include <iostream>
#include <stdio.h>
#include <string.h>


#define TEXTO_MAX 50
#define LARGO_MAX 5
#define LARGONOMBRE 19

using namespace std;
#include "Definiciones.h"
#include "Funciones.cpp"

int main()
{
    string comando;
    int x=0;
    Directorio d=NULL;
    int espacio=0;
    d = new _directorio;
    d->dirsig = NULL;
    d->contenido = NULL;
    char nombre_archivo [LARGONOMBRE];
    bool flag = true;
    while(flag == true){

        getline(cin,comando,'\n');
        cin.clear();

        int pos = comando.find(' ');
        string tipo = comando.substr(0, pos);
        string texto;
        string nom;
        //cout << "comando: " << tipo << endl;
        string subComando = comando.substr (pos + 1);
        //cout << "sub: " << subComando << endl;

        if(tipo.compare("create") == 0){
            subComando.copy(nombre_archivo,subComando.length(),0);
            MuestroRetorno(CREATE(d,nombre_archivo));
        }
        if(tipo.compare("fin") == 0)
            flag = false;
        if(tipo.compare("UNDELETE") == 0)
            cout << "IF";
        if(tipo.compare("dir") == 0)
            MuestroRetorno(DIR(d));
        if(tipo.compare("if") == 0){
          subComando.copy(nombre_archivo,subComando.find(' '),0);
          espacio=subComando.find(' ');
          texto=subComando.substr(espacio+1);
          cout<<nombre_archivo[0]<<endl;
          cout<<texto<<endl;

          for(x=0;x<strlen(nombre_archivo)-1;x++){
            cout<<nombre_archivo[x];
                                            }
          //MuestroRetorno(IF(d,nombre_archivo,texto));
                                   }
        if(tipo.compare("type") == 0){
            subComando.copy(nombre_archivo,subComando.length(),0);
            MuestroRetorno(TYPE(d,nombre_archivo));
                                     }
        if(tipo.compare("delete") == 0)
        {
          subComando.copy(nombre_archivo,subComando.length(),0);
            MuestroRetorno(DELETE(d,nombre_archivo));
        }
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
