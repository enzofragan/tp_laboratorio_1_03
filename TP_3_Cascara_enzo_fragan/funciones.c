#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
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
    int dura;
    int punt;
    char auxDu[20];
    char auxP[20];
    char auxT[20];
    char auxG[20];
    char auxD[20];
    char auxL[500];

    i=libre(peli,tam);

    if(peli!=NULL && tam>0 && i!=-1)
    {
        id=idAutoInc(peli,tam);
        retorno=1;
        printf("ingrese el titulo: ");
        fflush(stdin);
        gets(auxT);

        while(letraV(auxT)==0)
        {
            printf("ingrese un titulo valido: ");
            fflush(stdin);
            gets(auxT);
        }

        printf("ingrese el genero: ");
        fflush(stdin);
        gets(auxG);

        while(letraV(auxG)==0)
        {
            printf("ingrese un genero valido: ");
            fflush(stdin);
            gets(auxG);
        }

        printf("ingrese la duracion: ");
        fflush(stdin);
        gets(auxDu);

        while(numeroV(auxDu)==0)
        {
            printf("ingrese una duracion valida: ");
            fflush(stdin);
            gets(auxDu);
        }

        dura=atoi(auxDu);

        printf("ingrese el descripcion: ");
        fflush(stdin);
        gets(auxD);

        while(letraV(auxD)==0)
        {
            printf("ingrese una descripcion valida: ");
            fflush(stdin);
            gets(auxD);
        }

        printf("ingrese la puntuacion: ");
        fflush(stdin);
        gets(auxP);

        while(numeroV(auxP)==0)
        {
            printf("ingrese una puntuacion valida: ");
            fflush(stdin);
            gets(auxP);
        }

        punt=atoi(auxP);

        printf("ingrese el link de la portada: ");
        fflush(stdin);
        gets(auxL);

        (peli+i)->estado=0;
        (peli+i)->id=id;
        (peli+i)->duracion=dura;
        (peli+i)->puntaje=punt;
        strcpy((peli+i)->titulo,auxT);
        strcpy((peli+i)->genero,auxG);
        strcpy((peli+i)->descripcion,auxD);
        strcpy((peli+i)->linkImagen,auxL);

        mostrarUno((peli+i));

        guardarEnArchivo(peli,tam);
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
                retorno=(peli+i)->id;
            }
        }
    }
    return retorno+1;
}

int buscarId(EMovie* peli,int tamanio)
{
    int id;
    int i;
    int retorno=-1;

	printf("Ingrese id a dar de baja: ");
	scanf("%d", &id);

	for(i=0; i<tamanio; i++)
	{
		if((peli+i)->id==id)
		{
            retorno=i;
		}
	}
	return retorno;
}

int baja(EMovie* peli,int tamanio)
{
    int i=0;
	char opcion;
	int ret=0;

	if(peli!=NULL)
    {
        i=buscarId(peli,tamanio);
        if(i>0)
        {
            mostrarUno((peli+i));

            printf("\nSeguro desea dar de baja?\n");
            opcion=getche();
            if(opcion=='s')
            {
                (peli+i)->estado=1;
                (peli+i)->duracion=0;
                (peli+i)->puntaje=0;
                (peli+i)->id=0;
                strcpy((peli+i)->titulo,"");
                strcpy((peli+i)->linkImagen,"");
                strcpy((peli+i)->genero,"");
                strcpy((peli+i)->descripcion,"");
                guardarEnArchivo(peli,tamanio);
                ret=1;
            }
            else
            {
                printf("\nEl registro no fue eliminado!\n");
                ret=-1;
            }
        }
    }
}

