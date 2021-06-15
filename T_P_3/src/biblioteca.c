/*
 * biblioteca.c
 *
 *  Created on: 14 jun. 2021
 *      Author: user
 */

#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"

int menu(){
    int opcion;
    char ingreso[2];
    printf("\n  **********************************************************************\n");
    printf("  **********************************************************************\n");
    printf(" 1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
    printf(" 2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).\n");
    printf(" 3. Alta de empleado\n");
    printf(" 4  Modificar datos de empleado\n");
    printf(" 5  Baja de empleado\n");
    printf(" 6  Listar empleados\n");
    printf(" 7  Ordenar empleados\n");
    printf(" 8  Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
    printf(" 9. Guardar los datos de los empleados en el archivo data.bin (modo binario).\n");
    printf(" 10.Salir \n");
    printf("\n  **********************************************************************\n");
    printf("  **********************************************************************\n");
    //scanf("%d", &opcion);
    fflush(stdin);
    gets(ingreso);
    opcion = atoi(ingreso);
    return opcion;

}



