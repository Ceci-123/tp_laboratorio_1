#include "ArrayEmployees.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int menu(){
    int opcion;
    system("cls");

    printf("  --------------------------------------\n");
    printf("  -       Sistema de Empleados          -\n");
    printf("  -                                     -\n");
    printf("  ---------------------------------------\n");
    printf(" 1. Alta de un empleado\n");
    printf(" 2. Modificacion de un empleado\n");
    printf(" 3. Baja de un empleado\n");
    printf(" 4. Informar sobre los empleados \n");
    printf(" 5. Salir del menu\n");
    scanf("%d", &opcion);
    return opcion;
}

int addEmployees (eEmployee* lista[], int tamanio, int id, char name[], char lastName[], float salary, int sector)
{
    int todoOk = -1;
    printf("%d", salary);
    printf("esto funciona de maravilla");
    todoOk = 0;
    return todoOk;
}

void cambiarFlag(int* bandera){

     if(bandera != NULL)
     {
        *bandera = 1;
     }

}
