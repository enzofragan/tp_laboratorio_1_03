#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"

int inicio(EMovie* peli,int tama)
{
    int i;
    int retorno=-1;
    for(i=0;i<tama;i++)
    {
        if((peli+i)!=NULL)
        {
            retorno=0;
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
    return retorno;
}

int libre(EMovie* peli,int tam,int* retorno)
{
    int i;

    for(i=0;i<tam;i++)
    {
        if((peli+i)->estado==1 && (peli+i)!=NULL)
        {
            *(retorno)=i;
            break;
        }
    }
    return retorno;
}

int mostrarUno(EMovie* peli)
{
    int i;
    if(peli!=NULL)
    {
        printf("%d----%s----%s----%s----%d----%d----%s\n",peli->id,peli->titulo,peli->linkImagen,peli->genero,peli->duracion,peli->puntaje,peli->descripcion);
    }
}
int mostrar(EMovie* peli,int tam)
{
    int i;
    int retorno=0;

    if(peli!=NULL && tam>0)
    {
        retorno=1;
        for(i=0;i<tam;i++)
        {
            if((peli+i)->estado!=1)
            {
                if(!mostrarUno(peli+i))
                {
                    printf("no se puede mostrar");
                }
            }
        }
    }
    return retorno;
}

int agregarPelicula(EMovie* peli,int tam)
{
    int i;
    int indice=-1;
    int retorno=0;

    i=libre(&peli,tam,&indice);

    if(peli!=NULL && tam>0 && i!=-1)
    {
        retorno=1;
        printf("ingrese el titulo: ");
        fflush(stdin);
        scanf("%s",(peli+indice)->titulo);

        printf("ingrese el genero: ");
        fflush(stdin);
        scanf("%s",(peli+indice)->genero);

        printf("ingrese la duracion: ");
        fflush(stdin);
        scanf("%d",&(peli+indice)->duracion);

        (peli+indice)->estado=0;

        mostrarUno((peli+indice));
    }
    return retorno;
}