int modificar(EMovie* peli,int tamanio)
{
    int i;
	char opcion;
    char opcion2;
	int ret=0;
	int id;
    int dura;
    int punt;
    char auxDu[20];
    char auxP[20];
    char auxT[20];
    char auxG[20];
    char auxD[20];
    char auxL[500];

	if(peli!=NULL)
    {
        i=buscarId(peli,tamanio);
        if(i>0)
        {
            mostrarUno(peli);

            printf("\ndesea modificarlo?\n");
            opcion=getche();

            if(opcion=='s')
            {
                printf("\nque modificara?\n");

                printf("1- titulo\n");
                printf("2- genero\n");
                printf("3- duracion\n");
                printf("4- descripcion\n");
                printf("5- puntaje\n");
                printf("6- link de imagen\n");

                scanf("%d",&opcion2);

                switch(opcion2)
                {
                    case 1:
                        printf("ingrese el titulo: ");
                        fflush(stdin);
                        gets(auxT);

                        while(letraV(auxT)==0)
                        {
                            printf("ingrese un titulo valido: ");
                            fflush(stdin);
                            gets(auxT);
                        }
                        strcpy((peli+i)->titulo,auxT);
                        break;
                    case 2:
                        printf("ingrese el genero: ");
                        fflush(stdin);
                        gets(auxG);

                        while(letraV(auxG)==0)
                        {
                            printf("ingrese un genero valido: ");
                            fflush(stdin);
                            gets(auxG);
                        }
                        strcpy((peli+i)->genero,auxG);
                        break;
                    case 3:
                        printf("ingrese la duracion: ");
                        fflush(stdin);
                        gets(auxDu);

                        while(numeroV(auxDu)==0)
                        {
                            printf("ingrese una duracion valida: ");
                            fflush(stdin);
                            gets(auxDu);
                        }

                        dura=atoi(auxDu);
                        (peli+i)->duracion=dura;
                        break;
                    case 4:
                        printf("ingrese el descripcion: ");
                        fflush(stdin);
                        gets(auxD);

                        while(letraV(auxD)==0)
                        {
                            printf("ingrese una descripcion valida: ");
                            fflush(stdin);
                            gets(auxD);
                        }
                        strcpy((peli+i)->descripcion,auxD);
                        break;
                    case 5:
                        printf("ingrese la puntuacion: ");
                        fflush(stdin);
                        gets(auxP);

                        while(numeroV(auxP)==0)
                        {
                            printf("ingrese una puntuacion valida: ");
                            fflush(stdin);
                            gets(auxP);
                        }

                        punt=atoi(auxP);
                        (peli+i)->puntaje=punt;
                        break;
                    case 6:
                        printf("ingrese el link de la portada: ");
                        fflush(stdin);
                        gets(auxL);
                        strcpy((peli+i)->linkImagen,auxL);
                        break;

                }
                guardarEnArchivo(peli,tamanio);
                ret=1;
            }
            else
            {
                printf("\nEl registro no fue modificado!\n");
                ret=-1;
            }
        }
    }
}

int guardarEnArchivo(EMovie* peli,int tamanio)
{

	FILE *f;

    f=fopen("bin.dat","wb");
    if(f == NULL)
    {
        return 1;
    }

	fwrite(peli,sizeof(EMovie),tamanio,f);

	fclose(f);

	return 0;
}

int cargarDesdeArchivo(EMovie* peli,int tamanio)
{
	int flag = 0;
	FILE *f;

	f=fopen("bin.dat", "rb");
	if(f==NULL)
	{
		f= fopen("bin.dat", "wb");
		if(f==NULL)
		{
			return 1;
		}

		flag=1;

	}

	if(flag ==0)
	{
	fread(peli,sizeof(EMovie),tamanio,f);
    }

	fclose(f);
	return 0;

}

int letraV(char nom[])
{
    int i=0;
    while(nom[i] != '\0')
    {
        if((nom[i] != ' ') && (nom[i] < 'a' || nom[i] > 'z') && (nom[i] < 'A' || nom[i] > 'Z'))
        {
            return 0;
        }
        i++;
    }
    return 1;
}

int numeroV(char num[])
{
    int i=0;
    while(num[i] != '\0')
    {
        if(!(isdigit(num[i])))
        {
            return 0;
        }
        i++;
    }
    return 1;
}
