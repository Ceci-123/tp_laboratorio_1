#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED

int menu(void);

typedef struct{
          int id;
          char name[51];
          char lastName[51];
          float salary;
          char sector[15];
          int isEmpty;

} eEmployee;

int addEmployees (eEmployee lista[], int tamanio, int id, char name[], char lastName[], float salary, char sector[]);

void cambiarFlag(int* bandera);

int initEmployee(eEmployee lista[], int tamanio);

int printEmployee(eEmployee lista[], int tamanio);

int buscarLibre(eEmployee lista[], int tamanio);

int findEmployeeById(eEmployee lista[], int tamanio, int id);

int removeEmployee(eEmployee lista[], int tamanio, int indice);

int sortEmployees(eEmployee lista[], int tamanio, int order);

int modificarEmployee(eEmployee lista[], int tamanio, int id);

int informeContable(eEmployee lista[], int tamanio);


#endif // ARRAYEMPLOYEES_H_INCLUDED
