#include "validaciones.h"
#include "string.h"
#include <ctype.h>

int isInteger(float A)
{
   int X;
   int esEntero;

   X=A;
   if(A-X==0)
   {
       esEntero = 1;
   }
    else
    {
        esEntero = 0;
    }
    return esEntero;
}

int validacionDeNumero(int numero,int minimo, int maximo)
{
    int i;

    i=numero;

    while(minimo>numero||numero>maximo)
    {
        printf("Error, numero fuera de rango, reingresar: ");
        scanf("%d",&i);
        numero = i;
    }

    return i;
}

char validacionDeLetra(char letra, char maximo, char minimo)
{
    int auxLetra;
    int auxMaximo;
    int auxMinimo;

    auxLetra = letra;
    auxMaximo = maximo;
    auxMinimo = minimo;

    while(auxMinimo>auxLetra||auxLetra>auxMaximo)
    {
        printf("Error, la letra no es la correcta, Reingresar: ");
        fflush(stdin);
        scanf("%c",&letra);
        auxLetra = letra;
    }
    return auxLetra;
}

int obtenerNumero(char mensaje[])
{
    int numero;

    printf("%s: ", mensaje);
    fflush(stdin);
    scanf("%d", &numero);
    return numero;
}

char obtenerCaracter(char mensaje[])
{
    char caracter;

    printf("%s", mensaje);
    scanf("%c",&caracter);
    return caracter;
}

int obtenerCadena(char mensaje[],char cadena[])
{
    char string[30];

    printf("%s: ",mensaje);
    fflush(stdin);
    fgets(string,30,stdin);
    strtok(string,"\n");
    fflush(stdin);
    for(int i=0;i<30;i++)
        {
            if((string[i]== '0'||string[i]== '1'||string[i]== '2'||string[i]== '3'||string[i]== '4'||string[i]== '5'||string[i]== '6'
               ||string[i]== '7'||string[i]== '8'||string[i]== '9'))
            {
                printf("EL NOMBRE CONTIENE NUMEROS\n");
                return 0;
            }
        }
    strcpy(cadena,string);
    return 1;
}


int menuOpciones()
{
    int opcion;
    char ingreso[2];

    printf("---------------------------------------------------------------------------\n");
    printf("---------------------------------------------------------------------------\n");
    printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
    printf("2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).\n");
    printf("3. Alta de empleado\n");
    printf("4  Modificar datos de empleado\n");
    printf("5  Baja de empleado\n");
    printf("6  Listar empleados\n");
    printf("7  Ordenar empleados\n");
    printf("8  Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
    printf("9. Guardar los datos de los empleados en el archivo data.bin (modo binario).\n");
    printf("10.Salir \n");
    printf("---------------------------------------------------------------------------\n");
    printf("---------------------------------------------------------------------------\n");
    printf("\nIngrese Una Opcion: ");
    fflush(stdin);
    gets(ingreso);
    opcion = atoi(ingreso);
    opcion = validacionDeNumero(opcion,1,10);
    return opcion;
}

int reCall(void)
{
    int i;
    printf("\n");
    system("pause");
    printf("PRESIONE ENTER PARA CONTINUAR");
    system("cls");
    i = menuOpciones();
    return i;
}
