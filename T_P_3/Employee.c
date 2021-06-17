#include "Employee.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

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
    fflush(stdin);
    gets(ingreso);
    opcion = atoi(ingreso);
    return opcion;

}

Employee* employee_new()
{
    int todoOk = 0;
    Employee* punteroAEmpleado;

    punteroAEmpleado = malloc(sizeof(Employee));
    if(punteroAEmpleado != NULL)
    {
        todoOk = 1;
    }
     return todoOk;
}

int employee_setId(Employee* esteEmpleado,int id)
{
    int todoOk = 0;
    if(esteEmpleado != NULL)
    {
        esteEmpleado->id = id;
        todoOk = 1;
    }
    return todoOk;
}
int employee_getId(Employee* esteEmpleado,int* id)
{
    int todoOk = 0;
    if(esteEmpleado != NULL && id != NULL)
    {
        *id = esteEmpleado->id;
        todoOk = 1;
    }
    return todoOk;
}

int employee_setNombre(Employee* esteEmpleado,char* nombre)
{
    int todoOk = 0;
    printf("estoy dentro de la funcion set nombre");
    if(esteEmpleado == NULL || nombre == NULL)
    {
        printf("es null");
        system("pause");
    } else
    if(esteEmpleado !=NULL && nombre != NULL)
    {
        strcpy(esteEmpleado->nombre, nombre);
        todoOk = 1;
    }
    return todoOk;
}
int employee_getNombre(Employee* esteEmpleado,char* nombre)
{
    int todoOk = 0;
    if(esteEmpleado !=NULL && nombre != NULL)
    {
        strcpy(esteEmpleado->nombre, nombre);
        todoOk = 1;
    }
    return todoOk;
}

int employee_setHorasTrabajadas(Employee* esteEmpleado,int horasTrabajadas)
{
    int todoOk= 0;
    if(esteEmpleado != NULL && horasTrabajadas > 0)
    {
        esteEmpleado->horasTrabajadas = horasTrabajadas;
        todoOk = 1;
    }
    return todoOk;
}
int employee_getHorasTrabajadas(Employee* esteEmpleado,int* horasTrabajadas)
{
    int todoOk= 0;
    if(esteEmpleado != NULL && horasTrabajadas != NULL)
    {
        *horasTrabajadas = esteEmpleado->horasTrabajadas;
        todoOk = 1;
    }
    return todoOk;
}

int employee_setSueldo(Employee* esteEmpleado,int sueldo)
{
    int todoOk = 0;
    if(esteEmpleado != NULL && sueldo > 0)
    {
        esteEmpleado->sueldo = sueldo;
        todoOk = 1;
    }
    return todoOk;
}

int employee_getSueldo(Employee* esteEmpleado,int* sueldo)
{
    int todoOk = 0;
    if(esteEmpleado != NULL && sueldo != NULL)
    {
        *sueldo = esteEmpleado->sueldo;
        todoOk = 1;
    }
    return todoOk;

}

Employee* employee_newParametros(int id,char* nombre,int horasTrabajadas,int sueldo)
{
    Employee* auxiliarEmpleado;

    auxiliarEmpleado = employee_new();

    employee_setId(auxiliarEmpleado, id);
    employee_setNombre(auxiliarEmpleado,nombre);
    employee_setHorasTrabajadas(auxiliarEmpleado,horasTrabajadas);
    employee_setSueldo(auxiliarEmpleado, sueldo);

    return auxiliarEmpleado;
}
