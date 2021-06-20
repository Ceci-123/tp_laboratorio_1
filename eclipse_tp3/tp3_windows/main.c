// Cecilia Calanna 1° A

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "validaciones.h"

int main()
{
	setbuf(stdout, NULL);
	fflush(stdin);

    LinkedList* miLista = ll_newLinkedList();

    int opcion;
    int resultado;
    opcion = menuOpciones();
    for(;;)
    {

        if(opcion==10)
        {
            opcion = obtenerNumero("Desea salir ? 1.SI // 2. NO");
            if(opcion==1) break;
        }
    switch(opcion)
    {
    case 1:
        resultado = controller_loadFromText("data.csv", miLista);
        if(resultado == 1)
        {
            printf("Archivo cargado con exito\n");
        }
        else
        {
            printf("Error en la carga del archivo\n");
        }
        break;
    case 2:
        resultado = controller_loadFromBinary("dataBIN.bin",miLista);
        if(resultado == 1)
        {
           printf("Archivo cargado con exito\n");
        }
        else
        {
           printf("Error en la carga del archivo\n");
        }
        break;
    case 3:
        resultado = controller_addEmployee(miLista);
        if(resultado == 1)
        {
           printf("Empleado agregado\n");
        }
        else
        {
           printf("Error al agregar el empleado\n");
        }
        break;
    case 4:
        resultado = controller_editEmployee(miLista);
        if(resultado == 1)
        {
            printf("Empleado editado\n");
        }
        else
        {
            printf("Error al editar el empleado\n");
        }
        break;
    case 5:
        resultado = controller_removeEmployee(miLista);
        if(resultado == 1)
        {
            printf("Empleado eliminado de la lista\n ");
        }
        else
        {
           printf("Error, no se pudo eliminar el empleado\n");
        }
        break;
    case 6:
        resultado = controller_ListEmployee(miLista);
        if(resultado != 1)
        {
          printf("No se puede mostrar la lista\n");
        }
        break;
    case 7:
        resultado = controller_sortEmployee(miLista);
        controller_ListEmployee(miLista);
        if(resultado != 1)
        {
           printf("Error al ordenar la lista\n");
        }
        break;
    case 8:
        resultado = controller_saveAsText("data.csv",miLista);
        if(resultado == 1)
        {
          printf ("Archivo guardado con exito\n");
        }
        else
            printf("Error en el guardado del archivo\n");
        break;
    case 9:
        resultado = controller_saveAsBinary("dataBIN.bin",miLista);
        if(resultado == 1)
        {
           printf("Archivo guardado con exito\n");
        }
        else
        {
            printf("Error en el guardado del archivo\n");
        }
        break;
    }
    opcion = reCall();
    }
    ll_deleteLinkedList(miLista);
    return 0;
}
