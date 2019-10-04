#ifndef DEFINICIONES_H_INCLUDED
#define DEFINICIONES_H_INCLUDED
#define LARGO_MAX 10
typedef enum _retorno{
    OK,ERROR,NO_IMPLEMENTADO
                     }TipoRet;

//typedef struct *Cabezera;

typedef struct _archivo{
    char nombreArchivo[19];
    char contenido[LARGO_MAX]; //LARGO_MAX
    _archivo *ptrsig;
                       }*Archivo;

typedef struct _directorio{
    char nombreDirectorio[10];
    Archivo contenido;
    //_sistema *subdir;
    _directorio *dirsig;
                       }*Directorio;


//tipo1
TipoRet DIR(Directorio d);
TipoRet CREATE(Directorio d);
TipoRet IF();
TipoRet TYPE();

//tipo2
TipoRet DELETE(Directorio d, char palabra[]);
TipoRet BF();
TipoRet CAT();

//opcionales
TipoRet IC();
TipoRet BC();
TipoRet UNDELETE();

//otras
void MuestroRetorno(TipoRet ret);
int tamanio(Archivo a);
Directorio CrearArchivo(Directorio d, char nombre[]);
Directorio eliminarArchivo(Directorio d, char nombre[]);
bool esVacio(Archivo a);

#endif // DEFINICIONES_H_INCLUDED
