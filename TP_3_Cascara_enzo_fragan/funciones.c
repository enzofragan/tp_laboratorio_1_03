#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"

void inicio(EMovie* peli,int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
        if((peli+i)!=NULL)
        {
            (peli+i)->estado=1;
            (peli+i)->duracion=0;
            (peli+i)->puntaje=0;
            (peli+i)->id=0;
            strcpy((peli+i)->titulo,"");
            strcpy((peli+i)->linkImagen,"");
            strcpy((peli+i)->genero,"");
            strcpy((peli+i)->descripcion,"");
        }
    }
}
