/*
 * libreria.c
 *
 *  Created on: 8 abr. 2021
 *      Author: Ceci
 */

#include "libreria.h"
#include <stdio.h>
#include <stdlib.h>

int menu(){
    int opcion;
    //system("cls");
    printf("        *****************************\n");
    printf("        *****************************\n");
    printf("        ******** CALCULADORA ********\n");
    printf("        *****************************\n");
    printf("        *****************************\n");
    printf(" 1. Ingresar primer operando\n");
    printf(" 2. Ingresar segundo operando\n");
    printf(" 3. Calcular todas las operaciones\n");
    printf("          Calcular la suma (a + b) \n");
    printf("          Calcular la resta (a - b)\n");
    printf("          Calcular la multiplicacion (a * b)\n");
    printf("          Calcular la division (a/b)\n");
    printf("          Calcular el factorial (a!)\n");
    printf(" 4. Informar los resultados  \n");
    printf(" 5. para salir \n");
    scanf("%d", &opcion);
    return opcion;

}

void cambiarFlagATrue (int* f)
{
    *f = 1;
}

void informe(float a, float b, float c, float d, float e, float f, int g, float h, float i)
{
    printf("..............Informe de las operaciones realizadas .................\n");
    printf("          El resultado de %.2f + %.2f es %.2f\n",h, i, a);
    printf("          El resultado de %.2f - %.2f es %.2f\n",h, i, b);
    printf("          El resultado de %.2f * %.2f es %.2f\n",h, i, c);
    if(g == 0)
    {
        printf("          El resultado de %.2f / %.2f es %.2f\n",h ,i , d);
    } else
    {
        printf("          No es posible dividir por cero\n");
    }
    printf("          El resultado de (%.2f!) es %.2f y de (%.2f!) es %.2f\n",h, e ,i ,  f);
    //system("pause");
}

void sumar(float a, float b, float *c)
{
    if(c != NULL)
    {
        *c = a + b;
    }

}
void restar(float a, float b, float *c)
{
    if(c != NULL)
    {
    *c = a - b;
    }

}
void multiplicar(float a, float b, float *c)
{
    if(c != NULL)
    {
    *c = a * b;
    }

}
int dividir(float a, float b, float *c)
{
    int retorno = 1;
    if(b != 0 && c != NULL)
    {
    * c= a / b;
    retorno = 0;
    }
    return retorno;
}
void factorial(float a, float *b)
{
    int fact = 1;
    if(b != NULL)
    {
    for(int i=1; i <= a; i++)
    {
        fact *= i;
    }
    *b = (float) fact;

    }

}

