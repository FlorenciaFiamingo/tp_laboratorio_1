#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include "func.h"


/**
* \brief Inicializa el estado del array.
* \param Carga todos los estados en 1 (lugar vacio).
* \return Void.
*/


void iniciar(eMovie *movie, int largo)
{

    if(movie != NULL && largo>0)
    {
        int i;

        for(i=0; i<largo; i++)
        {
            movie[i].estado=1;
        }

    }
}

/**
* \brief Muestra el menú de opciones.
* \param Opcion. El número que ingresó el usuario.
* \return Opción. El número de la opción ingresada.
*/
int menu()
{
    int opcion;

    printf("\tMENU\t\n\n1. Agregar pelicula\n2. Borrar pelicula\n3. Modificar pelicula\n4. Generar pagina web\n5. Salir\n\n* Ingrese una opcion:\n");
    scanf("%d", &opcion);
    system("cls");


    return opcion;
}


/**
* \brief Valida el ingreso de las opciones de un menú.
* \param numOp. Recibe la opción ingresada por el usuario.
* \param mensaje.El mensaje que quiero mostrar.
* \param msgError. Mensaje de error de ingreso.
* \return Opción. El número de la opción ingresada.
*/

int validarMenu (int *numOp, char mensaje[], char msgError[])
{
    char buffer[300];
    int aux;

    printf("%s", mensaje);
    gets(buffer);
    Sleep(1300);
    aux = atoi (buffer);

    if(aux<1 && aux>5)
    {
        system("cls");
        printf("%s", msgError);
        gets(buffer);
        return -1;

    }
    else
    {
        *numOp = aux;
        return 0;
    }
}


/**
* \brief Cargar un alta .
* \param movie. Contiene los datos a completar.
* \param largo. Longitud del array.
* \return Void.
*/

void altaItem(eMovie *movie, int largo)
{
    int i;
    for(i=0; i<largo; i++)
    {
        if(movie[i].estado==1)
        {

            printf("*Ingrese titulo:\n ");
            fflush(stdin);
            gets(movie[i].titulo);
            strupr(movie[i].titulo);
            system("cls");

            printf("*Ingrese genero:\n ");
            fflush(stdin);
            gets(movie[i].genero);
            strupr(movie[i].genero);
            system("cls");

            fflush(stdin);
            getMin(&movie[i].duracion, "*Ingrese duracion en minutos:\n", "Error, ingrese duracion en minutos:\n");
            system("cls");

            printf("*Ingrese descripcion:\n ");
            fflush(stdin);
            gets(movie[i].descripcion);
            system("cls");

            fflush(stdin);
            getIntP(&movie[i].puntaje, "*Ingrese puntaje (01/10):\n", "Error, ingrese puntaje (01/10):\n");
            system("cls");

            printf("*Ingrese URL de la imagen:\n ");
            fflush(stdin);
            gets(movie[i].linkImagen);
            system("cls");

            movie[i].estado=0;
            break;


        }


    }
     if(i==largo)
    {
        printf("\n*No hay lugares libres*\n\n");
        Sleep(1000);
    }



}

/** \brief Borra pelicula
 * \param movie. Estructura donde se encuentra el campo a borrar
 * \param largo. Longitud.
 * \return Void.
 */

 void bajaItem(eMovie *movie,int largo)
{
    int i;
    char buffer[300];
    printf("Ingrese el titulo de la pelicula que desea borrar:\n ");
    fflush(stdin);
    gets(buffer);
    strupr(buffer);

    for(i=0; i<largo; i++)
    {
        if(movie[i].estado==0)
        {
            if(strcmp(buffer, movie[i].titulo)==0)
            {
                movie[i].estado=1;

                printf("*Borrado*\n\n");

                break;

            }

            if(!(strcmp(buffer, movie[i].titulo)==0))
            {

                printf("*No existe el dato ingresado*\n\n");

                break;

            }

        }


    }

}

/** \brief Modifica pelicula
 * \param movie. Estructura donde se encuentra el campo a modificar
 * \param largo. Longitud.
 * \return Void.
 */

/* void modificarItem(eMovie *movie,int largo)
{
    int i, opcion=0;
    char buffer[300];
    printf("Ingrese el titulo de la pelicula que desea modificar:\n ");
    fflush(stdin);
    gets(buffer);
    strupr(buffer);

    printf("\tMENU DE MODIFICACIONES\t\n\n1. Titulo\n2. Genero\n3. Duracion\n4. Descripcion\n5. Puntaje\n6. Salir\n\n* Ingrese una opcion:\n");
    fflush(stdin);
    scanf("%d", &opcion);

    for(i=0; i<largo; i++)
    {
        if(movie[i].estado==0)
        {
            if(strcmp(buffer, movie[i].titulo)==0)
            {
                if(opcion >= 1 && opcion <=6)
                {
                    switch(opcion)
                    {
                        case 1:
                            printf("Ingrese modificacion del titulo:");
                            gets(movie[i].titulo);
                            break;

                        case 2:
                            printf("Ingrese modificacion del genero:");
                            gets(movie[i].genero);
                            break;

                        case 3:
                            printf("Ingrese modificacion de la duracion:");
                            gets(movie[i].duracion);
                            break;

                        case 4:
                            printf("Ingrese modificacion de la descripcion:");
                            gets(movie[i].descripcion);
                            break;

                        case 5:
                            printf("Ingrese modificacion del puntaje:");
                            gets(movie[i].puntaje);
                            break;

                        case 6:
                            break;

                        default:
                            printf("No existe la opcion ingresada");
                            break;

                    }
                }
            }

            if(!(strcmp(buffer, movie[i].titulo)==0))
            {

                printf("*No existe el dato ingresado*\n\n");

                break;

            }

        }


    }

}





*/




