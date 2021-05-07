/** Ceci
 ** mayo 2021
 * Trabajo Practico 2 Laboratorio de Programacion
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
 int devolucionDeInit;
 int devolucionDeRemove;
 int flagIniciacion = 0;
 int empleadoElegido;
 int devolucionDeModificar;
 int opcion;

 // inicializo array

 devolucionDeInit = initEmployee(listadoEmpleados, TAM);
 if(devolucionDeInit == 0 && flagIniciacion == 0)
 {
     printf("--------------------------------------\n");
     printf("--                                  --\n");
     printf("--  Sistema inicializado con exito  --\n");
     printf("--                                  --\n");
     printf("--------------------------------------\n");
     cambiarFlag(&flagIniciacion);
     system("pause");
 }
 else
 {
     printf("-------------------------------------------------\n");
     printf("Ocurrio un error en la inicializacion del sistema\n");
     printf("--------------------------------------------------\n");
     system("pause");
 }

    do
    {
    switch(menu())
    {
    case 1:
        printf("Alta de empleado -- Numero de identificacion %3d\n", numeroDeId);
        printf("Ingrese su nombre :");
        fflush(stdin);
        gets(auxiliar.name);
        printf("Ingrese su apellido :");
        fflush(stdin);
        gets(auxiliar.lastName);
        printf("Ingrese su sector:");
        scanf("%d", &auxiliar.sector);

        printf("Ingrese su salario :");
        scanf("%f", &auxiliar.salary);
        devolucionDeAdd = addEmployees(listadoEmpleados, TAM, numeroDeId, auxiliar.name, auxiliar.lastName, auxiliar.salary, auxiliar.sector);
        if(devolucionDeAdd == 0)
        {
            cambiarFlag(&flagIngreso);
            numeroDeId ++;
            printf("Empleado ingresado con exito\n");
            system("pause");
        }
        else
        {
            printf("Ocurrio un error, no pudo ingresarse el empleado\n");
            system("pause");
        }
        break;
    case 2:
        if(flagIngreso == 1)
        {
            printEmployee(listadoEmpleados, TAM);
            printf("Ingrese numero de identificacion del empleado que desea modificar");
            scanf("%d", &empleadoElegido);
            devolucionDeModificar = modificarEmployee(listadoEmpleados, TAM, empleadoElegido);
            if(devolucionDeModificar)
            {
                printf("hubo un error en la modificacion\n");
                system("pause");
            }
            else
            {
                printf("Modificacion realizada con exito\n");
                system("pause");
            }


        }
        else
        {
            printf("No hay empleados ingresados, no pueden realizarse modificaciones\n");
            system("pause");
        }

        break;
    case 3:
        if(flagIngreso == 1)
        {
            printEmployee(listadoEmpleados, TAM);
            printf("Ingrese numero de identificacion del empleado que desea dar de baja");
            scanf("%d", &empleadoElegido);
            devolucionDeRemove = removeEmployee(listadoEmpleados, TAM, empleadoElegido);
            if(devolucionDeRemove == 0)
            {
                printf("El empleado fue dado de baja exitosamente");
                system("pause");
            }
            else
            {
                printf("El empleado no pudo ser dado de baja");
                system("pause");
            }
        }
        else
        {
            printf("No hay empleados ingresados, no pueden realizarse bajas\n");
            system("pause");
        }

        break;
    case 4:
        if(flagIngreso == 1)
        {
            printf("Para obtener un listado de empleados ordenado alfabeticamente\n por apellido ascendente y sector ingrese 1\n");
            printf("Para obtener un listado de empleados ordenado alfabeticamente\n por apellido descendente y sector ingrese 2\n");
            printf("Para obtener un informe sobre los salarios ingrese 3\n");
            scanf("%d", &opcion);
            switch(opcion)
            {
            case 1:
                sortEmployees(listadoEmpleados, TAM, 1);
                printEmployee(listadoEmpleados, TAM);
                system("pause");
            break;
            case 2:
                sortEmployees(listadoEmpleados, TAM, 0);
                printEmployee(listadoEmpleados, TAM);
                system("pause");
            break;
            case 3:
                informeContable(listadoEmpleados, TAM);
            break;
            default:
                printf("Opcion no valida\n");
                system("pause");
                break;
            }

        }
        else
        {
            printf("No hay empleados ingresados, no pueden realizarse informes\n");
            system("pause");
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
