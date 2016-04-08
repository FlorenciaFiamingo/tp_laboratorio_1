#include <stdio.h>
#include <stdlib.h>

// Funci�n Men�


/**
*\brief Muestra al usuario las opciones de la calculadora.
*\param Opcion. Se ingresa el numero de la opci�n deseada.
*\return Retorna el n�mero de la opci�n.
*
*/

int menu( float num1, float num2)
{
    int opcion;

    printf("1. Ingresar primer operando (A= %.2f)\n", num1);
    printf("2. Ingresar segundo operando (B= %.2f)\n", num2);
    printf("3. Sumar (A+B)\n");
    printf("4. Restar (A-B)\n");
    printf("5. Dividir (A/B)\n");
    printf("6. Multiplicar (A*B)\n");
    printf("7. Factorial (A!)(B!)\n");
    printf("8. Todas las operaciones\n");
    printf("9. Salir \n\n");
    printf("Ingrese el numero de una opcion: \n");
    scanf("%d", &opcion);

    return opcion;
}

// Funci�n Sumar

/**
*\brief Suma dos n�meros.
*\param Operando1, Operando2. Se ingresan los dos n�meros a relizar la operaci�n.
*\return Retorna el resultado.
*/

float sumar(float operando1, float operando2)
{
    float resultado;
    resultado = operando1 + operando2;
    return resultado;
}

// Funci�n Restar

/**
*\brief Resta dos n�meros.
*\param Operando1, Operando2. Se ingresan los dos n�meros a relizar la operaci�n.
*\return Retorna el resultado.
*/

float restar(float operando1, float operando2)
{
    float resultado;
    resultado = operando1 - operando2;
    return resultado;
}

// Funci�n Multiplicar

/**
*\brief Multiplica dos n�meros.
*\param Operando1, Operando2. Se ingresan los dos n�meros a relizar la operaci�n.
*\return Retorna el resultado.
*/

float multiplicar(float operando1, float operando2)
{
    float resultado;
    resultado = operando1 * operando2;
    return resultado;
}

// Funci�n Dividir

/**
*\brief Divide dos n�meros.
*\param Operando1, Operando2. Se ingresan los dos n�meros a relizar la operaci�n.
*\return Retorna el resultado.
*/

float dividir(float operando1, float operando2)
{
    float resultado;
    resultado = operando1 / operando2;
    return resultado;
}

//Funci�n Factorial

/**
*\brief Calcula el factorial de un n�mero.
*\param n. Se ingresa el n�mero del cual quiero calcular el factorial.
*\return Retorna el resultado.
*/

int factorial(int n)
{
   int resp;
   if(n==1)
   return 1;
   resp=n* factorial(n-1);
   return (resp);
}