/**
 * \brief Solicita un número al usuario y devuelve el resultado.
 * \param num. Puntero que recibe un número entero.
 * \return El número ingresado por el usuario.
 */

int getMin(int* num, char mensaje[], char msgError[])
{
    char buffer[300];
    int aux;

    printf("%s", mensaje);
    gets(buffer);
    aux = atoi(buffer);

    if(!(aux>=1 && aux<=500))
     {
       system("cls");
       printf("%s", msgError);
       gets(buffer);
       return -1;
     }
     else
     {
      * num = aux;
      return 0;
     }


}


/**
 * \brief Solicita un número al usuario y devuelve el resultado.
 * \param num. Puntero que recibe un número entero.
 * \return El número ingresado por el usuario.
 */

int getIntP(int *num, char mensaje[], char msgError[])
{
    char buffer[300];
    int aux;

    printf("%s", mensaje);
    gets(buffer);
    aux = atoi(buffer);

    if(!(aux>=1 && aux<=10))
     {
       system("cls");
       printf("%s", msgError);
       gets(buffer);
       return -1;
     }
     else
     {
      * num = aux;
      return 0;
     }


}


/** \brief genera html con las peliculas
 * \param movie.
 * \param largo. cantidad de iteraciones.
 * \return void
 */
void generarPagWeb(eMovie *movie, int largo)
{
    int i;

     FILE *arch;

    arch=fopen("mispelis.html", "w");

    if(arch == NULL)
    {
        printf("*No se pudo abrir el archivo*\n");
        exit(1);
    }
    fprintf(arch,"<!DOCTYPE html><html lang='en'><head><meta charset='utf-8'><meta http-equiv='X-UA-Compatible' content='IE=edge'><meta name='viewport' content='width=device-width, initial-scale=1'><title>Lista peliculas</title><link href='css/bootstrap.min.css' rel='stylesheet'><link href='css/custom.css' rel='stylesheet'></head><body><div class='container'><div class='row'>");

  for(i=0;i<largo;i++)
    {
        if(movie[i].estado==0)
        {
         fprintf(arch,"<article class='col-md-4 article-intro'><a href='#'><img class='img-responsive img-rounded' src='%s' alt=''>", movie[i].linkImagen);
         fprintf(arch,"</a><h3><a href='#'>%s</a></h3><ul>",movie[i].titulo);
         fprintf(arch,"<li>Genero:%s</li><li>Puntaje:%d</li><li>Duracion:%d</li></ul>", movie[i].genero, movie[i].puntaje,movie[i].duracion);
         fprintf(arch,"<p>%s</p></article>",movie[i].descripcion);
        }
    }

    fprintf(arch,"</div></div><script src='js/jquery-1.11.3.min.js'></script><script src='js/bootstrap.min.js'></script><script src='js/ie10-viewport-bug-workaround.js'></script><script src='js/holder.min.js'></script></body></html>");
    fclose(arch);
    printf("\n*Archivo escrito con exito*\n\n");

}


/** \brief genera archivo binario
 * \param estructura eMovie
 * \param longitud
 * \return void
 */


void guardarBin(eMovie *movie, int lenght)
{
    FILE *archBin;
    archBin = fopen("movie.dat", "wb");
    if(archBin == NULL)
    {
        printf("*No se pudo abrir el fichero*");
        exit(1);
    }

    fwrite(movie, sizeof(eMovie), lenght, archBin);

    printf("\n*Fichero guardado con exito*\n");

    fclose(archBin);
}

/** \brief Lee archivo binario
 * \param estructura eMovie
 * \param cantidad int
 * \return void
 */

void leerBin(eMovie *movie, int lenght)
{
    FILE *archBin;
    archBin = fopen("movie.dat", "rb");
    if(archBin == NULL)
    {
        archBin = fopen("movie.dat", "wb");

    }
    if(archBin == NULL)
    {
        printf("*No se pudo abrir el fichero*");
        exit(1);
    }
    fread(movie, sizeof(eMovie), lenght, archBin);

    printf("\n*Fichero cargado con exito*\n\n");

    system("cls");

    fclose(archBin);
}
