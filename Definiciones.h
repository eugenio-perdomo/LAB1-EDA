#ifndef DEFINICIONES_H_INCLUDED
#define DEFINICIONES_H_INCLUDED

typedef enum _retorno{
    OK,ERROR,NO_IMPLEMENTADO
                     }TipoRet;

typedef char *Cadena;

typedef struct _archivo{
    string nom;
    Cadena contenido[LARGO_MAX];
    _archivo *ptrsig;
                       }*Archivo;

typedef struct _sistema{
    char nom[];
    Archivo contenido;
    //_sistema *subdir;
    _sistema *dirsig;
                       }*Sistema;


//tipo1
TipoRet DIR(Sistema s);
TipoRet CREATE();
TipoRet IF(Directorio d, string nombreArchivo, string texto);
TipoRet TYPE(Directorio d, string nombreArchivo);

//tipo2
TipoRet DELETE();
TipoRet BF();
TipoRet CAT();

//opcionales
TipoRet IC(Directorio d, string nombreArchivo, string texto);
TipoRet BC();
TipoRet UNDELETE();

//otras
void MuestroRetorno(TipoRet ret);
int tamanio(Archivo a);
bool hayComillas(string texto);


#endif // DEFINICIONES_H_INCLUDED
