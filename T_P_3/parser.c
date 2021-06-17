#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    Employee* auxiliarEmpleado;
    char idChar[6];
    char nombre[128];
    char horasTrabajadasChar[10];
    char sueldoChar[10];
    int idNumero;
    int horasTrabajadasNumero;
    int sueldoNumero;
    int todoOk = 0;

    while(!feof(pFile))
    {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",idChar,nombre,horasTrabajadasChar,sueldoChar);
        idNumero = atoi(idChar);
        horasTrabajadasNumero = atoi(horasTrabajadasChar);
        sueldoNumero = atoi(sueldoChar);
        auxiliarEmpleado = employee_newParametros(idNumero,nombre,horasTrabajadasNumero, sueldoNumero);
        ll_add(pArrayListEmployee, auxiliarEmpleado);
        todoOk = 1;
    }
    return todoOk;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
   int todoOk = 0;
   Employee* auxiliarEmpleado;

   while(!feof(pFile))
   {
       auxiliarEmpleado = employee_new();
       fread(auxiliarEmpleado, sizeof(Employee), 1, pFile);
       ll_add(pArrayListEmployee, auxiliarEmpleado);
       todoOk = 1;
   }

    return todoOk;
}
