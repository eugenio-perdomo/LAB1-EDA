using namespace std;

//tipo1
TipoRet DIR(Sistema s)
{
    if(s==NULL){
      cout<<"Directorio Vacio"<<endl;
               }else{
                  Archivo aux=s->contenido;
                  while(aux!=NULL){
                    cout<<aux->nom<<"     Archivo     "/*<<resultado de la funcion tamaño*/<<endl;
                    aux=aux->ptrsig;
                                  }
                    }
    return OK;
}

TipoRet CREATE()
{
    return NO_IMPLEMENTADO;
}

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
