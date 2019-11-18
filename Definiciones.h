#ifndef DEFINICIONES_H_INCLUDED
#define DEFINICIONES_H_INCLUDED

typedef enum _retorno
{
    OK,ERROR,NO_IMPLEMENTADO
} TipoRet;

typedef struct _archivo
{
    std::string nombreArchivo;
    string contenido[LARGO_MAX];
    _archivo *ptrsig;
    int lineas;
    _archivo *archizq;
    _archivo *archder;
}*Archivo;

typedef struct _directorio      //  /   Dir1  -> Dir11  -> Dir12 ---  Dir2 -> Dir21  -> Dir22
{
    std::string nom;
    Archivo contenido;
    _directorio *hijo;
    _directorio *padre;
    _directorio *hermano;
}*Directorio;

/// tipo1
TipoRet DIR(Directorio d);
TipoRet CREATE(Directorio &d, std::string nombre_archivo);
TipoRet IF(Directorio &d, std::string nombreArchivo, std::string texto);
TipoRet TYPE(Directorio d, std::string nombreArchivo);
TipoRet MKDIR(Directorio &d, std::string nombre_archivo);
TipoRet CD(Directorio &d, string ruta);

/// tipo2
TipoRet DELETE(Directorio &d, std::string palabra);
TipoRet BF(Directorio &d,string nombreArchivo, int linea);
TipoRet CAT(/*Directorio &d, string nombreArchivo1, string nombreArchivo2*/);
TipoRet PWD(Directorio d);
TipoRet RMDIR();

/// opcionales
TipoRet IC(Directorio &d, std::string nombreArchivo, string texto);
TipoRet BC();
TipoRet UNDELETE(Directorio &d, Archivo &repuesto, string &ruta);
TipoRet DIR_S(Directorio d);
TipoRet COPY();

/// otras
void MuestroRetorno(TipoRet ret);
Directorio CreoDirectorio(Directorio d);
int tamanio(Archivo a);
bool hayComillas(std::string texto);
Directorio CrearArchivo(Directorio d, std::string nombre_archivo);
Directorio CrearDirectorio(Directorio &d, string padre, string nombre);
Directorio eliminarArchivo(Directorio d, std::string nombre);
bool esVacio(Archivo a);
bool esVacio2(Directorio d);
Archivo buscoArchivo(Archivo a, string nom);
Directorio buscoDirectorioHermano(Directorio d, string nombre);
Directorio buscoDirectorioHijo(Directorio d, string nombre);
bool hojaArch(Archivo a);
bool hojaDir(Directorio d);
void muestroArchivos(Archivo a);
void muestroArchivosDIRS(Archivo a);
void muestroDirectorios(Directorio d);
void muestroTodo(Directorio raiz);
void cargarDatosDePrueba(Directorio &d);
Directorio recorrida(Directorio d, string texto);
Directorio cargarDirectoriosDePrueba(Directorio d);
Directorio buscoDirectorio(Directorio d, string nombre);
Directorio irAraiz(Directorio d);
void moverseATodos(Directorio d);
void colorAlTexto();
#endif // DEFINICIONES_H_INCLUDED
