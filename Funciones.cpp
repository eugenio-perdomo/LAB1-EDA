/// TIPO 1
string ruta = "/";
Directorio CreoDirectorio()
{
    Directorio d;
    d = new _directorio;
    d->nom = "/";
    d->hijo = NULL;
    d->hermano = NULL;
    d->contenido = NULL;
    d->padre = NULL;
    return d;
}

TipoRet DIR(Directorio d)
{
    if(esVacio(d->contenido))
        cout << "Directorio Vacio\n" << endl;

    else
    {
        cout << "Nombre\t\t\tTipo\t\tTamanio\tLineas\n";
        muestroArchivos(d->contenido);
        cout<<"\nSubDirectorios:\n";
        muestroDirectorios(d->hijo);
    }
    return OK;
}

TipoRet CREATE(Directorio &d, string nombre_archivo)
{
    string arch=nombre_archivo.substr(nombre_archivo.find_last_of('/')+1);
    string dir=nombre_archivo.substr(0,nombre_archivo.find_last_of('/'));
    Directorio ubicacion;
    if(nombre_archivo.find_last_of('/')==0)
    {
        ubicacion=irAraiz(d);
    }
    else
    {
        dir=nombre_archivo.substr(0,nombre_archivo.find_last_of('/'));
        if(dir!=arch)
        {
            ubicacion=recorrida(d,dir);
        }
        else
        {
            ubicacion=d;
        }
    }
    if(esVacio2(ubicacion))
    {
        return ERROR;
    }
    else
    {

        int posicion = 0;
        if(arch.length() < LARGONOMBRE)
        {
            posicion = arch.find('.');
            if(posicion < 0)
            {
                return ERROR;
            }
            else
            {
                if(esVacio(ubicacion->contenido))
                {
                    ubicacion = CrearArchivo(ubicacion,arch);
                    return OK;
                }
                if(buscoArchivo(ubicacion->contenido,arch)->nombreArchivo==arch)
                {
                    return ERROR;
                }
                else
                {
                    ubicacion = CrearArchivo(ubicacion,arch);
                    return OK;
                }

            }
        }
        else return ERROR;
    }
}

