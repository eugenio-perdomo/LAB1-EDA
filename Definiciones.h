#ifndef DEFINICIONES_H_INCLUDED
#define DEFINICIONES_H_INCLUDED

typedef enum _retorno{
    OK,ERROR,NO_IMPLEMENTADO
                     }TipoRet;

typedef struct _archivo{
    string nom;
    string contenido[LARGO_MAX];
    _archivo *ptrsig;
                       }*Archivo;

typedef struct _sistema{
    string nom;
    Archivo contenido;
    //_sistema *subdir;
    _sistema *dirsig;
                       }*Sistema;


//tipo1
TipoRet DIR(Sistema s);

//tipo2

//opcionales

//otras
int tamanio(Archivo a);


#endif // DEFINICIONES_H_INCLUDED
