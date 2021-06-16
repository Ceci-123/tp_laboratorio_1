// Maria Cecilia Calanna 1° A

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

int main()
{
    // variables
	char salir = 'n';
	Employee* auxiliarEmpleado;
	int nextId = 1;
	int resultado = 0;

    //inicializacion
    LinkedList* listaEmpleados = ll_newLinkedList();
    if(listaEmpleados == NULL)
    {
        printf("No se pudo crear la lista de empleados\n");
        system("pause");
    }

    do {

	    switch(menu())
		{
		     case 1:
		         printf("Cargar los datos de los empleados desde el archivo en modo texto\n ");
		         resultado = controller_loadFromText("data.csv",listaEmpleados);
		         if(resultado == 1)
                 {
		             printf("Datos cargados con exito\n");
                 }
                 else
                 {
		             printf("Error al cargar los datos\n");
                 }
                 break;
		     case 2:
		         printf("Cargar los datos de los empleados desde el archivo en modo binario\n  ");
		         resultado = controller_loadFromBinary("data.bin", listaEmpleados);
		         if(resultado == 1)
                 {
		            printf("Datos cargados con exito\n");
                 }
                 else
                 {
		            printf("Error al cargar los datos\n");
                 }
    	         break;
		     case 3:
		    	printf("Alta de Empleado \n  ");
		    	resultado = controller_addEmployee(listaEmpleados);
		    	if(resultado == 1)
                {
		         	printf("Alta de empleado realizada\n");
                }
                else
                {
		           printf("Error al dar el alta\n");
                }
		        break;
		     case 4:
		    	printf("Modificar datos de empleado\n");
		    	resultado = controller_editEmployee(listaEmpleados);
		    	if(resultado == 1)
                {
		         	printf("Modificacion de empleado realizada\n");
                }
                else
                {
		           printf("Error al modificar\n");
                }
		        break;
		     case 5:
		    	printf("Baja de Empleado \n");
		    	resultado = controller_removeEmployee(listaEmpleados);
		    	if(resultado == 1)
                {
		        	printf("Baja de empleado realizada\n");
                }
                else
                {
		            printf("Error al dar la baja\n");
                }
		        break;
		     case 6:
		    	printf("Lista de Empleados \n  ");
		    	resultado = controller_ListEmployee(listaEmpleados);
		    	if(resultado != 1)
                {
		            printf("No se puede mostrar la lista\n");
                }
		        break;
		     case 7:
		    	printf("Ordenar empleados\n ");
		    	resultado = controller_sortEmployee(listaEmpleados);
		    	if(resultado != 1)
                {
		            printf("No se pudo ordenar la lista\n");
                }
		        break;
		     case 8:
		    	printf("Guardar los datos de los empleados en el archivo data.csv (modo texto).\n  ");
		    	resultado = controller_saveAsText("data.csv", listaEmpleados);
		    	if(resultado == 1)
                 {
		             printf("Datos cargados con exito\n");
                 }
                 else
                 {
		             printf("Error al cargar los datos\n");
                 }
		        break;
		     case 9:
		    	printf("Guardar los datos de los empleados en el archivo data.bin (modo binario).\n ");
		    	resultado = controller_saveAsBinary("data.bin", listaEmpleados);
		    	if(resultado == 1)
                 {
		             printf("Datos cargados con exito\n");
                 }
                 else
                 {
		             printf("Error al cargar los datos\n");
                 }
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


    return 0;
}

