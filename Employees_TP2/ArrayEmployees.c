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

int addEmployees (eEmployee lista[], int tamanio, int id, char name[], char lastName[], float salary, char sector[])
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
            strcpy(lista[posicion].sector, sector);
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
    int todoOk = -1;
    if(lista != NULL && tamanio > 0)
    {
          printf("-------------------------- NOMINA DE EMPLEADOS --------------------------------\n");
          printf("Legajo          Nombre             Apellido           Salario      Sector\n");
          printf("-------------------------------------------------------------------------------\n");
          for(int i=0; i< tamanio; i++)
             {
                 if(lista[i].isEmpty == 0)
                 {
                     printf("%2d  %20s  %20s  %6.2f  %15s\n ", lista[i].id, lista[i].name, lista[i].lastName, lista[i].salary, lista[i].sector);
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
    eEmployee auxiliarEmployee;
    int todoOk = -1;

    if(lista != NULL && tamanio > 0)
    {
        if(order == 1) // orden up
    {
        for(int i= 0; i < tamanio -1; i++)
    {
        for(int j= i+1; j < tamanio; j++)
        {
            if(strcmp(lista[i].lastName, lista[j].lastName) > 0 || (strcmp(lista[i].lastName, lista[j].lastName) ==0 && (strcmp(lista[i].sector, lista[j].sector) > 0 )))
            {
                //hacer swap
                auxiliarEmployee = lista[i];
                lista[i] = lista[j];
                lista[j] = auxiliarEmployee;
                todoOk = 0;

            }

        }  // segundo for

    }  // primer for
    }
    if(order == 0) // order down
    {
         for(int i= 0; i < tamanio -1; i++)
    {
        for(int j= i+1; j < tamanio; j++)
        {
            if(strcmp(lista[i].lastName, lista[j].lastName) < 0 || (strcmp(lista[i].lastName, lista[j].lastName) ==0 && (strcmp(lista[i].sector, lista[j].sector) < 0 )))
            {
                //hacer swap
                auxiliarEmployee = lista[i];
                lista[i] = lista[j];
                lista[j] = auxiliarEmployee;
                todoOk = 0;

            }

        }  // segundo for

    }  // primer for
    }

    }


    return todoOk;
}

int modificarEmployee(eEmployee lista[], int tamanio, int id)
{
 int todoOk = -1;
 int indice;
 int opcion;
 char auxiliarChar[20];
 float auxiliarFloat = 0;

    if(lista != NULL && tamanio > 0)
    {
        indice = findEmployeeById(lista, tamanio, id);
        if(indice != -1)
        {
               // encontre el que quiero modificar
                printf("Si desea modificar nombre ingrese 1\n");
                printf("Si desea modificar apellido ingrese 2\n");
                printf("Si desea modificar salario ingrese 3\n");
                printf("Si desea modificar sector ingrese 4\n");
                scanf("%d", &opcion);

                switch(opcion)
                {
                case 1:
                    printf("Ingrese el nuevo nombre: ");
                    fflush(stdin);
                    gets(auxiliarChar);
                    strcpy(lista[indice].name,auxiliarChar);
                    printf("Nuevo nombre: %s\n", auxiliarChar);
                    todoOk = 0;
                    break;
                case 2:
                    printf("Ingrese el nuevo apellido: ");
                    fflush(stdin);
                    gets(auxiliarChar);
                    strcpy(lista[indice].lastName,auxiliarChar);
                    printf("Nuevo nombre: %s\n", auxiliarChar);
                    todoOk = 0;
                    break;
                case 3:
                    printf("Ingrese el nuevo salario: ");
                    scanf("%f", &auxiliarFloat);
                    lista[indice].salary = auxiliarFloat;
                    printf("Nuevo salario: %f\n", auxiliarFloat);
                    todoOk = 0;
                    break;
                case 4:
                    printf("Ingrese el nuevo sector: (Ventas, RRHH, Contable, Administracion, Sistemas)");
                    fflush(stdin);
                    gets(auxiliarChar);
                    while( strcmp(auxiliarChar, "Ventas") != 0 &&
                           strcmp(auxiliarChar, "RRHH") != 0 &&
                           strcmp(auxiliarChar, "Contable") != 0 &&
                           strcmp(auxiliarChar, "Administracion") != 0 &&
                           strcmp(auxiliarChar, "Sistemas") != 0 )
                      {
                          printf("Error, reingrese su sector (Ventas, RRHH, Contable, Administracion, Sistemas:");
                          fflush(stdin);
                          gets(auxiliarChar);
                       }

                    strcpy(lista[indice].sector,auxiliarChar);
                    printf("Nuevo sector: %s\n", auxiliarChar);
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

int informeContable(eEmployee lista[], int tamanio)
{
    int todoOk = -1;
    float acumuladorSalarios = 0;
    float promedio = 0;
    int contadorDeEmpleadosBuenSueldo;
    int contadorEmpleados = 0;

    if(lista != NULL && tamanio > 0)
    {
        for(int i= 0; i < tamanio; i ++)
    {
        if(lista[i].isEmpty == 0)
        {
            acumuladorSalarios = acumuladorSalarios + lista[i].salary;
            contadorEmpleados ++;
        }

    }
    promedio = acumuladorSalarios / contadorEmpleados;

    for(int i= 0; i < tamanio; i ++)
    {
       if(lista[i].salary > promedio && lista[i].isEmpty == 0)
       {
           contadorDeEmpleadosBuenSueldo ++;
       }
    }
    printf("-----------------------------------------------------------------\n\n");
    printf("El total de salarios de la empresa es de %6.2f $\n", acumuladorSalarios);
    printf("El salario promedio es de %6.2f $\n", promedio);
    if(contadorDeEmpleadosBuenSueldo == 0)
    {
        printf("Ninguno de nuestros empleados supera el salario promedio");
    }
    printf("%2d de nuestros empleados superan el salario promedio\n", contadorDeEmpleadosBuenSueldo);
    printf("-----------------------------------------------------------------\n\n");
    system("pause");
    todoOk = 0;
    }

    return todoOk;
}

