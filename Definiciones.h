#ifndef DEFINICIONES_H_INCLUDED
#define DEFINICIONES_H_INCLUDED

typedef enum _retorno{
    OK,ERROR,NO_IMPLEMENTADO
}TipoRet;

typedef char *Cadena;

typedef struct _archivo{
    char nombreArchivo[LARGONOMBRE];
    Cadena contenido[LARGO_MAX];
    _archivo *ptrsig;
}*Archivo;

typedef struct _directorio{
    //std::string nombreDirectorio;
    Archivo contenido;
    _directorio *dirsig;
}*Directorio;


//tipo1
TipoRet DIR(Directorio d);
TipoRet CREATE(Directorio d,char nombre_archivo[]);
TipoRet IF(Directorio d, char nombreArchivo[], std::string texto);
TipoRet TYPE(Directorio d, char nombreArchivo[]);

//tipo2
TipoRet DELETE(Directorio d, char palabra[]);
TipoRet BF();
TipoRet CAT();

//opcionales
TipoRet IC(Directorio d, std::string nombreArchivo, std::string texto);
TipoRet BC();
TipoRet UNDELETE();

//otras
void MuestroRetorno(TipoRet ret);
int tamanio(Archivo a);
Directorio CrearArchivo(Directorio d, char nombre[]);
Directorio eliminarArchivo(Directorio d, char nombre[]);
bool esVacio(Archivo a);
bool hayComillas(std::string texto);

#endif // DEFINICIONES_H_INCLUDED
