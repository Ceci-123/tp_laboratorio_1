#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "validaciones.h"
#include "Controller.h"

int controller_setId(LinkedList* pArrayListEmployee)
{
    Employee* pEmpleado;
    int tamanio;
    int mayor;
    int idObtenido;


    tamanio = ll_len(pArrayListEmployee);
    if(tamanio == 0)
    {
        return tamanio;
    }
    for(int i=0;i<tamanio;i++)
    {
        pEmpleado = ll_get(pArrayListEmployee,i);
        employee_getId(pEmpleado,&idObtenido);
        if(i==0 || idObtenido>mayor)
        {
            mayor = idObtenido;
        }

    }
    return (mayor+1);
}

int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pFile;
    ll_clear(pArrayListEmployee);
    pFile = fopen(path,"r");

    if(pArrayListEmployee != NULL)
    {
        if(pFile == NULL)
        {
            printf("No se encontro el archivo\n");
            return 0;
        }
        parser_EmployeeFromText(pFile,pArrayListEmployee);
    }
    else
    {
        printf("Error en la lista\n");
        return 0;
    }
    fclose(pFile);
    return 1;
}

int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pFile;
    ll_clear(pArrayListEmployee);
    pFile = fopen(path,"rb");

    if(pArrayListEmployee != NULL)
    {
        if(pFile == NULL)
        {
            printf("No se encontro el archivo\n");
            return 0;
        }
        parser_EmployeeFromBinary(pFile,pArrayListEmployee);
        fclose(pFile);
        return 1;
    }
    else
    {
        printf("Error en la lista");
        return 0;
    }
}


int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    Employee* pEmpleado;
    char nombre[20];
    int horasTrabajadas;
    int sueldo;
    int id;
    int devuelve;
    int todoOk = 0;

    pEmpleado = (Employee*)employee_new();
    if(pEmpleado == NULL)
    {
        printf("No hay suficiente espacio en memoria para guardar un empleado\n");
    }
    else
    {
        do
        {
            devuelve = obtenerCadena("Ingrese nombre del empleado", nombre);
        }while(devuelve ==0);
        horasTrabajadas = obtenerNumero("Ingrese cantidad de horas trabajadas (entre 1 y 5000)\n");
        horasTrabajadas = validacionDeNumero(horasTrabajadas,1,5000);
        sueldo = obtenerNumero("Ingrese sueldo (entre 1 y 1000000)\n ");
        sueldo = validacionDeNumero(sueldo,1,1000000);
        id = controller_setId(pArrayListEmployee);
        employee_setNombre(pEmpleado,nombre);
        employee_setHorasTrabajadas(pEmpleado,horasTrabajadas);
        employee_setSueldo(pEmpleado,sueldo);
        employee_setId(pEmpleado,id);
        ll_add(pArrayListEmployee,pEmpleado);
        todoOk = 1;
    }
    return todoOk;
}

int controller_getIndexById(LinkedList* pArrayListEmployee,int idBuscado)
{
    Employee* pEmpleado;
    int tamanio;
    int idObtenido;

    tamanio = ll_len(pArrayListEmployee);
    for(int i=0;i<tamanio;i++)
    {
        pEmpleado = ll_get(pArrayListEmployee,i);
        employee_getId(pEmpleado,&idObtenido);
        if(idObtenido == idBuscado)
        {
            return i;
        }

    }
    return -1;
}

int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    Employee* pEmpleado;
    int id;
    int indice = -1;
    int continuar = 1;
    int opcion;
    int nuevoNumero;
    char nuevaCadena[128];
    int todoOk= 0;

    controller_ListEmployee(pArrayListEmployee);
    while(indice == -1)
    {
        id = obtenerNumero("\nIngrese el id del empleado que quiere modificar");
        indice = controller_getIndexById(pArrayListEmployee,id);
        if(indice == -1)
        {
            printf("El id ingresado es incorrecto\n");
            indice = -1;
        }
        else
            break;
    }
    pEmpleado = ll_get(pArrayListEmployee,indice);
    while(continuar == 1)
    {
        opcion = obtenerNumero("Ingrese 1 para modificar nombre\n Ingrese 2 para modificar horas trabajadas\n ingrese 3 para modificar el sueldo\n");
        switch(opcion)
        {
            case 1:
                obtenerCadena("Ingrese nuevo nombre:", nuevaCadena);
                employee_setNombre(pEmpleado,nuevaCadena);
                todoOk = 1;
                break;
            case 2:
                nuevoNumero = obtenerNumero("Ingrese nueva cantidad de horas trabajadas:");
                employee_setHorasTrabajadas(pEmpleado,nuevoNumero);
                todoOk = 1;
                break;
            case 3:
                nuevoNumero = obtenerNumero("Ingrese nuevo sueldo");
                employee_setSueldo(pEmpleado,nuevoNumero);
                todoOk = 1;
                break;
            default:
                printf("Opcion no valida\n");
                break;
        }
        continuar = obtenerNumero("Desea modificar otro dato?\n1.SI 2.NO");
    }

    return todoOk;
}


