#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include "func.h"
#define CANTIDAD 10


int main()
{
    eMovie movie[CANTIDAD];
    int opcion=0;
    iniciar(movie,CANTIDAD);
    leerBin(movie, CANTIDAD);

    do
    {
        system("cls");
        opcion=menu();

        switch(opcion)
        {

        case 1:
            altaItem(movie , CANTIDAD);
            break;

        case 2:
            bajaItem(movie, CANTIDAD);
            getch();
            break;

        case 3:
//          modificar(movie , CANTIDAD);
            getch();
            break;

        case 4:
            generarPagWeb(movie, CANTIDAD);
            getch();
            break;

        case 5:
            guardarBin(movie, CANTIDAD);
            getch();
            break;

        default:
            validarMenu(&opcion,"Error, usted eligio una opcion inexistente, reingrese..."," ");
            break;

        }
    }while(opcion!=5);



    return 0;
}

