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

TipoRet IF(Directorio d, string nombreArchivo, string texto)
{
    while((d->contenido->nom!=nombreArchivo)&&(d->contenido!=NULL)){
      d->contenido=d->contenido->ptrsig;
                                                                   }
    if(d->contenido==NULL){
      return ERROR;
                          }else{
                             if(hayComillas(texto)){
                               return ERROR;
                                                          }else{
                                                             if(sizeof(texto)-1>TEXTO_MAX+2){
                                                               return ERROR;
                                                                                            }else{
                                                                                               int x=0;
                                                                                               while((x<LARGO_MAX)&&(d->contenido->contenido[x]=='\0')){
                                                                                                 x++;
                                                                                                                                                       }
                                                                                               d->contenido->contenido[x]=new char[TEXTO_MAX];
                                                                                               texto.copy(d->contenido->contenido[x],TEXTO_MAX);
                                                                                               return OK;
                                                                                                 }
                                                               }
                               }
}

TipoRet TYPE(Directorio d, string nombreArchivo)
{
    while((d->contenido->nom!=nombreArchivo)&&(d->contenido!=NULL)){
      d->contenido=d->contenido->ptrsig;
                                                                   }
    if(d->contenido==NULL){
      return ERROR;
                          }else{
                             int x=0;
                             while(x<LARGO_MAX){
                               cout<<d->contenido->contenido[x]<<endl;
                               x++;
                                               }
                             return OK;
                               }
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
    int largo=0,x=0;

    while((strlen(a->contenido[x])>0)&&(x<LARGO_MAX)){
      largo=largo+strlen(a->contenido[x]);
      x++;
                                                     }
    return largo;
}

bool hayComillas(string texto)
{
    if((str[0]=='"')&&(str[strlen(str)-1]=='"')){
      return true;
                                                }else{
                                                   return false;
                                                     }
}
