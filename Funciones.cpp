//tipo1
TipoRet DIR(Directorio d)
{
    if(d->contenido == NULL)
    {
        cout<<"Directorio Vacio"<<endl;
        return ERROR;
    }
    else
    {
        Archivo aux = d->contenido;
        while(aux != NULL)
        {
            cout << aux->nombreArchivo << "\tArchivo \t" << tamanio(aux) << "\t" << aux->lineas << endl;
            aux = aux->ptrsig;
        }
        delete aux;
    }
    return OK;
}

TipoRet CREATE(Directorio d, string nombre_archivo)
{
    int posicion = 0;
    if(nombre_archivo.length() < LARGONOMBRE)
    {
        posicion = nombre_archivo.find('.');
        if(posicion < 0)
        {
            return ERROR;
        }
        d = CrearArchivo(d,nombre_archivo);
        return OK;
    }
    else return ERROR;
}

TipoRet IF(Directorio d, string nombreArchivo, string texto)
{
    if(esVacio(d->contenido))
    {
        return ERROR;
    }
    else
    {

        Archivo aux = d->contenido;
        while(aux->nombreArchivo != nombreArchivo && aux != NULL)
        {
            aux = aux->ptrsig;
        }
        if(!hayComillas(texto))
        {
            cout<<"No tiene comillas\n";
            return ERROR;
        }
        else
        {
            if(texto.length() > TEXTO_MAX)
            {
                cout<<"Muy largo\n";
                return ERROR;
            }
            else
            {
                int x=0;
                while(x < LARGO_MAX && aux->contenido[x] != NULL)
                {
                    x++;
                }
                aux->contenido[x] = new char[TEXTO_MAX];
                texto.copy(aux->contenido[x],TEXTO_MAX);
                aux->lineas++;
                return OK;
            }
        }
    }
}

TipoRet TYPE(Directorio d, string nombre_Archivo)
{
    if(esVacio(d->contenido))
    {
        return ERROR;
    }
    else
    {
        Archivo aux = d->contenido;
        while(aux != NULL)
        {
            if(aux->nombreArchivo == nombre_Archivo)
            {
                int x=0;
                while(x < LARGO_MAX)
                {
                    if(aux->contenido[x] != NULL)
                    {
                        cout << aux->contenido[x] << endl;
                    }
                    x++;
                }
            }
            aux = aux->ptrsig;
        }
        delete aux;
        return OK;
    }
}

//tipo2
TipoRet DELETE(Directorio d, string palabra)
{
    Archivo aux = d->contenido;
    while(!esVacio(aux))
    {
        if(aux->nombreArchivo.compare(palabra) == 0)
        {
            cout << palabra << endl;
            d = eliminarArchivo(d,palabra);
            return OK;
        }
        aux = aux->ptrsig;
    }
    return ERROR;
}

TipoRet BF(Directorio d, string nombreArchivo, int linea)
{
    if(esVacio(d->contenido)){
        return ERROR;
                             }else{
                                if(d->contenido->nombreArchivo.compare(nombreArchivo)==0){
                                  int x=0;
                                  while(d->contenido->contenido[x]!=NULL){
                                    x++;
                                                                         }
                                  int y;
                                  if(x<linea){
                                    for(y=x-1;y>-1;y--){
                                      delete d->contenido->contenido[y];
                                                       }
                                             }else{
                                                for(y=linea;y>0;y--){
                                                  delete d->contenido->contenido[x-1];
                                                  x--;
                                                                    }
                                                  }
                                  return OK;
                                                                                         }else{
                                                                                            Archivo aux= d->contenido->ptrsig;
                                                                                            while((aux->nombreArchivo.compare(nombreArchivo)!=0)&&(!esVacio(aux))){
                                                                                              aux=aux->ptrsig;
                                                                                                                                                                  }
                                                                                            if(esVacio(aux)){
                                                                                              return ERROR;
                                                                                                            }else{
                                                                                                               int x=0;
                                                                                                               while(aux->contenido[x]!=NULL){
                                                                                                                 x++;
                                                                                                                                             }
                                                                                                               int y;
                                                                                                               if(x<linea){
                                                                                                                 for(y=x-1;y>-1;y--){
                                                                                                                   delete aux->contenido[y];
                                                                                                                                    }
                                                                                                                          }else{
                                                                                                                             for(y=linea;y>0;y--){
                                                                                                                                delete aux->contenido[x-1];
                                                                                                                                x--;
                                                                                                                                                 }
                                                                                                                               }
                                                                                                               return OK;
                                                                                                                 }
                                                                                              }
                                  }

}

TipoRet CAT(Directorio d, string nombreArchivo1, string nombreArchivo2)
{
    /*if(nombreArchivo1 == nombreArchivo2) return ERROR;
    bool flag1 = false, flag2 = false; ///Ver la cantidad de lineas y que no se pasen entre los archivos
    Archivo aux = d->contenido;
    while(!esVacio(aux)){
        if(aux->nombreArchivo == nombreArchivo1)
            flag1 = true;
        if(aux->nombreArchivo == nombreArchivo2)
            flag2 = true;
        aux = aux->ptrsig;
    }
    if(flag1 && flag2){
        Concatenacion();
        return OK;
    }*/
    return NO_IMPLEMENTADO;
}

