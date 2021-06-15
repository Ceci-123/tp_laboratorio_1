/*
 ============================================================================
 Name        : Practico3.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"

int main(void) {

	// variables
	char salir = 'n';

	//inicializacion
	setbuf(stdout, NULL);
	fflush(stdin);

	do {

	    switch(menu())
		{
		     case 1:
		         printf("ingresaste 1 ");
                 break;
		     case 2:
		         printf("ingresaste 2:  ");
    	         break;
		     case 3:
		    	printf("ingresaste 3:  ");
		        break;
		     case 4:
		    	printf("ingresaste 4:  ");
		        break;
		     case 5:
		    	printf("ingresaste 5:  ");
		        break;
		     case 6:
		    	printf("ingresaste 6:  ");
		        break;
		     case 7:
		    	printf("ingresaste 7:  ");
		        break;
		     case 8:
		    	printf("ingresaste 8:  ");
		        break;
		     case 9:
		    	printf("ingresaste 9:  ");
		        break;
		     case 10:
		        printf("seguro que quiere salir? s / n\n");
		        fflush(stdin);
		        scanf("%c", &salir);
		        break;
		    default:
		        printf("Opcion no valida\n");
		        break;

		 }   // fin del switch de opciones

	}while(salir == 'n');  // fin del do while del menu


	return EXIT_SUCCESS;
}
