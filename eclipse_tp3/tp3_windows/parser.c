#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    Employee* pEmpleado;
    char id[21];
    char nombre[50];
    char horasTrabajadas[21];
    char sueldo[21];
    int retorno= 0;

    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        //lectura fantasma del encabezado
        fscanf(pFile,"%s\n",nombre);
         while(!feof(pFile))
        {
           if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n] \n",id,nombre,horasTrabajadas,sueldo) == 4)
           {
               pEmpleado = employee_newParametros(id,nombre,horasTrabajadas,sueldo);
               ll_add(pArrayListEmployee,pEmpleado);

           }
            else
            {
                break;
            }
        }
        retorno = 1;
    }

    return retorno;
}

int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    Employee* pEmpleado;
    int devolucionFread;
    int retorno = 0;

    fseek(pFile,33,SEEK_SET);
    while(!feof(pFile))
    {
        pEmpleado = employee_new();
        devolucionFread = fread(pEmpleado,sizeof(Employee),1,pFile);
        if(devolucionFread != 1)
        {
            break;
        }
        ll_add(pArrayListEmployee,pEmpleado);
        retorno = 1;
    }
    return retorno;
}
