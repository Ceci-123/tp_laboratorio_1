/** \brief Busca en la LinkedList el id con el numero mayor, le suma uno y devuelve el resultado
 *
 * \param Puntero del tipo LinkedList a la lista
 * \return Un entero, el proximo id para otorgar
 **/
int controller_setId(LinkedList* pArrayListEmployee);

/** \brief Busca el numero de id dado dentro de la LinkedList y devuelve el indice del empleado con ese ID.
 *
 * \param Puntero del tipo LinkedList a la lista
 * \param Un entero, el ID buscado
 * \return Un entero, el indice del empleado que tiene ese ID
 **/
int controller_getIndexById(LinkedList* pArrayListEmployee,int idBuscado);

/** \brief Abre el archivo de tipo texto que se solicita y llama a la funcion parser_EmployeeFromText
 *
 * \param Puntero al archivo, con su ruta correspondiente
 * \param Puntero del tipo LinkedList a la lista
 * \return Un entero, 1 en caso de exito o 0 si hubo error
 **/
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);


/** \brief Abre el archivo de tipo binario que se solicita y llama a la funcion parser_EmployeeFromBinary
 *
 * \param Puntero al archivo, con su ruta correspondiente
 * \param Puntero del tipo LinkedList a la lista
 * \return Un entero, 1 en caso de exito o 0 si hubo error
 **/
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);

/** \brief Agrega un empleado a la lista
 *
 * \param Puntero del tipo LinkedList a la lista
 * \return Un entero, 1 en caso de exito o 0 si hubo error
 **/
int controller_addEmployee(LinkedList* pArrayListEmployee);

/** \brief Modifica un empleado existente
 *
 * \param Puntero del tipo LinkedList a la lista
 * \return Un entero, 1 en caso de exito o 0 si hubo error
 **/
int controller_editEmployee(LinkedList* pArrayListEmployee);

/** \brief Borra un empleado de la lista
 *
 * \param Puntero del tipo LinkedList a la lista
 * \return Un entero, 1 en caso de exito o 0 si hubo error
 **/
int controller_removeEmployee(LinkedList* pArrayListEmployee);

/** \brief Imprime por pantalla la lista de empleados
 *
 * \param Puntero del tipo LinkedList a la lista
 * \return Un entero, 1 en caso de exito o 0 si hubo error
 **/
int controller_ListEmployee(LinkedList* pArrayListEmployee);

/** \brief Llama a las funciones de ordenamiento employee_CompareByName y employee_CompareById pasandole los parametros
 *
 * \param Puntero del tipo LinkedList a la lista
 * \return Un entero, 1 en caso de exito o 0 si hubo error
 **/
int controller_sortEmployee(LinkedList* pArrayListEmployee);

/** \brief Guarda la lista de empleados que esta en memoria dinamica en un archivo de texto csv
 *
 * \param Puntero al archivo, con su ruta correspondiente
 * \param Puntero del tipo LinkedList a la lista
 * \return Un entero, 1 en caso de exito o 0 si hubo error
 **/
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);

/** \brief Guarda la lista de empleados que esta en memoria dinamica en un archivo binario
 *
 * \param Puntero al archivo, con su ruta correspondiente
 * \param Puntero del tipo LinkedList a la lista
 * \return Un entero, 1 en caso de exito o 0 si hubo error
 **/
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);
