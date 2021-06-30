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
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
    Employee* pEmpleado;
    int flag = 0;
    pEmpleado = employee_new();

    if(pEmpleado != NULL)
    {
         if(employee_setId(pEmpleado, atoi(idStr)) == 1 &&
            employee_setNombre(pEmpleado, nombreStr)==1 &&
            employee_setHorasTrabajadas(pEmpleado, atoi(horasTrabajadasStr))==1 &&
            employee_setSueldo(pEmpleado,atoi(sueldoStr)) ==1)
           {
               flag = 1;
           }
        if(flag == 0)
        {
            printf("Ocurrio un error al crear el empleado");
            system("pause");
        }

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

int employee_CompareByName(void* employee1, void* employee2)
{
    int resultado;
    Employee* auxiliar1 = NULL;
    Employee* auxiliar2 = NULL;

    if(employee1 != NULL && employee2 != NULL)
    {
       auxiliar1 = (Employee*) employee1;
       auxiliar2 = (Employee*) employee2;
       resultado = strcmp(auxiliar1->nombre, auxiliar2->nombre);
    }
    return resultado;
}

int employee_CompareById(void* employee1, void* employee2)
{
    int resultado;
    Employee* auxiliar1 = NULL;
    Employee* auxiliar2 = NULL;

    if(employee1 != NULL && employee2 != NULL)
    {
       auxiliar1 = (Employee*) employee1;
       auxiliar2 = (Employee*) employee2;
       if(auxiliar1->id > auxiliar2->id)
    {
        resultado = 1;
    }
    else
    {
        if(auxiliar1->id < auxiliar2->id)
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
