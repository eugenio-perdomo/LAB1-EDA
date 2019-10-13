#ifndef DEFINICIONES_H_INCLUDED
#define DEFINICIONES_H_INCLUDED

typedef enum _retorno
{
    OK,ERROR,NO_IMPLEMENTADO
} TipoRet;
typedef char *Cadena;

typedef struct _archivo
{
    string nombreArchivo;
    Cadena contenido[LARGO_MAX];
    _archivo *ptrsig;
    int lineas;
}*Archivo;

typedef struct _directorio
{
    string nom;
    Archivo contenido;
    //_directorio *subdir;
    _directorio *dirsig;
}*Directorio;

//tipo1
TipoRet DIR(Directorio d);
TipoRet CREATE(Directorio d, string nombre_archivo);
TipoRet IF(Directorio d, string nombreArchivo, string texto);
TipoRet TYPE(Directorio d, string nombreArchivo);

//tipo2
TipoRet DELETE(Directorio d, string palabra);
TipoRet BF(Directorio d, string nombreArchivo, int linea);
TipoRet CAT(/*Directorio d, string nombreArchivo1, string nombreArchivo2*/);

//opcionales
TipoRet IC(Directorio d, string nombreArchivo, string texto);
TipoRet BC();
TipoRet UNDELETE();

//otras
void MuestroRetorno(TipoRet ret);
int tamanio(Archivo a);
bool hayComillas(string texto);
Directorio CrearArchivo(Directorio d, string nombre_archivo);
Directorio eliminarArchivo(Directorio d, string nombre);
bool esVacio(Archivo a);

#endif // DEFINICIONES_H_INCLUDED
