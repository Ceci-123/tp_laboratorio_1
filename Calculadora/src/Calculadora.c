/*
 ============================================================================
 Name        : Calculadora.c
 Author      : Ceci
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "libreria.h"

int main(void) {

	 // declaracion de variables
	    char salir = 'n';
	    float primerOperando;
	    float segundOperando;
	    int flagPrimerOperando = 0;
	    int flagSegundOperando = 0;
	    int flagOperaciones = 0;
	    float resultadoSuma;
	    float resultadoResta;
	    float resultadoMultiplicacion;
	    float resultadoDivision;
	    float resultadoFactorialPrimero;
	    float resultadoFactorialSegundo;
	    int comoSalioLaDivision;

	    setbuf(stdout, NULL);
	    fflush(stdin);

	    do {

	        switch(menu())
	        {
	            case 1:
	            printf("ingrese numero:  ");
	            scanf("%f", &primerOperando);
	            printf("(a = %.2f)\n", primerOperando);
	            cambiarFlagATrue(&flagPrimerOperando);
	            break;

	            case 2:
	            if(flagPrimerOperando == 0)
	            {
	                printf("primero ingrese el primer operando\n");

	            } else
	            {
	                printf("ingrese numero:  ");
	                scanf("%f", &segundOperando);
	                printf("(a = %.2f)", primerOperando);
	                printf("(b = %.2f)\n", segundOperando);
	                cambiarFlagATrue(&flagSegundOperando);

	            }
	            break;

	            case 3:
	            if(flagPrimerOperando == 1 && flagSegundOperando == 1)
	            {
	            printf("Realizando operaciones.......\n");
	            sumar(primerOperando, segundOperando, &resultadoSuma);
	            restar(primerOperando, segundOperando, &resultadoResta);
	            multiplicar(primerOperando, segundOperando, &resultadoMultiplicacion);
	            comoSalioLaDivision = dividir(primerOperando, segundOperando, &resultadoDivision);
	            factorial(primerOperando, &resultadoFactorialPrimero);
	            factorial(segundOperando, &resultadoFactorialSegundo);
	            cambiarFlagATrue(&flagOperaciones);

	            } else
	            {
	                printf("Primero debe ingresar los operandos.......\n");

	            }
	            break;

	            case 4:
	            if(flagOperaciones ==1)
	            {
	                informe(resultadoSuma, resultadoResta, resultadoMultiplicacion, resultadoDivision, resultadoFactorialPrimero, resultadoFactorialSegundo, comoSalioLaDivision, primerOperando, segundOperando);
	            }
	            else
	            {
	                printf("Primero debe realizar las operaciones.......\n");
	            }

	            break;

	            case 5:
	            printf("seguro que quiere salir? s / n\n");
	            fflush(stdin);
	            scanf("%c", &salir);
	            break;
	            default:
	                printf("Opcion no valida\n");
	            break;

	        }   // fin del switch de opciones

	    }while(salir == 'n');  // fin del do while del menu
	    return 0;
}
