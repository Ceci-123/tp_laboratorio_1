/*
 ============================================================================
 Name        : TP_2_Employees_Eclipse.c
 Author      : Ceci
 Version     : mayo 2021
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "ArrayEmployees.h"
#define TAM 1000

int main(void) {

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
	 int devolucionDeValidacion;
	 char auxiliarSalario[10];

	 // inicializo array
     setbuf(stdout, NULL);
     fflush(stdin);

	 devolucionDeInit = initEmployee(listadoEmpleados, TAM);
	 if(devolucionDeInit == 0 && flagIniciacion == 0)
	 {
	     printf("--------------------------------------\n");
	     printf("--                                  --\n");
	     printf("--  Sistema inicializado con exito  --\n");
	     printf("--                                  --\n");
	     printf("--------------------------------------\n");
	     cambiarFlag(&flagIniciacion);

	 }
	 else
	 {
	     printf("-------------------------------------------------\n");
	     printf("Ocurrio un error en la inicializacion del sistema\n");
	     printf("--------------------------------------------------\n");

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
	        printf("Ingrese su sector: 1-Ventas, 2-RRHH, 3-Contable, 4-Administracion, 5-Sistemas");
	        scanf("%d", &auxiliar.sector);
	        while(auxiliar.sector < 1 || auxiliar.sector > 5 )
	        {
	            printf("Error, reingrese su sector 1-Ventas, 2-RRHH, 3-Contable, 4-Administracion, 5-Sistemas");
	            scanf("%d", &auxiliar.sector);
	        }
	        printf("Ingrese su salario :");
	        fflush(stdin);
	        gets(auxiliarSalario);
	        devolucionDeValidacion = validarNumero(auxiliarSalario, &auxiliar.salary);
	        if(devolucionDeValidacion != 1)
	        {
	            printf("Error, reingrese su salario :");
	            fflush(stdin);
	            gets(auxiliarSalario);
	            devolucionDeValidacion = validarNumero(auxiliarSalario, &auxiliar.salary);

	        }
	        devolucionDeAdd = addEmployees(listadoEmpleados, TAM, numeroDeId, auxiliar.name, auxiliar.lastName, auxiliar.salary, auxiliar.sector);
	        if(devolucionDeAdd == 0)
	        {
	            cambiarFlag(&flagIngreso);
	            numeroDeId ++;
	            printf("Empleado ingresado con exito\n");

	        }
	        else
	        {
	            printf("Ocurrio un error, no pudo ingresarse el empleado\n");

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

	            }
	            else
	            {
	                printf("Modificacion realizada con exito\n");

	            }


	        }
	        else
	        {
	            printf("No hay empleados ingresados, no pueden realizarse modificaciones\n");

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
	                printf("El empleado fue dado de baja exitosamente\n");

	            }
	            else
	            {
	                printf("El empleado no pudo ser dado de baja\n");

	            }
	        }
	        else
	        {
	            printf("No hay empleados ingresados, no pueden realizarse bajas\n");

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

	            break;
	            case 2:
	                sortEmployees(listadoEmpleados, TAM, 0);
	                printEmployee(listadoEmpleados, TAM);

	            break;
	            case 3:
	                informeContable(listadoEmpleados, TAM);
	            break;
	            default:
	                printf("Opcion no valida\n");
	                break;
	            }

	        }
	        else
	        {
	            printf("No hay empleados ingresados, no pueden realizarse informes\n");

	        }

	        break;
	    case 5:
	        printf("Desea salir ? s/n");
	        fflush(stdin);
	        scanf("%c", &salir);
	        break;
	    default:
	        printf("Opcion no valida\n");

	        break;
	    }
	    }while(salir == 'n');

	return EXIT_SUCCESS;
}
