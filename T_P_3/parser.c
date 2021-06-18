#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    Employee* pEmpleado;
    char id[21];
    char nombre[21];
    char horasTrabajadas[21];
    char sueldo[21];
    int idNum;
    int horasNum;
    int sueldoNum;
    fseek(pFile,33,SEEK_SET);
    while(!feof(pFile))
    {
    fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horasTrabajadas,sueldo);
    idNum = atoi(id);
    horasNum = atoi(horasTrabajadas);
    sueldoNum = atoi(sueldo);
    pEmpleado = employee_newParametros(&idNum,nombre,&horasNum,&sueldoNum);
    ll_add(pArrayListEmployee,pEmpleado);
    }
    return 1;
}

int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    Employee* pEmpleado;
    int devolucionFread;

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

    }
    return 1;
}
