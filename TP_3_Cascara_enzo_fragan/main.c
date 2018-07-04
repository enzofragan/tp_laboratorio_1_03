#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"
#define tam 100

int main()
{
    char seguir='s';
    int opcion=0;
    EMovie peli[tam];
    inicio(&peli,tam);

    cargarDesdeArchivo(peli,tam);

    while(seguir=='s')
    {
        printf("1- Agregar pelicula\n");
        printf("2- Mostrar peliculas\n");
        printf("3- Borrar pelicula\n");
        printf("4- Modificar pelicula\n");
        printf("5- Generar pagina web\n");
        printf("6- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                agregarPelicula(peli,tam);
                break;
            case 2:
                mostrar(peli,tam);
                break;
            case 3:
                baja(peli,tam);
                break;
            case 4:
                modificar(peli,tam);
                break;
            case 6:
                seguir = 'n';
                break;
        }
    }

    return 0;
}
