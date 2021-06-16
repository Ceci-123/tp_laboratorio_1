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

int employee_setId(Employee* this,int id)
{
    int todoOk = 0;
    if(this != NULL)
    {
        this->id = id;
        todoOk = 1;
    }
    return todoOk;
}
int employee_getId(Employee* this,int* id)
{
    int todoOk = 0;
    if(this != NULL && id != NULL)
    {
        *id = this->id;
        todoOk = 1;
    }
    return todoOk;
}

int employee_setNombre(Employee* this,char* nombre)
{
    int todoOk = 0;
    if(this !=NULL && nombre != NULL)
    {
        strcpy(this->nombre, nombre);
        todoOk = 1;
    }
    return todoOk;
}
int employee_getNombre(Employee* this,char* nombre)
{
    int todoOk = 0;
    if(this !=NULL && nombre != NULL)
    {
        strcpy(nombre,this->nombre);
        todoOk = 1;
    }
    return todoOk;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int todoOk= 0;
    if(this != NULL && horasTrabajadas > 0)
    {
        this->horasTrabajadas = horasTrabajadas;
        todoOk = 1;
    }
    return todoOk;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int todoOk= 0;
    if(this != NULL && horasTrabajadas != NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        todoOk = 1;
    }
    return todoOk;
}

int employee_setSueldo(Employee* this,int sueldo)
{
    int todoOk = 0;
    if(this != NULL && sueldo > 0)
    {
        this->sueldo = sueldo;
        todoOk = 1;
    }
    return todoOk;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
    int todoOk = 0;
    if(this != NULL && sueldo != NULL)
    {
        *sueldo = this->sueldo;
        todoOk = 1;
    }
    return todoOk;

}

