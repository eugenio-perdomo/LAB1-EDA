
/// TIPO 1
string rutaActual= "/";
TipoRet DIR(Directorio d)
{
    if(esVacio(d->contenido))
        cout << "Directorio Vacio\n" << endl;

    else
    {
        cout << "Nombre\t\t\tTipo\t\tTamanio\tLineas\n";
        muestroArchivos(d->contenido);
        cout<<endl;
        muestroDirectorios(d->hijo);
    }
    return OK;
}

TipoRet CREATE(Directorio &d, string nombre_archivo)
{
    int posicion = 0;
    if(nombre_archivo.length() < LARGONOMBRE)
    {
        posicion = nombre_archivo.find('.');
        if(posicion < 0)
        {
            return ERROR;
        }
        else
        {
            if(esVacio(d->contenido))
            {
                d = CrearArchivo(d,nombre_archivo);
                return OK;
            }
            if(buscoArchivo(d->contenido,nombre_archivo)->nombreArchivo==nombre_archivo)
            {
                return ERROR;
            }
            else
            {
                d = CrearArchivo(d,nombre_archivo);
                return OK;
            }

        }
    }
    else return ERROR;
}

TipoRet IF(Directorio &d, string nombreArchivo, string texto)
{
    if(esVacio(d->contenido))
    {
        return ERROR;
    }
    else
    {
        Archivo aux = buscoArchivo(d->contenido,nombreArchivo);
        if(aux->nombreArchivo==nombreArchivo)
        {

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
        else
        {
            return ERROR;
        }
    }
}

TipoRet TYPE(Directorio d, string nombre_Archivo)
{
    Archivo aux=buscoArchivo(d->contenido,nombre_Archivo);
    if(aux->nombreArchivo!=nombre_Archivo)
    {
        return ERROR;
    }
    else
    {
        if(aux->contenido[0]==NULL)
        {
            cout<<"Archivo vacio"<<endl;
        }
        else
        {
            int x=0;
            while(aux->contenido[x]!=NULL)
            {
                cout<<aux->contenido[x]<<endl;
                x++;
            }
        }
        return OK;
    }
}

TipoRet MKDIR(Directorio &d, string nombre_directorio)
{
    int ocurrencia = count(nombre_directorio.begin(), nombre_directorio.end(), '/');



    if(ocurrencia == 0){
        /// donde estamos parados
    }



    else if(ocurrencia == 1){
        d = CrearDirectorio(d,"/",nombre_directorio);
    }



    else{
        int posicion = nombre_directorio.find_last_of('/');
        string path = nombre_directorio.substr(0,posicion);
        int posicion2 = path.find_last_of('/');
        string padre = path.substr(posicion2 + 1);
        nombre_directorio=nombre_directorio.substr(posicion+1);
        d = CrearDirectorio(d,padre,nombre_directorio);
    }
    return OK;
}

TipoRet CD(Directorio &d, string ruta)
{
    //cout<<"entramos "<<endl;
    if(ruta=="/"){
      while(!esVacio2(d->padre)){
        d=d->padre;
                                }
      cout<<"raiz nombre: "<<d->nom<<endl;
                 }else{
                    d=recorrida(d,ruta);
                    //cout<<"locacion: "<<d->nom<<endl;
                      }
    if(esVacio2(d)){
      return ERROR;
                   }else{
                      return OK;
                        }

    /*string delimeter = "/";
    size_t pos = 0;
    string nombreDirectorio;
    if(ruta.find('/') == 0)
        ruta = ruta.substr(1);
    while ((pos = ruta.find(delimeter)) != std::string::npos) {
        nombreDirectorio = ruta.substr(0, pos);
        cout << nombreDirectorio << endl;
        ruta.erase(0, pos + delimeter.length());
    }
    cout << ruta << endl;*/
    //return NO_IMPLEMENTADO;
}

/// TIPO 2
TipoRet DELETE(Directorio &d, string palabra)
{
    Archivo aux = d->contenido;
    while(!esVacio(aux))
    {
        if(aux->nombreArchivo.compare(palabra) == 0)
        {
            cout << palabra << endl;

            if(!hojaArch(aux))
            {
                ///desenganchar y enganchar todo;
            }
            d = eliminarArchivo(d,palabra);
            return OK;
        }
        else
        {
            if(palabra<aux->nombreArchivo)
            {
                aux=aux->archizq;
            }
            else
            {
                aux=aux->archder;
            }
        }
    }
    return ERROR;
}

TipoRet BF(Directorio &d, string nombreArchivo, int linea)
{
    if(esVacio(d->contenido))
    {
        return ERROR;
    }
    else
    {
        if(d->contenido->nombreArchivo.compare(nombreArchivo)==0)
        {
            int x=0;
            while(d->contenido->contenido[x]!=NULL)
            {
                x++;
            }
            int y;
            if(x<linea)
            {
                for(y=x-1; y>-1; y--)
                {
                    delete d->contenido->contenido[y];
                }
            }
            else
            {
                for(y=linea; y>0; y--)
                {
                    delete d->contenido->contenido[x-1];
                    x--;
                }
            }
            return OK;
        }
        else
        {
            Archivo aux= buscoArchivo(d->contenido,nombreArchivo);
            if(aux->nombreArchivo!=nombreArchivo)
            {
                return ERROR;
            }
            else
            {
                int x=0;
                while(aux->contenido[x]!=NULL)
                {
                    x++;
                }
                int y;
                if(x<linea)
                {
                    for(y=x-1; y>-1; y--)
                    {
                        delete aux->contenido[y];
                    }
                }
                else
                {
                    for(y=linea; y>0; y--)
                    {
                        delete aux->contenido[x-1];
                        x--;
                    }
                }
                return OK;
            }
        }
    }

}

TipoRet CAT(Directorio &d, string nombreArchivo1, string nombreArchivo2)
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

TipoRet PWD(Directorio d)
{
    string ruta="/";
    if(d->nom!="/"){
      Directorio aux=d;
      ruta=ruta+aux->nom;
      while(!esVacio2(aux->padre)){
        aux=aux->padre;
        if(aux->nom!="/"){
          ruta="/"+aux->nom+ruta;
                         }
                                  }
                   }else{
                      ruta="/";
                        }
    cout<<ruta<<endl;
    return OK;
}

TipoRet RMDIR()
{
    return NO_IMPLEMENTADO;
}

/// OPCIONALES
TipoRet IC(Directorio &d, string nombreArchivo, string texto)
{
    if(esVacio(d->contenido))
    {
        return ERROR;
    }
    else
    {
        Archivo aux = buscoArchivo(d->contenido,nombreArchivo);
        if(aux->nombreArchivo==nombreArchivo)
        {
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
        else
        {
            return ERROR;
        }
    }
}

TipoRet BC(Directorio &d,string nombreArchivo, int linea)
{
    if(esVacio(d->contenido))
    {
        return ERROR;
    }
    else
    {
        if(d->contenido->nombreArchivo.compare(nombreArchivo)==0)
        {
            int x=0;
            while(d->contenido->contenido[x]!=NULL)
            {
                x++;
            }
            int y;
            if(x<=linea)
            {
                for(y=x-1; y>-1; y--)
                {
                    delete d->contenido->contenido[y];
                }
            }
            else
            {
                for(y=0; y<x-linea; y++)
                {
                    strcpy(d->contenido->contenido[y],d->contenido->contenido[y+linea]);
                }
                for(y=x-linea; y<LARGO_MAX; y++)
                {
                    delete d->contenido->contenido[y];
                }
            }
            return OK;
        }
        else
        {
            Archivo aux= buscoArchivo(d->contenido,nombreArchivo);
            if(aux->nombreArchivo!=nombreArchivo)
            {
                return ERROR;
            }
            else
            {
                int x=0;
                while(aux->contenido[x]!=NULL)
                {
                    x++;
                }
                int y;
                if(x<=linea)
                {
                    for(y=x-1; y>-1; y--)
                    {
                        delete aux->contenido[y];
                    }
                }
                else
                {
                    for(y=0; y<x-linea; y++)
                    {
                        strcpy(aux->contenido[y],aux->contenido[y+linea]);
                    }
                    for(y=x-linea; y<LARGO_MAX; y++)
                    {
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

TipoRet DIR_S()
{
    return NO_IMPLEMENTADO;
}

TipoRet COPY()
{
    return NO_IMPLEMENTADO;
}

/// OTRAS
void MuestroRetorno(TipoRet ret)
{
    switch(ret)
    {
    case OK:
        cout<<"\e[32mOK\e[0m"<<endl;
        break;
    case ERROR:
        cout<<"\e[31mERROR\e[0m"<<endl;
        break;
    case NO_IMPLEMENTADO:
        cout<<"\e[33mNO IMPLEMENTADO\e[0m"<<endl;
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
    for(int x = 0; x < LARGO_MAX; x++)
    {
        nuevoArchivo->contenido[x] = NULL;
    }
    nuevoArchivo->archder=NULL;
    nuevoArchivo->archizq=NULL;
    if(esVacio(d->contenido))
    {
        d->contenido=nuevoArchivo;
    }
    else
    {
        Archivo aux=buscoArchivo(d->contenido,nombre);
        if(aux->nombreArchivo>nombre)
        {
            aux->archizq=nuevoArchivo;
        }
        else
        {
            aux->archder=nuevoArchivo;
        }
    }
    return d;
}

Directorio CrearDirectorio(Directorio d, string padre, string nombre)
{
    Directorio nuevoDirectorio = new _directorio;
    nuevoDirectorio->nom = nombre;
    nuevoDirectorio->contenido = NULL;
    nuevoDirectorio->hijo = NULL;
    nuevoDirectorio->padre = buscoDirectorioHermano(d, padre);
    buscoDirectorioHermano(d, padre)->hijo = nuevoDirectorio;
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

bool esVacio(Archivo a)
{
    if(a == NULL) return true;
    else return false;
}

bool esVacio2(Directorio d)
{
    if(d == NULL) return true;
    else return false;
}

Archivo buscoArchivo(Archivo a, string nom)
{
    if(a->nombreArchivo==nom)
    {
        return a;
    }
    else
    {
        if(hojaArch(a))
        {
            return a;
        }
        else
        {
            if(nom<a->nombreArchivo)
            {
                if(esVacio(a->archizq))
                {
                    return a;
                }
                else
                {
                    return buscoArchivo(a->archizq,nom);
                }
            }
            else
            {
                if(esVacio(a->archder))
                {
                    return a;
                }
                else
                {
                    return buscoArchivo(a->archder,nom);
                }
            }
        }
    }
}

Directorio buscoDirectorioHermano(Directorio d, string nombre)
{
    if (esVacio2(d))
        return NULL;
    if (d->nom == nombre)
        return d;
    return buscoDirectorioHermano(d->hermano, nombre);
}

Directorio buscoDirectorioHijo(Directorio d, string nombre)
{
    if (esVacio2(d))
        return NULL;
    if (d->nom == nombre)
        return d;
    return buscoDirectorioHijo(d->hijo, nombre);
}

bool hojaArch(Archivo a)
{
    if((esVacio(a->archizq))&&(esVacio(a->archder)))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void muestroArchivos(Archivo a)
{
    if(!esVacio(a))
    {
        muestroArchivos(a->archizq);
        cout << a->nombreArchivo;
        if(a->nombreArchivo.length() <= 7) cout << "\t";
        if(a->nombreArchivo.length() <= 13) cout << "\t";
        cout << "\tArchivo \t" << tamanio(a) << "\t" << a->lineas << endl;
        muestroArchivos(a->archder);
    }
}

void muestroDirectorios(Directorio d)
{
    if(!esVacio2(d)){
      cout<<d->nom<<"     Directorio"<<endl;
      muestroDirectorios(d->hermano);
                    }
}

void muestroTodo(Directorio raiz)
{
    ///queda para despues
}

void cargarDatosDePrueba(Directorio &d)
{
    string a;
    a = (char)34;
    d = CrearArchivo(d,"algo.txt");
    d = CrearArchivo(d,"Ozzy Osbourne.mp3");
    IC(d,"Ozzy Osbourne.mp3",a+"Hellraiser"+a);
    IC(d,"Ozzy Osbourne.mp3",a+"Crazy Train"+a);
    d = CrearArchivo(d,"Nirvana.mp3");
    IC(d,"Nirvana.mp3",a+"Smells like teen spirit"+a);
    IC(d,"Nirvana.mp3",a+"Come as you are"+a);
    IC(d,"Nirvana.mp3",a+"All Apologies"+a);
    d = CrearArchivo(d,"Led_Zeppelin.mp3");
    IC(d,"Led_Zeppelin.mp3",a+"Stairway to heaven"+a);
    IC(d,"Led_Zeppelin.mp3",a+"Whole Lotta Love"+a);
    IC(d,"Led_Zeppelin.mp3",a+"Inmigrant Song"+a);
    IC(d,"Led_Zeppelin.mp3",a+"Black Dog"+a);
}

Directorio recorrida(Directorio d, string texto)
{
    cout<<"recorriendo"<<endl;
    string ruta,txt2,destino;
    int pos=texto.find('/');
    cout<<"pos: "<<pos<<endl;
    destino=texto.substr(texto.find_last_of('/')+1,-1);
    cout<<"destino: "<<destino<<endl;
    Directorio aux=d->hijo;
    if(pos==0){
      while(!esVacio2(aux->padre)){
        aux=aux->padre;
                                  }
      txt2=texto.substr(1,texto.find_last_of('/')-1);
      cout<<"txt2: "<<txt2<<endl;
      pos=txt2.find('/');
      ruta=txt2.substr(0,pos);
      aux=buscoDirectorioHermano(aux->hijo,ruta);
      txt2=texto.substr(pos+2,texto.find_last_of('/')-1);
                          }else{
                             ruta=texto.substr(0,pos);
                             aux=buscoDirectorioHermano(aux,ruta);
                             txt2=texto.substr(0,texto.find_last_of('/'));
                               }
    //cout<<"pos: "<<pos<<"   ruta: "<<ruta<<"  txt2: "<<txt2<<endl;


    string delimeter = "/";
    size_t pos2 = 0;
    string nombreDirectorio;

    if(txt2.find('/') == 0)
        txt2 = txt2.substr(1);

    while (((pos2 = txt2.find(delimeter)) != std::string::npos)&&(!esVacio2(aux))) {
        nombreDirectorio = txt2.substr(0, pos2);
        aux=buscoDirectorioHermano(aux->hijo,nombreDirectorio);
        txt2.erase(0, pos2 + delimeter.length());
    }

    //cout << txt2 << endl;

    return aux;
}

Directorio cargarDirectoriosDePrueba(Directorio d){
    Directorio a = NULL;
    a = new _directorio;
    a->nom = "qwe";
    a->hijo = NULL;
    a->hermano = NULL;
    a->contenido = NULL;

    Directorio c = NULL;
    c = new _directorio;
    c->nom = "asd";
    c->hijo = NULL;
    c->hermano = NULL;
    c->contenido = NULL;

    Directorio b = NULL;
    b = new _directorio;
    b->nom = "zxc";
    b->hijo = NULL;
    b->hermano = NULL;
    b->contenido = NULL;

    d->hijo = a;
    a->padre=d;
    a->hermano = c;
    c->padre=d;
    c->hijo = b;
    b->padre=c;
    return d;
}



























