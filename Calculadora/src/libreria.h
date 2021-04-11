/*
 * libreria.h
 *
 *  Created on: 8 abr. 2021
 *      Author: Ceci
 */

#ifndef LIBRERIA_H_
#define LIBRERIA_H_
/** \brief  Muestra el menu principal del programa
 *
 * \return Devuelve un entero, el numero de la opcion que el usuario elijio
 *
 */
int menu();


/** \brief Cambia el valor de una bandera a true (escribe un 1)
 *
 * \param El puntero a la variable de la bandera
 *
 */
void cambiarFlagATrue (int* f);


/** \brief Muestra en pantalla el resultado de las operaciones matematicas realizadas
 *
 * \param El resultado de la operacion de suma
 * \param El resultado de la operacion de resta
 * \param El resultado de la operacion de multiplicacion
 * \param El resultado de la operacion de division
 * \param El resultado de la operacion de factorial del primer numero
 * \param El resultado de la operacion de factorial del segundo numero
 * \param El valor que devolvio la funcion de division
 * \param El primer operando
 * \param El segundo operando
 *
 */
void informe(float a, float b, float c, float d, float e, float f, int g, float h, float i);


/** \brief  Realiza la suma de los numeros pasados como parametros y escribe el resultado
 *
 * \param Primer numero a sumar, float
 * \param Segundo numero a sumar, float
 * \param Puntero a la variable donde escribe el resultado
 *
 */
void sumar(float a, float b, float* c);


/** \brief Realiza la resta de los numeros pasados como parametros y escribe el resultado
 *
 * \param Primer numero a restar, float
 * \param Segundo numero a restar, float
 * \param Puntero a la variable donde escribe el resultado
 *
 */
void restar(float a, float b, float* c);


/** \brief Multiplica los numeros pasados como parametros y escribe el resultado
 *
 * \param Primer numero a multiplicar, float
 * \param Segundo numero a multiplicar, float
 * \param Puntero a la variable donde escribe el resultado
 *
 */
void multiplicar(float a, float b, float* c);

/** \brief Divide los numeros pasados como parametros, escribe el resultado. Informa si pudo
 *         realizar la division correctamente o si hubo error.
 *
 * \param El numero a dividir, float
 * \param El divisor, float
 * \param El puntero a la variable donde escribe resultado
 * \return Devuelve un 0 si pudo realizar la division correctamente, o devuelve un 1 si hubo error.
 *
 */
int dividir(float a, float b, float* c);


/** \brief Realiza el factorial del numero pasado como parametro
 *
 * \param El numero a factorizar, float
 * \param El puntero a la variable donde escribe el resultado
 *
 */
void factorial(float a, float*b);





#endif /* LIBRERIA_H_ */
