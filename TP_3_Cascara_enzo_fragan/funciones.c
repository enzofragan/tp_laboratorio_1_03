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

int libre(EMovie* peli,int tam)
{
    int retorno = -1;
    int i;
    if(tam > 0 && peli != NULL)
    {
        retorno = -2;
        for(i=0;i<tam;i++)
        {
            if((peli+i)->estado == 1)
            {
                retorno = i;
                break;
            }
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
    int id;
    int auxDu;
    int auxP;
    char auxT[20];
    char auxG[20];
    char auxD[20];
    char auxL[500];

    i=libre(&peli,tam);

    if(peli!=NULL && tam>0 && i!=-1)
    {
        id=idAutoInc(&peli,tam);
        retorno=1;
        printf("ingrese el titulo: ");
        fflush(stdin);
        gets(auxT);

        printf("ingrese el genero: ");
        fflush(stdin);
        gets(auxG);

        printf("ingrese la duracion: ");
        fflush(stdin);
        scanf("%d",&auxDu);

        printf("ingrese el descripcion: ");
        fflush(stdin);
        gets(auxD);

        printf("ingrese la puntuacion: ");
        fflush(stdin);
        scanf("%d",&auxP);

        printf("ingrese el link de la portada: ");
        fflush(stdin);
        gets(auxL);

        (peli+indice)->estado=0;
        (peli+indice)->id=id;
        (peli+indice)->duracion=auxDu;
        (peli+indice)->puntaje=auxP;
        strcpy((peli+indice)->titulo,auxT);
        strcpy((peli+indice)->genero,auxG);
        strcpy((peli+indice)->descripcion,auxD);
        strcpy((peli+indice)->linkImagen,auxL);

        mostrarUno((peli+indice));
    }
    return retorno;
}

int idAutoInc(EMovie* peli,int tam)
{
    int retorno = 0;
    int i;
    if(tam > 0 && peli != NULL)
    {
        for(i=0; i<tam; i++)
        {
            if((peli+i)->estado == 0)
            {
                    if((peli+i)->id<i)
                    {
                         retorno=(peli+i)->id;
                    }

            }
        }
    }

    return retorno+1;
}
