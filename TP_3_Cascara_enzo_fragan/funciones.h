#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED


typedef struct{
    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[50];
    int puntaje;
    char linkImagen[500];
    int estado;
    int id;
}EMovie;

int inicio(EMovie* ,int);
int libre(EMovie* ,int);
int mostrarUno(EMovie* );
int mostrar(EMovie* ,int);
int idAutoInc(EMovie* ,int);
int letraV(char []);
int numeroV(char []);
int guardarEnArchivo(EMovie* ,int);
int cargarDesdeArchivo(EMovie* ,int);
int buscarId(EMovie* ,int);
int baja(EMovie* ,int);
int modificar(EMovie* ,int);


/**
 *  Agrega una pelicula al archivo binario
 *  @param movie la estructura a ser agregada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo agregar la pelicula o no
 */
int agregarPelicula(EMovie* ,int);

/**
 *  Borra una pelicula del archivo binario
 *  @param movie la estructura a ser eliminada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo eliminar la pelicula o no
 */
int borrarPelicula(EMovie movie);

/**
 *  Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *  @param lista la lista de peliculas a ser agregadas en el archivo.
 *  @param nombre el nombre para el archivo.
 */
void generarPagina(EMovie lista[], char nombre[]);

#endif // FUNCIONES_H_INCLUDED
