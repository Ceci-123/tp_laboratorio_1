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

int addEmployees (eEmployee lista[], int tamanio, int id, char name[], char lastName[], float salary, int sector)
{
    int todoOk = -1;
    int posicion;

    if(lista != NULL && tamanio > 0 && id > 0)
    {
        posicion = buscarLibre(lista, tamanio);
        if(posicion == -1)
        {
            printf("no hay posiciones disponibles para ingresar otro empleado \n");
            system("pause");
        }
        else
        {
            lista[posicion].isEmpty = 0;
            strcpy(lista[posicion].name, name);
            strcpy(lista[posicion].lastName, lastName);
            lista[posicion].salary = salary;
            lista[posicion].sector = sector;
            lista[posicion].id = id;

        }
        todoOk = 0;
    }

    return todoOk;
}

void cambiarFlag(int* bandera){

     if(bandera != NULL)
     {
        *bandera = 1;
     }

}

int initEmployee(eEmployee lista[], int tamanio){

    int todoOk = -1;
    if(lista != NULL && tamanio > 0)
    {
        for(int i = 0; i < tamanio; i++)
           {
        lista[i].isEmpty = 1;
           }
        todoOk = 0;
    }

    return todoOk;

}

int printEmployee(eEmployee lista[], int tamanio)
{
    int todoOk = 1;
    if(lista != NULL && tamanio > 0)
    {
          printf("------------- NOMINA DE EMPLEADOS ------------------\n");
          printf("Legajo  Nombre     Apellido     Salario  Sector\n");
          for(int i=0; i< tamanio; i++)
             {
                 if(lista[i].isEmpty == 0)
                 {
                     printf("%2d  %10s  %10s     %5.2f  %2d \n ", lista[i].id, lista[i].name, lista[i].lastName, lista[i].salary, lista[i].sector);
                 }

             }
      todoOk = 0;

    }
    else
    {
        printf("No puede mostrarse la lista\n");
    }
    return todoOk;
}

int buscarLibre(eEmployee lista[], int tamanio)
{
    int posicionVacia = -1;
    if(lista != NULL && tamanio > 0)
    {
       for(int i= 0; i < tamanio;i++)
       {
         if(lista[i].isEmpty)
         {
                posicionVacia = i;
                break;
         }
        }
    }
     return posicionVacia;
}

int findEmployeeById(eEmployee lista[], int tamanio, int id)
{
    int indice = -1;
    if(lista != NULL && tamanio > 0)
    {
        for(int i= 0; i < tamanio; i++)
        {
            if(lista[i].id == id)
            {
                indice = i;
                break;
            }
        }
    }
    return indice;
}

int removeEmployee(eEmployee lista[], int tamanio, int indice)
{
    int todoOk = -1;
    if(lista != NULL && tamanio > 0)
    {
        for(int i= 0; i < tamanio; i++)
        {
            if(lista[i].id == indice)
            {
                lista[i].isEmpty = 1;
                todoOk = 0;
                break;
            }
        }
    }
    return todoOk;

}

int sortEmployees(eEmployee lista[], int tamanio, int order)
{
    //1 up 0 down  -1 error y 0 ok
    return 0;
}

int modificarEmployee(eEmployee lista[], int tamanio, int id)
{
 int todoOk = -1;
 int indice;
 int opcion;

    if(lista != NULL && tamanio > 0)
    {
        indice = findEmployeeById(lista, tamanio, id);
        if(indice != -1)
        {
               // encontre el que quiero modificar
                printf("Si desea modificar nombre ingrese 1");
                printf("Si desea modificar apellido ingrese 2");
                printf("Si desea modificar salario ingrese 3");
                printf("Si desea modificar sector ingrese 4");
                scanf("%d", &opcion);

                switch(opcion)
                {
                case 1:
                    printf("Nuevo nombre: ");
                    todoOk = 0;
                    break;
                case 2:
                    printf("Nuevo apellido: ");
                    todoOk = 0;
                    break;
                case 3:
                    printf("Nuevo salario: ");
                    todoOk = 0;
                    break;
                case 4:
                    printf("Nuevo sector: ");
                    todoOk = 0;
                    break;
                default:
                    printf("opcion no valida");
                    system("pause");
                    break;
                }

        }
     }

    return todoOk;
}


