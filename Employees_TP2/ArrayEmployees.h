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

/** \brief  Agrega los valores recibidos como parametros en la primer posicion vacia del array recibido como parametro
 *
 * \param  El array de empleados
 * \param  El tamaño del array, un entero
 * \param  Un entero, id del empleado
 * \param  Un array de caracteres, el nombre del empleado
 * \param  Un array de caracteres, el apellido del empleado
 * \param  Un numero flotante, el sueldo del empleado
 * \param  Un array de caracteres, el sector al que pertenece el empleado
 * \return  Devuelve 0 si realiza la carga de datos o devuelve -1 si hubo un error
 *
 */
int addEmployees (eEmployee lista[], int tamanio, int id, char name[], char lastName[], float salary, char sector[]);

/** \brief Cambia el valor de la bandera a true (1)
 *
 * \param  La direccion de memoria de la bandera
 *
 */
void cambiarFlag(int* bandera);

/** \brief Pone la bandera isEmpty en true (1) en todas las posiciones del array
 *
 * \param Puntero al array de empleados
 * \param Tamaño del array de empleados
 * \return Devuelve 0 si inicializa o devuelve -1 si hubo un error
 *
 */
int initEmployee(eEmployee lista[], int tamanio);

/** \brief Muestra en pantalla el contenido del array de empleados
 *
 * \param El array de empleados
 * \param El tamaño del array
 * \return Devuelve -1 si hubo un error, o 0 si muestra el array
 *
 */
int printEmployee(eEmployee lista[], int tamanio);

/** \brief Busca la primer posicion con la bandera isEmpty en true (1) del array
 *
 * \param El array de empleados
 * \param El tamaño del array
 * \return El indice de la primer posicion con isEmpty en true del array, o -1 si hubo un error
 *
 */
int buscarLibre(eEmployee lista[], int tamanio);

/** \brief Encuentra en un array el empleado que corresponde al id
 *
 * \param El array de empleados
 * \param El tamaño del array
 * \param Un entero, el id que estoy buscando
 * \return El indice del array donde se encuentra ese empleado, o devuelve -1 si hay un error
 *
 */
int findEmployeeById(eEmployee lista[], int tamanio, int id);

/** \brief Realiza una baja logica (pone isEmpty en 1) en el indice pasado como parametro
 *
 * \param El array de empleados
 * \param El tamaño del array
 * \param El indice del array donde se quiere realizar la baja
 * \return Devuelve -1 si hubo un error o 0 si realizo la baja logica
 *
 */
int removeEmployee(eEmployee lista[], int tamanio, int indice);

/** \brief Ordena los elementos del array de manera alfabetica ascendente o descendente
 *         segun se especifica en el parametro de orden usando el apellido como primer
 *         clave de ordenamiento y el sector como segunda clave
 *
 * \param El array de empleados
 * \param El tamaño del array
 * \param El orden 1 ascendente o 0 descendente
 * \return  Devuelve 0 si realiza el ordenamiento o -1 si hubo un error
 *
 */
int sortEmployees(eEmployee lista[], int tamanio, int order);

/** \brief Realiza modificaciones en el id pasado como parametro del array de empleados
 *
 * \param El array de empleados
 * \param El tamaño del array
 * \param El id de empleado que quiero modificar
 * \return Devuelve 0 si realizo la modificacion o -1 si hubo error
 *
 */
int modificarEmployee(eEmployee lista[], int tamanio, int id);

/** \brief Recibe el array de empleados y realiza un informe sobre los sueldos
 *
 * \param El array de empleados
 * \param El tamaño del array
 * \return Devuelve -1 si hay un error o 0 si realiza el informe
 *
 */
int informeContable(eEmployee lista[], int tamanio);


#endif // ARRAYEMPLOYEES_H_INCLUDED
