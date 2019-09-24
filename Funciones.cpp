using namespace std;

//tipo1
/*TipoRet DIR(Sistema s)
{
    if(s==NULL){
      cout<<"Directorio Vacio"<<endl;
               }else{
                  Archivo aux=s->contenido;
                  while(aux!=NULL){
                    cout<<aux->nom<<"     Archivo     "<<endl;
                    aux=aux->ptrsig;
                                  }
                    }
    return OK;
}*/

TipoRet IF()
{
    return NO_IMPLEMENTADO;
}

TipoRet TYPE()
{
    return NO_IMPLEMENTADO;
}


//tipo2
TipoRet DELETE()
{
    return NO_IMPLEMENTADO;
}

TipoRet BF()
{
    return NO_IMPLEMENTADO;
}

TipoRet CAT()
{
    return NO_IMPLEMENTADO;
}


//opcionales
TipoRet IC()
{
    return NO_IMPLEMENTADO;
}

TipoRet BC()
{
    return NO_IMPLEMENTADO;
}

TipoRet UNDELETE()
{
    return NO_IMPLEMENTADO;
}


//otras
void MuestroRetorno(TipoRet ret)
{
  switch(ret){
    case OK: cout<<"OK"<<endl;
             break;
    case ERROR: cout<<"ERROR"<<endl;
             break;
    case NO_IMPLEMENTADO: cout<<"NO IMPLEMENTADO"<<endl;
                          break;
             }
}


int tamanio(Archivo a)
{
    return 0;
}

TipoRet CREATE(Directorio d){
    char palabra[19];
    bool flag = true;
    cin.getline(palabra,19,'\n');
    if(strlen(palabra) < 0){
        for(int i = 19; i > 0; i--){ // Verificar 3 , 2 , 1
            if(palabra[i] == '.')
            flag = false;
        }
        if(flag == true){
            return ERROR;
        }
        d = CrearArchivo(d,palabra);
        return OK;
    }else{
        return ERROR;
    }

}
Directorio CrearArchivo(Directorio d, char nombre[]){
    Archivo nuevoArchivo = new _archivo;
    strcpy(nuevoArchivo->nombreArchivo,nombre);
    nuevoArchivo->contenido[0]='\0';
    nuevoArchivo->ptrsig = NULL;
    return d;
}











