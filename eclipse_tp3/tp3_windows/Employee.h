#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

/** \brief Crea un espacio en memoria dinámica para la estructura empleado
 *
 * \return Puntero al empleado
 **/
Employee* employee_new();

/** \brief Crea un espacio en memoria dinámica para la estructura empleado, pasandole los parámetros que quiero agregar
 *
 * \param Un puntero a un entero, el id
 * \param Un puntero al nombre
 * \param Un puntero a un entero, las horas trabajadas
 * \param Un puntero a un entero, el sueldo
 * \return Puntero al empleado
 **/
Employee* employee_newParametros(int* id,char* nombre,int* horasTrabajadas,int* sueldo);


/** \brief Escribe la variable parámetro en el campo ID de la estructura empleado
 *
 * \param Puntero al empleado
 * \param Un entero, el id
 * \return Un entero, 1 si lo pudo escribir y 0 si hubo error
 **/
int employee_setId(Employee* employee,int id);


/** \brief Lee el valor del campo ID de la estructura empleado y lo copia en la variable pasada como parametro
 *
 * \param Puntero al empleado
 * \param Un entero, el id
 * \return Un entero, 1 si lo pudo escribir y 0 si hubo error
 **/
int employee_getId(Employee* employee,int* id);

/** \brief Escribe la variable pasada como parámetro en el campo NOMBRE de la estructura empleado
 *
 * \param Puntero al empleado
 * \param Un puntero a char, el nombre a escribir
 * \return Un entero, 1 si lo pudo escribir y 0 si hubo error
 **/
int employee_setNombre(Employee* employee,char* nombre);


/** \brief Lee el valor del campo NOMBRE de la estructura empleado y lo copia en la variable pasada como parametro
 *
 * \param Puntero al empleado
 * \param Un puntero a char, el nombre a leer
 * \return Un entero, 1 si lo pudo escribir y 0 si hubo error
 **/
int employee_getNombre(Employee* employee,char* nombre);

/** \brief Escribe la variable pasada como parámetro en el campo HORAS TRABAJADAS de la estructura empleado
 *
 * \param Puntero al empleado
 * \param Un entero, las horas trabajadas
 * \return Un entero, 1 si lo pudo escribir y 0 si hubo error
 **/
int employee_setHorasTrabajadas(Employee* employee,int horasTrabajadas);


/** \brief Lee el valor del campo HORAS TRABAJADAS de la estructura empleado y lo copia en la variable pasada como parametro
 *
 * \param Puntero al empleado
 * \param Un entero, las horas trabajadas
 * \return Un entero, 1 si lo pudo escribir y 0 si hubo error
 **/
int employee_getHorasTrabajadas(Employee* employee,int* horasTrabajadas);

/** \brief Escribe la variable pasada como parámetro en el campo SUELDO de la estructura empleado
 *
 * \param Puntero al empleado
 * \param Un entero, el sueldo
 * \return Un entero, 1 si lo pudo escribir y 0 si hubo error
 **/
int employee_setSueldo(Employee* employee,int sueldo);


/** \brief Lee el valor del campo SUELDO de la estructura empleado y lo copia en la variable pasada como parametro
 *
 * \param Puntero al empleado
 * \param Un entero, el sueldo
 * \return Un entero, 1 si lo pudo escribir y 0 si hubo error
 **/
int employee_getSueldo(Employee* employee,int* sueldo);

/** \brief Compara el campo NOMBRE de ambas estructuras empleado y devuelve el resultado
 *
 * \param  Puntero al primer empleado
 * \param  Puntero al segundo empleado
 * \return Un entero, si las cadenas son iguales retornara un valor 0, si la primera cadena es mayor
 *         retornara un valor positivo y si es menor retornara un valor negativo.
 **/
int employee_CompareByName(Employee* e1, Employee* e2);


/** \brief Compara el campo ID de ambas estructuras empleado y devuelve el resultado
 *
 * \param Puntero al primer empleado
 * \param Puntero al segundo empleado
 * \return Un entero, devuelve 1(si el primero es mayor que el segundo),
 *        -1 (si el primero es menor que el segundo) o 0 si son iguales
 **/
int employee_CompareById(Employee* e1, Employee* e2);

#endif // employee_H_INCLUDED
