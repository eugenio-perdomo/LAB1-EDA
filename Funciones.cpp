using namespace std;

//tipo1
/*TipoRet DIR(Sistema s)
{
    if(s==NULL){
    cout<<"Directorio Vacio"<<endl;
    }else{
        Archivo aux=s->contenido;
        while(aux!=NULL){
            cout<<aux->nom<<"Archivo";
            aux=aux->ptrsig;
        }
    }
    return OK;
}*/

TipoRet CREATE(Directorio d, char nombre_archivo[]){

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

TipoRet IF(Directorio d, string nombreArchivo, string texto){

    while(d->contenido->nombreArchivo != nombreArchivo && d->contenido != NULL){
        d->contenido = d->contenido->ptrsig;
    }
    if(d->contenido == NULL){
        return ERROR;
    }else{
        if(hayComillas(texto)){
            return ERROR;
        }else{
            if(sizeof(texto)-1 > TEXTO_MAX + 2){
                return ERROR;
            }else{
                int x=0;
                while(x < LARGO_MAX && d->contenido->contenido[x]=='\0'){
                    x++;
                }
                //d->contenido->contenido[x] = new char[TEXTO_MAX];
                //texto.copy(d->contenido->contenido[x],TEXTO_MAX);
                return OK;
            }
        }
    }
}

TipoRet TYPE(Directorio d, string nombreArchivo){

    while(d->contenido->nombreArchivo != nombreArchivo && d->contenido != NULL){
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


///tipo2
/// ya puede venir el nombre por parametro desde main
TipoRet DELETE(Directorio d, char palabra[]){

    cin.getline(palabra,19,'\n');
    while(!esVacio(d->contenido))
    {
        if(strcmp(d->contenido->nombreArchivo,palabra)==0)
        {
            eliminarArchivo(d,palabra);
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
TipoRet IC(Directorio d, string nombreArchivo, string texto){

    while(d->contenido->nombreArchivo != nombreArchivo && d->contenido != NULL){
        d->contenido = d->contenido->ptrsig;
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
                while(x < LARGO_MAX && d->contenido->contenido[x] == '\0'){
                    x++;
                }
                //d->contenido->contenido[x]=new char[TEXTO_MAX];
                while(x > 0){
                    //strcpy(d->contenido->contenido[x],d->contenido->contenido[x]-1);
                    x++;
                }
                //texto.copy(d->contenido->contenido[0],TEXTO_MAX);
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
    return NO_IMPLEMENTADO;
}

Directorio eliminarArchivo(Directorio d, char nombre[]){

    Archivo aux = d->contenido;
    Archivo ant = NULL;
    while(!esVacio(aux)){
        if(aux->nombreArchivo == nombre){
            if(ant == NULL){
                d->contenido = aux->ptrsig;
                delete aux;
            }else{
                if(aux->ptrsig == NULL){
                    ant->ptrsig = aux->ptrsig;
                    delete aux;
                }else{
                    ant->ptrsig = aux->ptrsig;
                    delete aux;
                    aux = ant->ptrsig;
                }
            }
        }else{
            ant = aux;
            aux = aux->ptrsig;
        }
    }
    return d;
}

/// Esto por ahora no pone el archivo dentro del directorio pasado por parametro
Directorio CrearArchivo(Directorio d, char nombre[]){

    Archivo nuevoArchivo = new _archivo;
    d->contenido=nuevoArchivo;
    strcpy(nuevoArchivo->nombreArchivo,nombre);
    //nuevoArchivo->contenido[0]='\0';
    nuevoArchivo->ptrsig = NULL;
    return d;
}

//otras
void MuestroRetorno(TipoRet ret){

    switch(ret){
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

bool esVacio(Archivo a){

    if(a == NULL) return true;
    else return false;
}

int tamanio(Archivo a){

    int largo = 0, x = 0;
    while(strlen(a->contenido[x]) > 0 && x < LARGO_MAX){
        largo = largo+strlen(a->contenido[x]);
        x++;
    }
    return largo;
}

bool hayComillas(string texto){

    if(str[0] == '"' && str[strlen(str)-1] == '"') return true;
    else return false;
}
