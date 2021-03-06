/*
 * ArrayEmployees.c
 *
 *  Created on: 11 may. 2021
 *      Author: user
 */

#include "ArrayEmployees.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int menu(){
    int opcion;
    char ingreso[2];

    system("cls");

    printf("  --------------------------------------\n");
    printf("  --------------------------------------\n");
    printf("  -            Alta, baja y             -\n");
    printf("  -            modificacion             -\n");
    printf("  -            de Empleados             -\n");
    printf("  ---------------------------------------\n");
    printf("  --------------------------------------\n");
    printf(" 1. Alta de un empleado\n");
    printf(" 2. Modificacion de un empleado\n");
    printf(" 3. Baja de un empleado\n");
    printf(" 4. Informar sobre los empleados \n");
    printf(" 5. Salir del menu\n");

    fflush(stdin);
    gets(ingreso);

    opcion = atoi(ingreso);

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
    int todoOk = -1;
    char auxiliarChar[15];

    if(lista != NULL && tamanio > 0)
    {
          printf("-------------------------- NOMINA DE EMPLEADOS --------------------------------\n");
          printf("Legajo          Nombre             Apellido           Salario      Sector\n");
          printf("-------------------------------------------------------------------------------\n");
          for(int i=0; i< tamanio; i++)
             {
                 if(lista[i].isEmpty == 0)
                 {
                     mostrarSector(lista[i].sector, auxiliarChar);
                     printf("%2d  %20s %20s        %6.2f        %2d  %s \n \n", lista[i].id, lista[i].name, lista[i].lastName, lista[i].salary, lista[i].sector, auxiliarChar);

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
            if(strcmp(lista[i].lastName, lista[j].lastName) > 0 || (strcmp(lista[i].lastName, lista[j].lastName) ==0 && lista[i].sector < lista[j].sector))
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
            if(strcmp(lista[i].lastName, lista[j].lastName) < 0 || (strcmp(lista[i].lastName, lista[j].lastName) ==0 && lista[i].sector < lista[j].sector))
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
 int auxiliarInt = 0;
 int validacion;

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
                    validacion = sonLetras(auxiliarChar);
                    while(validacion == -1)
                    {
                         	printf("No puede ingresar numeros");
                           	printf("Error, reingrese su nombre :");
                           	fflush(stdin);
                           	gets(auxiliarChar);
                    	    validacion = sonLetras(auxiliarChar);
                    }
                    strcpy(lista[indice].name,auxiliarChar);
                    printf("Nuevo nombre: %s\n", auxiliarChar);
                    todoOk = 0;
                    break;
                case 2:
                    printf("Ingrese el nuevo apellido: ");
                    fflush(stdin);
                    gets(auxiliarChar);
                    validacion = sonLetras(auxiliarChar);
                    while(validacion == -1)
                    {
                      	printf("No puede ingresar numeros");
                       	printf("Error, reingrese su apellido :");
                       	fflush(stdin);
                       	gets(auxiliarChar);
                   	    validacion = sonLetras(auxiliarChar);
                    }
                	strcpy(lista[indice].lastName,auxiliarChar);
                    printf("Nuevo apellido: %s\n", auxiliarChar);
                    todoOk = 0;
                    break;
                case 3:
                	printf("Ingrese el nuevo salario :");
                	fflush(stdin);
                	gets(auxiliarChar);
                	validacion = validarNumero(auxiliarChar, &auxiliarFloat);
                	if(validacion != 1)
                	{
                	    printf("Error, reingrese su salario :");
                	    fflush(stdin);
                	    gets(auxiliarChar);
                		validacion = validarNumero(auxiliarChar, &auxiliarFloat);
            		 }
                   // printf("Ingrese el nuevo salario: ");
                   // scanf("%f", &auxiliarFloat);
                    //lista[indice].salary = auxiliarFloat;
                    printf("Nuevo salario: %.2f\n", auxiliarFloat);
                    todoOk = 0;
                    break;
                case 4:
                    printf("Ingrese el nuevo sector: 1-Ventas, 2-RRHH, 3-Contable, 4-Administracion, 5-Sistemas");
                    scanf("%d", &auxiliarInt);
                    while(auxiliarInt < 1 || auxiliarInt > 5 )
                         {
                           printf("Error, reingrese su sector 1-Ventas, 2-RRHH, 3-Contable, 4-Administracion, 5-Sistemas");
                           scanf("%d", &auxiliarInt);
                        }
                    lista[indice].sector = auxiliarInt;
                    mostrarSector(auxiliarInt, auxiliarChar);
                    printf("Nuevo sector: %d %s\n", auxiliarInt, auxiliarChar);
                    todoOk = 0;
                    break;
                default:
                    printf("opcion no valida");

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
    int contadorDeEmpleadosBuenSueldo = 0;
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
        printf("Ninguno de nuestros empleados supera el salario promedio\n");
    }
    else
    {
       printf("%2d de nuestros empleados superan el salario promedio\n", contadorDeEmpleadosBuenSueldo);
       printf("-------------------------- NOMINA DE EMPLEADOS --------------------------------\n");
       printf(" Nombre             Apellido   \n");
    }
    for(int i= 0; i < tamanio; i ++)
        {
           if(lista[i].salary > promedio && lista[i].isEmpty == 0)
           {
               printf("%s   %s\n", lista[i].name, lista[i].lastName);
           }
        }
    printf("-----------------------------------------------------------------\n\n");

    todoOk = 0;
    }

    return todoOk;
}

int validarNumero(char cadena[], float *variable)
{
    int todoOk = 0;

    for(int i= 0; i < strlen(cadena) - 1; i++)
    {
        if(cadena[i] < '0' || cadena[i] > '9' )
        {
            todoOk = -1;
        }
        else
        {
            todoOk = 1;
            *variable = atof(cadena);

        }
    }

    return todoOk;
}

void mostrarSector(int idSector, char nombreSector[15])
{
    char sectores[5][15] = {"Ventas", "RRHH", "Contable", "Administracion", "Sistemas"};

    if((idSector > 0 || idSector < 6) && nombreSector != NULL)
    {
        idSector = idSector -1;
        strcpy(nombreSector, sectores[idSector]);
    }

}

int sonLetras(char cadena[])
{
    int todoOk= -1;
    int i;
    int longitud = strlen(cadena);

      for(i= 0; i < longitud; i++)
      {
          if((cadena[i] > 65 && cadena[i] < 90) || (cadena[i] > 97 && cadena[i] < 122))
          {
              //son letras
              todoOk= 1;
          }
      }

   // devuelve 1 si son letras, devuelve -1 si son numeros

    return todoOk;
}
