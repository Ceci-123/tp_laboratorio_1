/** Ceci
 ** mayo 2021
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#define TAM 5


int main()
{

 // variables
 char salir='n';
 int numeroDeId = 1;
 eEmployee listadoEmpleados[TAM];
 eEmployee auxiliar;
 int flagIngreso = 0;
 int devolucionDeAdd;

    do
    {
    switch(menu())
    {
    case 1:
        printf("Alta de empleado -- Numero de identificacion %3d\n", numeroDeId);
        printf("Ingrese su nombre");
        fflush(stdin);
        gets(auxiliar.name);
        printf("Ingrese su apellido");
        fflush(stdin);
        gets(auxiliar.lastName);
        printf("Ingrese su sector");
        scanf("%d", &auxiliar.sector);
        printf("Ingrese su salario");
        scanf("%f", &auxiliar.salary);
        devolucionDeAdd = addEmployees(listadoEmpleados, TAM, numeroDeId, auxiliar.name, auxiliar.lastName, auxiliar.salary, auxiliar.sector);
        system("pause");
        if(devolucionDeAdd == 0)
        {
            cambiarFlag(&flagIngreso);
            printf("Empleado ingresado con exito");
        }
        else
        {
            printf("Ocurrio un error, no pudo ingresarse el empleado");
        }
        break;
    case 2:
        if(flagIngreso = 1)
        {
            printf("modificar");
            system("pause");
        }
        else
        {
            printf("No hay empleados ingresados, no pueden realizarse modificaciones");
        }

        break;
    case 3:
        if(flagIngreso = 1)
        {
            printf("baja");
            system("pause");
        }
        else
        {
            printf("No hay empleados ingresados, no pueden realizarse bajas");
        }

        break;
    case 4:
        if(flagIngreso = 1)
        {
            printf("informes");
            system("pause");
        }
        else
        {
            printf("No hay empleados ingresados, no pueden realizarse informes");
        }

        break;
    case 5:
        printf("Desea salir ? s/n");
        fflush(stdin);
        scanf("%c", &salir);
        break;
    default:
        printf("Opcion no valida\n");
        system("pause");
        break;
    }
    }while(salir == 'n');
    return 0;
}