//opcionales
TipoRet IC(Directorio d, string nombreArchivo, string texto)
{
    if(esVacio(d->contenido))
    {
        return ERROR;
    }
    else
    {
        Archivo aux = d->contenido;
        while(aux->nombreArchivo != nombreArchivo && aux != NULL)
        {
            aux = aux->ptrsig;
        }
        if(!hayComillas(texto))
        {
            cout<<"No tiene comillas\n";
            return ERROR;
        }
        else
        {
            if(texto.length() > TEXTO_MAX)
            {
                cout<<"Muy largo\n";
                return ERROR;
            }
            else
            {
                int x=0;
                while(x < LARGO_MAX && aux->contenido[x] != NULL)
                {
                    x++;
                }
                aux->contenido[x] = new char[TEXTO_MAX];
                if(x>0)
                {
                    int y;
                    for(y=x; y>0; y--)
                    {
                        strcpy(aux->contenido[y],aux->contenido[y-1]);
                    }
                }
                texto.copy(aux->contenido[0],TEXTO_MAX);
                aux->lineas++;
                return OK;
            }
        }
    }
}

TipoRet BC(Directorio d,string nombreArchivo, int linea)
{
    if(esVacio(d->contenido)){
        return ERROR;
                             }else{
                                if(d->contenido->nombreArchivo.compare(nombreArchivo)==0){
                                  int x=0;
                                  while(d->contenido->contenido[x]!=NULL){
                                    x++;
                                                                         }
                                  int y;
                                  if(x<=linea){
                                    for(y=x-1;y>-1;y--){
                                      delete d->contenido->contenido[y];
                                                       }
                                              }else{
                                                 for(y=0;y<x-linea;y++){
                                                   strcpy(d->contenido->contenido[y],d->contenido->contenido[y+linea]);
                                                                       }
                                                 for(y=x-linea;y<LARGO_MAX;y++){
                                                   delete d->contenido->contenido[y];
                                                                               }
                                                   }
                                  return OK;
                                                                                         }else{
                                                                                            Archivo aux= d->contenido->ptrsig;
                                                                                            while((aux->nombreArchivo.compare(nombreArchivo)!=0)&&(!esVacio(aux))){
                                                                                              aux=aux->ptrsig;
                                                                                                                                                                  }
                                                                                            if(esVacio(aux)){
                                                                                              return ERROR;
                                                                                                            }else{
                                                                                                               int x=0;
                                                                                                               while(aux->contenido[x]!=NULL){
                                                                                                                 x++;
                                                                                                                                             }
                                                                                                               int y;
                                                                                                               if(x<=linea){
                                                                                                                 for(y=x-1;y>-1;y--){
                                                                                                                   delete aux->contenido[y];
                                                                                                                                    }
                                                                                                                           }else{
                                                                                                                              for(y=0;y<x-linea;y++){
                                                                                                                                strcpy(aux->contenido[y],aux->contenido[y+linea]);
                                                                                                                                                    }
                                                                                                                              for(y=x-linea;y<LARGO_MAX;y++){
                                                                                                                                 delete aux->contenido[y];
                                                                                                                                                            }
                                                                                                                                }
                                                                                                               return OK;
                                                                                                                 }
                                                                                              }
                                  }

}

TipoRet UNDELETE()
{
    //exclusivamente el ultimo
    return NO_IMPLEMENTADO;
}

//otras
void MuestroRetorno(TipoRet ret)
{
    switch(ret)
    {
    case OK:
        cout<<"OK"<<endl;
        break;
    case ERROR:
        cout<<"ERROR"<<endl;
        break;
    case NO_IMPLEMENTADO:
        cout<<"NO IMPLEMENTADO"<<endl;
        break;
    }
}

int tamanio(Archivo a)
{
    int largo = 0, x = 0;
    while(x < LARGO_MAX)
    {
        if(a->contenido[x] != NULL)
        {
            largo = largo + sizeof(a->contenido[x]) - 1;
        }
        x++;
    }
    return largo;
}

bool hayComillas(string texto)
{
    if(texto.find('"') == 0 && texto.rfind('"') == texto.length() -1)
        return true;
    return false;
}

Directorio CrearArchivo(Directorio d, string nombre)
{
    Archivo nuevoArchivo = new _archivo;
    nuevoArchivo->nombreArchivo = nombre;
    nuevoArchivo->ptrsig = d->contenido;
    d->contenido = nuevoArchivo;
    for(int x = 0; x < LARGO_MAX; x++)
    {
        d->contenido->contenido[x] = NULL;
    }
    return d;
}

Directorio eliminarArchivo(Directorio d, string nombre)
{

    Archivo aux = d->contenido;
    Archivo ant = NULL;
    while(!esVacio(aux))
    {
        if(aux->nombreArchivo.compare(nombre) == 0)
        {
            if(ant == NULL)
            {
                d->contenido = d->contenido->ptrsig;
                delete aux;
                break;
            }
            else
            {
                if(aux->ptrsig == NULL)
                {
                    ant->ptrsig = aux->ptrsig;
                    delete aux;
                    break;
                }
                else
                {
                    ant->ptrsig = aux->ptrsig;
                    delete aux;
                    break;
                }
            }
        }
        else
        {
            ant = aux;
            aux = aux->ptrsig;
        }
    }
    return d;
}
/*Concatenacion(){
}*/
bool esVacio(Archivo a)
{
    if(a == NULL) return true;
    else return false;
}






































