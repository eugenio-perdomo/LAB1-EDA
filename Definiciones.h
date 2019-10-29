#ifndef DEFINICIONES_H_INCLUDED
#define DEFINICIONES_H_INCLUDED

typedef enum _retorno
{
    OK,ERROR,NO_IMPLEMENTADO
} TipoRet;

typedef char *Cadena;

typedef struct _archivo
{
    std::string nombreArchivo;
    Cadena contenido[LARGO_MAX];
    //_archivo *ptrsig;
    int lineas;
    _archivo *archizq;
    _archivo *archder;
}*Archivo;

typedef struct _directorio
{
    std::string nom;
    Archivo contenido;
    _directorio *subdir;
    _directorio *dirizq;
    _directorio *dirder;
}*Directorio;

//tipo1
TipoRet DIR(Directorio d);
TipoRet CREATE(Directorio d, std::string nombre_archivo);
TipoRet IF(Directorio d, std::string nombreArchivo, std::string texto);
TipoRet TYPE(Directorio d, std::string nombreArchivo);

//tipo2
TipoRet DELETE(Directorio d, std::string palabra);
TipoRet BF(Directorio d,string nombreArchivo, int linea);
TipoRet CAT();

//opcionales
TipoRet IC(Directorio d, std::string nombreArchivo, string texto);
TipoRet BC();
TipoRet UNDELETE();

//otras
void MuestroRetorno(TipoRet ret);
int tamanio(Archivo a);
bool hayComillas(std::string texto);
Directorio CrearArchivo(Directorio d, std::string nombre_archivo);
Directorio eliminarArchivo(Directorio d, std::string nombre);
bool esVacio(Archivo a);
bool esVacioDir(Directorio d);
Archivo buscoArchivo(Archivo a, string nom);
Directorio buscoDirectortio(Directorio d, string nom);
bool hojaArch(Archivo a);
bool hojaDir(Directorio d);
void muestroArchivos(Archivo a);
void muestroDirectorios(Directorio d);
void muestroTodo(Directorio raiz);
void cargarDatosDePrueba(Directorio d);

#endif // DEFINICIONES_H_INCLUDED
