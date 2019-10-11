using namespace std;


//tipo1
TipoRet DIR(Directorio d)
{
    if(d==NULL){
      cout<<"Directorio Vacio"<<endl;
               }else{
                  Archivo aux=d->contenido;
                  if(aux!=NULL){
                    while(aux!=NULL){
                      cout<<aux->nombreArchivo<<"     Archivo     "<<tamanio(aux)<<endl;
                      aux=aux->ptrsig;
                                    }
                               }else{
                                  cout<<"Directorio Vacio"<<endl;
                                    }

                    }
    return OK;
}

TipoRet CREATE(Directorio d, char nombre_archivo[])
{

    bool flag = true;
    if(strlen(nombre_archivo) > 0){
        for(int i = 19; i > 0; i--){
            if(nombre_archivo[i] == '.')
            flag = false;
        }

        if(flag == true){
            return ERROR;
        }
        d = CrearArchivo(d,nombre_archivo);
        return OK;
    }else{
        return ERROR;
    }
}

TipoRet IF(Directorio d, char nombreArchivo[], string texto)
{
    cout<<"Entramos";
    bool flag=true;
    while(flag){
      if(d->contenido->nombreArchivo==nombreArchivo){
        flag=false;
                                                     }else{
                                                        if(d->contenido==NULL){
                                                          flag=false;
                                                                              }else{
                                                                                 d->contenido=d->contenido->ptrsig;
                                                                                   }
                                                          }
                }
    cout<<d->contenido->nombreArchivo;
    if(d->contenido==NULL){
      cout<<"vacio";
      return ERROR;
                          }else{
                             if(hayComillas(texto)){
                               cout<<"comillas";
                               return ERROR;
                                                          }else{
                                                             if(sizeof(texto)-1>TEXTO_MAX+2){
                                                               cout<<"largo";
                                                               return ERROR;
                                                                                            }else{
                                                                                               int x=0;
                                                                                               while((x<LARGO_MAX)&&(d->contenido->contenido[x]!=NULL)){
                                                                                                 x++;
                                                                                                                                                       }
                                                                                               d->contenido->contenido[x]=new char[TEXTO_MAX];
                                                                                               texto.copy(d->contenido->contenido[x],TEXTO_MAX);
                                                                                               return OK;
                                                                                                 }
                                                               }
                               }
}

TipoRet TYPE(Directorio d, char nombreArchivo[])
{
    while((d->contenido->nombreArchivo!=nombreArchivo)&&(d->contenido!=NULL)){
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
TipoRet DELETE(Directorio d, char palabra[]){

    while(!esVacio(d->contenido))
    {
        if(strcmp(d->contenido->nombreArchivo,palabra)==0)
        {
            d=eliminarArchivo(d,palabra);
            return OK;
        }
        d->contenido=d->contenido->ptrsig;
    }
    return ERROR;
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
TipoRet IC(Directorio d, char nombreArchivo[], string texto)
{
    while((d->contenido->nombreArchivo!=nombreArchivo)&&(d->contenido!=NULL)){
      d->contenido=d->contenido->ptrsig;
                                                                   }
    if(d->contenido==NULL){
      cout<<"es null";
      return ERROR;
                          }else{
                             if(hayComillas(texto)){
                               cout<<"no tiene comillas";
                               return ERROR;
                                                          }else{
                                                             if(sizeof(texto)-1>TEXTO_MAX+2){
                                                               cout<<"muylargo";
                                                               return ERROR;
                                                                                            }else{
                                                                                               int x=0;
                                                                                               while((x<LARGO_MAX)&&(d->contenido->contenido[x]!=NULL)){
                                                                                                 x++;
                                                                                                                                                       }
                                                                                               d->contenido->contenido[x]=new char[TEXTO_MAX];
                                                                                               while(x>0){
                                                                                                 strcpy(d->contenido->contenido[x],d->contenido->contenido[x]-1);
                                                                                                 x++;
                                                                                                         }
                                                                                               texto.copy(d->contenido->contenido[0],TEXTO_MAX);
                                                                                               return OK;
                                                                                                 }
                                                               }
                               }
}

TipoRet BC()
{
    return NO_IMPLEMENTADO;
}

TipoRet UNDELETE()
{
    //exclusivamente el ultimo
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

    while((sizeof(a->contenido[x])-1>0)&&(x<LARGO_MAX)&&(a->contenido[x]!=NULL)){
      largo=largo+sizeof(a->contenido[x])-1;
      x++;
                                                                                }
    return largo;
}

bool hayComillas(string texto)
{
    char str[TEXTO_MAX];
    texto.copy(str,sizeof(texto)-1);
    if((str[0]=='"')&&(str[strlen(str)-1]=='"')){
      return true;
                                                }else{
                                                   return false;
                                                     }
}

Directorio CrearArchivo(Directorio d, char nombre[])
{

    Archivo nuevoArchivo = new _archivo;
    nuevoArchivo->ptrsig=d->contenido;
    d->contenido=nuevoArchivo;
    strcpy(nuevoArchivo->nombreArchivo,nombre);
    int x;
    for(x=0;x<LARGO_MAX;x++){
      d->contenido->contenido[x]=NULL;
                            }
    return d;
}

Directorio eliminarArchivo(Directorio d, char nombre[]){

    Archivo aux = d->contenido;
    Archivo ant = NULL;
    while(!esVacio(aux)){
        if(strcmp(aux->nombreArchivo,nombre)==0){
            if(ant == NULL){
                d->contenido = d->contenido->ptrsig;
                delete aux;
                cout<<"borrado1";
                break;
            }else{
                if(aux->ptrsig == NULL){
                    ant->ptrsig = aux->ptrsig;
                    delete aux;
                    cout<<"borrado2"<<endl;
                    break;
                }else{
                    ant->ptrsig = aux->ptrsig;
                    delete aux;
                    //aux = ant->ptrsig;
                    cout<<"borrado3"<<endl;
                    break;
                }
            }
        }else{
            ant = aux;
            aux = aux->ptrsig;
        }
    }
    return d;
}

bool esVacio(Archivo a){

    if(a == NULL) return true;
    else return false;
}










































