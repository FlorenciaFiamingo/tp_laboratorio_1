#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include "funciones.h"
#define CANTIDAD 20

int main()
{
    ePersona personas[CANTIDAD];
    int opcion=0;
    iniciar(personas,CANTIDAD);

    do
    {
        system("cls");
        opcion=menu();


        switch(opcion)
        {

        case 1:
            altaItem(personas,CANTIDAD);
            break;

        case 2:
            bajaItem(personas,CANTIDAD);
            getch();
            break;

        case 3:
            printf("\t*Nombre - Apellido - Documento - Edad*\n\n");
            ordenarNombre(personas,CANTIDAD);
            getch();
            break;

        case 4:
            graficoEdad(personas, CANTIDAD);
            getch();
            break;

        case 5:
            break;

        default:
            validarMenu(&opcion,"Error, usted eligio una opcion inexistente, reingrese..."," ");
            break;

        }
    }while(opcion!=5);



    return 0;
}