int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int id;
    int indice = -1;
    int continuar = 1;
    int todoOk = 0;

    controller_ListEmployee(pArrayListEmployee);
    while(continuar == 1)
    {
        while(indice == -1)
        {
            id = obtenerNumero("Ingrese el numero de id del empleado que desea borrar");
            indice = controller_getIndexById(pArrayListEmployee,id);
            if(indice == -1)
            {
                printf("El id ingresado es incorrecto\n");
            }
            else
                continue;
        }
        ll_remove(pArrayListEmployee,indice);
        todoOk = 1;
        continuar = obtenerNumero("Desea borrar otro empleado?\n 1.SI 2.NO");
        if(continuar==1)
        {
            indice = -1;
        }
        else
            break;
    }

    return todoOk;
}


int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    Employee* auxiliarEmpleado;
    int tamanio;
    int id;
    char nombre[128];
    int horas;
    int sueldo;
    int todoOk = 0;

    printf("    ID              NOMBRE  HORAS TRABAJADAS   SUELDO $\n");
    tamanio = ll_len(pArrayListEmployee);
    for(int i=0;i< tamanio;i++)
    {
        auxiliarEmpleado = ll_get(pArrayListEmployee,i);
        employee_getId(auxiliarEmpleado,&id);
        employee_getNombre(auxiliarEmpleado,nombre);
        employee_getHorasTrabajadas(auxiliarEmpleado,&horas);
        employee_getSueldo(auxiliarEmpleado,&sueldo);
        printf("%5d %20s %8d     %10d\n",id,nombre,horas,sueldo);
        todoOk = 1;
    }
    return todoOk;
}


int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int opcion;
    int upOrDown;
    int todoOk= 0;

    opcion = obtenerNumero("Ingrese 1 si desea ordenar por nombre\n Ingrese 2 si desea ordenar por ID\n ELECCION");
    opcion = validacionDeNumero(opcion,1,2);
    upOrDown = obtenerNumero("Ingrese 0 para ordenar de forma descendente\n Ingrese 1 para ordenar de forma ascendente\n ELECCION");
    upOrDown = validacionDeNumero(upOrDown,0,1);
    switch(opcion)
    {
    case 1:
        ll_sort(pArrayListEmployee,employee_CompareByName,upOrDown);
        todoOk = 1;
        break;
    case 2:
        ll_sort(pArrayListEmployee,employee_CompareById,upOrDown);
        todoOk = 1;
        break;
    }
    return todoOk;
}


int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pFile;
    Employee* auxiliarEmpleado;
    int tamanio;
    char nombre[128];
    int id;
    int horas;
    int sueldo;

    if(pArrayListEmployee != NULL)
    {
    pFile = fopen(path,"w");
    if(pFile == NULL)
    {
        printf("No se pudo abrir el archivo\n");
        return 0;
    }
    else
    {
        tamanio = ll_len(pArrayListEmployee);
        fprintf(pFile,"id,nombre,horastrabajadas,sueldo\n");
        for(int i=0;i<tamanio;i++)
        {
                auxiliarEmpleado = (Employee*)ll_get(pArrayListEmployee,i);
                employee_getId(auxiliarEmpleado, &id);
                employee_getNombre(auxiliarEmpleado,nombre);
                employee_getHorasTrabajadas(auxiliarEmpleado,&horas);
                employee_getSueldo(auxiliarEmpleado, &sueldo);
                fprintf(pFile,"%d,%s,%d,%d\n",id,nombre,horas,sueldo);
        }
    }
    fclose(pFile);
    return 1;
    }
    else printf("Direccion de memoria de la lista incorrecta");
    return 0;
}


int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pFile;
    Employee* employee;
    int tamanio;
    int i;
    char cabecera[33]={"id,nombre,horastrabajadas,sueldo\n"};

    if(pArrayListEmployee != NULL)
    {
    pFile = fopen(path,"wb");
    if(pFile == NULL)
    {
        printf("No se pudo abrir el archivo\n");
        return 0;
    }
    else
    {
        fwrite(cabecera,sizeof(char[33]),1,pFile);
        tamanio = ll_len(pArrayListEmployee);
        for(i=0;i<tamanio;i++)
        {
                employee = (Employee*)ll_get(pArrayListEmployee,i);
                fwrite(employee,sizeof(Employee),1,pFile);
        }
    }
    fclose(pFile);
    return 1;
    }
    else printf("Direccion de memoria de la lista incorrecta");
    return 0;

}
