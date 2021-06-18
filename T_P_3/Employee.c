#include <stdlib.h>
#include <stdio.h>
#include "Employee.h"
#include <string.h>

Employee* employee_new()
{
    Employee* pEmpleado;
    pEmpleado = malloc(sizeof(Employee));
    if(pEmpleado == NULL)
    {
        printf("No hay espacio suficiente en memoria\n");
        return 0;
    }
    return pEmpleado;
}
Employee* employee_newParametros(int* id,char* nombre,int* horasTrabajadas,int* sueldo)
{
    Employee* pEmpleado;
    pEmpleado = employee_new();

    if(pEmpleado != NULL)
    {
       employee_setId(pEmpleado, *id);
       employee_setNombre(pEmpleado, nombre);
       employee_setHorasTrabajadas(pEmpleado, *horasTrabajadas);
       employee_setSueldo(pEmpleado, *sueldo);
    }

    return pEmpleado;
}

int employee_setNombre(Employee* employee,char* nombre)
{
    int todoOk= 0;
    if(employee !=NULL && nombre != NULL)
    {
       strcpy(employee->nombre, nombre);
       todoOk = 1;
    }
    return todoOk;
}

int employee_getNombre(Employee* employee,char* nombre)
{
    int todoOk = 0;
    if(employee !=NULL && nombre != NULL)
    {
       strcpy(nombre,employee->nombre);
       todoOk = 1;
    }
    return todoOk;

}

int employee_setSueldo(Employee* employee,int sueldo)
{
    int todoOk = 0;

    if(employee !=NULL && sueldo > 0)
    {
      employee->sueldo = sueldo;
      todoOk = 1;
    }
    return todoOk;

}

int employee_getSueldo(Employee* employee,int* sueldo)
{
    int todoOk = 0;

    if(employee != NULL && sueldo != NULL)
    {
       *sueldo = employee->sueldo;
        todoOk = 1;
    }
    return todoOk;
}

int employee_setId(Employee* employee,int id)
{
    int todoOk = 0;
    if(employee !=NULL && id > 0)
    {
       employee->id = id;
       todoOk = 1;
    }
    return todoOk;

}
int employee_getId(Employee* employee,int* id)
{
    int todoOk = 0;
    if(employee !=NULL && id != NULL)
    {
        *id = employee->id;
        todoOk = 1;
    }
    return todoOk;

}

int employee_setHorasTrabajadas(Employee* employee,int horasTrabajadas)
{
    int todoOk = 0;

    if(employee != NULL && horasTrabajadas > 0)
    {
       employee->horasTrabajadas = horasTrabajadas;
       todoOk = 1;
    }
    return todoOk;

}

int employee_getHorasTrabajadas(Employee* employee,int* horasTrabajadas)
{
    int todoOk = 0;

    if(employee != NULL && horasTrabajadas != NULL)
    {
      *horasTrabajadas = employee->horasTrabajadas;
       todoOk = 1;
    }
    return todoOk;
}

int employee_CompareByName(Employee* employee1, Employee* employee2)
{
    int resultado;

    if(employee1 != NULL && employee2 != NULL)
    {
        resultado = strcmp(employee1->nombre, employee2->nombre);
    }
    return resultado;
}

int employee_CompareById(Employee* employee1, Employee* employee2)
{
    int resultado;

    if(employee1 != NULL && employee2 != NULL)
    {
       if(employee1->id > employee2->id)
    {
        resultado = 1;
    }
    else
    {
        if(employee1->id < employee2->id)
        {
            resultado = -1;
        }
        else
        {
            resultado = 0;
        }
    }

    }
   return resultado;
}
