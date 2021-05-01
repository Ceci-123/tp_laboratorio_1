#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED

int menu(void);

typedef struct{
          int id;
          char name[51];
          char lastName[51];
          float salary;
          int sector;
          int isEmpty;

} eEmployee;

int addEmployees (eEmployee* lista[], int tamanio, int id, char name[], char lastName[], float salary, int sector);

void cambiarFlag(int* bandera)


//void mostrarEmpleado(eEmpleado unEmpleado);
//void mostrarEmpleados(eEmpleado lista[], int tamanio);
//void ordenarEmpleados(eEmpleado lista[], int tamanio);
//void inicializarEmpleado(eEmpleado lista[], int tamanio);

//int buscarLibre(eEmpleado lista[], int tamanio);
//int buscarEmpleado(int legajo, eEmpleado lista[], int tamanio);
#endif // ARRAYEMPLOYEES_H_INCLUDED
