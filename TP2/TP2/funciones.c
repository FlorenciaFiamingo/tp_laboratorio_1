#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include "funciones.h"

/**
* \brief Valida el ingreso de las opciones de un menú.
* \param numOp. Recibe la opción ingresada por el usuario.
* \param mensaje.El mensaje que quiero mostrar.
* \param msgError. Mensaje de error de ingreso.
* \return Opción. El número de la opción ingresada.
*/

int validarMenu (int* numOp, char mensaje[], char msgError[])
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
        * numOp = aux;
        return 0;
    }
}





/**
 * \brief Solicita un número al usuario y devuelve el resultado sólo si es un número entero.
 * \param mensaje. Es el mensaje a ser mostrado.
 * \param mensajeError. Es el mensaje que se muestra cuando no se ingresó un número entero.
 * \return El número ingresado por el usuario o (-1) en caso de error.
 *
 */

 int getLong (long int* doc, char mensaje[], char mensajeError[])
 {
     char buffer[300];
     long int auxDoc;

     printf("%s", mensaje);
     gets(buffer);
     auxDoc = atol (buffer);

     if(auxDoc <= 0)
     {
         system("cls");
         printf("%s", mensajeError);
         gets(buffer);
         return -1;
     }
     else
     {
         * doc = auxDoc;
         return 0;
     }
 }


/**
 * \brief Solicita un número al usuario y devuelve el resultado.
 * \param num. Puntero que recibe un número entero.
 * \return El número ingresado por el usuario.
 *
 */

int getEdad(int* num, char mensaje[], char msgError[])
{
    char buffer[300];
    int aux, i=0;

    printf("%s", mensaje);
    gets(buffer);
    aux = atoi(buffer);

    if(!(aux>=1 && aux<=120))
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
* \brief Muestra el menú de opciones.
* \param Opcion. El número que ingresó el usuario.
* \return Opción. El número de la opción ingresada.
*/
int menu()
{
    int opcion;

    printf("\tMENU\t\n\n1. Agregar una persona\n2. Borrar una persona\n3. Imprimir lista ordenada por nombre\n4. Imprimir grafico de edades\n5. Salir\n\n* Ingrese una opcion:\n");
    scanf("%d", &opcion);
    system("cls");


    return opcion;
}

/**
* \brief Inicializa el estado del array.
* \param IsEmpty. Carga todos los estados en 1 (lugar vacio).
* \return Void.
*/

void iniciar(ePersona personas[], int largo)
{
    int i;
    for(i=0; i<largo; i++)
    {
        personas[i].isEmpty=1;
    }
}

/**
* \brief Cargar un alta .
* \param personas. Contiene los datos a completar.
* \param largo. Longitud del array.
* \return Void.
*/

void altaItem(ePersona personas[], int largo)
{
    int i;
    for(i=0; i<largo; i++)
    {
        if(personas[i].isEmpty==1)
        {

            printf("*Ingrese nombre:\n ");
            fflush(stdin);
            gets(personas[i].nombre);
            strupr(personas[i].nombre);
            system("cls");

            printf("*Ingrese apellido:\n ");
            fflush(stdin);
            gets(personas[i].apellido);
            strupr(personas[i].apellido);
            system("cls");

            fflush(stdin);
            getLong(&personas[i].dni, "*Ingrese documento:\n", "Error, ingrese documento:\n");
            system("cls");

            fflush(stdin);
            getEdad(&personas[i].edad, "*Ingrese edad: \n", "Error, ingrese edad:\n");
            system("cls");

            personas[i].isEmpty=0;
            break;


        }

    }
    if(i==largo)
    {
        printf("\n*No hay lugares libres*\n\n");
        Sleep(1000);
    }
}

/**
* \brief Ordena el array por el criterio "Nombre".
* \param personas. Contiene la variable nombre.
* \param largo. Longitud del array.
* \return Void.
*/

void ordenarNombre(ePersona personas[],int largo)
{
    int i, j;
    ePersona aux;

    for(i=0; i<largo-1; i++)
    {
        for(j=i+1; j<largo; j++)
        {
            if(personas[j].isEmpty!=1)
            {
                if(strcmp(personas[i].nombre,personas[j].nombre)>0)
                {
                    aux=personas[i];
                    personas[i]=personas[j];
                    personas[j]=aux;
                }
            }

        }
    }

    for(i=0;i<largo; i++)
    {
        if(personas[i].isEmpty==0)
            printf("%s - %s - %ld - %d\n",personas[i].nombre, personas[i].apellido,personas[i].dni,personas[i].edad);
    }
}

/**
* \brief Genera la baja funcional de un item.
* \param personas. Contiene el dni.
* \param largo. Longitud del array.
* \return Void.
*/

void bajaItem(ePersona personas[],int largo)
{
    int dni, i;
    printf("Ingrese el documento de la persona que desea borrar:\n ");
    scanf("%d", &dni);

    for(i=0; i<largo; i++)
    {
        if(personas[i].isEmpty==0 && dni==personas[i].dni)
        {
            personas[i].isEmpty=1;

            printf("*Borrado*\n\n");

            break;
        }

    }
    if(i==largo)
    {
       printf("\n\n*No existe el documento ingresado*\n");
    }

}

/**
* \brief Gráfico de barras que indica rango de edades.
* \param personas. Contiene la edad.
* \param largo. Longitud del array.
* \return Void.
*/


void graficoEdad(ePersona* personas, int largo)
{
    int i, j, menor18=0, de19a35=0, mayor35=0, contTodos=0;


    printf("Grafico de edades:\n\n\n\n");

    for(i=0; i<largo; i++)
    {
            if(personas[i].isEmpty!=1)
            {
                     if(personas[i].edad<=18)
                     {
                        menor18++;

                     }
                     else if(personas[i].edad>=19 && personas[i].edad<=35)
                     {
                        de19a35++;
                     }
                     else
                     {
                       mayor35++;

                     }

               contTodos++;

            }

    }

    char graficoBarras[3][contTodos];

    for(i=0; i<3; i++)
    {
        for( j=0 ; j<contTodos; j++ )
        {
            graficoBarras[i][j] = ' ';
        }
    }

    for( j=0 ; j<contTodos ; j++ )
    {
        if( menor18 > j )
        {
            graficoBarras[0][j] = '*';
        }
        if( de19a35 > j)
        {
            graficoBarras[1][j] = '*';
        }
        if( mayor35 > j)
        {
            graficoBarras[2][j] = '*';
        }
    }

    system("cls");

    if(contTodos>0)
    {
        for( j=0 ; j<contTodos ; j++ )
        {
            for( i=0 ; i<3 ; i++ )
            {
                printf("%c\t\t", graficoBarras[i][j]);
            }
            printf("\n");
        }
        printf("\n\n");

        printf("<18\t\t19 a 35\t\t>35\n");
    }

}

