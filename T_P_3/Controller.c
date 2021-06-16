#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    FILE* p;
    int todoOk = 0;
    p = fopen(path,"r");
    if(p == NULL)
     {
         printf("No se pudo abrir el archivo\n");
         exit(1);
     }
    if(pArrayListEmployee!= NULL)
    {
       parser_EmployeeFromText(p,pArrayListEmployee);
       todoOk = 1;
    }
    fclose(p);
    return todoOk;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    int todoOk = 0;
    FILE* f = fopen(path, "rb");
    if(f == NULL)
     {
         printf("No se pudo abrir el archivo\n");
     }
     if(pArrayListEmployee != NULL)
     {
         parser_EmployeeFromBinary(f, pArrayListEmployee);
         todoOk= 1;
     }
    fclose(f);
    return todoOk;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    Employee* punteroAEmpleado;
    int todoOk = 0;
    int resultado = 0;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
    int id;

    punteroAEmpleado = employee_new();
    if(punteroAEmpleado != NULL)
    {
       printf("Ingrese nombre del empleado\n");
       fflush(stdin);
       gets(nombre);
       printf("Ingrese cantidad de horas trabajadas\n");
       scanf("%d", horasTrabajadas);
       printf("Ingrese sueldo del empleado\n");
       scanf("%d", sueldo);
       id = 1;
       id++;
       employee_setNombre(punteroAEmpleado, nombre);
       employee_setSueldo(punteroAEmpleado, sueldo);
       employee_setHorasTrabajadas(punteroAEmpleado, horasTrabajadas);
       employee_setId(punteroAEmpleado, id);

    }

    resultado = ll_add(pArrayListEmployee,punteroAEmpleado);
    if(resultado == 1)
    {
       todoOk = 1;
    }
    return todoOk;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk= 0;
    int idAModificar;
    int indice;
    int opcion;
    char nuevoNombre[128];
    int nuevoNumero;
    Employee* pEmpleado = NULL;

    //mostrar lista
    controller_ListEmployee(pArrayListEmployee);
    printf("Ingrese el id del empleado que desea modificar\n");
    scanf("%d", &idAModificar);
    indice = getIndiceXId(pArrayListEmployee, idAModificar);
    if(indice == -1)
    {
        printf("El id ingresado no es valido\n");
    }

    pEmpleado = ll_get(pArrayListEmployee, indice);
    if(pEmpleado != NULL)
    {
       printf("Si desea modificar nombre ingrese 1\n si desea modificar horas trabajadas ingrese 2\n si desea modificar sueldo ingrese 3: ");
       scanf("%d", &opcion);
       switch(opcion)
       {
           case 1:
                 printf("Ingrese nuevo nombre de empleado\n");
                 fflush(stdin);
                 gets(nuevoNombre);
                 employee_setNombre(pEmpleado, nuevoNombre);
                 todoOk= 1;
                 break;
           case 2:
                 printf("Ingrese nueva cantidad de horas trabajadas\n");
                 scanf("%d", &nuevoNumero);
                 employee_setHorasTrabajadas(pEmpleado, nuevoNumero);
                 todoOk= 1;
                 break;
           case 3:
                 printf("Ingrese nuevo sueldo\n");
                 scanf("%d", &nuevoNumero);
                 employee_setSueldo(pEmpleado, nuevoNumero);
                 todoOk= 1;
                 break;
           default:
                 printf("Opcion no valida\n");
                 break;
        }
    }

    return todoOk;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk = 0;
    int idABorrar;
    int indice;
    int resultado;

    controller_ListEmployee(pArrayListEmployee);
    printf("Ingrese el id del empleado que desea borrar\n");
    scanf("%d", &idABorrar);
    indice = getIndiceXId();
    if(indice == -1)
    {
        printf("El indice ingresado es incorrecto\n");
    }
    resultado = ll_remove(pArrayListEmployee, indice);
    if(resultado ==0)
    {
        todoOk = 1;
    }
    return todoOk;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk = 0;
    Employee* auxiliarEmpleado = NULL;
    int tamanio;
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;

    printf(" Id Nombre Horas Trabajadas Sueldo\n");
    printf("-----------------------------------------");
    tamanio = ll_len(pArrayListEmployee);
    for(int i= 0; i < tamanio; i++)
    {
        auxiliarEmpleado = ll_get(pArrayListEmployee, i);
        employee_getId(auxiliarEmpleado, &id);
        employee_getNombre(auxiliarEmpleado, nombre);
        employee_getHorasTrabajadas(auxiliarEmpleado, horasTrabajadas);
        employee_getSueldo(auxiliarEmpleado, &sueldo);
        printf("%4d  %30s  %3d  %6d\n", id, nombre, horasTrabajadas, sueldo);
        todoOk = 1;
    }

    return todoOk;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk = 1;

    return todoOk;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    int todoOk = 0;
    FILE* f;
    Employee* auxiliarEmpleado;
    int tamanio;
    char nombre[128];
    int id;
    int horasTrabajadas;
    int sueldo;

    if(pArrayListEmployee != NULL)
    {
       f = fopen(path, "w");
       if(f == NULL)
       {
             printf("No se pudo abrir el archivo\n");
       }
       else
       {
           //esta todo bien
           tamanio = ll_len(pArrayListEmployee);
           fprintf(f,"Id,Nombre,horasTrabajadas,Sueldo\n");
           for(int i = 0; i < tamanio; i++)
           {
               //escribo en el archivo
               auxiliarEmpleado = (Employee*)ll_get(pArrayListEmployee,i);
               employee_getId(auxiliarEmpleado, &id);
               employee_getNombre(auxiliarEmpleado, nombre);
               employee_getHorasTrabajadas(auxiliarEmpleado, &horasTrabajadas);
               employee_getSueldo(auxiliarEmpleado, &sueldo);
               fprintf(f,"&d,%s,%d,%d\n", id, nombre, horasTrabajadas, sueldo);
               todoOk = 1;
           }
       }
    }

    fclose(f);
    return todoOk;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    int todoOk = 0;
    FILE* f;
    Employee* auxiliarEmpleado;
    int tamanio;

    if(pArrayListEmployee != NULL)
    {
       f = fopen(path, "wb");
    }
    if(f == NULL)
     {
         printf("No se pudo abrir el archivo\n");
     }
     else
     {
         // esta todo bien
         tamanio = ll_len(pArrayListEmployee);
         for(int i= 0; i < tamanio; i++)
         {
             auxiliarEmpleado = (Employee*)ll_get(pArrayListEmployee, i);
             fwrite(auxiliarEmpleado,sizeof(Employee),1,f);
         }
     }

    fclose(f);
    return todoOk;

}

