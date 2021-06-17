#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
//Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr);
Employee* employee_newParametros(int id,char* nombre,int horasTrabajadas,int sueldo);
void employee_delete();

int employee_setId(Employee* esteEmpleado,int id);
int employee_getId(Employee* esteEmpleado,int* id);

int employee_setNombre(Employee* esteEmpleado,char* nombre);
int employee_getNombre(Employee* esteEmpleado,char* nombre);

int employee_setHorasTrabajadas(Employee* esteEmpleado,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* esteEmpleado,int* horasTrabajadas);

int employee_setSueldo(Employee* esteEmpleado,int sueldo);
int employee_getSueldo(Employee* esteEmpleado,int* sueldo);

int menu(void);

#endif // employee_H_INCLUDED