TipoRet IF(Directorio &d, string nombreArchivo, string texto)
{
    string arch=nombreArchivo.substr(nombreArchivo.find_last_of('/')+1);
    string dir=nombreArchivo.substr(0,nombreArchivo.find_last_of('/'));
    Directorio ubicacion;
    if(nombreArchivo.find_last_of('/')==0)
    {
        ubicacion=irAraiz(d);
    }
    else
    {
        dir=nombreArchivo.substr(0,nombreArchivo.find_last_of('/'));
        if(dir!=arch)
        {
            ubicacion=recorrida(d,dir);
        }
        else
        {
            ubicacion=d;
        }
    }
    if(esVacio2(ubicacion))
    {
        return ERROR;
    }
    else
    {
        if(esVacio(ubicacion->contenido))
        {
            return ERROR;
        }
        else
        {
            Archivo aux = buscoArchivo(ubicacion->contenido,arch);
            if(aux->nombreArchivo==arch)
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
                        while(x < LARGO_MAX && aux->contenido[x] != "")
                        {
                            x++;
                        }
                        string txt=texto.substr(1,texto.length()-2);
                        aux->contenido[x] = txt;
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
}

TipoRet TYPE(Directorio d, string nombre_Archivo)
{
    string arch=nombre_Archivo.substr(nombre_Archivo.find_last_of('/')+1);
    string dir=nombre_Archivo.substr(0,nombre_Archivo.find_last_of('/'));
    Directorio ubicacion;
    if(nombre_Archivo.find_last_of('/')==0)
    {
        ubicacion=irAraiz(d);
    }
    else
    {
        dir=nombre_Archivo.substr(0,nombre_Archivo.find_last_of('/'));
        if(dir!=arch)
        {
            ubicacion=recorrida(d,dir);
        }
        else
        {
            ubicacion=d;
        }
    }
    if(esVacio2(ubicacion))
    {
        return ERROR;
    }
    else
    {
        Archivo aux=buscoArchivo(ubicacion->contenido,arch);
        if(aux->nombreArchivo!=arch)
        {
            return ERROR;
        }
        else
        {
            if(aux->contenido[0]=="")
            {
                cout<<"Archivo vacio"<<endl;
            }
            else
            {

                for(int x=0; x < aux->lineas; x++)
                {
                    cout<<aux->contenido[x]<<endl;
                }
            }
            return OK;
        }
    }
}

TipoRet MKDIR(Directorio &d, string nombre_directorio)
{
    int ocurrencia = 0;
    ocurrencia = count(nombre_directorio.begin(), nombre_directorio.end(), '/');

    if(ocurrencia == 0)
    {
        d = CrearDirectorio(d,d->nom,nombre_directorio);
    }

    else if(ocurrencia == 1)
    {
        int posicion=nombre_directorio.find('/');
        nombre_directorio=nombre_directorio.substr(posicion+1);
        d = CrearDirectorio(d,"/",nombre_directorio);
    }

    else
    {
        int posicion = nombre_directorio.find_last_of('/');
        string path = nombre_directorio.substr(0,posicion);
        int posicion2 = path.find_last_of('/');
        string padre = path.substr(posicion2 + 1);
        nombre_directorio=nombre_directorio.substr(posicion+1);
        d = CrearDirectorio(d,padre,nombre_directorio);
    }
    return OK;
}

TipoRet CD(Directorio &d, string camino)
{
    Directorio aux=d;
    aux=recorrida(aux,camino);
    if(esVacio2(aux))
    {
        return ERROR;
    }
    else
    {
        d=aux;
        PWD(d);
        return OK;
    }
}

/// TIPO 2
TipoRet DELETE(Directorio &d, string palabra, Archivo &repuesto, string &camino)
{
    string arch=palabra.substr(palabra.find_last_of('/')+1);
    string dir=palabra.substr(0,palabra.find_last_of('/'));
    Directorio ubicacion;
    if(palabra.find_last_of('/')==0){
      ubicacion=irAraiz(d);
                                           }else{
                                              dir=palabra.substr(0,palabra.find_last_of('/'));
                                              if(dir!=arch){
                                                ubicacion=recorrida(d,dir);
                                                           }else{
                                                              ubicacion=d;
                                                                }
                                                }
    if(esVacio2(ubicacion)){
      return ERROR;
                           }else{
    Archivo aux=buscoArchivo(ubicacion->contenido,arch),auxizq=NULL,auxder=NULL,mini;
    if(aux->nombreArchivo!=arch){
      return ERROR;
                                }else{
                                   if(ubicacion->contenido!=aux){
                                     Archivo ant=ubicacion->contenido;
                                     while((ant->archder!=aux)&&(ant->archizq!=aux)){
                                       if(aux->nombreArchivo<ant->nombreArchivo){
                                         ant=ant->archizq;
                                                                                }else{
                                                                                   ant=ant->archder;
                                                                                     }
                                                                                    }
                                     if(aux->nombreArchivo<ant->nombreArchivo){
                                       ant->archizq=NULL;
                                                                              }else{
                                                                                 ant->archder=NULL;
                                                                                   }
                                                                }else{
                                                                   if(!esVacio(ubicacion->contenido->archder)){
                                                                     ubicacion->contenido=ubicacion->contenido->archder;
                                                                                                              }else{
                                                                                                                 ubicacion->contenido=ubicacion->contenido->archizq;
                                                                                                                   }
                                                                     }
                                   if(!hojaArch(aux)){
                                     if(!esVacio(aux->archizq)){
                                       auxizq=aux->archizq;
                                                               }
                                     if(!esVacio(aux->archder)){
                                       auxder=aux->archder;
                                       mini=buscoMenor(auxder);
                                       mini->archizq=auxizq;
                                                               }else{
                                                                  mini=buscoMenor(ubicacion->contenido);
                                                                  mini->archizq=auxizq;
                                                                    }
                                                     }
                                   repuesto->nombreArchivo=aux->nombreArchivo;
                                   repuesto->lineas=aux->lineas;
                                   int x;
                                   for(x=0;x<LARGO_MAX;x++){
                                     repuesto->contenido[x]=aux->contenido[x];
                                                           }
                                   camino="/"+aux->nombreArchivo;
                                   while(!esVacio2(ubicacion->padre)){
                                     camino="/"+ubicacion->nom+camino;
                                     ubicacion=ubicacion->padre;
                                                                     }
                                   delete aux;
                                   cout<<ubicacion->contenido->nombreArchivo<<": "<<ubicacion->contenido<<endl;
                                   cout<<ubicacion->contenido->archder->nombreArchivo<<": "<<ubicacion->contenido->archder<<endl;
                                   cout<<ubicacion->contenido->archizq->nombreArchivo<<": "<<ubicacion->contenido->archizq<<endl;
                                   return OK;
                                     }
                                }
}

TipoRet BF(Directorio &d, string nombreArchivo, int linea)
{
    string arch=nombreArchivo.substr(nombreArchivo.find_last_of('/')+1);
    string dir=nombreArchivo.substr(0,nombreArchivo.find_last_of('/'));
    Directorio ubicacion;
    if(nombreArchivo.find_last_of('/')==0)
    {
        ubicacion=irAraiz(d);
    }
    else
    {
        dir=nombreArchivo.substr(0,nombreArchivo.find_last_of('/'));
        if(dir!=arch)
        {
            ubicacion=recorrida(d,dir);
        }
        else
        {
            ubicacion=d;
        }
    }
    if(esVacio2(ubicacion))
    {
        return ERROR;
    }
    else
    {

        if(esVacio(ubicacion->contenido))
        {
            return ERROR;
        }
        else
        {
            if(ubicacion->contenido->nombreArchivo.compare(arch)==0)
            {
                int x=0;
                while(ubicacion->contenido->contenido[x]!="")
                {
                    x++;
                }
                int y;
                if(x<linea)
                {
                    for(y=x-1; y>-1; y--)
                    {
                        ubicacion->contenido->contenido[y]="";
                    }
                }
                else
                {
                    for(y=linea; y>0; y--)
                    {
                        ubicacion->contenido->contenido[x-1]="";
                        x--;
                    }
                }
                return OK;
            }
            else
            {
                Archivo aux= buscoArchivo(ubicacion->contenido,arch);
                if(aux->nombreArchivo!=arch)
                {
                    return ERROR;
                }
                else
                {
                    int x=0;
                    while(aux->contenido[x]!="")
                    {
                        x++;
                    }
                    int y;
                    if(x<linea)
                    {
                        for(y=x-1; y>-1; y--)
                        {
                            aux->contenido[y]="";
                        }
                    }
                    else
                    {
                        for(y=linea; y>0; y--)
                        {
                            aux->contenido[x-1]="";
                            x--;
                        }
                    }
                    return OK;
                }
            }
        }

    }
}

TipoRet CAT(Directorio &d, string nombreArchivo1, string nombreArchivo2)
{
    Archivo receptor;
    Archivo donador;
    receptor = buscoArchivo(d->contenido, nombreArchivo1);
    donador = buscoArchivo(d->contenido, nombreArchivo2);
    if(receptor != NULL && donador != NULL)
    {
        int i = 0;
        int j = 0;
        while(receptor->contenido[i+1]!="")
        {
            ++i;
        }
        if(receptor->contenido[i] != "")
            ++i;
        while(donador->contenido[j]!="" && receptor->lineas < LARGO_MAX)
        {
            receptor->lineas++;
            receptor->contenido[i] += donador->contenido[j];
            ++j;
            ++i;
        }
    }
    else
        return ERROR;
    return OK;
}

TipoRet PWD(Directorio d)
{
    ruta = "/";
    if(d->nom != "/")
    {
        Directorio aux=d;
        ruta = ruta+aux->nom;
        while(!esVacio2(aux->padre))
        {
            aux = aux->padre;
            if(aux->nom != "/")
            {
                ruta = "/"+aux->nom + ruta;
            }
        }
    }
    else ruta = "/";
    cout << ruta << endl;
    return OK;
}

TipoRet RMDIR()
{
    return NO_IMPLEMENTADO;
}

/// OPCIONALES
TipoRet IC(Directorio &d, string nombreArchivo, string texto)
{
    string arch=nombreArchivo.substr(nombreArchivo.find_last_of('/')+1);
    string dir=nombreArchivo.substr(0,nombreArchivo.find_last_of('/'));
    Directorio ubicacion;
    if(nombreArchivo.find_last_of('/')==0)
    {
        ubicacion=irAraiz(d);
    }
    else
    {
        dir=nombreArchivo.substr(0,nombreArchivo.find_last_of('/'));
        if(dir!=arch)
        {
            ubicacion=recorrida(d,dir);
        }
        else
        {
            ubicacion=d;
        }
    }
    if(esVacio2(ubicacion))
    {
        return ERROR;
    }
    else
    {

        if(esVacio(ubicacion->contenido))
        {
            return ERROR;
        }
        else
        {
            Archivo aux = buscoArchivo(ubicacion->contenido,arch);
            if(aux->nombreArchivo==arch)
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
                        while(x < LARGO_MAX && aux->contenido[x] != "")
                        {
                            x++;
                        }
                        if(x>0)
                        {
                            int y;
                            for(y=x; y>0; y--)
                            {
                                aux->contenido[y]=aux->contenido[y-1];
                            }
                        }
                        string txt=texto.substr(1,texto.length()-2);
                        aux->contenido[0]=txt;
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
}

TipoRet BC(Directorio &d,string nombreArchivo, int linea)
{
    string arch=nombreArchivo.substr(nombreArchivo.find_last_of('/')+1);
    string dir=nombreArchivo.substr(0,nombreArchivo.find_last_of('/'));
    Directorio ubicacion;
    if(nombreArchivo.find_last_of('/')==0)
    {
        ubicacion=irAraiz(d);
    }
    else
    {
        dir=nombreArchivo.substr(0,nombreArchivo.find_last_of('/'));
        if(dir!=arch)
        {
            ubicacion=recorrida(d,dir);
        }
        else
        {
            ubicacion=d;
        }
    }
    if(esVacio2(ubicacion))
    {
        return ERROR;
    }
    else
    {

        if(esVacio(ubicacion->contenido))
        {
            return ERROR;
        }
        else
        {
            if(ubicacion->contenido->nombreArchivo.compare(arch)==0)
            {
                int x=0;
                while(ubicacion->contenido->contenido[x]!="")
                {
                    x++;
                }
                int y;
                if(x<=linea)
                {
                    for(y=x-1; y>-1; y--)
                    {
                        ubicacion->contenido->contenido[y]="";
                    }
                }
                else
                {
                    for(y=0; y<x-linea; y++)
                    {
                        ubicacion->contenido->contenido[y]=ubicacion->contenido->contenido[y+linea];
                    }
                    for(y=x-linea; y<LARGO_MAX; y++)
                    {
                        ubicacion->contenido->contenido[y]="";
                    }
                }
                return OK;
            }
            else
            {
                Archivo aux= buscoArchivo(ubicacion->contenido,arch);
                if(aux->nombreArchivo!=arch)
                {
                    return ERROR;
                }
                else
                {
                    int x=0;
                    while(aux->contenido[x]!="")
                    {
                        x++;
                    }
                    int y;
                    if(x<=linea)
                    {
                        for(y=x-1; y>-1; y--)
                        {
                            aux->contenido[y]="";
                        }
                    }
                    else
                    {
                        for(y=0; y<x-linea; y++)
                        {
                            aux->contenido[y]=aux->contenido[y+linea];
                        }
                        for(y=x-linea; y<LARGO_MAX; y++)
                        {
                            aux->contenido[y]="";
                        }
                    }
                    return OK;
                }
            }
        }

    }
}

TipoRet UNDELETE(Directorio &d, Archivo repuesto, string camino)
{
    string arch=camino.substr(camino.find_last_of('/')+1);
    string dir=camino.substr(0,camino.find_last_of('/'));
    Directorio ubicacion;
    if(camino.find_last_of('/')==0){
      ubicacion=irAraiz(d);
                                           }else{
                                              dir=camino.substr(0,camino.find_last_of('/'));
                                              if(dir!=arch){
                                                ubicacion=recorrida(d,dir);
                                                           }else{
                                                              ubicacion=d;
                                                                }
                                                }
    if(esVacio2(ubicacion)){
      return ERROR;
                           }else{
                              Archivo aux=buscoArchivo(ubicacion->contenido,arch);
                              if(aux->nombreArchivo==arch){
                                return ERROR;
                                                          }else{
                                                             Archivo aux2=new _archivo;
                                                             aux2=repuesto;
                                                             if(aux2->nombreArchivo>aux->nombreArchivo){
                                                               aux->archder=aux2;
                                                                                                       }else{
                                                                                                          aux->archizq=aux2;
                                                                                                            }
                                                             return OK;
                                                               }
                                }
}

TipoRet DIR_S(Directorio d)
{
    d = irAraiz(d);
    moverseATodos(d);
    return OK;
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
        if(a->contenido[x] != "")
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
        nuevoArchivo->contenido[x] = "";
    }
    nuevoArchivo->archder=NULL;
    nuevoArchivo->archizq=NULL;
    nuevoArchivo->lineas = 0;
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

Directorio CrearDirectorio(Directorio &d, string padre, string nombre)
{
    Directorio nuevoDirectorio,Directoriopadre,aux,root = d;
    if(padre=="/")
    {
        nuevoDirectorio = new _directorio;
        nuevoDirectorio->nom = nombre;
        nuevoDirectorio->padre = root;
        nuevoDirectorio->hijo = NULL;
        nuevoDirectorio->hermano = NULL;
        recorrerDirectorioHermano(root->hijo)->hermano = nuevoDirectorio;
    }
    else
    {
        if(!esVacio2(d))
        {
            Directoriopadre=recorrida(root,padre);
            cout << Directoriopadre << endl;

            if(!esVacio2(Directoriopadre))
            {
                nuevoDirectorio=new _directorio;
                nuevoDirectorio->nom=nombre;
                nuevoDirectorio->padre=Directoriopadre;
                nuevoDirectorio->hijo=NULL;
                nuevoDirectorio->hermano=NULL;
                if(esVacio2(Directoriopadre->hijo))
                {
                    Directoriopadre->hijo=nuevoDirectorio;
                }
                else
                {
                    aux=Directoriopadre->hijo;
                    while(!esVacio2(aux->hermano))
                    {
                        aux=aux->hermano;
                    }
                    aux->hermano=nuevoDirectorio;
                }
            }
            else
            {
                cout << "Directorio padre no encontrado" << endl;
            }
        }
        else
        {
            cout << "Directorio encontrado" << endl;
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

Directorio recorrerDirectorioHermano(Directorio d)
{
    if (!esVacio2(d->hermano))
    {
        return recorrerDirectorioHermano(d->hermano);
    }
    return d;
}

Directorio buscoDirectorioHijo(Directorio d, string nombre)
{
    if (esVacio2(d))
        return NULL;
    if (d->nom == nombre)
        return d;
    return buscoDirectorioHijo(d->hijo, nombre);
}

void moverseATodos(Directorio d)
{
    if(!esVacio2(d))
    {

        cout << "<contenido: " << d->nom << ">\n";
        muestroArchivosDIRS(d->contenido);
        moverseATodos(d->hijo);
        moverseATodos(d->hermano);
    }
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

void muestroArchivosDIRS(Archivo a)
{
    if(!esVacio(a))
    {
        muestroArchivosDIRS(a->archizq);
        cout << a->nombreArchivo << "     Archivo"<< endl;
        muestroArchivosDIRS(a->archder);
    }
}

void muestroDirectorios(Directorio d)
{
    if(!esVacio2(d))
    {
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
    d = CrearArchivo(d,"b.b");
    d = CrearArchivo(d,"a.a");
    IC(d,"a.a",a+"Hellraiser"+a);
    IC(d,"a.a",a+"Crazy Train"+a);
    d = CrearArchivo(d,"n.n");
    IC(d,"n.n",a+"Smells like teen spirit"+a);
    IC(d,"n.n",a+"Come as you are"+a);
    IC(d,"n.n",a+"All Apologies"+a);
    d = CrearArchivo(d,"l.l");
    IC(d,"l.l",a+"Stairway to heaven"+a);
    IC(d,"l.l",a+"Whole Lotta Love"+a);
    IC(d,"l.l",a+"Inmigrant Song"+a);
    IC(d,"l.l",a+"Black Dog"+a);
}

Directorio recorrida(Directorio d, string texto)
{
    string camino,txt2;
    if(texto=="/")
    {
        return irAraiz(d);
    }
    else
    {
        int pos=texto.find('/');
        if(pos==0)
        {
            d=irAraiz(d);
            txt2=texto.substr(1);
            pos=txt2.find('/');
        }
        else
        {
            txt2=texto;
        }
        txt2=txt2.substr(pos+1);
        string destino=texto.substr(texto.find_last_of('/')+1);

        while(!esVacio2(d)&&(pos!=-1))
        {

            camino=txt2.substr(0,pos);
            d=buscoDirectorioHermano(d->hijo,camino);
            pos=txt2.find('/');
            if(pos!=-1)
            {
                txt2=txt2.substr(pos+1);
            }

        }

        if(!esVacio2(d))
        {
            d = buscoDirectorioHermano(d->hijo,destino);
        }
        return d;
    }
}

Directorio cargarDirectoriosDePrueba(Directorio d)
{
    Directorio a = NULL;
    a = new _directorio;
    a->nom = "dir1";
    a->hijo = NULL;
    a->hermano = NULL;
    a->contenido = NULL;
    a->padre = d;
    d->hijo = a;
    cargarDatosDePrueba(a);

    Directorio c = NULL;
    c = new _directorio;
    c->nom = "dir2";
    c->hijo = NULL;
    c->hermano = NULL;
    c->contenido = NULL;
    c->padre = d;
    a->hermano = c;
    cargarDatosDePrueba(c);

    Directorio b = NULL;
    b = new _directorio;
    b->nom = "dir21";
    b->hijo = NULL;
    b->hermano = NULL;
    b->contenido = NULL;
    b->padre = c;
    c->hijo = b;
    cargarDatosDePrueba(b);

    return d;
}

void colorAlTexto()
{
    cout << "\e[1;92mLABORATORIO\e[0m:\e[36m "<< ruta << "\e[0m$ ";
}

Directorio irAraiz(Directorio d)
{
    while(!esVacio2(d->padre))
    {
        d=d->padre;
    }
    return d;
}

Archivo buscoMenor(Archivo a)
{
    while(!esVacio(a->archizq))
    {
        a=a->archizq;
    }
    return a;
}
